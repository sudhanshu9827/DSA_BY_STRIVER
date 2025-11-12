#include <bits/stdc++.h>
using namespace std;

// recursion implementation problem
// i though here is the problem i think question and implemented in a correct way
// some part still have issume that implementation part


// go in a straight direction other recursive code is difficult to run 

#define vvc vector<vector<char>>

class Solution
{

    bool isValid(int row , int col , char val , vvc & board){
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == val)return false;

            if(board[i][col]== val)return false;

            if(board[3*(row/3) + i /3][3* (col/3) + i % 3] == val)return false;
        }
        return true;
    }

    bool solve(vvc &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isValid(i, j, val, board))
                        {
                            board[i][j] = val;

                            if(solve(board) == true)
                                return true;
                            else{
                                board[i][j] = '.';

                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution obj;
    obj.solveSudoku(board);

    cout << "Sudoku board after solveSudoku call:\n";
    for (auto &row : board)
    {
        for (auto &c : row)
            cout << c << " ";
        cout << "\n";
    }
    return 0;
}

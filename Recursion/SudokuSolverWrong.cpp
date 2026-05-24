#include <bits/stdc++.h>
using namespace std;


// Wrong

#define vvc vector<vector<char>>


class Solution {

    bool isGood(char val , int row , int col , vvc & board){
        // Three phases check only 
        // check complete row
        int dupcol = col;
        while(dupcol < 9){
            if(board[row][dupcol++]==val)return false;
        }
        int dupcol = col;
        while(dupcol >=0){
            if(board[row][dupcol--]==val)return false;
        }

        int duprow = row;
        while(duprow < 9){
            if(board[duprow++][col]==val)return false;
        }
        int duprow = row;
        while(duprow >=0){
            if(board[duprow--][col]==val)return false;
        }

        int startrow = (row/3)*3;
        int startcol = (col/3)*3;

        for(int i = startrow ; i <= startrow + 2 ; i++){
            for(int j = startcol ; j <= startcol + 2 ; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
    return true;
    } 

    void solve(int row , int col , vvc & board){
        if(row == 9 && col == 9)return;
        // if(row >= 9 || col >=9 )return;

        for(int col = 0 ; col < 9; col++){
            if(board[row][col] =='.'){
                int val;
                for(int val = 1; val <=9 ; val++){
                    if(isGood('0'+ val , row , col , board)){
                        board[row][col] = '0'+ val;
                        solve(row + 1 , 0 , board);
                        board[row][col] = '.';
                    }
                }
                if(val==10)return;
            }
        }
        if(col==9)
            solve(row + 1 , col , board);
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0 , 0 , board);
    }
};  



// #include <bits/stdc++.h>
// using namespace std;

// #define vvc vector<vector<char>>

// class Solution {

//     bool isGood(char val, int row, int col, vvc &board) {
//         // check row
//         for (int j = 0; j < 9; j++) {
//             if (board[row][j] == val) return false;
//         }

//         // check column
//         for (int i = 0; i < 9; i++) {
//             if (board[i][col] == val) return false;
//         }

//         // check 3x3 box
//         int startrow = (row / 3) * 3;
//         int startcol = (col / 3) * 3;
//         for (int i = startrow; i < startrow + 3; i++) {
//             for (int j = startcol; j < startcol + 3; j++) {
//                 if (board[i][j] == val) return false;
//             }
//         }

//         return true;
//     }

//     bool solve(vvc &board) {
//         for (int row = 0; row < 9; row++) {
//             for (int col = 0; col < 9; col++) {
//                 if (board[row][col] == '.') {
//                     for (char val = '1'; val <= '9'; val++) {
//                         if (isGood(val, row, col, board)) {
//                             board[row][col] = val;
//                             if (solve(board)) return true;
//                             board[row][col] = '.';
//                         }
//                     }
//                     return false; // no valid number found
//                 }
//             }
//         }
//         return true;
//     }

// public:
//     void solveSudoku(vector<vector<char>> &board) {
//         solve(board);
//     }
// };

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    obj.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for (auto &row : board) {
        for (auto &c : row) cout << c << " ";
        cout << "\n";
    }
    return 0;
}

 


int main()
{
     
    return 0;
}
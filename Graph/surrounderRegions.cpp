#include <bits/stdc++.h>
using namespace std;
 

// BFS karke mujhe koi benefit nhi hoo raha 

//DFS ka soch raha hu ki esse karu ki pehle check karlu ki edge too nhi hai jaa jaa kar if ek bhi kahi edge nikal aai too change nhi karunga otherwise i will definitely change



class Solution {

    void markNotConvertable(vector<vector<char>>& board , vector<vector<bool>> notConvertable , int row , int col , int m , int n){
        if(row < 0 || col < 0 || row >=m || col >=n || board[row][col] == 'X' || notConvertable[row][col])return;

        notConvertable[row][col] = true;
        markNotConvertable(board , notConvertable , row + 1 , col , m , n);
        markNotConvertable(board , notConvertable , row - 1 , col , m , n);
        markNotConvertable(board , notConvertable , row , col + 1 , m , n);
        markNotConvertable(board , notConvertable , row , col - 1 , m , n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // sirf corner par trace kar raha hu 
        vector<vector<bool>> notConvertable(m , vector<bool>(n));

        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                markNotConvertable(board, notConvertable , 0 , i , m , n);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(board[m - 1][i] == 'O'){
                markNotConvertable(board, notConvertable , m - 1, i , m , n);
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O'){
                markNotConvertable(board, notConvertable , i , 0 , m , n);
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(board[i][n - 1] == 'O'){
                markNotConvertable(board, notConvertable , i , n - 1 , m, n);
            }
        }

        for(int row = 0 ; row < m ; row++){
            for(int col = 0; col < n ; col++){
                if(board[row][col] == 'O' && !notConvertable[row][col])
                    board[row][col] = 'X';
            }
        }
    }
};
 
int main()
{
     
    return 0;
}
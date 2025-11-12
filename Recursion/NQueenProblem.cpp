#include <bits/stdc++.h>
using namespace std;

#define vvs vector<vector<string>>
#define vs vector<string>
#define pi 3.14


class Solution {

    bool isSafe(int n  , int row , int col , vs & board){
        // their are total 8 direction but we need to checek only three because we have not filled right yet as we are going column wise 
        // check for upper diagonal 
        // Again same mistake  if you change the row and col then how will you check it later 
        // you should have copy of these
        int duprow = row;
        int dupcol = col;
        while(duprow >=0 && dupcol>=0){
            if(board[duprow--][dupcol--] == 'Q')
                return false;
        }
        duprow = row;
        dupcol = col;

        while(dupcol >=0){
            if(board[duprow][dupcol--] =='Q')
                return false;
        }
        duprow = row;
        dupcol = col;

        while(duprow < n && dupcol >=0){
            if(board[duprow++][dupcol--] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int col , int n , vvs &ans , vs & board ){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(n , row , col , board)){
                board[row][col] = 'Q';
                solve(col + 1 , n , ans , board);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n , '.');
        for(int i = 0 ; i < n ; i++)board[i] = s;

        solve(0 , n , ans , board);
        return ans;
    }
};
 
int main()
{
    cout<<pi;
     
    return 0;
}
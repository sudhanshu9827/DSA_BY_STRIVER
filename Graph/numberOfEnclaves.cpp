#include <bits/stdc++.h>
using namespace std;


class Solution {

    void dfs(vector<vector<int>>& grid , int row , int col , int m , int n){
        if(row < 0 || col <0 || row >=m || col >=n || !grid[row][col])return;

        grid[row][col] = 0;

        dfs(grid , row + 1 , col , m  , n);
        dfs(grid , row - 1 , col , m  , n);
        dfs(grid , row , col + 1 , m  , n);
        dfs(grid , row , col - 1 , m  , n);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i <n ; i++){
            if(grid[0][i] == 1){
                dfs(grid , 0 , i , m, n);
            }
        }

        for(int i = 0 ; i <n ; i++){
            if(grid[m - 1][i] == 1){
                dfs(grid , m - 1 , i , m, n);
            }
        }

        for(int i = 0 ; i <m ; i++){
            if(grid[i][0] == 1){
                dfs(grid , i , 0 , m, n);
            }
        }

        for(int i = 0 ; i <m ; i++){
            if(grid[i][n - 1] == 1){
                dfs(grid , i , n - 1 , m, n);
            }
        }

        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                count+=grid[i][j];
            }
        }

        return count;
    }
};
 
int main()
{
     
    return 0;
}
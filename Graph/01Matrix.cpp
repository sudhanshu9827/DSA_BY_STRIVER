#include <bits/stdc++.h>
using namespace std;


// you are not marking cell as visited loop me fass jaayega 

// From (row, col) → goes to (row+1, col)

// From (row+1, col) → goes back to (row, col)

// This loop continues forever

// mark kar bhi dunga too yeh soln koi optimal nhi hai 

// it took O(n4) complexity which is not feasible 
// galt
// // class Solution {

// //     int dfs(int m , int n , int row , int col , vector<vector<int>>& mat , int dis){
// //         if(row < 0 || col < 0 || row >=m ||col >=n || !mat[row][col]){
// //             return dis;
// //         }

// //         return min(min(dfs(m , n , row + 1 , col , mat , dis + 1) , dfs(m , n , row - 1 , col , mat , dis + 1)) , min(dfs(m , n , row, col + 1 , mat , dis + 1) , dfs(m , n , row , col - 1 , mat , dis + 1)));
// //     }
// // public:
// //     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

// //         int m = mat.size();
// //         int n = mat[0].size();

// //         vector<vector<int>> ans(m , vector<int>(n));

// //         for(int row = 0 ; row < m ; row++){
// //             for(int col = 0; col < n ; col++){
// //                 ans[row][col] = dfs(m  , n , row  , col , mat , 0);
// //             }
// //         }
// //     }
// // };


// ek thought aaya ki zero se start karke bfs laga du 

class Solution {

    void nearBy(vector<vector<int>>& mat , queue<pair<int , int>> & q , vector<vector<int>>& ans , int row , int col , int m , int n ,int time){
        if(row + 1 < m && mat[row + 1][col] == 1){
            q.push({row + 1 , col});
            mat[row + 1][col] = 0;
            ans[row + 1][col] = time;
        }

        if(row - 1 >=0 && mat[row - 1][col] == 1){
            q.push({row - 1 , col});
            mat[row - 1][col] = 0;
            ans[row - 1][col] = time;
        }

        if(col + 1 < n && mat[row][col + 1] == 1){
            q.push({row , col + 1});
            mat[row][col + 1] = 0;
            ans[row][col + 1] = time;
        }

        if(col -1 >=0 && mat[row][col - 1] == 1){
            q.push({row , col - 1});
            mat[row][col - 1] = 0;
            ans[row][col - 1] = time;
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m , vector<int>(n));

        queue<pair<int , int>> q;

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(!mat[row][col]){
                    q.push({row , col});
                    ans[row][col] = 0;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            time++;

            for(int i = 0 ; i < size ; i++){
                auto [r , c] = q.front();
                q.pop();

                nearBy(mat , q , ans , r , c , m , n , time);
            }
        }

        return ans;
    }
};
 
int main()
{
     
    return 0;
}
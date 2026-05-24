#include <bits/stdc++.h>
using namespace std;


// if 2 ka count one se jaada hai then boo particular minute par dono kaam karenge aur boo evaluate karna muskil hoo raha hai 
// dfs ke through i cant see all the rotten oranges at a particular timing 


// My thinking goes toward BFS


// Not fully correct incorrect for multiple rotten oranges 
// class Solution {
//     int dfs(int row , int col, vector<vector<int>>& grid , int count, int m , int n){
//         if(row < 0 || col < 0 || row >= m || col >=n || grid[row][col] == 0)return count;
//         grid[row][col] = 0;

//         return max(max(dfs(row - 1 , col , grid , count + 1 , m , n),
//         dfs(row + 1 , col , grid , count + 1 , m , n)),
//         max(dfs(row , col + 1 , grid , count + 1 , m ,n),
//         dfs(row , col - 1 , grid , count + 1 , m , n)));
//     }
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int count = 0;
//         int m = grid.size();
//         int n = grid[0].size();

//         for(int row = 0 ;row < m ; row++){
//             for(int col = 0; col < n ; col++){
//                 if(grid[row][col] == 2){
//                     count = dfs(row , col , grid , -1 , m , n);
//                     break;
//                 }
//             }
//         }

//         // for(int row = 0 ;row < m ; row++){
//         //     for(int col = 0; col < n ; col++){
//         //         cout<<grid[row][col]<<" ";
//         //     }
//         //     cout<<endl;
//         // }


//         for(int row = 0 ;row < m ; row++){
//             for(int col = 0; col < n ; col++){
//                 if(grid[row][col]){
//                     return -1;
//                 }
//             }
//         }

//         return count;
//     }
// };

class Solution {
    void makeFreshToRotten(queue<pair<int , int>>& q , vector<vector<int>>& grid , int row , int col , int m , int n ){
        if(row + 1 < m && grid[row + 1][col] == 1){
            q.push({row + 1 , col});
            grid[row + 1][col] = 2;
        }

        if(row - 1 >=0 && grid[row - 1][col] == 1){
            q.push({row - 1 , col});
            grid[row - 1][col] = 2;
        }

        if(col + 1 < n && grid[row][col + 1] == 1){
            q.push({row , col + 1});
            grid[row][col + 1] = 2;
        }

        if(col -1 >=0 && grid[row][col - 1] == 1){
            q.push({row , col - 1});
            grid[row][col - 1] = 2;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int , int>> q;
        int m = grid.size();
        int n = grid[0].size();
    
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]==2){
                    q.push({row , col});
                }
            }
        }


        int count = -1;

        while(!q.empty()){
            int size = q.size();
            count++;
            
            for(int i = 0 ; i < size; i++){
                auto [r , c] = q.front();
                q.pop();
                makeFreshToRotten(q , grid , r , c , m , n);
            }
        }

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]==1){
                   return -1;
                }
            }
        }

        return count == -1 ? 0 : count;
    }
};
 
int main()
{
     
    return 0;
}
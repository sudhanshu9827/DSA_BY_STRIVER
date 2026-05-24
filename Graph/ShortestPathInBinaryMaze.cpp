#include <bits/stdc++.h>
using namespace std;


// why not dfs 

// dfs 1st explore the full path in depth then find another path 

// theoritically dfs is possible 

//practically it is now possible 

// everytime i explore 8 directions in an n * n grid so TC : (8 ^ n * n) which is astronomically large.



// what i make mistake is 

// 1st day me nhi karra tha dimaag ghoom gaya 

// 2nd day only dy[i] and nhi kiya during checking 

// Takeaways are very good 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we can move if zero in any of the 8 direction we have 

        int n = grid.size();

        if(grid[0][0] || grid[n - 1][n - 1])return -1;


        vector<int> dx = {0 , 0 , 1 , 1 , 1 , -1 , -1 , -1};
        vector<int> dy = {1 , -1 , 0 , 1 , -1 , 0 , -1 , 1};

        queue<pair<int , int>> q;

        q.push({0 , 0});

        vector<vector<int>> cost(n , vector<int>(n , 1e9));

        cost[0][0] = 1;

        while(!q.empty()){
            auto [currRow , currCol] = q.front();
            q.pop();
            
            for(int i = 0; i < 8 ; i++){
                if(currRow + dx[i] >=0 && currRow + dx[i] <n && currCol + dy[i] >=0 && currCol + dy[i] < n &&
                    grid[currRow + dx[i]][currCol + dy[i]] == 0 &&
                    cost[currRow][currCol] + 1 < cost[currRow + dx[i]][currCol + dy[i]]){
                    cost[currRow + dx[i]][currCol + dy[i]] = cost[currRow][currCol] + 1;
                    q.push({currRow + dx[i] , currCol + dy[i]});
                }
            }
        }

        return cost[n - 1][n - 1] == 1e9 ? -1 : cost[n - 1][n - 1];
    }
};
 
int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// ! How do i store the shape in matrix really very much intutive 

// Unable to thing 

// I can able to find number of island but how can i distinguise between similar island this is really a bit challenging for me 

//how do i store the shape of the island  this is the major task for me 

//Apprently got an idea how do i store the shape :

// How do i think later on i can store shape as like 1 hii cell hai boo identical hai ki nhi kaise pata karoge usko usme se hii gatha doo

// [() ()] base me se bagal waale ko gatha dunga then definitely i am damnn sure i will get same shape 

//for  Identical store it into the set data struture

// User function Template for C++

class Solution {
    
    void dfs(vector<vector<int>>& grid , vector<pair<int , int>>& vp , vector<vector<bool>>& visited , int row , int col , int n , int m , int startRow , int startCol ){
        if(row < 0 || col < 0 || row >=n || col >= m || visited[row][col] || !grid[row][col]){
            return;
        }
        
        visited[row][col] = true;
        
        vp.push_back({row - startRow ,col - startCol});
        dfs(grid , vp , visited, row + 1 , col , n , m , startRow , startCol);
        dfs(grid , vp , visited, row - 1 , col , n , m , startRow , startCol);
        dfs(grid , vp , visited, row , col + 1 , n , m , startRow , startCol);
        dfs(grid , vp , visited, row , col - 1 , n , m , startRow , startCol);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n , vector<bool>(m));
        
        set<vector<pair<int , int>>> svp;
        
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                vector<pair<int , int>> vp;
                if(grid[row][col] && visited[row][col]){
                    dfs(grid , vp , visited , row , col , n , m , row , col);
                    svp.insert(vp);
                }
            }
        }
        return svp.size();
    }
};

 
int main()
{
     
    return 0;
}
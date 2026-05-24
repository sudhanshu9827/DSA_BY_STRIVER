#include <bits/stdc++.h>
using namespace std;



// This code is correct but gives Time Limit Exceed error for large test cases
class Solution
{
    int dfs(int n, int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (row >= n && col >= n && row < 0 && col < 0 && grid[row][col] == 0 && visited[row][col])
        {
            return 0;
        }

        visited[row][col] = true;

        // this is to find longest path 
        // not connected one's bhool gaye kya nhi nhi 

        return 1 +
           dfs(n, row + 1, col, grid, visited) +
           dfs(n, row - 1, col, grid, visited) +
           dfs(n, row, col + 1, grid, visited) +
           dfs(n, row, col - 1, grid, visited);
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n));

        int maxi = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] && !visited[row][col])
                {
                    maxi = max(maxi, dfs(n, row, col, grid, visited));
                }
            }
        }

        // visited.clear(); yeh size ko bhi clear kar dega 
        visited = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // visited.clear();
                visited = vector<vector<bool>>(n, vector<bool>(n, false));
                if (!grid[row][col])
                {
                    grid[row][col] = 1;
                    maxi = max(maxi, dfs(n, row, col, grid, visited));
                    grid[row][col] = 0;
                }
            }
        }

        return maxi;
    }
};

// We are adding the edge basically when converting 0 -> 1 so dynamic graph => use disjoint data set

class DisjointSet{
    vector<int> rank , parent;
    public:
        // constructor 
        vector<int> size;
        DisjointSet(int n){
            rank.resize(n + 1 , 0); // to work with both zero as well as 1 based indexing
            parent.resize(n + 1);
            size.resize(n + 1 , 1);

            // yaha n ko equal me nhi likha tha
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
        }

        int findPar(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findPar(parent[node]); // This is where we used path compression
        }

        void unionByRank(int u , int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v) return ;

            if(rank[ulp_u] < rank[ulp_v]){
                // soo smaller guy gets attached 
                parent[ulp_u] = ulp_v;
            }

            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }

            else{
                // if both the ranks are equall can attack anbody with anyone 
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u , int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v)return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }

            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<int> dx = {1 , 0 , -1 , 0};
        vector<int> dy = {0 , 1 , 0 , -1};

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col]){
                    int node = row * n + col;
                    for(int i = 0 ; i < 4 ; i++){
                        int nr = row + dx[i];
                        int nc = col + dy[i];

                        if(nr >=0 && nr < n && nc >=0 && nc <n && grid[nr][nc]){
                            int nextNode = nr * n + nc;
                            ds.unionBySize(node , nextNode);
                        }
                    }
                }
            }
        }
        int maxi = 0;
        for(int i = 0 ; i < n * n ; i++){
            maxi = max(maxi , ds.size[i]);
        }
        

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                int tempSize = 1;
                if(!grid[row][col]){
                    set<int> component;
                    for(int i = 0 ; i < 4 ; i++){
                        int nr = row + dx[i];
                        int nc = col + dy[i];
                        
                        // kyu yeh sahi nhi hai because it may be possible ki agal bagal waal connect hoo then count ek hi parent ko 2 baar hoo jaayega so store all the parent then check the size
                        if(nr >=0 && nr < n && nc >=0 && nc < n && grid[nr][nc]){
                            int nextNode = nr * n + nc;
                            component.insert(ds.findPar(nextNode));
                        }
                    }

                    for(auto com : component){
                        tempSize+=ds.size[com];
                    }

                    maxi = max(maxi , tempSize);
                }
            }
        }
        return maxi;
    }
};

int main()
{

    return 0;
}
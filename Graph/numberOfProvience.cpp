#include <bits/stdc++.h>
using namespace std;

class Solution {

    void dfs(int u , vector<bool>& visited , vector<vector<int>> adj){
        visited[u] = true;

        for(auto v : adj[u]){
            if(!visited[v]){
                dfs(v , visited , adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // i thought to convert the matrix to the list 
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(isConnected[row][col] && row!=col){
                    adj[row].push_back(col);
                }
            }
        }

        // now applying dfs 
        int count = 0;

        vector<bool> visited(n);

        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                count++;
                dfs(i , visited , adj);
            }
        }

        return count;

    }
};
 
int main()
{
     
    return 0;
}
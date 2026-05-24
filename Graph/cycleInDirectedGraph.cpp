#include <bits/stdc++.h>
using namespace std;

// This code return false is cycle present 

class Solution {
    
    bool dfs(int u , vector<bool> &visited , vector<bool>& inProgress ,  vector<vector<int>>& adj){
        visited[u] = true;

        inProgress[u] = true;
        
        
        for(auto v : adj[u]){
            if(!visited[v]){
                if(dfs(v , visited , inProgress  , adj))
                    return true;
            }
            // ! may forget 
            else if(inProgress[v])return true;
            
        }

        inProgress[u] = false;

        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool> visited(V);
        vector<bool> inProgress(V);
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                if(dfs(i , visited ,inProgress ,  adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

 
int main()
{
     
    return 0;
}
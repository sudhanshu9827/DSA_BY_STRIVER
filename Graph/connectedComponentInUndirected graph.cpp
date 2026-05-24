#include <bits/stdc++.h>
using namespace std;




class Solution {

    void dfs(int node , vector<bool>& visited , vector<vector<int>>& adj, vector<int>&c){
        visited[node] = true;
        c.push_back(node);
        for(auto v : adj[node]){
            if(!visited[v]){
                dfs(v , visited , adj , c);
            }
        }
    }

  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }


        vector<bool> visited(V, false);

        vector<vector<int>> com;

        for(int i = 0 ; i < V; i++){
            vector<int> c;
            if(!visited[i]){
                dfs(i , visited , adj ,c);
            }
            com.push_back(c);
        }

    }
};

 
int main()
{
     
    return 0;
}
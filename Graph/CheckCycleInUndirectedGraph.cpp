#include <bits/stdc++.h>
using namespace std;

// this i bi directional i know intead of i created only one entry form u -> v forgot about v -> u i should take care of these things might make my soln incorrect 

// ek cheeck aur joo mene nhi socchi which is very intutive as well is that ki agar me uska parent hu bidirectianl me too boo mera bhi too parent hoga that's the things what should i need to take care 

// yeh cheez bhool skte hoo 

//! DFS 
class Solution {
    
    bool dfs(int u , int parent, vector<bool> &visited , vector<vector<int>>& adj){
        visited[u] = true;
        
        
        for(auto v : adj[u]){
            if(!visited[v]){
                if(dfs(v , u , visited  , adj))
                    return true;
            }
            // ! may forget 
            else if(v != parent){
                return true;
            }
            
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
        }
        
        vector<bool> visited(V);
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                if(dfs(i , i , visited , adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// Lets try with bfs 

// issme yeh samjh nhi aa rhaa ki adjacent parent ko kaise check kar raha houng 
// d

// This logic is completely wrong 
// // class Solution {
// //   public:
// //     bool isCycle(int V, vector<vector<int>>& edges) {
// //         // Code 
// //         // lets try bfs 
        
// //         vector<vector<int>> adj(V);
        
// //         for(auto e : edges){
// //             adj[e[0]].push_back(e[1]);
// //             adj[e[1]].push_back(e[0]);
            
// //         }
        
// //         vector<int> visited(V , 0);
// //         // 0-> not visited 
// //         // 1->visited in a stack 
// //         // 2 ->visited out of the stack 
        
// //         queue<int> q;
        
// //         q.push(0);
        
// //         while(!q.empty()){
// //             int u = q.front();
// //             q.pop();
// //             visited[u] = 2;

// //             for(auto v : adj[u]){
// //                 if(!visited[v]){
// //                     visited[v] = 1;
// //                     q.push(v);
// //                 }
// //                 else if(visited[v] == 1){
// //                     return true;
// //                 }
// //             }
// //         }
// //         return false;
// //     }
// // };

// I should have to store the parent to check whether this node is a parent of this 
class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<pair<int,int>> q;  // {node, parent}
                q.push({i, -1});
                visited[i] = true;

                while (!q.empty()) {
                    auto [u, parent] = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push({v, u});
                        }
                        else if (v != parent) {
                            return true;  // cycle detected
                        }
                    }
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
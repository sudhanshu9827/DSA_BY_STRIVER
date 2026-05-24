#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]); // directed
        }


        // apply bfs
        // where to start indegree zero se start karo 

        vector<int> indegree(V);

        for(int i = 0 ; i < V; i++){
            for(auto v : adj[i]){
                indegree[v]++;
            }
        }

        // know jiski bhi zero hai unn sab se start kar sakte hai 

        vector<int> visited(V);

        queue<int> q;

        for(int u = 0; u <  V; u++){
            if(!indegree[u]){
                q.push(u);
                visited[u] = 1;
            }
        }
        vector<int> ans;

        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();

            for(int v : adj[u]){
                indegree[v]--;
                if(!visited[v] && !indegree[v]){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        
        // for(int i : ans){
        //     cout<<i<<" ";
        // }

        
        return ans.size()== V? ans:vector<int>{};
    }
};
 
int main()
{
     
    return 0;
}
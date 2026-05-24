#include <bits/stdc++.h>
using namespace std;

// this is also correct 

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<int>> adj(V);
        
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        
        q.push(src);
        
        vector<int> ans(V , -1);
        
        int curr_cost = -1;
        
        vector<bool> visited(V);
        
        while(!q.empty()){
            int size = q.size();
            curr_cost++;
            
            for(int i = 0 ; i < size ; i++){
                int curr = q.front();
                visited[curr] = true;
                q.pop();
                
                if(ans[curr] == -1)
                    ans[curr] = curr_cost;
                
                for(int v : adj[curr]){
                    if(!visited[v])
                        q.push(v);
                }
            }
        }
        // for(int i = 0 ; i < V; i++){
        //     cout<<ans[i]<<" ";
        // }
        
        return ans;
    }
};


// correct method : 

class Solution {
public:
    // Function to find the shortest path from source to all vertices
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

        // Create an adjacency list of size N to store the undirected graph
        vector<int> adj[N]; 

        // Build the graph by adding edges to the adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        // Initialize the distance array with a large value (treated as infinity)
        int dist[N];
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9;

        // Set the source node distance to 0
        dist[src] = 0;

        // Use a queue to perform BFS traversal
        queue<int> q;

        // Start BFS from the source node
        q.push(src); 

        // Loop until queue is empty
        while (!q.empty()) {

            // Get the front node from the queue
            int node = q.front(); 
            q.pop(); 

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {

                // If a shorter path to neighbor is found
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }

        // Initialize the result array with -1 for unreachable nodes
        vector<int> ans(N, -1);

        // Fill in the result array with distances where reachable
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }

        // Return the final shortest distances
        return ans; 
    }
};

// Driver code
int main() {

    // Number of vertices and edges
    int N = 9, M = 10;

    // Edge list representing the undirected graph
    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };

    // Create object of Solution class
    Solution obj;

    // Call the shortestPath function with source as node 0
    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    // Print the shortest distances from source to each node
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}






 
int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Got the idea cycle me joo states rahenge boo saare unsafe state honge baaki saare safe rahenge 

// class Solution {
// public:
// with this approach i am not able to determine the path of the cycle 
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         // How do i determine the path of cycle 
//         // indegree wala concept laga sakte hai 

//         int V = graph.size();

//         vector<int> indegree(V);

//         for(auto vec : graph){
//             for(auto v : vec){
//                 indegree[v]++;
//             }
//         }

//         queue<int> q;

//         for(int i = 0 ; i < V;i++){
//             if(!indegree[i])q.push(i);
//             indegree[i]--;
//         }

//         while(!q.empty()){
//             int curr = q.front();
//             q.pop();

//             for(auto v : graph[curr]){
//                 indegree[v]--;
//                 if(indegree[v] == 0){
//                     q.push(v);
//                 }
//             }
//         }

//         vector<int> ans;

//         for(int i = 0 ; i < V; i++){
//             if(indegree[i] <= 0){
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

// indegree wala concept sahi tha but yeh nhi socch paaya ki edges too reverse karni padengi naa 
// outdegree kaa khela hai that's why we are reversing 


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adj(V);

        // Reversing the grah;
        for(int u = 0; u < V ; u++){
            for(auto v : graph[u]){
                adj[v].push_back(u);
            }
        }

        // now apply indegree logic 
        vector<int> indegree(V);

        for(auto vec : adj){
            for(auto v : vec){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i = 0; i <V; i++){
            if(!indegree[i]){
                q.push(i);
                indegree[i]--;
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto v : adj[curr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int> ans;

        for(int i = 0; i < V ; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
 
int main()
{
     
    return 0;
}
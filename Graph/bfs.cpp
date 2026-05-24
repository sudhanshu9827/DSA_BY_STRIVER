#include <bits/stdc++.h>
using namespace std;



// This i did if there is disconnected graph 

// Took help of chatGPT for debugging 

//return karna bhool raha tha and yes har baar push karwa raha tha queue me doo galti hui 
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here

        queue<int> q;
        
        vector<int> bfsTraversal;
        
        vector<bool> visited(int(adj.size()) , false);
        
        for(int i = 0 ; i < adj.size() ; i++){
            
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                bfsTraversal.push_back(i);
            
                while(!q.empty()){
                    int currNode = q.front();
                    q.pop();
                    
                    for(int u : adj[currNode]){
                        if(!visited[u]){
                            visited[u] = true;
            
                            q.push(u);
                            bfsTraversal.push_back(u);
                        }
                    }
                }
            }
        }
        return bfsTraversal;
    }
};

// If i know graph only has one componenet i dont even putt extra loop directly hoo jaayega 

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here

        vector<int> trav;

        queue<int> q;

        q.push(0);

        vector<bool> visited(adj.size());

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            trav.push_back(currNode);

            visited[currNode] = true;

            for(auto u : adj[currNode]){
                if(!visited[u]){
                    q.push(u);

                    visited[u] = true;
                }
            }
        }
        
    }
};




 
int main()
{
     
    return 0;
}
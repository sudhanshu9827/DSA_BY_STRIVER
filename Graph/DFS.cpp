#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N) + O(V+2E) aur kaise aa rahi hai we know that
// space complexity :  O(n) for recursive calls 

class Solution {
    
    void dfs(int u , vector<bool>& visited , vector<vector<int>>& adj , vector<int> &dfsTrav){
        visited[u] = true;
        
        dfsTrav.push_back(u);
        
        for(auto v : adj[u]){
            if(!visited[v])dfs(v , visited , adj , dfsTrav);
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(adj.size());
        
        vector<int> dfsTrav;
        
        for(int i = 0; i < adj.size() ; i++){
            if(!visited[i]){
                dfs(0 , visited , adj , dfsTrav);
            }
        }
        return dfsTrav;
    }
};
 
int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// Topo sort ka matlb indegree joo zero wala hai usse karo phir usko hone par dusre esse karta tha that means dfs start kar do naa

// agar mene jiski indegree zero hai usse start nhi bhi karri tabhi boo automatic uper aa hii jaayega kyuki pura dfs khatam usske baat too sab stack ke uper hii aayega 
// too start kaha se karenge dfs kya jiski indegree zero hogi waha se ?

//agar kahi se bhi karra then stack me too wahi pehele aayega naa Let's see: yes intution is right but this will take care by dfs and stack 

class Solution {

    void dfs(int u , vector<vector<int>>& adj , vector<bool>& visited , stack<int>& st){
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                dfs(v , adj , visited , st);
            }
        }

        st.push(u);
    }

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }

        // adj list taiyaar hai 

        vector<bool> visited(V);

        // stack kyu bana raha hu boo logic intution clear hai ? yes kyuki u - > v then u pehle karna padega 
        stack<int> st;

        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                dfs(i , adj , visited , st);
            }
        }
        

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


int main()
{
     
    return 0;
}
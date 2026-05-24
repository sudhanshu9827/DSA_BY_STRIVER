#include <bits/stdc++.h>
using namespace std;


class Solution {

    bool dfs(int node , vector<vector<int>>& adj , vector<int>& visited){
        visited[node] = 1;

        for(int v : adj[node]){
            if(!visited[v]){
                // agar ek false mill gaya too pura false 
                // true milla hai then aage check karna hai 
                if(!dfs(v , adj , visited))
                    return false;
            }

            else if(visited[v] == 1){
                return false;
            }
        }

        visited[node] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make a graph if graph have cycle then we can say it quite not possible 

        vector<vector<int>> adj(numCourses);

        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses , 0);

        for(int i =0 ; i < numCourses ;i++){
            if(!visited[i]){
                if(!dfs(i , adj , visited))
                    return false;
            }
        }
        return true;
    }
};
 
int main()
{
     
    return 0;
}
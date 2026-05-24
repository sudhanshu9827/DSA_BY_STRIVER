#include <bits/stdc++.h>
using namespace std;


// I know if the color of the graph is more than 2 then the graph is no more bipartite 

// But i have difficulty in my brain how do i implement it 

// make an array of colors in which initially sabko ek hii color kardo phir change karte jaao if same color any of two then return false


class Solution {
    bool dfs(vector<vector<int>> & graph , vector<int>& color , int u , int currentColor){
        color[u] = currentColor;

        for(int v : graph[u]){
            if(color[v] == -1){
                if(!dfs(graph , color , v , 1 - currentColor)){
                    return false;
                }
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , -1);

        // -1 ka matlab hii visited hoo gaya 

        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(!dfs(graph , color , i , 0))
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
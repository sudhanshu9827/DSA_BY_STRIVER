#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> degree(v);
        for(auto pair : edges){
            degree[pair[0]]++;
            degree[pair[1]]++;
        }
        bool is_same = true;
        int max_degree = degree[0];
        for(int i = 1 ; i < v ; i++){
            if(max_degree < degree[i])max_degree = degree[i];
            
            if(max_degree != degree[i]) is_same = false;
        }
        
        if(is_same){
            if(max_degree + 1 <=m)return true;
            return false;
        }
        else {
            if(max_degree <= m) return true;
            return false;
        }
        return false;
    }
};

int main()
{
     
    return 0;
}
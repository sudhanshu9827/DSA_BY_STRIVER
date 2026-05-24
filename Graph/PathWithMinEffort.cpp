#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int numRow = heights.size();
        int numCol = heights[0].size();

        // start form 0 , 0 

        vector<int> dx = {1 , 0 , -1 , 0};
        vector<int> dy = {0 , 1 , 0 , -1};

        vector<vector<int>> effort(numRow , vector<int>(numCol , 1e9));

        // using priority_queue 
        // <effort , row , col >

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<tuple<int , int , int>>> pq;

        pq.push({0 , 0 , 0});

        while(!pq.empty()){
            auto [eff , currRow , currCol] = pq.top();
            pq.pop();

            for(int i = 0 ; i < 4; i++){
                int nr = currRow + dx[i];
                int nc = currCol + dy[i];

                if(nr >= 0 && nr< numRow && nc >= 0 && nc < numCol && 
                 abs(eff - heights[nr][nc]) < effort[currRow][currCol]){
                    effort[nr][nc] = abs(eff - heights[nr][nc]);
                    pq.push({effort[nr][nc] , nr , nc});
                 }
            }
        }
        return effort[numRow - 1][numCol - 1];
    }
};
 
int main()
{
     
    return 0;
}
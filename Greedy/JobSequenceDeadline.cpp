#include <bits/stdc++.h>
using namespace std;

// what i thought when read the question 

// Just sort with respect to deadline in decending order and check which has the maximum profit upto this deadline and take that 

//What acctually we need to do 

// sort based on maximum profit and take that time and then check if that deadline is filled then go down untill deadline not found if not found dont take 

// i do little mistakes now 

// This right now giving an runtime error which can be solved by disjoint union set . we will do it later in graph 
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = profit.size();
        // find max deadline 
        int maxDead = INT_MIN ;
        for(int dead : deadline){
            maxDead = max(dead , maxDead);
        }
        vector<bool> taken(maxDead + 1, 0);

        vector<pair<int , int>> profDead;

        for(int i = 0 ; i < n ; i++){
            profDead.push_back({profit[i] , deadline[i]});
        }

        sort(profDead.rbegin() , profDead.rend());
        int maxProfit = 0;
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            int d = profDead[i].second;
            if(!taken[d]){
                //the slot has been occupied
                taken[d] = 1;
                maxProfit+=profDead[i].first;
                count++;
            }
            else{
                while(d > 0 && taken[d]){
                    d--;
                }
                if(d!=0){
                    maxProfit+=profDead[i].first;
                    taken[d] = 1;
                    count++;
                }
            }
        }

        return {count , maxProfit};
    }
};
 
int main()
{
     
    return 0;
}
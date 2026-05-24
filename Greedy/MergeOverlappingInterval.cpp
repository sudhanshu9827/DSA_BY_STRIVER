#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // what we need to do 
        // we need to merge the intervals which are overlapping
        // means definitely ek ke khatam hone se pehele dusra aa raha hoga 
        // if i sort basis of start value soo boo overlapping concecutive rehene waali hai 
        //kyuki agar ek hai boo dusre ke saath tabhi overlap hoga jab boo pehle ke dusre se choota ho aur pehle ke pehle se bada hoo 

        // if sort based on second value then no pattern i am finding 
        //aur koi cheez confirm sii nhi hai issme 

        //based on start
        sort(intervals.begin() , intervals.end());

        vector<vector<int>> res;
        vector<int>interval = intervals[0];

        for(int i = 0 ; i <intervals.size();i++){
            if(interval[1] >= intervals[i][0]){
                interval[1] = max(intervals[i][1] , interval[1]);
            }
            else{
                res.push_back(interval);
                interval = intervals[i];
            }
        }
        //push last interval 
        res.push_back(interval);
        return res;
    }
}; 
 
int main()
{
     
    return 0;
}
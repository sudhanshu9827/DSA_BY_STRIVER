#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());
        int count = 0;
        int i = 1;
        vector<int> interval = intervals[0];
        while(i < n){
            if( interval[1] > intervals[i][0]){
                count++;
                if(interval[1] > intervals[i][1]){
                    interval = intervals[i];
                }
            }
            else{
                interval = intervals[i];
            }
            i++;
        }
        return count;
    }
};
 
int main()
{
     
    return 0;
}
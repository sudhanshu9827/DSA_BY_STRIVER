#include <bits/stdc++.h>
using namespace std;


// i did this question past with a very poor strategy and unconsiously not structure 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // check kisi interval ke ander aa raha hai ki nhi 
        vector<vector<int>> newInt;
        int n = intervals.size();
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];
        while(i < n){
            if(intervals[i][0] >= start && intervals[i][1] <= start){
                newInt.push_back({intervals[i][0] , intervals[i][1]});
                i++;
            }
            
            else if(i < n-1 && intervals[i][1] < start && intervals[i+1][0] < end){
                //sepearte hai
                newInt.push_back({start , end});
                i++;
            }

            else if(i < n - 1 && intervals[i][1] <=start && intervals[i + 1][0] > end){
                newInt.push_back({intervals[i][0] , end});
                i++;
            }

            else{
                // 2 ya 2 se jaada ke me beech me rahega
                int st = intervals[i][0];
                while( i < n && intervals[i][1] >= end){
                    i++;
                }
                newInt.push_back({st , intervals[i][1]});
                i++;
            }      
        }
        return newInt;
    }
};

// This is looking such a difficult at first time but really it is easy try 

// divide into three portion first one no overlapping then overlapping waala part le lunga then no overlapping wala part 

//issme buss socch kar kaam karna hai  
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> res;

        int i = 0;
        //aage wala portion 
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
        }

        // i am at the newInterval intersection may be it is intersection or just getting added to the list of intervals 

        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
        }

        res.push_back(newInterval);

        while(i < n){
            res.push_back(intervals[i]);
        }
        return res;
    }
};
 
int main()
{
     
    return 0;
}
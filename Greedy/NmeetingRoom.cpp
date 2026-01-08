#include <bits/stdc++.h>
using namespace std;


// What i was thinking that we are greedy to take that meeting which end faster 

// Immediately ask yourself:

// 👉 What blocks me from attending more meetings?
// Answer: Time overlap.

// So the goal becomes:

// Finish meetings as early as possible so I can attend more later.

// class Soluiton{

//     // bool cmp(auto a , auto b){
//     //     return a.first > b.first;
//     // }


//     vector<int> MaxMeeting(vector<int>& start , vector<int>& end){
//         // end ke base par start ko sort kaise kar sakta hu 
//         // I thought ki map se hoo jaayega 
//         //But their can be multiple end on which start could be mapped

//         //and i also need to store where it was actually 
//         // unordered_map<pair<int , int> , int> ump;

//         // for(int i = 0 ; i < start.size(); i++){
//         //     ump[end[i]] = start[i];
//         // }
//         vector<pair<int , int>> endValues;
//         vector<int> ans;
//         vector<int>newStart(start);

//         for(int i = 0 ; i < end.size() ; i++){
//             endValues.push_back({end[i] , i});
//         }

//         sort(endValues.begin() , endValues.end());

//         int index , val;

//         for(int i = 0 ; i < start.size(); i++){
//             index = endValues[i].second;
//             start[i] = newStart[index];
//         }

//         int currentStart;
//         int previousEnd = endValues[0].first;
//         ans.push_back(endValues[0].second);

//         for(int i = 1 ; i < start.size(); i++){
//             currentStart = start[i];
//             if(currentStart > previousEnd){
//                 previousEnd = endValues[i].first;
//                 ans.push_back(endValues[i].second);
//             }
//         }
//         return ans;
//     }
// };

// another same verison 


class Solution {
public:
    vector<int> MaxMeeting(vector<int>& start, vector<int>& end) {

        int n = start.size();
        vector<pair<int,int>> endValues;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            endValues.push_back({end[i], i});
        }

        sort(endValues.begin(), endValues.end());

        // select first meeting
        int previousEnd = endValues[0].first;
        ans.push_back(endValues[0].second);

        for(int i = 1; i < n; i++){
            int idx = endValues[i].second;
            if(start[idx] > previousEnd){
                previousEnd = endValues[i].first;
                ans.push_back(idx);
            }
        }

        return ans;
    }
};
 
int main()
{
     
    return 0;
}
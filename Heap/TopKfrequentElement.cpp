#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int , int> freq;
        for(int num : nums){
            freq[num]++;
        }

        // freq,value
        priority_queue<pair<int , int>> maxHeap;

        for(auto fr : freq){
            maxHeap.push({fr.second , fr.first});
        }

        for(int i = 0 ; i < k ; i++){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
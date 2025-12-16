#include <bits/stdc++.h>
using namespace std;


// Just i want to remove the element from front when window is exausted and maintain the highest element such that it will retrieve in O(1)
// using dequeue i can acchieve so prefare data structure will be dequeue


// It will took overall O(n); 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; // its size is n - k
        deque<int> dq;

        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
    }
};




// In the worst case my code TimeComplexity is O(n2); can be do a better 

class Solution {
    pair<int , int> FindMaxiInWindowK(vector<int>& nums , int k , int start){
        int maxi;
        int maxIndex;
        for(int i = start ; i < k ; i++){
            if(maxi <= max(maxi , nums[i])){
                maxi = max(maxi , nums[i]);
                maxIndex = i;
            }
        }
        return {maxi , maxIndex};
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        pair<int , int> maxProp = FindMaxiInWindowK(nums , k  , 0);

        int maxi = maxProp.first;
        int maxIndex = maxProp.second;

        ans.push_back(maxi);
        int i = 1;
        int j = k + 1;
        while(j < n){
            if(nums[j] >= maxi){
                maxIndex = j;
                maxi = nums[j];
            }

            else{
                if(i > maxIndex){
                    maxProp = FindMaxiInWindowK(nums , k , i);
                    maxIndex = maxProp.second;
                    maxi = maxProp.first;
                }
            }
            i++;
            j++;
            ans.push_back(maxi);
        }
    }
};
 
int main()
{
     
    return 0;
}
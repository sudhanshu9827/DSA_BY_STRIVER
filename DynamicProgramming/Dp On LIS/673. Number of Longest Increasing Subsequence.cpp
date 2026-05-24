#include <bits/stdc++.h>
using namespace std;

// Thought process is just roming around dp  dp se nikal sakta hu ki kitne subsequence bann rahe honge 

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // as normal dp soln of lis 

        vector<int> dp(n , 1) , count(n , 1);

        int maxi = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];

                    count[i] = count[j]; // jab logest mill jaaye reset karoo i was not able to get that idea but it teaches me how should i think consisely 
                }
                else if(nums[j] < nums[i] && 1 + dp[j] == dp[i]){
                    count[i]+=count[j];
                }
            }
            maxi = max(maxi , dp[i]);
        }
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(dp[i] == maxi){
                ans+=count[i];
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
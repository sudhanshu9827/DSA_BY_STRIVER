#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // i am gready to be jump as high as possible 
        //so me uspar jump karunga joo sabse higher hoga

        int n = nums.size();
        if(n==1)return 0;
        int i = 0;
        int maxJump;
        int maxJumpIndex = 0;
        int count = 0;
        while(i < n){
            maxJump = nums[i];
            cout<<maxJump<<endl;
            if(!maxJump)return false;
            // maxJumpIndex = i;
            count++;

            if(i + maxJump >= n - 1)return count;
            int j;
            for(j = i + 1 ; j <= i + nums[i] ; j++){
                if(j + nums[j] >= maxJumpIndex + maxJump){
                    maxJump = nums[j];
                    maxJumpIndex = j;
                }
            }

            if(maxJumpIndex!=i)i = maxJumpIndex;
            else i = nums[i];
        }
        return true;
    }
};

// brute force i can try all the possible ways 

class Solution{
    int jumpRecursive(vector<int>& nums , int jumps){
        if(jumps >= nums.size())return jumps;
        int mini = INT_MAX;
        for(int i = 1; i <= nums[i]; i++){
            mini = min(mini , jumpRecursive(nums , jumps + 1));
        }
        return mini;
    }
    public:
        int jump(vector<int> & nums){
            int jumps = 0;
            return jumpRecursive(nums , jumps);
        }
};

// we can optimize it further using dp 

class Solution{
    int jumpRecursive(vector<int>& nums , int index , int jumps  , vector<vector<int>>& dp){
        if(jumps >= nums.size())return jumps;
        if(dp[index][jumps]!=-1)return dp[index][jumps];
        int mini = INT_MAX;
        for(int i = 1; i <= nums[index]; i++){
            mini = min(mini , jumpRecursive(nums , index++, jumps + 1 , dp));
        }
        dp[index][jumps] = mini;
        return mini;
    }
    public:
        int jump(vector<int> & nums){
            int n = nums.size();
            vector<vector<int>> dp(n , vector(n , -1));
            return jumpRecursive(nums ,0, 0, dp);
        }
};

// What i can do best 
// simple soln hai dimaag slow chal raha hai abhi 
//pata nhi why 
class Solution{
    int jump(vector<int>& nums){
        // recursive range can i think something which can convert solution to iterative one 
        // soo as similar to validParenthesis we can carry the range 
        int jumps = 0 , currentEnd = 0 , farthest = 0;
        int n = nums.size();

        for(int i = 0 ; i  < n ; i++){
            farthest = max(farthest , i + nums[i]);

            if(currentEnd == i){
                jumps++;

                currentEnd = farthest;
            }
        }
        
    }
};
 
int main()
{
     
    return 0;
}
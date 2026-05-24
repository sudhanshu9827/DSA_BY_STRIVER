#include <bits/stdc++.h>
using namespace std;


// Memoization 

// Improvement : storing the value can also store index instead 

class Solution {
    int solve(vector<int>& nums , int n , int i , int prev , vector<vector<int>>& dp , int offset){
        if(i == n)return 0;

        if(dp[i][prev + offset]!=-1)return dp[i][prev + offset];
        int take = 0 , notTake = 0;
        if(prev < nums[i]){
            take = (1 + solve(nums , n , i + 1 , nums[i] , dp , offset));
        }

        notTake = solve(nums , n , i+1 , prev , dp , offset);

        return dp[i][prev + offset] =  max(take , notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // int maxi = *max_element(nums.begin() , nums.end());

        // offset lagakar kaam karna padega 

        int offset = 1e4+1;

        vector<vector<int>> dp(n , vector<int>(2*offset + 1 , -1));

        return solve(nums , n , 0 , -1e4-1, dp , offset);
    }
};


class Solution {
    int solve(vector<int>& nums , int n , int i , int prevIndex , vector<vector<int>>& dp ){
        if(i == n+1)return 0;
        
        if(dp[i][prevIndex]!=-1)return dp[i][prevIndex];

        int take = 0 , notTake = 0;
        if(prevIndex == 0 || nums[prevIndex - 1] < nums[i - 1]){
            take = (1 + solve(nums , n , i + 1 , i , dp));
        }

        notTake = solve(nums , n , i+1 , prevIndex , dp );

        return dp[i][prevIndex] =  max(take , notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // int maxi = *max_element(nums.begin() , nums.end());

        // offset lagakar kaam karna padega 

        vector<vector<int>> dp(n+1 , vector<int>(n + 1 , -1));

        return solve(nums , n , 1 , 0,  dp);
    }
};

// Due to extra auxillary space convert it into tabulation solution 
// tabulation later 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        int offset = 1e4+1;

        vector<vector<int>> dp(n+1 , vector<int>(n + 1));

        // its not much intutive to me i found difficulties in convertion to tabulation

        // -1 ko include kar rahe then prev index + 1 karke chalna padgega 


        for(int i = n ; i >=1; i--){
            for(int prevIndex = i - 1; prevIndex >=0 ; prevIndex++){
                int take = 0 , notTake = 0;
                if(prevIndex == 0 || nums[prevIndex - 1] < nums[i - 1]){
                    take = (1 + dp[i +1][i]);
        }

                notTake = dp[i+1][prevIndex];
            }
        }

        return dp[0][0];
    }
};


// By striver : 
// I confused a lot and again doing the same problem with correct and accurate approach i did it should know best approach 

// there are mutiple possibilites could take a element or not take an element right 

class Solution {
    int solve(vector<int>& nums , int i , int n , int prevIndex){
        if(i == n){
            return 0;
        }

        int notTake = solve(nums , i + 1 , n , prevIndex);
        int take = 0;
        
        if(prevIndex == -1 || nums[prevIndex] < nums[i]){
            take = 1 + solve(nums , i+1 , n , i);
        }

        return max(take , notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return solve(nums , 0 , n , -1);
    }
};

// Now introducing dp 
// but dp can't store negative values 

// prevIndex koi nhi hai too wahi return hona chahiye right 
// so prevIndex ko ek aage khiska lete hai 
// -1 treated as 0 

// What did i mistake?
// return dp[i][prevIndex]=> should be dp[i][prevIndex + 1]



class Solution {
    int solve(vector<int>& nums , int i , int n , int prevIndex , vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prevIndex + 1]!=-1)return dp[i][prevIndex + 1];

        int notTake = solve(nums , i + 1 , n , prevIndex , dp);
        int take = 0;
        
        if(prevIndex == -1 || nums[prevIndex] < nums[i]){
            take = 1 + solve(nums , i+1 , n , i , dp);
        }

        return dp[i][prevIndex + 1] =  max(take , notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));

        return solve(nums , 0 , n , -1 ,dp);
    }
};

// Now converting it to memoization to tabulation 

// dp table me sab ek aage shift kiya hai prevIndex ke liye 
// too jaha bhi prev -> hai waha actually prev + 1 hai 
// i hai usski jagha i + 1 hai kyuki prev usse liye i hii hai  ek aage khiakaaya hai naa -1 ->0 1 ->2 , i -> i + 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1));


        // base case automatically manage 

        // now think about index 

        // in recursion 0 -> n  here n -> 0
        //in recursion prev {i -> 0} particular index ka prev hoga boo soccho so 

        for(int i = n - 1 ; i >=0 ; i--){
            for(int prevIndex = i - 1; prevIndex>=-1 ; prevIndex--){
                int notTake = dp[i + 1][prevIndex + 1];
                int take = 0;

                if(prevIndex == -1 || nums[prevIndex] < nums[i]){
                    take = 1 + dp[i + 1][i+1]; // prev waale me i + 1 intutive nhi hoo raha baaki too ok hai take a pause thing calmly 
                }

                dp[i][prevIndex + 1] = max(take , notTake);
            }
        }

        return dp[0][0];
    }
};


// Better soln 
// More intutive to me 

// time com; O(n2);
// sc : O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n , 1);

        for(int i = 1 ; i < n ; i++){
            for(int prev = 0 ; prev <= i - 1 ; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i] , 1 + dp[prev]);
                }
            }
        }

        int ans = *max_element(dp.begin() , dp.end());

        return ans;
    }
};

// Now best approach using binary search to reduce the time 

// TC:O(nlogn)
// SC: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;

        temp.push_back(nums[0]);

        int len = 1;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }

            else{
                // just overright
                int idx = lower_bound(temp.begin() , temp.end() , nums[i]) - temp.begin();

                temp[idx] = nums[i];
            }
        }

        return len;
    }
};



int main() {
    
    return 0;
}
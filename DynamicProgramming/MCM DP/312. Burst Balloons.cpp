#include <bits/stdc++.h>
using namespace std;

// very interesting and deep question mazza hii aa gaya karke 
// 10 baar karo samjhna bahut jaruri hai its needy 

// Greedy will not work here its clear 

// i identify it will be solved by dp 

// okk but the partition part is something which is tricky 

// I am not able to found that how do i partition such that 2 independent problems will generate and solve them recursively 

// Lets say we attack the boundaries at last 1 and 1

// then agar ek ko liye then then uske agal wagal waale too khudpar too depend karenge hii 

// we cannot directly partition the array here if we partitioned it still have dependency 

class Solution {
    int f(int i , int j , vector<int>& nums , vector<vector<int>>& dp){
        if(i > j) return 0; // single problem should also be solved means i ==j bhi solve karna hai 

        int maxi = INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];

        for(int k = i; k <= j ; k++){
            int cost = nums[i - 1] * nums[k] * nums[j + 1] + f(i , k - 1 , nums , dp) + f(k + 1 , j , nums , dp);

            maxi = max(cost , maxi);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);

        vector<vector<int>> dp(n +1 , vector<int>(n +1 , -1));

        return f(1 , n , nums , dp);
    }
};

// Now converting this soln to Tabulation 

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin() , 1);

        vector<vector<int>> dp(n +2 , vector<int>(n +2));
        

        for(int i = n ; i >= 1 ; i--){
            for(int j = 1; j <= n ; j++){ // j i se bhi chala sakte the if want 
                if(i>j)continue;
                // kyuki max me nhi dalana kuch bhi 
                int maxi = INT_MIN;
                for(int k = i; k <= j ; k++){
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k+1][j];
                    maxi = max(cost , maxi);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

int main() {
    
    return 0;
}
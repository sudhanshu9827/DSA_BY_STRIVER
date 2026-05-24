#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &prices , int i , int n , int buy , int fee , vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }

        int profit = 0;

        if(buy){
                profit = max(-prices[i]-fee + solve(prices , i + 1, n , 0 , fee , dp) ,
                        solve(prices ,i + 1 , n , 1 , fee , dp));
        }

        else{
            profit = max(prices[i] + solve(prices , i + 1 , n , 1 , fee, dp), solve(prices , i + 1 , n , 0 , fee, dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n ,vector<int>(2 , -1));

        return solve(prices , 0, n , 1 , fee , dp);
    }
};

int main() {
    
    return 0;
}
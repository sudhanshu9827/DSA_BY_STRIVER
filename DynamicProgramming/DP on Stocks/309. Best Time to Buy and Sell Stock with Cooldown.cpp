#include <bits/stdc++.h>
using namespace std;

// As normal i know how do i introduce colldown 

class Solution {

    int solve(vector<int> &prices , int i , int n , int buy , int cooldown , vector<vector<vector<int>>> &dp){
        if(i == n){
            return 0;
        }

        if(dp[i][buy][cooldown]!=-1){
            return dp[i][buy][cooldown];
        }

        int profit = 0;

        if(buy){
            if(!cooldown)
                profit = max(-prices[i] + solve(prices , i + 1, n , 0 , 0 , dp) ,
                        solve(prices ,i + 1 , n , 1 ,0 , dp));
            else{
                profit = solve(prices , i + 1, n, 1 , 0 , dp);
            }
        }

        else{
            profit = max(prices[i] + solve(prices , i + 1 , n , 1 , 1 , dp), solve(prices , i + 1 , n , 0 , 0 , dp));
        }
        return dp[i][buy][cooldown] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(2 , -1)));

        return solve(prices , 0, n , 1 , 0 , dp);
    }
};

int main() {
    
    return 0;
}
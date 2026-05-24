#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& prices , int i , int n , int k , int buy , vector<vector<vector<int>>> &dp){
        //base codition
        if(k == 0 || i == n){
            return 0;
        }

        if(dp[i][k][buy]!=-1)return dp[i][k][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[i] +  solve(prices , i + 1 , n , k , 0 , dp) , solve(prices , i + 1 ,n , k , 1 , dp));
        }

        else {
            profit = max(prices[i] + solve(prices , i + 1 ,n , k - 1, 1, dp) , solve(prices , i + 1 ,n , k , 0 ,dp));
        }

        return dp[i][k][buy] =  profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // i need to introduce dp here  joo joo variable hai sab par dp lagegi

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(k+1 , vector<int>(2 , -1)));

        return solve(prices , 0 , n , k , 1, dp);
    }
};

int main() {
    
    return 0;
}
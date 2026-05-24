#include <bits/stdc++.h>
using namespace std;

// har ek baar yeh sochna hai khareed lu beech du ? 

// 07.04.2026

// 2 process ki tarha soch sakte hai ek hii time par ander naa jaaye soo lock lagana padega 
// har ek step me khaareed sakte hai yaa bech sakte hai agar khareeda hoo too 
// Every possibility explore recusion 

// // issme selling price bhi too varibale hai kisi i , k , buy ke specific ke liye ek hii selling price todina rahegi 

// class Solution {
//     int solve(vector<int>& prices , int i , int k , int buy , int sellingPrice , vector<vector<vector<int>>> &dp){
//         //base codition
//         if(k == 0 || i < 0){
//             return dp[i][k][buy] =  0;
//         }

//         if(dp[i][k][buy]!=-1)return dp[i][k][buy];

//         int profit = 0;

//         if(buy){
//             profit = 0 + max(solve(prices , i - 1  , k , 0 , prices[i] , dp) , solve(prices , i - 1 , k , 1 , 0, dp));
//         }

//         else if(sellingPrice > prices[i]){
//             profit = max((sellingPrice - prices[i]) + solve(prices , i - 1 , k - 1, 1 ,0 , dp) , solve(prices , i - 1 , k , 0 , sellingPrice, dp));
//         }

//         else{
//             profit = solve(prices , i - 1 , k , 0 , sellingPrice , dp);
//         }

//         return dp[i][k][buy] =  profit;
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // i need to introduce dp here  joo joo variable hai sab par dp lagegi

//         vector<vector<vector<int>>> dp(n , vector<vector<int>>(3 , vector<int>(2 , -1)));

//         return solve(prices , n - 1 , 2 , 1 , 0 , dp);
//     }
// };


class Solution {
    int solve(vector<int>& prices , int i , int n , int k , int buy , vector<vector<vector<int>>> &dp){
        //base codition
        if(k == 0 || i == n){
            return dp[i][k][buy] =  0;
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // i need to introduce dp here  joo joo variable hai sab par dp lagegi

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(3 , vector<int>(2 , -1)));

        return solve(prices , n - 1 , n , 2 , 1, dp);
    }
};

// Now got it 

// convert it into tabulation 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(3)));

        // i == n kaa answer hai aur memo me 0 ---> n ki taraf jaa raha hai then tabu me ulta jaayega

        for(int i = n - 1; i >=0 ; i--){
            for(int buy = 0 ; buy <=1 ; buy++){
                for(int k = 1 ; k <=2 ; k++){
                    if(buy){
                        dp[i][buy][k] = max(-prices[i] + dp[i + 1][0][k] ,dp[i + 1][1][k]);
                    }

                    else {
                        dp[i][buy][k] = max(prices[i] + dp[i + 1][1][k -1] , dp[i + 1][0][k]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

// here we use  sc : N * 2 * 3 

// in some solution SC : O(N * 4)  How represent every transaction as buy sell like 2 transaction 0 , 1  , 2 ,3 even meas buy and odd means sell rest will be same 


// Do it next round : pakka 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//     }
// };

int main() {
    
    return 0;
}
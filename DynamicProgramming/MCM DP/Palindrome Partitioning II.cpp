#include <bits/stdc++.h>
using namespace std;


// memoization soln 

class Solution {
    bool checkPallindrome(string s , int start , int end){
        while(start < end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }

    int solve(string s , int i , int j , vector<vector<int>>& dp){
        if(i >= j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(checkPallindrome(s ,i , j ))return 0;

        int mini = INT_MAX;

        for(int k = i; k < j ; k ++){
           int cuts = 1 + solve(s , i , k , dp) + solve(s , k + 1, j , dp);

           mini = min(mini , cuts);
        }

        return mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));

        return solve(s , 0 , n - 1 , dp);
    }
};

// Tabulation method 


class Solution {
    bool checkPallindrome(string s , int start , int end){
        while(start < end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
public:
    int minCut(string s) {
         int n = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1));

        vector<vector<bool>>check(n , vector<bool>(n , false));



        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(checkPallindrome(s, i, j)){
                    check[i][j] = true;
                }
            }
        }

        for(int i = n - 1 ; i >=0; i--){
            for(int j = i+1 ; j < n ; j++){
                if(check[i][j]){
                    dp[i][j] = 0;
                    continue;
                }
                int mini = INT_MAX;
                for(int k = i; k < j ; k++){
                    int cuts = 1 + dp[i][k] + dp[k+1][j];
                    mini = min(mini , cuts);
                }
                dp[i][j] = mini;
            }
        }

        return dp[0][n - 1];
    }
};

// What if you could know instantly whether any substring is a palindrome without re-checking every single character?

// Above solution is not the best solution should be optimize further 

// question ko toda galat socch liya tabhi sahi hoo gaya 

class Solution {

    bool isPallindrome(int start , int end , string& s){
        while(start < end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }

    int solve(int i , int n , string& s , vector<int>& dp){
        if(i == n) return 0;

        int mini = INT_MAX;

        for(int j = i ; j <n; j++){
            if(isPallindrome(i , j , s)){
                int cut = 1 + solve(j+1 , n , s , dp);
                mini = min(mini , cut);
            }
        }

        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n , -1);

        return solve(0 , n, s , dp) - 1;
    }
};


// converting it to tabulation 


class Solution {
    bool isPallindrome(int start , int end , string& s){
        while(start < end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n);



        for(int i = n - 1 ; i >=0 ; i--){
            int mini = INT_MAX;
            for(int j = i ; j <n; j++){
                if(isPallindrome(i , j , s)){
                    int cost = 1 + dp[j + 1];
                    mini = min(mini , cost); 
                }
            }
            dp[i] = mini;
        }

        return dp[0] - 1;
    }
};

int main() {
    
    return 0;
}
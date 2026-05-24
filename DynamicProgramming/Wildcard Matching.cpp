#include <bits/stdc++.h>
using namespace std;


// Given memory limit exceed 
class Solution {
    int solve(const string s , string p , int i , int j , vector<vector<int>>& dp){
        if(i < 0 && j < 0)return 1;

        if(i < 0){
            // all the characters from now are the stars
            while(j >= 0){
                if(p[j--]!='*')return 0;
            } 
            return 1;
        }

        if(j < 0)return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(s , p  ,i - 1 , j - 1 , dp);
        }

        else if (s[i]!=p[j] && p[j]!= '*'){
            return dp[i][j] = 0;
        }

        else{
            return dp[i][j] = solve(s , p , i - 1 , j , dp) | solve(s , p , i - 1 , j - 1 , dp) | solve(s , p , i , j - 1, dp); // consider empty as well
        }
        // cout<<"hi";
        return 0;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(),  m = p.size();

        vector<vector<int>> dp(n, vector<int>(m , -1));

        return solve(s , p , n - 1 ,m - 1 ,dp) == 1;

    }
};


// Converting the code to tabulation fasion 

// bahut jagha m -> n kar diya  p likhna tha m kar diya that's the reason it took time otherwise question is bit intutive 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),  m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        
        // method shifting will  apply while dealing with less than 0 we tried to thing convert -1 to 0 right 

        // writing base cases 
        dp[0][0] = true;

        for(int j = 1; j <= m ; j++){
            if(p[j - 1] == '*')dp[0][j] = true;
            else break;
        }

        // so recursion is top - down so you came from n -> 1 now bottom up from 1 -> n  

        for(int i = 1; i <=n ; i++){
            for(int j = 1 ; j <= m; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if(s[i - 1]!=p[j - 1] && p[j - 1]!= '*'){
                    dp[i][j] = false;
                    // cout<<s[i]<<" "<<p[j];
                    // return false;
                }

                else{
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - 1] | dp[i][j - 1] ; // consider empty as well
                }
            }
        }

        // for(int i = 0; i <= n ; i++){
        //     for(int j = 0 ; j <= m ; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }
};

int main() {
    
    return 0;
}
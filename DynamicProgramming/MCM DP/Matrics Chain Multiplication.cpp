#include <bits/stdc++.h>
using namespace std;
// Recursion should be used that i know 

// How do i approach the question that aspect is missing 
// copy pen me tabhi samjh aa raha hai par code me bilkul nhi 

// Lets 1st relate the question an when the partition dp come into me head 
// when someone says about multiple options to do something like multiplication 2 + 3 * 5 => (2 + 3)*5 or 2 +(3 * 5) give different answer then we can able relate the pattern to something as partition dp 

// We should remember some of the steps at the time the formation quite not happening much faster 

class Solution {
    int solve(vector<int>& arr, int i , int j){
        if(i == j) return 0; // no matrix multiplicatio is there

        // try all the possible ways 
        int mini = 1e9;

        // we can go from i -> k - 1 or  i + 1 to j right try using pen and paper  

        for(int k = i; k <j ; k++){
            int steps = arr[i - 1] * arr[k] * arr[j] + solve(arr , i , k) + solve(arr , k + 1 , j);

            mini = min(steps , mini);
        }

        return mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here

        int n = arr.size();

        return solve(arr,  1 , n - 1);
        
    }
};

// Above solution TC : is exponential in nature 

// we can further apply memoization yes there are overlapping subproblems 

class Solution {
    int solve(vector<int>& arr, int i , int j , vector<vector<int>>& dp){
        if(i == j) return 0; // no matrix multiplicatio is there

        // try all the possible ways 
        int mini = 1e9;

        // we can go from i -> k - 1 or  i + 1 to j right try using pen and paper  

        if(dp[i][j]!=-1)return dp[i][j];

        for(int k = i; k <j ; k++){
            int steps = arr[i - 1] * arr[k] * arr[j] + solve(arr , i , k , dp) + solve(arr , k + 1 , j , dp);
 
            mini = min(steps , mini);
        }

        return dp[i][j] =  mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here

        int n = arr.size();

        vector<vector<int>> dp(n , vector<int>(n , -1));

        return solve(arr,  1 , n - 1 , dp);
        
    }
};

// TC : O(n^3)
//SC : O(n^2) + O(n){auxilary stack space }

// Now convert the solution into tabulation 


class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here

        int n = arr.size();

        vector<vector<int>> dp(n , vector<int>(n));

        // firslty base case joo ki already satisfied hai 

        // i=> n - 1 to 0 opposite to recusion 

        // what about j ? it should be n - 1 to 1 right but logically i is always left of j so i se start hoga na nhi i + 1 se 



        for(int i = n - 1 ; i >=1 ; i--){
            for(int j = i + 1 ; j <n ; j++){
                int mini = 1e9;
                for(int k = i; k <j ; k++){
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

                    mini = min(steps , mini);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
        
    }   
};


int main() {
    
    return 0;
}
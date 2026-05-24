#include <bits/stdc++.h>
using namespace std;


// soo partition kar rahe hai partitioning dp pattern visibile clearly 

// (0 ---- k - 1) partitions are there 

class Solution {

    int findMax(int start , int end  ,vector<int>& arr){
        return *max_element(arr.begin() + start , arr.begin() + end + 1);
    }


    int solve(int i , int n , int k , vector<int>& arr , vector<int>& dp){
        if(i == n)return 0;

        if(dp[i]!=-1)return dp[i];

        int maxSum = 0;
        for(int p = i ; (p < n && p <i+k) ; p++){
            int sum = (p - i + 1)* findMax(i , p , arr) + solve(p+1 , n, k , arr ,dp);

            maxSum = max(maxSum ,sum);
        } 
        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);

        return solve(0 , n, k , arr  ,dp);
    }
};

int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// Not fully correct 
// class Solution {
//     int solve(int start , int end , int len_start , int len_end , vector<int>& cuts){
//         if(start == end){
//             return len_end - len_start;
//         }

//         int mini = 1e9;
//         for(int i = start ; i <=end; i++){
//             int make = len_end - len_start + solve(start , cuts[i] , len_start , cuts[i] , cuts) + solve(cuts[i] , end , cuts[i] , len_end , cuts);

//             mini = min(mini , make);
//         }

//         return mini;
//     }
// public:
//     int minCost(int n, vector<int>& cuts) {
//         int end = cuts.size() - 1;
//         sort(cuts.begin() , cuts.end());

//         return solve(0 , end , 0 , n, cuts); // Having full length 
//     }
// };


class Solution {
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (j - i <= 1) return 0;  // no cuts in between
        
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int cost = (cuts[j] - cuts[i]) +
                       solve(i, k, cuts, dp) +
                       solve(k, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(0, m - 1, cuts, dp);
    }
};

// Now converting the memo soln to tabu soln 

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));

        for(int i = m - 1 ; i >=0 ; i--){
            for(int j = i + 1 ; i < m ; i++){
                if(j == i +1)continue; // yeh visualize nhi hoo raha tha but simple hai hoo jaayega no worry 
                int mini = 1e9;
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k]+ dp[k][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][m - 1];
    }
};

int main() {
    
    return 0;
}
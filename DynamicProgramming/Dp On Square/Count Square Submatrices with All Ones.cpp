#include <bits/stdc++.h>
using namespace std;

// The question is really very intutive in hand 

// How do i count the number of squares / rectange in matrix 

//  first we fill dp and try to create the formulation to fill that dp

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // create a dp of same size as matrix 
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>(m));

        // first row and col will be the same 

        for(int row = 0 ; row < n ; row++){
            dp[row][0] = matrix[row][0];
        }

        for(int col = 0 ; col < m ; col++){
            dp[0][col] = matrix[0][col];
        }


        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j < m ; j++){
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = min(min(dp[i - 1][j - 1] , dp[i - 1][j]) , dp[i][j - 1]) + 1;
                }
            }
        }

        // now we just add all the cells of the array 

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans+= dp[i][j];
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
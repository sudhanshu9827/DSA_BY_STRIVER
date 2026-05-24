#include <bits/stdc++.h>
using namespace std;

// aage se longest increasing nikal lu aur peeche se decreasing what an idea yrr 


// I took a lot time but the question is solvable fast 

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {

        vector<int> dp_inc(n , 1) , dp_dec(n , 1);


        for(int i = 1 ; i < n ; i++){
            for(int prev = 0 ; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp_inc[i]= max(1 + dp_inc[prev] , dp_inc[i]);
                }
            }

            for(int next = n - i + 1; next < n; next++){
                if(nums[next] < nums[n - i]){
                    dp_dec[n - i] = max(1 + dp_dec[next] , dp_dec[n - i]);
                }
            }
        }

        // check pura increasing yaa pura decreasing too nhi hai
        
        // for(int i : dp_inc){
        //     cout<<i<<" ";
        // }
        
        // cout<<endl;
        
        // for(int i : dp_dec){
        //     cout<<i<<" ";
        // }
        
        // cout<<endl;
        
        

        bool check_inc = true , check_dec = true; 

        for(int i = 0 ; i < n ; i++){
            if(dp_inc[i]!=1)check_inc = false;
            if(dp_dec[i]!=1)check_dec = false;
        }

        int maxi = 0;

        if(!check_dec && !check_inc){
            for(int i = 0 ; i < n ; i++){
                if(dp_inc[i]!=1 && dp_dec[i]!=1)
                    maxi = max(maxi , dp_inc[i]+dp_dec[i]);
            }
        }

        return maxi!=0? maxi - 1 : 0;
    }
};

int main() {
    
    return 0;
}
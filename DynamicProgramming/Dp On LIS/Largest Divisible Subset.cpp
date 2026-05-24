#include <bits/stdc++.h>
using namespace std;

// How could i find the soln which have all the numbers which satistfies 
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0


// Can't able to think and recognize the pattern of the question 
// How do i approach such question?

// Can't you relate the question 
// That is quite simple still i can't relate it 

// subset hai order does'nt matter at all 

// like can't we find longest divisible subseqenve if sorted i know [1 , 2 , 4 , 8] if 2/1 and 4/2 this implies 4/1

// yeh sab too pata hai then why question nhi hoo raha 

// same qestion : Try to find the pattern this could help you deduce the problem 

// simple question untill you able to find the pattern of the question 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
                sort(nums.begin() , nums.end());


        vector<int> dp(n , 1);// initially sab 1 hai matlb longest 1 too hai hii

        vector<int> hash(n);

        int maxi = 1;
        int lastIndex = 0;


        for(int i = 0 ; i < n ; i++){
            // pichle jaakar dekho sabse bada kon mill raha tha
            hash[i] = i;
            for(int prev = 0 ; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]){

                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Now just backtrack karna hai 

        vector<int> ans;
        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(lastIndex);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};

int main() {
    
    return 0;
}
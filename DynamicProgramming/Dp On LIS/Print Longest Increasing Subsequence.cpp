#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here

        int n = arr.size();

        vector<int> dp(n , 1);

        vector<int> hash(n);


        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
        }

        for(int i = 1 ; i < n ; i++){
            for(int prev = 0 ; prev <= i - 1 ; prev++){
                if(arr[prev] < arr[i]){
                    if(dp[i] < 1 + dp[prev]){
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
        }

        int lastIndex = max_element(dp.begin() , dp.end()) - dp.begin();

        // now we have an hash boo batayega jana kaha hai 
        vector<int> ans;
        ans.push_back(arr[lastIndex]);

        // while(1){
        //     // int prev = hash[hash[lisIndex]];

        //     if(hash[lisIndex]!=lisIndex){
        //         arr.push_back(arr[prev]);
        //         lisIndex = hash[lisIndex];
        //     }
        //     else break;
        // }

        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};

int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        vector<int> freq(26 , 0);
        
        int l = 0 , r = 0 , n = s.size() , distinct = 0;
        int ans =-1;
        // ek window me kaam karna hai sliding window concept 
        while(r < n){
            if(++freq[s[r] - 'a'] == 1)distinct++;
            
            if(distinct > k){
                if(--freq[s[l] - 'a'] == 0)distinct--;
                l++;
            }
            if(distinct == k){
                ans = max(ans , r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
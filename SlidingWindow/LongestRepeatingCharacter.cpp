#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26 , 0);

        int l = 0 , r = 0 , maxf = 0 , maxLen = 0;
        int changes;
        while(r < s.size()){
            freq[s[r] - 'A']++;
            maxf = max(maxf , freq[s[r] - 'A']);

            changes = (r - l + 1) - maxf;

            while(changes > k){
                // yeh blunder kabhi nhi karna ki maxf too bahutoo ki hoo sakti hai like b bhi max hai aur a bhi dono 3 -3 baar hai maanlo tumne too gatha diya that is not correct aur multiple time i said try to understand 

                // if(maxf == freq[s[l] - 'A'])maxf--;
                freq[s[l] - 'A']--;
                // after this i need to cross check the maxf again 
                maxf = 0;
                for(int i = 0 ; i < 26 ; i++){
                    maxf = max(maxf , freq[i]);
                }
                l++;
                changes = (r - l + 1) - maxf;
            }

            if(changes <= k){
                maxLen = max(maxLen , r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};
 
int main()
{
     
    return 0;
}
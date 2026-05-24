#include <bits/stdc++.h>
using namespace std;


// it is not considering beech waali substring why diyaan se karo balaak 
class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int sizeOfS1 = s1.size() , sizeOfS2 = s2.size();
        if(sizeOfS1 < sizeOfS2)return "";
        int l = 0 , r = 0 , pointS2 = 0 , minLen = INT_MAX;
        string ans = "";
        
        while(r < sizeOfS1){
            if(s1[r] == s2[pointS2])pointS2++;
            
            if(pointS2 == sizeOfS2){
                while(true){
                    if(l < r and s1[l]!=s2[0] or s1[l] == s1[l + 1]){
                        l++;
                    }
                    else break;
                }
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    ans = s1.substr(l , minLen);
                }
                pointS2 = 0;
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
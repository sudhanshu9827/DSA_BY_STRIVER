#include <bits/stdc++.h>
using namespace std;


// same prefix and suffix of highest length 

// the brute force could be find all the prefix and suffix and check which one is of longest length & and same 

// and the other method could be the algorith of counting (KMP) algorithm

class Solution {
    vector<int> prefix_fun(string s){
        int n = s.size();

        vector<int> prefix(n , 0);

        int j;

        for(int i = 1 ; i < n ; i++){
            j = prefix[i - 1];

            while(j > 0 and s[i]!=s[j]){
                j = prefix[j - 1];
            }

            if(s[i] == s[j])
                j++;

            prefix[i] = j;
        }

        return prefix;
    }
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> pre = prefix_fun(s);
        string ans = "";

        // last me jitna number hoga uthna hii too character equal aa rahe hone 

        int lasti = pre[n - 1];

        ans = s.substr(n - lasti , lasti);

        return ans;
    }
};

int main() {
    
    return 0;
}
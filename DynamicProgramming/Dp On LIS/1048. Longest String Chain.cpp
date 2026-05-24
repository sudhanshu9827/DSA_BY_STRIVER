#include <bits/stdc++.h>
using namespace std;

// What i think of in this question 
// lets get sort the entire array 
// check if length of current word - 1 = prev ki ban rahi hai agar haa then character check karlo just 

// How do i sort the elements of a string such that smaller string comes before than the larger string 

class Solution {
    bool check(string str1 , string str2){
        // str1 should be present in same order as str2 with one extra character 

        int i = 0 , j = 0;

        while(i < str1.size() && j < str2.size()){
            if(str1[i] == str2[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }

        return i == str1.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin() , words.end() ,[](string &a , string&b){
            if(a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });

        vector<int> dp(n , 1) , hash(n);

        int maxi = 1;
        int lastIndex = 0;

        for(int i = 0 ; i < n; i++){
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if(words[i].size()== 1 + words[prev].size() && check(words[prev], words[i]) && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    // hash[i] = prev;
                }
            }

            if(maxi < dp[i]){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        return maxi;

        // vector<string> ans;

        // ans.push_back(words[lastIndex]);

        // while(hash[lastIndex]!=lastIndex){
        //     lastIndex = hash[lastIndex];
        //     ans.push_back(words[lastIndex]);
        // }


        // return ans;
    }
};

int main() {
    
    return 0;
}
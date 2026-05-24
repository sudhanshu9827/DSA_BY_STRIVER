#include <bits/stdc++.h>
using namespace std;


//After writing the code apply on any test case got the better undertstanding

// Learning 

// we are doing partiton means at first step partition can be any where in the string 
// partion in  such a way that partioned string is pallindrome is the implementing approach #include <bits/stdc++.h>


class Solution {

    bool checkPallindrome(string &s , int start , int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
}


    void applyPartition(int idx , string s , vector<vector<string>>& ans , vector<string> & vs){
    if(idx == s.size()){
        ans.push_back(vs);
        return;
    }

    for(int i = idx ; i < s.size() ; i++){
        if(checkPallindrome(s , i , idx)){
            vs.push_back(s.substr(idx , i - idx + 1));
            applyPartition(i+1 , s , ans , vs);
            vs.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vs;
        applyPartition(0 , s , ans , vs);
        return ans;
    }
};
 
int main()
{
    string s = "abaa";
    Solution sol;
    vector<vector<string>> ans;
    ans = sol.partition(s);
     
    return 0;
}
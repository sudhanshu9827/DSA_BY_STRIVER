#include <bits/stdc++.h>
using namespace std;

// Can easily be solved using BF in O(n3) TC 

// Can we optimize it further yes we can use recursion => then DP

class Solution {
    void solve(string s , int start , int end , int & val){
        if(start == end){
            val++;
            return;
        }

        if(start == end - 1){
            if(s[start] == s[end]){
                val++;
                return;
            }
            else{
                return;
            }
        }

        int val = 0;
        if(s[start] == s[end]){
            solve(s , start + 1 , end - 1 , val);
        }

        else{
            solve(s , start + 1 , end , val);
            solve(s , start , end - 1 , val);
        }
    }
public:
    int countSubstrings(string s) {
        int n = s.size();

        int val = 0;

        solve(s , 0 , n - 1 , val);

        return val;
    }
};



// After few hours i will try it again 


// Try it again

class Solution {
    int solve(string s , int start , int end){
        if(start == end){
            return 1;
        }

        if(start > end){
            if(s[start] == s[end]){
                return 1;
            }
            return 0;
        }

        int val = 0;

        if(s[start] == s[end]){
            val = solve(s , start + 1 , end - 1);
        }

        val+= solve(s , start + 1 , end) + solve(s , start , end - 1);

        return val;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();

        return solve(s , 0 , n - 1);
    }
};

// we can do this question without dp as well in O(n2) TC 

// correct solution  

class Solution {

    int expand(string s , int l , int r){
        int count = 0;

        while(l >=0 && r < s.size() && s[l] == s[r]){
            count++;
            l++;
            r--;
        }

        return count;
    }

public:
    int countSubstrings(string s) {
        int n = s.size();

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            ans+=expand(s , i , i);
            ans+=expand(s , i , i+1);
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
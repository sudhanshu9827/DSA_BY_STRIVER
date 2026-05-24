#include <bits/stdc++.h>
using namespace std;


// i need to understand why this below solution is wrong ???


// map the text case first if the ith pointer aage nikal gaya but occurence peeche possible thi then 
// "mississippi"
// "issip"

// for example above 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int n = needle.size();
        int m = haystack.size();
        while(i < m){
            int j = 0;

            bool inside = false;

            while(j < n && i < m && haystack[i] == needle[j]){
                i++;j++;
                inside = true;
            }

            if(j == n)return i - j;

            if(!inside)
                i++;
        }

        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        
        vector<int> pote;

        for(int i = 0 ; i < m ; i++){
            if(haystack[i] == needle[0]) pote.push_back(i);
        }

        // all the potential candidates me chale jaao

        for(int pos : pote){
            int j = 0;
            while(pos < m && j < n && haystack[pos] == needle[j]){
                pos++;
                j++;
            }

            if(j == n)return pos - j;
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};


// BY KMP ALGO 


class Solution {
    vector<int> prefix_fun(string s){

        int n = s.size();

        vector<int> pi(n , 0);

        for(int i = 1 ; i < n ; i++){
            int j = pi[i - 1];

            while(j > 0 and s[i]!=s[j]){
                j = pi[j - 1];
            }

            if(s[i] == s[j])
                j++;
            
            pi[i] = j;
        }

        return pi;
    }
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        vector<int>prefix = prefix_fun(needle);

        int i = 0;
        int j = 0;

        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++;j++;
            }

            else{
                if(j!=0){
                    j = prefix[j - 1];
                }
                else{
                    i++;
                }
            }

            if(j == needle.size()){
                return i - j;
            }
        }

    }
};



int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// The Thought process is get rid of larger k starting element from the string 


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        int n = num.size();

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && k > 0 &&(st.top() - '0') > (num[i] - '0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty())return "0";
        while(!st.empty()){
            ans +=st.top();
            st.pop();
        }

        while(ans.size() && ans.back() == '0')ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans.size() ? ans : "0";
    }
};
 
int main()
{
     
    return 0;
}
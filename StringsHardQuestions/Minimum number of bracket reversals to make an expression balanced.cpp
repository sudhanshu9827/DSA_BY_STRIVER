#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        // I thought to be a direct question of the stack 

        stack<int> st;

        int n = s.size();

        int brac = 0;

        for(int i = 0 ; i < n; i++){
            if(s[i] == '('){
                st.push(1);
            }
            else if(!st.empty()) st.pop();

            else brac++;
        }

        return brac + st.size();
    }
};

int main() {
    
    return 0;
}
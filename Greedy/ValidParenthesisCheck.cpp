#include <bits/stdc++.h>
using namespace std;


// Ek soch thi not optimal not feasible exam me nhi kar paaung 
// three posibilities bann rahi hai le sakte hai ( or ) yaa nhi le 


// Brute force approach of solving the problem thinking like a present or not present methodology 
// Time complexity : their are three branches so in the worst possible scenario (3^n);
// depth of the tree  is the length of the string so Space complexity is O(n)
// We can optimize the code using Dynamic programming 
//I will do it later on 
class Solution {
    bool solve(string& s , int index , int count){
        if(count < 0)return false;
        if(index == s.size()){
            return count==0;
        }

        if(s[index] == '(')return solve(s , index + 1 , count+1);
        else if(s[index] == ')')return solve(s , index + 1 , count - 1);
        return solve(s , index + 1 , count + 1) or solve(s , index + 1 , count - 1) or solve(s, index + 1 , count);
    }
public:
    bool checkValidString(string s) {
        int index = 0 ; 
        int count = 0;
        return solve(s , index , count);
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int count = 0;
        int n = s.size();
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '(')st.push('(');

            else if(s[i]=='*'){
                int cnt = 0;
                int j = i + 1;
                while(j < n && s[j] != '('){
                    j++;
                }
                if(j!=n){
                    j++;
                    cnt++;
                    while(j < n){
                        if(s[j] == '(')cnt++;
                        else if(cnt>0) cnt--;
                        j++;
                    }
                }
                cout<<i<<" Sp "<<" "<<cnt<<" ";
                if(cnt > 0)return false;
                else count++;
            }

            else{
                if(!st.empty())st.pop();
                else if(count > 0)count--;

                else{
                    return false;
                }
            }
        }

        // but yeh hamesha nhi kehe sakta naa 
        while(!st.empty() && count){
            st.pop();
            count--;
        }

        return st.empty() ? true : false;
    }
};


// How can i solve the question more intutively and fast speed from next time will come in the interview 

// Lets look for the solution of striver 
// Most optimal solution on the screen 

// In normal solution we keep count but count here fails so we take a range of variable by which we can analyze the flow of * it can be using min and max 

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        
        int max = 0 , min = 0;

        for(char ch : s){
            if(ch == '('){
                max++;min++;
            }
            else if (ch==')'){
                max--;min--;
            }
            else{
                max++;
                min--;
            }
            if(min < 0)min = 0;
            if(max < 0)return false;
        }
        return min==0;
    }
};


//But aur bhi tareeke hai 
 
int main()
{
     
    return 0;
}
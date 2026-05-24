#include <bits/stdc++.h>
using namespace std;

vector<int> FindNextSmallerElement(const vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n - 1 ; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty())nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }
        return nse;
    }

 
int main()
{
     
    return 0;
}
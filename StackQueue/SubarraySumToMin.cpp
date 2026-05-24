#include <bits/stdc++.h>
using namespace std;


// Brute force find all the subarray in O(n2) time and take the minimum of that subarray and sum 
// Bahut aacha question hai 
//In register also 
// But saara khel frequency ka hai 
// jitni waal joo usske chetr ke min hoga wahi aayega 
//boo apn nse or pse se nikal sakte hai 
//but ussme bhi same honge too diyaan rakho element ka diyaan rakhna hoga
//like 1 2 1 => 2 baar repeat naa hoo jaaye
class Solution {

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

    vector<int> FindPrevSmallerOrEqualElement(const vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty())psee[i] = st.top();
            else psee[i] = -1;
            st.push(i);
        }
        return psee;
    }


public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int>psee(n);
        nse = FindNextSmallerElement(arr);
        psee = FindPrevSmallerOrEqualElement(arr);

        int total = 0;
        int mod = 1e9+7;

        for(int i = 0 ; i < n ; i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + ((left + right)* arr[i]) % mod ) % mod;
        }

        return total;
    }
};
 
int main()
{
     
    return 0;
}
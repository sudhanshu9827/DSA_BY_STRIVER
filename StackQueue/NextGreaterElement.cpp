// How do you think from traverse from back 
// right ke element dekhne hai joo bade hai 
// peeche se too dekhna hi padega clear though hai 
// Pata nhi dimaag me nhi aaya 
// and if koi bada element mill gaya uske aage joo bhi chote element hai bekaar hai unko pop kar sakte hoo 

// 1 3 5 2 9 11

// 5 ke liye 9 imp hai 5 se left waalo ke liye bhi 2 kabhi imp nhi hoga yaa too 5 hoga yaa usee koi bada soo usse pop kar sakte hai 





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mp;
        stack<int> st;
        int n = nums2.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            if(st.empty())mp[nums2[i]] = -1;
            else{
                while(!st.empty() && nums2[i] > st.top()){
                    st.pop();
                }
                if(!st.empty())
                    mp[nums2[i]] = st.top();
                else mp[nums2[i]] = -1;
            }
        }
        int m = nums1.size();

        vector<int> ans(m);
        for(int i = 0; i < m ; i++){
            ans[i] = mp[nums1[i]];
        }

        return ans;
    }
};
 
int main()
{
     
    return 0;
}
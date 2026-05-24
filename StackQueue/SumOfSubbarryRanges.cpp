#include <bits/stdc++.h>
using namespace std;

// Just go with your intution 

class Solution {
    int n;

    vector<int> NextSmallerElement(vector<int>& nums){
        vector<int> Nse(n);

        stack<int> st;


        for(int i = n - 1; i >=0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                Nse[i] = st.top();
            }
            else{
                Nse[i] = n;
            }
            st.push(i);
        }
        return Nse;
    }

    vector<int> PrevSmallerElementEqual(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty())psee[i] = st.top();
            else psee[i] = -1;
            st.push(i);
        }
        return psee;
    }

    vector<int> NextGreaterElement(vector<int>& nums){
        vector<int> Nge(n);

        stack<int> st;


        for(int i = n - 1; i >=0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                Nge[i] = st.top();
            }
            else{
                Nge[i] = n;
            }
            st.push(i);
        }
        return Nge;
    }

    vector<int> PrevGreaterElementEqual(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty())psee[i] = st.top();
            else psee[i] = -1;
            st.push(i);
        }
        return psee;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        vector<int>Nse = NextSmallerElement(nums);
        vector<int> Psee = PrevSmallerElementEqual(nums);
        vector<int> Nge = NextGreaterElement(nums);
        vector<int> Pgee =  PrevGreaterElementEqual(nums);
        for(int i = 0 ; i < n ; i++){
            int leftSmaller =  i - Psee[i];
            int rightSmaller = Nse[i] - i;
            int TotalSmaller = rightSmaller * leftSmaller;

            int leftGreater = i  - Pgee[i];
            int rightGreater = Nge[i] - i;
            int TotalGreater = rightGreater * leftGreater;

            ans += nums[i] * (TotalGreater - TotalSmaller);
        }
        return ans;
    }
};
int main()
{
     
    return 0;
}
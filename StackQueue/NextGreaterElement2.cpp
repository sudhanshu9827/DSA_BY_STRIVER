#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // brute force approach tc : O(n2)
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            int j = 0;
            int k = i + 1;
            while(j < n){
                if(nums[i] < nums[k % n]){
                    ans[i] = nums[k % n];
                    break;                
                }
                j++;
                k++;
            }
            if(j==n)ans[i] = -1;
        }
    }
};


// Approach 2: 
// I though stack can be used as lamp comcept bada usse bada phir bada 
// same element ke liye bhi too soccho 
// forget to puttt inside loop if empty hoo gaya 
// mene soccch empty too kabhi hoga nhi but essa nhi hai empty hoo sakta hai 
// in which case when frequency of max element is greater than one 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxIndex = max_element(nums.begin() , nums.end()) - nums.begin();

        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        st.push(nums[maxIndex]);

        ans[maxIndex] = -1;
        int j = maxIndex - 1 + n;
        while((j % n) != maxIndex){
            while(!st.empty() && nums[j%n] >= st.top()){
                st.pop();
            }
            if(!st.empty())
                    ans[j % n] = st.top();
            else ans[j % n ] = -1;
            st.push(nums[j%n]);
            j--;
        }
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
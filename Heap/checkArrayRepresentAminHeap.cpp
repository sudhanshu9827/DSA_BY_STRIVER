// first method min heap banao and then compare kar lu 
//during hepify ek bhi baar swap hota hai then it is not an min or max heap
#include <bits/stdc++.h>
using namespace std;

class Solution{
    bool check(int i , vector<int>& nums){
        int n = nums.size();
        int smallest = i;
        int left = 2 * i + 1 , right = 2 * i + 2;
        if(left <  n && nums[smallest] > nums[left]) smallest = left;
        if(right < n && nums[smallest] > nums[right]) smallest = right;

        if(i!=smallest)return false;
        return true;
    }
    public:
    bool isMinHeap(vector<int> & nums){
        int n = nums.size();
        for(int i = n/2 - 1 ; i>=0 ; i--){
            if(!check(i , nums))return false;
        }
        return true;
    }
};
 
int main()
{
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};

    // Output result
    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
     
    return 0;
}
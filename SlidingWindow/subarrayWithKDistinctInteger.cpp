#include <bits/stdc++.h>
using namespace std;

class Solution {
    int subarraysKDistinct(vector<int>& nums, int k){
        if(k < 0)return 0;
        vector<int> freq(20001 , 0);

        int r = 0 , l = 0 , n = nums.size() ,count = 0 , diff = 0;
        while(r < n){
            if(++freq[nums[r]] == 1)diff++;

            while(diff > k){
                if(--freq[nums[l++]] == 0)diff--;
            }

            if(diff <= k){
                count+= r - l + 1;
            }
            r++;
        } 
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        cout<<subarraysKDistinct(nums , k);
        return subarraysKDistinct(nums , k) - subarraysKDistinct(nums , k - 1);
    }
};
 
int main()
{
     
    return 0;
}
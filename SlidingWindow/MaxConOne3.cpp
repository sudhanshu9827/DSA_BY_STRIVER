#include <bits/stdc++.h>
using namespace std;

// Follow up the pattern 


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() , l = 0 , maxCon = 0 , zeroes = 0;
        for(int r = 0; r < n ; r++){
            if(nums[r] == 0)zeroes++;

            while(zeroes > k){
                if(nums[l] == 0)zeroes--;
                l++;
            }

            if(zeroes <=k) maxCon = max(maxCon , r - l + 1);
        }
        return maxCon;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() , l = 0 , maxCon = 0 , zeroes = 0;
        for(int r = 0; r < n ; r++){
            if(nums[r] == 0)zeroes++;

            if(zeroes > k){
                if(nums[l] == 0)zeroes--;
                l++;
            }

            if(zeroes <=k) maxCon = max(maxCon , r - l + 1);
        }
        return maxCon;
    }
};
 
int main()
{
     
    return 0;
}
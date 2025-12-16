#include <bits/stdc++.h>
using namespace std;


// Brute Force solution TC: O(n2)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // brute force 
        // generate all the subarray and try checking the possibilities 
        int count = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int curr_sum = 0;
            for(int j = i; j < n ; j++){
                curr_sum += nums[j];
                if(curr_sum == goal)count++;
                else if(curr_sum > goal)break;
            }
        }
        return count;
    }
};


// Can We do it better 
//subarray ke saath sum prefix sum is the best option that we have 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // brute force
        // generate all the subarray and try checking the possibilities
        int count = 0;
        int n = nums.size();

        unordered_map<int, int> prefixSum;

        int current_sum = 0;

        prefixSum[0] = 1;
        for(auto num : nums){
            current_sum+=num;
            
            if(prefixSum.find(current_sum - goal)!=prefixSum.end())count+=prefixSum[current_sum - goal];

            prefixSum[current_sum]++;
        }
        return count;
    }
};

// optimal try 
// NOT successfull 
// l ko chalao yaa r ko not define iss wajaha se sliding window direct nhi laga paa raha 

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0 , r = 0 , n = nums.size() , count = 0 , sum = 0;
        int initalZero = 0;
        while(r < n){
            sum+=nums[r];

            if(sum > goal){
                sum-=nums[l];
                l++;
            }

            if(sum == goal){
                count++;
                while(l < r && !nums[l]){
                    count++;l++;initalZero++;
                }
                r++;
                if(r < n && !nums[r]){
                    count+= 1 + initalZero;
                    r++;
                }
                initalZero = 0;
            }
            else r++;
        }
        return count;
    }
};


// Optimal by striver 
// use a trick of maths find all subarray whoes sum is <= goal and then subtract it from all subarray whoes sum is <=goal -1

class Solution {

    int numSubarrays(vector<int>& nums , int goal){
        // soo find all the subarray whoes sum is less than equal to goal 

        if(goal < 0)return 0;

        int l = 0 , r = 0 , count = 0 , sum = 0 , n = nums.size();
        while(r < n){
            sum+=nums[r];

            while(sum > goal)sum-=nums[l++];

            count+= r - l + 1;r++;
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // what if goal is zero so use edge case 
        return numSubarrays(nums , goal) - numSubarrays(nums , goal - 1);
    }
};

int main()
{
     
    return 0;
}
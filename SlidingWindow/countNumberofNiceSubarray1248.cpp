#include <bits/stdc++.h>
using namespace std;


// I made it complex and not clearly understood by me also after some time 
//can we do better and the answer is YES
// same as BinarySubarrayQuestion count(k) - count(k - 1) is the answer
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // sliding window using 
        int l = 0 , r = 0 ,count = 0 , Nodd = 0 , Neven = 0;;
        while(r < nums.size()){
            if(nums[r] & 1)Nodd++;

            while(Nodd > k){
                if(nums[l] & 1)Nodd--;
                l++;
            }
            // bool ander = false;
            if(Nodd == k){
                //find even
                while(l < nums.size() && nums[l] % 2 ==0){
                    Neven++;
                    l++;
                }
                count++;
                r++;
                while(r < nums.size() && nums[r] % 2 ==0){
                    count+=Neven + 1;
                    r++;
                }
                count+=Neven;
                Neven = 0;
            }
            else r++;
        }
        return count;
    }
};
 
int main()
{
     
    return 0;
}
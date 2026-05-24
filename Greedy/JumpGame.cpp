#include <bits/stdc++.h>
using namespace std;

// what i did wrong is :
// 1. neeche pata nhi kyu j likh diya pehle phir j - 1 likh diya jabki maxJumpIndex likhna tha just 
// 2. akele zero ko consider nhi kiya ; itni baar galti hui hai akela element , akela zero and essi galtiya par consider hii hoti while doing quesion 


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // i am gready to be jump as high as possible 
        //so me uspar jump karunga joo sabse higher hoga


        int n = nums.size();
        if(n==1 && nums[0] == 0)return true;
        int i = 0;
        int maxJump;
        int maxJumpIndex = 0;
        while(i < n){
            maxJump = nums[i];
            cout<<maxJump<<endl;
            if(!maxJump)return false;
            // maxJumpIndex = i;


            if(i + maxJump >= n - 1)return true;
            int j;
            for(j = i + 1 ; j <= i + nums[i] ; j++){
                if(j + nums[j] >= maxJumpIndex + maxJump){
                    maxJump = nums[j];
                    maxJumpIndex = j;
                }
            }

            if(maxJumpIndex!=i)i = maxJumpIndex;
            else i = nums[i];
        }
        return true;
    }
};

// Lets see striver Soluton for the question which enhance clearity 

// agar me maxIndex rakh lu ki boo kaha tak reach hoo sakta hai then mera kaam too wahi bann jaayega extra loop ki koi need hii nhi hai 
// joo maximum pahuchaaye usse seedha max rakhlo harr check me 

// if there is no zero we always reach to the end 

class Solution{
    bool canJump(vector<int>& nums){
        int n = nums.size();

        int maxIndex = 0;

        for(int i = 0 ; i < n ; i++){
            maxIndex = max(maxIndex , i + nums[i]);

            if(maxIndex >= n - 1)return true;
            if(i > maxIndex)return false;
        }
        return true;
    }
};
 
int main()
{
     
    return 0;
}
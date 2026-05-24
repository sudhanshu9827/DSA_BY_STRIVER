#include <bits/stdc++.h>
using namespace std;


// Take not take concept can be use here  but dimaag me nhi aaya 

// approach of the question is not correct 
// what if smaller ke baad bahut bada mill gaya but apn smaller pehel smaller tha iss wajha se liya nhi 
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int cardRemain = k , maxi = 0 , temp_s , temp_e;
//         int start = 0 , end = cardPoints.size() - 1;
//         while(cardRemain){
//             // jaakar check kar loo if same hai then konsa bada hai 
//             if(start < end && cardPoints[start] == cardPoints[end]){
//                 temp_s = start + 1;
//                 temp_e = end - 1;

//                 while(temp_s < temp_e && cardPoints[temp_s] == cardPoints[temp_e]){
//                     temp_s++; temp_e--;
//                 }
//                 if(cardPoints[temp_s] > cardPoints[temp_e]){
//                     for(int i = start ; i <= temp_s && cardRemain; i++){
//                         maxi+=cardPoints[i];
//                         cardRemain--;
//                     }
//                     start = temp_s + 1;
//                 }
//                 else{
//                     for(int j = end ; j >=temp_e && cardRemain; j--){
//                         maxi+=cardPoints[j];
//                         cardRemain--;
//                     }
//                     end = temp_e - 1;
//                 }
//             }
//             else if(cardPoints[start] > cardPoints[end]){
//                 maxi+=cardPoints[start];
//                 cardRemain--;
//                 start++;
//             }
//             else{
//                 maxi+=cardPoints[end];
//                 cardRemain--;
//                 end--;
//             }
//         }
//         return maxi;
//     }
// };




class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum+=cardPoints[i];
        }
        int rightIndex = cardPoints.size() - 1;
        long long maxSum = sum;
        for(int j = k - 1 ; j>=0 ; j--){
            sum-= cardPoints[j];
            sum+=cardPoints[rightIndex--];
            maxSum = max(maxSum , sum);
        }

        return maxSum;
    }
};


 
int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// min ki baat kare too max heap ka use karte hai max heap ki baat kare then min heap use karte hai 

class Solution{
    int KthSmallestElement(vector<int>& nums , int k){
        priority_queue<int> maxHeap;

        for(int num : nums){
            maxHeap.push(num);
            if(maxHeap.top() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};
 
int main()
{
     
    return 0;
}
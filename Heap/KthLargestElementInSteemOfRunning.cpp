#include <bits/stdc++.h>
using namespace std;

class Solution{
    priority_queue<int , vector<int> , greater<int>> maxHeap;

    int size;
    public:
        Solution(vector<int> nums , int k){
            size = k;
            for(int num : nums){
                maxHeap.push(num);

                if(maxHeap.size() > size){
                    maxHeap.pop();
                }
            }
        }

        int add(int val){
            maxHeap.push(val);
            if(maxHeap.size() > size)maxHeap.pop();

            return maxHeap.top();
        }
};
 
int main()
{
     
    return 0;
}
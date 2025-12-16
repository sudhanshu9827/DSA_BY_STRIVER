#include <bits/stdc++.h>
using namespace std;


// Using MaxHeap 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin() , nums.end());
        for(int i = 1  ; i <= k-1 ; i++){
            pq.pop();
        }

        return pq.top();
    }
};

// Using MinHeap 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // if i can make the queue of size k and its min and only 
        priority_queue<int , vector<int> , greater<int>> pq;
        
        for(int num : nums){
            if(pq.size() >= k && pq.top() < num){
                pq.pop();
                pq.push(num);
            }
            else if(pq.size() <= k)
                pq.push(num);
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);// har baar push karta gaya if size k se jaada koi element too hoga joo bada hoga joo jth largest se chhota hoga multiple bhi hoo sakte hai mene kaha maan loo saare increasing me hai k tak kth wala element uper hai abb next k + 1 me koi aur element aaa jaayega boo pop hoga
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();        
    }
};
 
int main()
{

     
    return 0;
}
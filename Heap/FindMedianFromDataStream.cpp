#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    vector<int> nums;
    // essa kya kardu joo baar sort naa karna padde aur mera kaam hojaaye
    //kya heap ka use kar sakte hai Yes i guess 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        if(n % 2 != 0){
            return double(nums[n/2]);
        }
        else{
            return double(nums[n/2] + nums[n/2-1])/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())return maxHeap.top();

        return (maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
 
int main()
{
     
    return 0;
}
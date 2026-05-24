#include <bits/stdc++.h>
using namespace std;


// Two major mistakes that i did 

// 1. Unable to understood the question first
// 2. map me erase karna bhool gaya map me erase ke liye that name.erase(just key here)

// Brute force approach :
// i can take all the possible subarrays and which is the biggest subarray which containts atmost two types of number 
//store it into set 
// like
// for int i => n 
//     // set<int> 
//     set.add();
//     if(set.size() > 2) maxlen = max(maxlen , j - i + 1)
// something like that i can do 

// better solution Sliding window + 2 pointer approach

// TC : toop (O(n + n))
// SC : O(3);

// Can be optimize it further yaa 
//What is the thing which takes extra time 
//that inside while loop can we trim down that while loop YES

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count[100001] = {0}; // adjust size based on constraints
        int left = 0, distinct = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); right++) {
            if (++count[fruits[right]] == 1) distinct++;

            while (distinct > 2) {
                if (--count[fruits[left]] == 0) distinct--;
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};

// Most optimal solution 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int> count;
        int maxlen = 0, left = 0;

        for(int right = 0 ; right < fruits.size() ; right++){
            count[fruits[right]]++;

            if(count.size() > 2){
                // i need to trim it down 
                if(--count[fruits[left]] == 0)count.erase(fruits[left]);
                left++;
            }
            else{
                maxlen = max(maxlen , right - left + 1);
            }
        }
        return maxlen;
    }
};


 
int main()
{
     
    return 0;
}
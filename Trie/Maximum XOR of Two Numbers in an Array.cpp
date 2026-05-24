// simple approach is giving time limit exceed in this cource 
// at first anybody think about the simple approach which is quite simple

// How do i create an idea or map in my mind this problem could be related to the TRIE (Important)
// I cant able to think in the way How do i use trie in this question lets check the concept 

// Yaa this i think well for the number i need to take opposite to the particular number


// when i combine the two numbers whose bits position has maximum different like 0101 xor 1010 this will yield the maximum answer 

// How do i get to know in less then <O(n2) time Complexity 

#include <bits/stdc++.h>
using namespace std;

// lets make the binary trie 

// For this TC can be come out to be 

// O(n * 32) + O(n * 32); 

// Instead of using POW use bit 
// Why ? pow() returns a double. For large values of i (like 30, 31), floating point imprecision 



struct Node{
    Node * link[2];
    bool flag;

    Node(){
        link[0] = link[1] = NULL;
        flag = false;
    }

    bool presentBit(int bit){
        return link[bit]!=NULL;
    }

    void put(int bit , Node * newNode){
        link[bit] = newNode;
    }

    Node * get(int bit){
        return link[bit];
    }
};


class Trie{
    public:
    Node * root = new Node();

    void insertNumber(int num){
        // it is a 32 bit number 

        Node * node = root;

        for(int i = 31 ; i >=0 ; i--){
            // int bit = ( 1 << i ) & num; // this will give me the masked value not 0 and 1 like if 1 << i => 4& 6 => 4 
            int bit = (num >> i) & 1;

            if(!node->presentBit(bit)){
                // then i need to create an another node 
                node->put(bit , new Node());
                node = node->get(bit);
            }
            else{
                node = node->get(bit);
            }
        }
    }

    int maxXorNumber(int num){

        Node * node = root;

        int number = 0;

        for(int i = 31 ; i >= 0 ; i--){
            int requireBit = !((num >> i) & 1);
            if(node->presentBit(requireBit)){
                number+=requireBit *  (1 << i); 
                node = node->get(requireBit);
            }
            else{
                number+= (!requireBit) * (1 << i);
                node = node->get(!requireBit);
            }
        }

        return number;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // just insert all the numbers 
        int n = nums.size();

        Trie t;

        for(int i = 0 ; i < n ; i++){
            t.insertNumber(nums[i]);
        }

        // just i need to find the number opposite or max flipped bit from the number 

        int maxi = INT_MIN;
        int currNumber;

        for(int i = 0; i < n ; i++){
            currNumber = nums[i];

            // check is opposite of this number exit 
            int xoredNumber = t.maxXorNumber(currNumber);

            maxi = max(maxi , xoredNumber ^ currNumber);
        }

        return maxi;
    }
};

int main() {
    
    return 0;
}
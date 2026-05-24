#include <bits/stdc++.h>
using namespace std;


// How should i consider the case in which boo merko num nhi lena joo mi se bada hoo then how do i ignore that particular element 

// pehele mene saare save kar liye hai usse me koi ched khaani nhi kar sakta 

// then joo bade hai unko consider naa karu kaise ??




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

        Node * node = root;

        for(int i = 31 ; i >=0 ; i--){
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        // the intution is quite simple what if my trie always contain the element <=ai then the problem boils down to the prev problem 
        // so instead of making trie at once make it according to the ai 
        int n = nums.size();

        Trie t;

        sort(nums.begin() , nums.end());

        // i need tp sort the queries but also save the particular trie position 

        vector<tuple<int , int , int>> vt;

        int m = queries.size();

        vector<int> ans(m , 0);

        // Index saving for order of the answer
        for(int i = 0 ; i < m ; i++){
            int xi = queries[i][0];
            int mi = queries[i][1];

            vt.push_back({mi , xi , i});
        }


        // now sort it based on mi


        sort(vt.begin() , vt.end());


        int pointerToArray = 0; 

        for(int i = 0 ; i < m ; i++){
            auto [mi , xi , index] = vt[i];

            while(pointerToArray < n && nums[pointerToArray] <= mi){
                // putt the element into the trie 
                t.insertNumber(nums[pointerToArray]);
                pointerToArray++;
            }

            // just find maximum xor 

            if(!pointerToArray){
                ans[index] = -1;
            }

            else{
                int temp = xi ^ t.maxXorNumber(xi);
                ans[index] = temp;
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}
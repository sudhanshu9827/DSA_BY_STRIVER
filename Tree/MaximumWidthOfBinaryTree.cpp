#include <bits/stdc++.h>
using namespace std;

// !Tag : Remember , again 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// width is the distance between two nodes 
// what i can say if i give indexing to the binary tree i can directly find out by high - low + 1 at each level and take maximum out of each level 
// how can i give indexing heap me kaise dete the bhool gaye bese hii 
// 2i + 1 , 2i + 2 in 0 based indexing 

// The number of nodes in the tree is in the range [2, 10^5]. contraints are very high if 2 * i it will be very large after some level

// let simple failure skew tree of 10^5 nodes then it will become 2^10power(5) - 1 this could not be possible or feasible 

// what i can do is ussko chota kardo naa number ko ek hii row me too dekhana hai  
// then one intution is ki usko chotta karne ke liye joo uper waale level me minimum tha usse minus karte jaayenege

//Nice question which teaches ki binary tree me bhi indexing dekar question kiya jaa sakta hai 

// and haa agar overflow hoo raha hai tab kaise precaution le sakte hai 



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // level order traversal i should use 
        if(!root)return 0;

        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});

        int width = 0;
        int size;

        while(!q.empty()){

            int start = q.front().second;
            int end = q.back().second;

            width = max(width , end - start + 1);

            size = q.size();

            for(int i = 0; i < size ; i++){
                auto [node , idx] = q.front();
                q.pop();

                int currIdx = idx - start;//chota karne ke liye

                if(node->left)q.push({node->left , 1LL *2 * currIdx + 1});
                if(node->right)q.push({node->right , 1LL * 2 * currIdx + 2});
            }
        }
        return width;
    }
};

 
int main()
{
     
    return 0;
}
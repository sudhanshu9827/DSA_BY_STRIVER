#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Basic idea wahi hai neeche chala gaya abb soccho kaise kar sakta hu upper aate aate 

class Solution {
    int diameter(TreeNode* root , int &maxDia){
        if(!root)return 0;

        int leftHeight = diameter(root->left , maxDia);
        int rightHeight = diameter(root->right , maxDia); 

        maxDia = max(maxDia , leftHeight + rightHeight);

       return 1 + max(leftHeight , rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        diameter(root , maxDia);
        return maxDia;
    }
};
 
int main()
{
     
    return 0;
}
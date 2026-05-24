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


// Intution sahi tha but ulta socch raha tha that why galt hoo raha tha 


class Solution {
    bool checkBst(TreeNode * root , long long min , long long max){
        if(!root)return true;

        TreeNode * left = root->left;
        TreeNode * right = root->right;

        if(root->val < max and root->val > min)
            return checkBst(root->left , min , root->val) and checkBst(root->right , root->val , max);

        else return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        return checkBst(root , (long long)INT_MIN -1  , (long long)INT_MAX + 1);
    }
};
 
int main()
{
     
    return 0;
}
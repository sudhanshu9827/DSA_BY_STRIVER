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

class Solution {
    void insert(TreeNode * &root , int val){
        TreeNode * left = root->left;
        TreeNode * right = root->right;

        if(root->val > val && !left){
            root->left = new TreeNode(val);
            return;
        }

        if(root->val < val && !right){
            root->right = new TreeNode(val);
            return;
        }

        if(root->val > val){
            insert(root->left , val);
        }

        if(root->val < val){
            insert(root->right , val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(!root){
        root = new TreeNode(val);
        return root;
       }
    }
};
 
int main()
{
     
    return 0;
}
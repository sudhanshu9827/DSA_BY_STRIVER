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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // agar koi bhi mill gaya yaa too khud null hoo gaya too return too karna hii padega 
        if(!root || root == p || root == q){
            return root;
        }

        TreeNode * left =  NULL;
        if(root->val > p->val || root->val > q->val){
            left = lowestCommonAncestor(root->left , p , q);
        }

        TreeNode * right = NULL;
        if(root->val < p->val || root->val < q->val){
            right = lowestCommonAncestor(root->right , p , q);
        }

        if(left && right){
            return root;
        }

        return left ? left : right;
    }
};

//! Basic intution of this question 

// yeh aacha hai aur aasani se cheeze hoo rahi hai 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val > root->val && q->val > root->val){
                root = root->right;
            }

            else if (p->val < root->val && q->val < root->val){
                root= root->left;
            }

            else return root;
        }
        return nullptr;
    }
};

int main()
{
     
    return 0;
}
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

// Not solved in one go 
// but dimaag chala sakte hoo like 
// agar khud hai then return turant warna left right me dhuno dono mill gaye then wahi hoga agar ek milla koi too usko return kardo ki ek mill gaya kahi aur se dusra laao jaise left subtree se ek mill gaya right subtree se dusra abb finally jissne usse call kiya tha root uspar hii jaakar dono not null honge recursion me 
//!Intution aacha hai toda dimaag me bhi rakhna

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root ||root == p || root == q)return root; // matlb ek common hai root ke too wahi answer shuru ka socchkar chalo joo root hai wahi hoo gaya then wahi too answer hoga naa 

        TreeNode * left = lowestCommonAncestor(root->left , p , q);
        TreeNode * right = lowestCommonAncestor(root->right , p , q);

        if(left and right){
            // null koi bhi nhi hai 
            // root hii answer hoga joo common hai dono ke beech ka aadhar 
            return root;
        }

        return left!=nullptr ? left : right;
    }
};
 
int main()
{
     
    return 0;
}
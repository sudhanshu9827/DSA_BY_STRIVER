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


// Brute Force method 
// Think : if i found and traversal and sort it and save into the vector 
// then again inorder traversal then harr node ki value jaha vector me point kar rahi hogi wahi hogi simple 

// what if i dont waana to use extra space 
// can we do it in space complexity : O(1)


// found malacious nodes is a trick 

// am i getting always two malcious nodes ! no.

// some time i will get only one malcious what it signifies ki agal bagal waale element me hii dikkat hai matlb just swap agal bagal waala 

//! Remeber 


class Solution {
    private:
        TreeNode * first;
        TreeNode * middle;
        TreeNode * prev;
        TreeNode * last;

        void inOrder(TreeNode * root){
            if(!root)return;

            inOrder(root->left);

            if(prev && prev->val > root->val){
                if(!first){
                    first = prev;
                    middle = root;
                }

                else{
                    last = root;
                }
            }
            prev = root;
            inOrder(root->right);
        }

public:
    void recoverTree(TreeNode* root) {

        first = middle = last = prev = NULL;

        inOrder(root);
        if(first && last)swap(first->val , last->val);
        else if(first && middle)swap(first->val , middle->val);
    }
};

 
int main()
{
     
    return 0;
}
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


// A single thought can lead towards the correct answer
// Recursive Approach 
// Date : 11/01/2026 
//!Q1
// today Target : 6 questions

class Solution {
    bool compareTree(TreeNode * root1 , TreeNode* root2){
        if(!root1 && !root2)return true;
        if(root1 && !root2 || root2 && !root1 || root1->val != root2->val)return false;

        bool check;

        check = compareTree(root1->left , root2->right) && compareTree(root1->right , root2->left);

        return check;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right ))return true;
        return compareTree(root->left , root->right);
    }
};

// ? Interviwer siad can you do that question iteratively
// I found Iterative is little bit difficulty

// Solved Successfully 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st1 , st2;

        if(!root || (!root->left && !root->right))return true;
        if(root->left && !root->right || root->right && !root->left)return false;
        st1.push(root->left);
        st2.push(root->right);


        while(!st1.empty() && !st2.empty()){
            TreeNode* top1 = st1.top(); 
            TreeNode* top2 = st2.top();
            if(top1->val != top2->val)return false;
            st1.pop();st2.pop();


            if(!top1->right && top2->left || top1->right && !top2->left ||
                !top1->left && top2->right || top1->left && !top2->right) return false;

            if(top1->right)st1.push(top1->right);
            if(top1->left)st1.push(top1->left);
            if(top2->left)st2.push(top2->left);
            if(top2->right)st2.push(top2->right);
        }

        return (st1.empty() && st2.empty());
    }
};

 
int main()
{
     
    return 0;
}
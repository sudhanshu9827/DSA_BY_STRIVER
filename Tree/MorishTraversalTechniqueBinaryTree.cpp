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

// bus right most me jaakar curr se add kar dena hai soo apn left ke baad turant root par phir right par jaa paaye 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        TreeNode * curr = root;
        if(!root)preOrder;

        while(curr!=NULL){
            if(!curr->left){
                preOrder.push_back(curr->val);
                curr = curr->right;
            }

            else{
                TreeNode * ptr = curr->left;

                while(ptr->right && ptr->right!=curr){
                    ptr = ptr->right;
                }

                if(!ptr->right){
                    ptr->right = curr;
                    curr = curr->left;
                }

                if(ptr->right == curr){
                    ptr->right = nullptr;
                    preOrder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return preOrder;
    }
};

// For preOrder we just need to change one line of code 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        TreeNode * curr = root;
        if(!root)preOrder;

        while(curr!=NULL){
            if(!curr->left){
                preOrder.push_back(curr->val);
                curr = curr->right;
            }

            else{
                TreeNode * ptr = curr->left;

                while(ptr->right && ptr->right!=curr){
                    ptr = ptr->right;
                }

                if(!ptr->right){
                    ptr->right = curr;
                    preOrder.push_back(curr->val);
                    curr = curr->left;
                }

                if(ptr->right == curr){
                    ptr->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preOrder;
    }
};
 
int main()
{
     
    return 0;
}
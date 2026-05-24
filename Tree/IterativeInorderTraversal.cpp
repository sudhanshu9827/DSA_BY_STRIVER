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


// BFS 
 class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Soo inorder  Left paerent right

        // using stack 
        vector<int> Inorder;
        stack<TreeNode*> order;

        TreeNode* curr = root;

        while(curr!= NULL || !order.empty()){
            // left most too jaana padega 
            while(curr!=NULL){
                order.push(curr);
                curr = curr->left;
            }

            curr = order.top();
            order.pop();
            Inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
};

// But there are more easy and itutive ways to do this same question 

// kabhi kabhi hota hai dimaag nhi chalta ya dimaag kehe deta hai hogaya aaj ke liye 
// jab simple question bhi nhi bante 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        if(root){
            maxi = 1 + max(maxDepth(root->left) , maxDepth(root->right));
        }
        return maxi;
    }
};
 
int main()
{
     
    return 0;
}
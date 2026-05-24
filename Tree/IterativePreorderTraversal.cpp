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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        stack<TreeNode*> nodes;

        nodes.push(root);
        TreeNode* t = root;
        while(!nodes.empty()){
            // pehle mujhe joo chahiye usse baadme daalunga clear thought
            t = nodes.top(); 

            preOrder.push_back(t->val);
            nodes.pop();
            if(t->right)
                nodes.push(t->right);
            if(t->left)
                nodes.push(t->left);
        }
        return preOrder;
    }
};
 
int main()
{
     
    return 0;
}
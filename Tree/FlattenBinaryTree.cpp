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
    void preOrderTraversal(TreeNode * root , vector<pair<int , TreeNode*>>& valNode){
        if(!root)return;

        valNode.push_back({root->val , root});
        preOrderTraversal(root->left , valNode);
        preOrderTraversal(root->right , valNode);
    }
public:
    void flatten(TreeNode* root) {
        vector<pair<int , TreeNode*>> valNode;

        preOrderTraversal(root , valNode);

        for(int i = 0 ; i < valNode.size()-1 ; i++){
            TreeNode * curr = valNode[i].second;
            TreeNode * next = valNode[i+1].second;

            curr->right = next;
            curr->left = nullptr;
        }
        valNode[valNode.size() - 1].second->left = nullptr;
    }
};


// Can you flatten the tree in O(1) space complexity ? 
 
int main()
{
     
    return 0;
}
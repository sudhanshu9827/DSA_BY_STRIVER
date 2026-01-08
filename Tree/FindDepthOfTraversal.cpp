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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* curr;

        int level = 0;
        int n;
        while(!q.empty()){
            n = q.size();
            for(int i = 0 ; i < n; i++){
                curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return level;
    }
};
 
int main()
{
     
    return 0;
}
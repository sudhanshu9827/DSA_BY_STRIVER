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
int dfs(TreeNode* root , int &maxPath){
     if(!root)return 0;

     int left = dfs(root->left , maxPath);
     int right = dfs(root->right , maxPath);

     maxPath = max(maxPath , max(left + right + root->val , max(left + root->val , max(right +root->val , root->val))));

     return max(root->val, root->val + max(left , right)); 
}


// Remind mathod 
class Solution2 {
    int dfs(TreeNode* root , int &maxPath){
        if(!root)return 0;

        int left = max(0 , dfs(root->left , maxPath));
        int right =max(0 , dfs(root->right , maxPath));

        maxPath = max(maxPath , left + right + root->val);

        return max(left , right) + root->val; 
    }
    public:
        int maxPathSum(TreeNode* root) {
            int maxPath = INT_MIN;
            dfs(root , maxPath);

            return maxPath;
        }
};
    
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root , maxPath);

        return maxPath;
    }
};
 
int main()
{
     
    return 0;
}
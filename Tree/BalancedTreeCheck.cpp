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
    int maxDepth(TreeNode* root) {
        int maxi = 0 ;
        if(root){
            maxi = 1 + max(maxDepth(root->left) , maxDepth(root->right));
        }
        return maxi;
}
public:
    bool isBalanced(TreeNode* root) {
        bool check=  true;
        if(root){
            int depth_left = maxDepth(root->left) - maxDepth(root->right);
            check = abs(depth_left) > 1 ? false : isBalanced(root->left) && isBalanced(root->right);
        }
        return check;
    }
};

// ek baar me dono nikaalo neeche jaana hai sabse pehele and then phir too kaam hii hoagyaa 
class Solution {
    pair<bool , int> dfs(TreeNode* root){
        if(!root)return {true , 0};

        auto [leftBalanced , leftHeight] = dfs(root->left);
        auto [rightBalanced , rightHeight] = dfs(root->right);

        bool isBalanced = leftBalanced & rightBalanced & abs(leftHeight - rightHeight) <=1;

        return {isBalanced , 1 + max(leftHeight , rightHeight)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
 
int main()
{
     
    return 0;
}
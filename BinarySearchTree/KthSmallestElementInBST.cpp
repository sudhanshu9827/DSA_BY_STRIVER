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
    void Inorder(TreeNode * root , vector<int>& inorder){
        if(!root)return;

        Inorder(root->left  , inorder);
        inorder.push_back(root->val);
        Inorder(root->right , inorder);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;

        Inorder(root , inOrder);

        return inOrder[k - 1];
    }
};

// Can you do it inplace this is a major question 

class Solution {
    void Inorder(TreeNode * root , int& val , int &posEle , int k){
        if(!root)return;
        Inorder(root->left  , val , posEle , k);
        posEle++;

        if(posEle == k){
            val = root->val;
            return;
        }

        Inorder(root->right , val , posEle , k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val;

        int posEle = 0;

        Inorder(root ,val , posEle , k);

        return val;
    }
};
 
int main()
{
     
    return 0;
}
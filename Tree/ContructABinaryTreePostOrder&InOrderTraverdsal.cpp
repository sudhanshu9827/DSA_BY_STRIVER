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
     void IndexMapper(vector<int>inorder , unordered_map<int , int> &ump){
        for(int i = 0 ; i < inorder.size() ; i++){
            ump[inorder[i]] = i;
        }
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int > ump;
        IndexMapper(inorder , ump);

        return buildTree(postorder , postorder.size() - 1 , 0 , inorder , 0 , inorder.size() - 1, ump);
    }

    TreeNode* buildTree(vector<int>& postOrder , int postEnd , int postStart , vector<int>& inorder , int inStart , int inEnd , unordered_map<int, int>& ump){
        if(postStart > postEnd || inStart > inEnd)return NULL;

        int nodeValue = postOrder[postEnd];

        TreeNode * root = new TreeNode(nodeValue);

        int nodePosition = ump[nodeValue];

        int rightSubTreeSize = inEnd - nodePosition;

        root->left = buildTree(postOrder , postEnd - rightSubTreeSize -1 , postStart , inorder , inStart , nodePosition - 1, ump);
        root->right = buildTree(postOrder , postEnd - 1 , postEnd - rightSubTreeSize ,inorder ,  nodePosition + 1 , inEnd , ump);

        return root;

    }
};

 
int main()
{
     
    return 0;
}
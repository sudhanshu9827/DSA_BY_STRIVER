#include <bits/stdc++.h>
using namespace std;

//? Today : 13-10-2026

// Todo : Today i will implement 7 questions and complete binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// I know the method everybody know ! what will i do to implement it on the code 
//Its quite be challenging 

// Recursive too karna hai indexex of new tree bhi dene padegi but its quite difficult without practise to get the idea of generating binary tree from these traversal



class Solution {

    void IndexMapper(vector<int>inorder , unordered_map<int , int> &ump){
        for(int i = 0 ; i < inorder.size() ; i++){
            ump[inorder[i]] = i;
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int > ump;
        IndexMapper(inorder , ump);

        return buildTree(preorder , 0 , preorder.size() - 1, inorder , 0 , inorder.size() - 1 , ump);
    }


    TreeNode* buildTree(vector<int>& preOrder , int preStart , int preEnd , vector<int>&inorder , int inStart , int inEnd , unordered_map<int , int>& ump){
        // if(// if does'nt satisfies then child should be null)

        // Try to dry run get the idea 

        if(preStart > preEnd || inStart > inEnd)return nullptr;

        int nodeValue = preOrder[preStart];

        TreeNode * root = new TreeNode(nodeValue);

        int NodePosition = ump[nodeValue];

        int leftSubtreeLength = NodePosition - inStart;

        root->left = buildTree(preOrder , preStart + 1 , preStart + leftSubtreeLength , inorder , inStart , NodePosition - 1 , ump);
        root->right = buildTree(preOrder , preStart + leftSubtreeLength + 1 , preEnd , inorder , NodePosition + 1 , inEnd , ump);

        return root;
    }
};
 
int main()
{
     
    return 0;
}
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
    void mappingInorderWithIndex(vector<int>& inorder , unordered_map<int , int>& ump){
    for(int i = 0; i < inorder.size(); i++){
        ump[inorder[i]] = i;
    }
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin() , inorder.end());

        unordered_map<int , int> ump;

        mappingInorderWithIndex(inorder , ump);

        return bstMaker(preorder , 0 ,n-1 , inorder , 0  , n-1 , ump);
    }


    TreeNode * bstMaker(vector<int>& preorder , int preStart , int preEnd , vector<int>inorder , int inStart , int inEnd , unordered_map<int , int>& ump){
        // some condition for ending recursive call 
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        int val = preorder[preStart];

        TreeNode * root = new TreeNode(val);

        int posOfValInorder = ump[inorder[val]];

        int nextOrderLength = posOfValInorder - inStart;

        TreeNode * left = bstMaker(preorder , preStart + 1 , preStart + nextOrderLength , inorder , inStart , posOfValInorder - 1 , ump);

        TreeNode * right = bstMaker(preorder , preStart + nextOrderLength + 1 , preEnd , inorder ,posOfValInorder + 1 , inEnd  ,ump);

        root->left = left;
        root->right = right;

        return root;
    }
};

 
int main()
{
     
    return 0;
}
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


class BSTIterator {
    void inOrder(TreeNode * root , vector<int>& inorder){
        if(!root)return;

        inOrder(root->left , inorder);
        inorder.push_back(root->val);
        inOrder(root->right , inorder);
    }
public:
    vector<int> inorder;
    int size = 0;
    int index = 0;
    BSTIterator(TreeNode* root) {
        inOrder(root , inorder);
        size = inorder.size();
    }
    
    int next() {
        if(index < size){
            return inorder[index++];
        }
        return -1;
    }
    
    bool hasNext() {
        if(index < size) return true;
        return false;
    }
};


// Interviewer asked you are not allowed to store the inorder traversal how do you solve the question now 
// We need to solve in O(H)=>space complexity 

// so we may create an stack which store the elements like left left ----- then somebody calls next the first element will be the element 
// but next me dekhna padega ki kisi kaa right too nhi aa raha ussse bhi phir left left jaana  padega 


// I dont think ki upper waale se bhi aacha kuch hoo sakta hai but exist 

// ! Quite Intutive (Mazza aa gaya yeh soln karke)
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode * node = st.top();
        st.pop();

        // right me too kuch nhi hai warna daaldo  This is quite intutive 

        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};
 
int main()
{
     
    return 0;
}
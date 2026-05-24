#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// Very Intutive try :

class Solution {
    bool isLeaf(Node * node){
        if(!node->left && !node->right)return true;
        return false;
    }
    
    
    void addLeftBoundary(Node * node , vector<int>& res){
        while(node){
            if(!isLeaf(node))res.push_back(node->data);
            if(node->left)node = node->left;
            else node = node->right;
        }
    }
    
    void addRightBoundary(Node * node , vector<int>& res){
        stack<int> st;
        while(node){
            if(!isLeaf(node))st.push(node->data);
            if(node->right)node = node->right;
            else node = node->left;
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }
    
    void leafNodes(Node * node , vector<int>& res){
        // apply inorder traversal
        if(node){
            leafNodes(node->left , res);
            if(isLeaf(node))res.push_back(node->data);
            leafNodes(node->right , res);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
       if(!root)return res;
       if(isLeaf(root))return {root->data};
       
        res.push_back(root->data);
       
       // ! It can be divided into three parts boundaries lelu left + right + leaf nodes le lu kisi bhi traversal se joo left to right jaaye 
       // according to me it can be preOrder as well inOrder
       
       addLeftBoundary(root->left , res);
       leafNodes(root , res);
       addRightBoundary(root->right , res);
       
       return res;
    }
};
 
int main()
{
     
    return 0;
}
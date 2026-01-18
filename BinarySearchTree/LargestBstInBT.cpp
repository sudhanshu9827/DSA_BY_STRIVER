#include <bits/stdc++.h>
using namespace std;


/* Tree node structure  used in the program */

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// !This is a brute force approach Which is giving TLE

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bool checkBst(Node * curr, long long  min , long long max){
        if(!curr)return true;
        
        if(curr->data > min && curr->data < max)return checkBst(curr->left , min , curr->data) and checkBst(curr->right , curr->data , max);
    
        else return false;
    }
    
    int countNodes(Node * root){
        if(!root)return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int largestBst(Node *root) {
        // Your code here
        queue<Node*> q;
        
        q.push(root);
        int maxi = INT_MIN;
        
        while(!q.empty()){
            Node * curr = q.front();
            q.pop();
            
            if(checkBst(curr , (long long)INT_MIN -1 , (long long)INT_MAX + 1)){
                maxi = max(countNodes(curr) , maxi);
            }
            
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        return maxi;
    }
};

// Interviewer would be happy if you tell him/her a better approach 

// What could be the basic intution behind the optimization 

// when we called a node is satisfied bst property 

// when all nodes max(to its left) < root->val and min(all nodes to right) are greater then we can say node 

//so take at each step min and max while computing 

// how do i use post order traversal we want size as well store these 3 can help us to understand the question 

class NodeValue{
    public:
        int maxNode , minNode , maxSize;

        NodeValue(int maxNode , int minNode , int maxSize){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
        }
};


class Solution {

    NodeValue largestBstHelper(Node * root){
        if(!root)return NodeValue(INT_MIN , INT_MAX , 0);

        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);

        // current node is greater than max in left and smaller than min in right

        if(root->data > left.maxNode && root->data < right.minNode){
            // It is BST 
            return NodeValue(max(root->data , right.maxNode) , min(root->data , left.minNode) , left.maxSize + right.maxSize + 1);
        }

        return NodeValue(INT_MAX , INT_MIN , max(left.maxSize , right.maxSize));
    }

  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return largestBstHelper(root).maxSize;
    }
};

int main()
{
     
    return 0;
}
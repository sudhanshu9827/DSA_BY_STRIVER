#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Recursion makes life easy though binary tree left nikaal lenege right daal denge 
// ! Solved 
class Solution {
    void rootToLeaf(Node* root , vector<int>& path , vector<vector<int>>&ans){
        if(!root || (!root->left && !root->right)){
            ans.push_back(path);
            return;
        }
        if(root->left){
            path.push_back(root->left->data);
            rootToLeaf(root->left , path, ans);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->data);
            rootToLeaf(root->right , path , ans);
            path.pop_back();
        }
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> path;
        vector<vector<int>> ans;
        if(!root)return ans;
        
        path.push_back(root->data);
        
        rootToLeaf(root , path , ans);
        
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
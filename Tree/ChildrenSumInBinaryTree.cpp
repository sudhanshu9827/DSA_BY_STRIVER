#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
    
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root)return true;
        
        
        Node * left = root->left;
        Node * right = root->right;
        
        if(!left && !right)return true;
        

        // if(!left && !right && root->data || !left && right || !right && left || root->data != left->data + right->data)return false;
        
    if(!left &&  right && root->data != right->data || !right && left && root->data != left->data || left && right && root->data !=left->data + right->data) return false;
        
        bool check = isSumProperty(root->left) && isSumProperty(root->right);
        
        return check;
        
    }
};
 
int main()
{
     
    return 0;
}
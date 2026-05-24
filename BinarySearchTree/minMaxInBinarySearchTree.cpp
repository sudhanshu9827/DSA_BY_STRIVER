#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    int minValue(Node* root) {
        
        if(!root->left)return root->data;
        
        return minValue(root->left);
    }
};
 
int main()
{
     
    return 0;
}
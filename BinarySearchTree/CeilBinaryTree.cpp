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
    void Ceil(Node* root , int x , int& ceilVal){
        if(!root || !root->right && root->data < x){
            return;
        }
        
        if(root->data == x){
            ceilVal = x;
            return;
        } 
        
        else if(root->data > x){
            ceilVal = min(ceilVal , root->data);
            Ceil(root->left , x , ceilVal);
        }
        
        else{
            Ceil(root->right , x , ceilVal);
        }
        
        
    }
  public:
    int findCeil(Node* root, int x) {
        int ceilVal = INT_MAX;
        Ceil(root , x , ceilVal);
        
        return ceilVal == INT_MAX ? -1 : ceilVal;
    }
};

 
int main()
{
     
    return 0;
}
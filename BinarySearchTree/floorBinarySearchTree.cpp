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
    void Floor(Node* root , int x , int& floorVal){
        if(!root || !root->left && root->data > x){
            return;
        }
        
        if(root->data == x){
            floorVal = x;
            return;
        } 
        
        else if(root->data < x){
            floorVal = max(floorVal , root->data);
            Floor(root->right , x , floorVal);
        }
        
        else{
            Floor(root->left , x , floorVal);
        }
        
        
    }
    
  public:
    int floor(Node* root, int x) {
        int floorVal = INT_MIN;
        
        Floor(root , x , floorVal);
        
        return floorVal == INT_MIN ? -1 : floorVal;
        
    }
};
 
int main()
{
     
    return 0;
}
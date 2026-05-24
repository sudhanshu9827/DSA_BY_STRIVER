#include <bits/stdc++.h>
using namespace std;

/* BST Node */
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    void Find(Node * root , int key , Node *&pred , Node *&succ){
        if(!root)return;
        
        if(root->data <= key){
            //It may be the predecessor
            if(root->data!= key && (!pred || pred->data < root->data)){
                pred = root;
            }
            Find(root->right , key , pred , succ);
        }
        
        if(root->data >= key){
            if( root->data!= key && (!succ || succ->data > root->data)){
                succ = root;
            }
            Find(root->left ,key ,  pred , succ);
        }
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node * pred = nullptr;
        Node * succ = nullptr;
        
        Find(root , key , pred , succ);
        
        return {pred , succ};
        
    }
};
 
int main()
{
     
    return 0;
}
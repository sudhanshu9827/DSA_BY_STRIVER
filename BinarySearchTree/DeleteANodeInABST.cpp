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

// Delete can have three possibilites 
// 1. the root is null 
// 2. It may have only single child 
// 3. it have 2 childs 
// ;;

  // !NOT CORRECT
// // class Solution {
// // public:
// //     TreeNode* deleteNode(TreeNode* root, int key) {
// //         if(!root)return root;

// //         else if(root->val > key){
// //              return deleteNode(root->left , key);
// //         }

// //         else if(root->val < key){
// //             return deleteNode(root->right , key);
// //         }

// //         else if(root->val == key && !root->left){
// //             root = root->left;
// //             return root;
// //         }

// //         else if(root->val == key && !root->right){
// //             root = root->right;
// //             return root;
// //         }

// //         else if(root->val == key){
// //             // chahe too left ke right most me chale jaao yaa phir right ke left most me chale jaao 
// //             successor dhund loo yaa phir predecessor dhund loo 

// //             TreeNode * curr = root ->left;
// //             TreeNode* prev = root;

// //             while(curr->right){
// //                 prev = curr;
// //                 curr = curr->right;
// //             }

// //             swap(curr->val , root->val);

// //             prev->right = nullptr;

// //             return root;
// //         }
// //     }
// // };


// if neeche gaya recursively aur ek bhi child nhi hai too pehle usko purely delete kardo par uske prev me too values hongi naa ussko kaise hatayenge 

class Solution {
    void deleteNode(TreeNode *&root , int key , TreeNode *&prev){

        if(!root)return;

        if(root->val > key){
            deleteNode(root->left , key , root);
        }

        else if(root->val < key){
            deleteNode(root->right , key , root);
        }

        else if(root->val == key && (!root->left && !root->right)){
            if(prev->left == root){
                prev->left = nullptr;
            }
            else{
                prev->right = nullptr;
            }
        }

        else if(root->val == key && !root->left){
            root = root->right;
        }

        else if(root->val == key && !root->right){
            root = root->left;
        }

        else if(root->val == key && root->left && root->right){

            // left se rightmost ki taraff jaa raha hu predecessor le raha hu 
            TreeNode * ptr = root->left;
            TreeNode * prev = root;

            while(ptr->right != nullptr){
                prev = ptr;
                ptr = ptr->right;
            }

            swap(root->val , ptr->val);

            TreeNode * left = ptr->left;

            if(prev == root){
                prev->left = left;
            }

            else{
                prev->right = left;
            }
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root || (root->val!=key && !root->left && !root->right))return root;

        else if(root->val == key && !root->left && !root->right){
            delete(root);
            return nullptr;
        }

        deleteNode(root , key , root);
        return root;
    }
};
 
int main()
{
     
    return 0;
}
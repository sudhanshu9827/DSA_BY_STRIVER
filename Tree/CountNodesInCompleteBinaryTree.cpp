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


// We can easily do this question in O(n) time by any traversal 

// ? Can we do it less than O(n) Time Complexity

class Solution {
    void traversal(TreeNode* root , int &count){
        if(!root)return;

        count++;
        traversal(root->left , count);
        traversal(root->right , count);
    }
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        traversal(root , count);

        return count;
    }
};

// Logn time complexity toda saa dimaag lagana tha 
class Solution {
    int heightLeft(TreeNode * root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }

    int heightRight(TreeNode * root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int left = heightLeft(root);
        int right = heightRight(root);

        if(left == right){
            return (1<<left) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
     
    return 0;
}
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


// This Soltion is wrong i am checking with only preorder yaa too 2 se check karo 

// class Solution {
//     void findPreorder(TreeNode* node , vector<int>& preOrder){
//         if(node){
//             findPreorder(node->left , preOrder);
//             preOrder.push_back(node->val);
//             findPreorder(node->right , preOrder);
//         }
//         return;
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<int> preOrderP;
//         vector<int> preOrderQ;


//         findPreorder(p , preOrderP);
//         findPreorder(q , preOrderQ);

//         // for(int i : preOrderP)cout<<i<<" ";
//         // cout<<endl;
//         // for(int i : preOrderQ)cout<<i<<" ";

//         if(preOrderP == preOrderQ)return true;
//         return false;
//     }
// };

class Solution {

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;

        if(!p and q or !q and p)return false;

        if(p->val != q->val){
            return false;
        }
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};
 
int main()
{
     
    return 0;
}
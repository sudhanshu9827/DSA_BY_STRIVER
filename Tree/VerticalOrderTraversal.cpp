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

// ! I know map is not the correct concept here but i wanna did the question using map 

// ? Failed at we need to sort only when there are more than one element at the same row and column

// Nice Attempt i appreciate ! 

class Solution {
    void traversal(TreeNode * root , map<int , vector<int>> &mp , int currCol){
        if(root){
            mp[currCol].push_back(root->val);
            if(root->left) traversal(root->left , mp , currCol - 1);
            if(root->right)traversal(root->right , mp , currCol + 1);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<int , vector<int>> mp;
        traversal(root , mp , 0);

        for(auto it : mp){
            sort(it.second.begin() , it.second.end());
            ans.push_back(it.second);
        }

        return ans;
    }
};
int main()
{
     
    return 0;
}
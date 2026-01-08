#include <bits/stdc++.h>
using namespace std;
#define vvl vector<vector<int>>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Method 1 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0;i<size ; i++){
                TreeNode* node = q.front();

                level.push_back(q.front()->val);
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


// Method 2 
class Solution {

    vvl levelOrderTraversal(TreeNode* root){
        if(!root)return {};
        vvl levelOrder;

        queue<TreeNode*> currentLevel;

        currentLevel.push(root);

        while(!currentLevel.empty()){

            queue<TreeNode*>currNodes = currentLevel;
            vector<int>level;

            while(!currNodes.empty()){
                TreeNode* curr = currNodes.front();
                currNodes.pop();
                currentLevel.pop();

                level.push_back(curr->val);
                if(curr->left)
                    currentLevel.push(curr->left);
                if(curr->right)
                    currentLevel.push(curr->right);
            }
            levelOrder.push_back(level);
        }
        return levelOrder;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};
 
int main()
{
     
    return 0;
}
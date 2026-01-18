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


// mapping child to parent for back level order traversal 


class Solution {

    void MapChildToParent(TreeNode * root , unordered_map<TreeNode * , TreeNode *>& ump){
        if(!root)return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
                ump[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                ump[curr->right] = curr;
            }
        }
    } 

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        if(!root) return {};

        unordered_map<TreeNode* , bool> visited;

        unordered_map<TreeNode *, TreeNode*> ump;
        MapChildToParent(root , ump);

        q.push(target);
        visited[target] = true;

        int size;
        int level = 0;

        while(!q.empty() && level != k){
            size = q.size();
            level++;
            for(int i = 0 ; i < size ; i++){
                TreeNode * curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                //root par pahuch gaya uska too koi nhi hai naa
                // ! Yeh aacha laga sochna ki ek root ke liye harr baar check karna hai 
                if(ump[curr] && !visited[ump[curr]]){
                    q.push(ump[curr]);
                    visited[ump[curr]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
 
int main()
{
     
    return 0;
}
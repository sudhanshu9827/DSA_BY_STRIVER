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


// Method is really very intutive but not the correct one 
//Interviewer said please dont use the function reverse 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> order;
        if(!root)return order;

        queue<TreeNode*> q;
        q.push(root);

        bool rev = true;
        int n ;

        while(!q.empty()){
            vector<int> currLevel;
            n = q.size();
            
            for(int i = 0 ; i < n;i++){
                TreeNode* curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);

                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            rev = !rev;

            if(rev){
                reverse(currLevel.begin() , currLevel.end());
            }

            order.push_back(currLevel);
        }
        return order;
    }
};


// method which is more intutive joo zigzag karne me madad karega boo deque kaa idea hai 
// hell0 


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;

        deque<TreeNode*> dq;
        dq.push_back(root);

        bool reverse = false;

        while(!dq.empty()){
            int size = dq.size();
            vector<int> level;

            for(int i = 0 ; i < size ; i++){
                if(!reverse){
                    TreeNode* node = dq.front(); dq.pop_front();
                    level.push_back(node->val);

                    if(node->left)dq.push_back(node->left);
                    if(node->right)dq.push_back(node->right);
                }
                else{
                    TreeNode* node = dq.back();dq.pop_back();
                    level.push_back(node->val);

                    if(node->right)dq.push_front(node->right);
                    if(node->left)dq.push_front(node->left);
                }
            }
            res.push_back(level);
            reverse = !reverse;
        }
        return res;
    }
};

int main()
{
     
    return 0;
}
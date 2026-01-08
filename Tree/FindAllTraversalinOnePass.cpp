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

//Basic idea is that is maintains state like for pre -> 1 , in -> 2 , post -> 3 
//I should remember some of the things one of these is this


class Solution{
    public:
        vector<vector<int>> preInPostTraversal(TreeNode* root){
            vector<vector<int>> traversal;
            vector<int> pre , in , post;

            stack<pair<TreeNode* , int>> st;
            
            st.push({root , 1});

            while(!st.empty()){
                auto it = st.top();

                if(it.second == 1){
                    pre.push_back(it.first->val);
                    it.second = 2;

                    if(it.first->left){
                        st.push({it.first->left , 1});
                    }
                }

                else if(it.second == 2){
                    in.push_back(it.first->val);
                    it.second = 3;

                    if(it.first->right){
                        st.push({it.first->right , 1});
                    }
                }

                else{
                    post.push_back(it.first->val);
                    st.pop();
                }
            }
            traversal.push_back(pre);
            traversal.push_back(in);
            traversal.push_back(post);

            return traversal;
        }
};
 
int main()
{
     
    return 0;
}
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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Post order <Left Right Root> 
        if(!root)return {};
        vector<int> postOrder;
        stack<TreeNode*> order;

        TreeNode* curr = root;

        while(curr!=NULL || !order.empty()){
            // root right left nikaal loo usse ulta kar denge
            if(curr!=NULL){
                postOrder.push_back(curr->val);

                order.push(curr);
                curr= curr->right;
            }

            else{
                curr = order.top();
                order.pop();
                curr = curr->left;
            }
        }

        // reverse the soltuion 
        reverse(postOrder.begin() , postOrder.end());
        return postOrder;
    }
};

// second method we can use 2 stacks

class Solution{
    vector<int> postOrderTraversal(TreeNode* root){
        stack<TreeNode*> st1 ,st2;
        vector<int> postOrder;
        st1.push(root);

        TreeNode* curr; 

        while(!st1.empty()){
            curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left){
                st1.push(curr->left);
            }
            if(curr->right){
                st1.push(curr->right);
            }
        }

        while(!st2.empty()){
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }
};

// How do i do in a single stack 

// Basic intution is that we need to to go extreme left then right phir left if right nhi hai then uss samye waapis aate jaana hai 
//matlb kisi ke paas child nhi hai boo print hoga 

// ** 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return{};
        vector<int> postOrder;
        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* temp;

        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                //turant right ko dundiye
                temp = st.top()->right;
                if(temp == NULL){
                    // abb print karne kaa samye aaya hai
                    //right child bhi nhi hai 
                    // then 
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;// naaye tree jaisa behave karwaao
                }
            }
        }
        return postOrder;
    }
};
 
int main()
{
     
    return 0;
}
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
    void checkTarget(TreeNode * root , int k ,unordered_map<int , int>& ump , bool& found){
        if(!root){
            return;
        }

        if(ump.find(k - root->val)!=ump.end()){
            found = true;
            return;
        }

        ump[root->val] = 1;

        checkTarget(root->left , k , ump , found);
        checkTarget(root->right , k , ump , found);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int , int> ump;
        bool found = false;
        checkTarget(root , k , ump , found);

        return found;
    }
};

// what if we need to optimize and somebody said it is optimizable can you ? 

// purana wala iterator wala funda use kar sakte hai aur 2 pointer approach laga sakte hai 


class Solution {
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    int next(){
        TreeNode * node = st1.top();
        st1.pop();
        pushAllLeft(node->right);
        return node->val;
    }

    void pushAllLeft(TreeNode * root){
        while(root){
            st1.push(root);
            root = root->left;
        }
    }

    int before(){
        //right node left
        TreeNode * node = st2.top();
        st2.pop();
        pushAllRight(node->left);
        return node->val;
    }

    void pushAllRight(TreeNode * root){
        while(root){
            st2.push(root);
            root = root->right;
        }
    }


public:
    bool findTarget(TreeNode* root, int k) {
        pushAllLeft(root);
        pushAllRight(root);

        int leftVal = next();
        int rightVal = before();

        while(!st1.empty() && !st2.empty() && leftVal < rightVal){
            if(leftVal + rightVal == k)return true;

            else if(leftVal + rightVal < k){
                leftVal = next();
            }
            else{
                rightVal = before();
            }
        }

        return false;
    }
};

// But in bestPractise you are not allowed to initialize the global variable 

//! so it suggested that make a single iterator which works for both and with extra parameter reverse (According to Striver)
 

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse = false;
    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = !reverse ? root->left : root->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool reverse = false) : reverse(reverse) {
        pushAll(root);
    }
    int next() {
        TreeNode* top = st.top(); st.pop();
        pushAll(!reverse ? top->right : top->left);
        return top->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftItr(root), rightItr(root, true);
        int left = leftItr.next(), right = rightItr.next();
        while (left < right) {
            if (left + right == k) return true;
            if (left + right < k)
                left = leftItr.next();
            else
                right = rightItr.next();
        }
        return false;
    }
};

int main()
{
     
    return 0;
}
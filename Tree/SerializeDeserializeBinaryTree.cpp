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

// Todo Try with level order traversal 


// I am geeting while serialize i can apply any traversal and append into string but kya me alag alag identify kaise kar raha hounga 
// this is a major question how do i identify like one node + second node kuch too seprator chahiye joo bataye

class Codec {
    void preOrderTraversal(TreeNode * root , string& preOrder){
        if(!root){
            preOrder += "#,";
            return;
        }
        int value = root->val;
        preOrder += to_string(value) + ',';
        preOrderTraversal(root->left , preOrder);
        preOrderTraversal(root->right , preOrder);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preOrderTraversal(root , s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // joo mujhe nhi aa raha doo comma ke beech me se value uthani hai buss : soln loop chala kar check kar loo ki comma kaha hai 
        // deserilization is bit tricky for me 
        // stringstream ka sakte hai , chahe too 
        
        queue<string> q;

        string token = "";

        for(char c : data){
            if(c==','){
                q.push(token);
            }
        }

        return deserializeHelper(q);
    }

// jaise serialize kiya hai ussi tareeke se deserialize kar doo 

    TreeNode * deserializeHelper(queue<string>& q){
        string curr = q.front();
        q.pop();

        if(curr == "#")return nullptr;
        TreeNode * root = new TreeNode(stoi(curr));

        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);

        return root;
    }
};


//! Given by leetCode 
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
 
int main()
{
     
    return 0;
}
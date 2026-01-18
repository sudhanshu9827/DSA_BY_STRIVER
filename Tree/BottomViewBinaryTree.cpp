#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// solved 
// Intution is last ka utha loo har level order se 

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if(!root)return {};
        // code here
        map<int , vector<int>> mp;
        queue<pair<Node* , int>> q;
        
        q.push({root , 0});
        
        while(!q.empty()){
            auto [node , col] = q.front();
            q.pop();
            
            mp[col].push_back(node->data);
            
            if(node->left)q.push({node->left , col - 1});
            if(node->right)q.push({node->right , col + 1});
        }
        
        vector<int> ans;
        
        for(auto it : mp){
            ans.push_back(it.second.back());
        }
        
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
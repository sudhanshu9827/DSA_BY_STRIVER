#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/   

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ! I know map is not the correct concept here but i wanna did the question using map : i Found now it is correct but kuch too galti karri

// ? Failed at we need to sort only when there are more than one element at the same row and column

// if row alag alag hai then joo row pehle aai hai boo lena that means row ko bhi save karana padega 
// aur maan lo row bhi same hai then val ke base par compare hoga 

// Nice Attempt i appreciate ! 
/*
! class Solution {
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

*/

// correct 

class Solution {

    void traversal(TreeNode* root , vector<tuple<int , int , int>>& order , int row , int col){
        //applying inorder for easiness 
        if(!root)return;

        order.push_back({row , col , root->val});
        traversal(root->left , order , row + 1 , col - 1);
        traversal(root->right , order , row + 1 , col + 1);
    }


public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // [col , row , val]
        vector<tuple<int , int , int>> order;
        traversal(root , order , 0 , 0);

        sort(order.begin() , order.end());

        // [sort on basis of col row and val ]
        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for(auto it : order){
            auto [col , row , val] = it;
            if(prevCol!=col){
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }
};

// TODO : Do it using lavel order traversal 

int main()
{
     
    return 0;
}
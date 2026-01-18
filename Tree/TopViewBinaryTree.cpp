#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


// First Thought is wrong because bahut last me bhi element hoo sakta hai kisi ke right child ke left me usko consider karna hai 

// class Solution {
    
//     void leftSideNodes(Node * root , vector<int>& res){
//         if(root){
//             Node * curr = root->left;
//             while(curr){
//                 res.push_back(curr->data);
//                 curr = curr->left;
//             }
//             reverse(res.begin() , res.end());
//         }
//     }
    
//     void rightSideNodes(Node* root , vector<int>& res){
//         if(root){
//             Node * curr = root->right;
//             while(curr){
//                 res.push_back(curr->data);
//                 curr = curr->right;
//             }
//         }
//     }
    
//   public:
//     vector<int> topView(Node *root) {
//         vector<int> res;
//         leftSideNodes(root , res);
//         res.push_back(root->data);
//         rightSideNodes(root , res);
        
//         return res;
//     }
// };

// For some test cases this is not working i dont know why quite not get the answer of why 

class Solution {
    
     void traversal(Node* root , vector<tuple<int , int , int>>& order , int row , int col){
        //applying inorder for easiness 
        if(!root)return;

        order.push_back({col , row , root->data});
        traversal(root->left , order , row + 1 , col - 1);
        traversal(root->right , order , row + 1 , col + 1);
    }
    
  public:
    vector<int> topView(Node *root) {
       // [col , row , val]
        vector<tuple<int , int , int>> order;
        traversal(root , order , 0 , 0);

        sort(order.begin() , order.end());

        // [sort on basis of col row and val ]
        vector<int> res;
        int prevCol = INT_MIN;

        for(auto it : order){
            auto [col , row , val] = it;
            if(prevCol!=col){
                res.push_back(val);
                prevCol = col;
            }
        }
        
        return res;
    }
};


// lets use actuall mathod whih is preferable in level order traversal 


class Solution {
  public:
    vector<int> topView(Node *root) {
        // lets do it 
        // node->col 
        vector<int> res;
        queue<pair<Node* , int>> q;
        // map<col , val > 
        map<int , int >colMap;

        q.push({root , 0});

        while(!q.empty()){
            auto [node , col] = q.front();
            q.pop();

            if(colMap.find(col) == colMap.end()){
                // res.push_back(node->data); incorrect because ordered me chahiye alag se loop chalao 
                colMap[col] = node->data;
            }

            if(node->left)q.push({node->left , col - 1});
            if(node->right)q.push({node->right , col + 1});
        }

        for(auto it : colMap){
            res.push_back(it.second);
        }

        return res;
    }
};
 
int main()
{
     
    return 0;
}
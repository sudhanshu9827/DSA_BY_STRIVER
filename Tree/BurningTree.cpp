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


class Solution {
    void mappingChildToParent(Node * root , unordered_map<Node* , Node*>& ump , int target , Node * &targetNode){
        if(!root)return;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target)targetNode = curr;

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
    int minTime(Node* root, int target) {
        // code here
        int seconds = -1;
        
        queue<Node*> q;
        
        Node * targetNode = nullptr;
        
        unordered_map<Node * , Node * > ump;
        mappingChildToParent(root , ump , target , targetNode);

        q.push(targetNode);
        
        unordered_map<Node* , bool > visited;
        
        visited[targetNode] = true;
        
        while(!q.empty()){
            int size = q.size();
            seconds++;
            for(int i = 0 ; i < size ; i++){
                Node * curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                
                if(ump[curr] && !visited[ump[curr]]){
                    q.push(ump[curr]);
                    visited[ump[curr]] = true;
                }
            }
        }
        return seconds;
    }
};
 
int main()
{
     
    return 0;
}

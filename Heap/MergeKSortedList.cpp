#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = nullptr;

        // comparison kaise kar raha hoga 
        priority_queue<ListNode* , vector<ListNode*> , greater<ListNode*>> minHeap;

        // boo kaise bataung ki boo kis list kaa node tha
        for(auto list : lists){
            minHeap.push(list);
        }

        ListNode * prev = new ListNode(-1);
        head = prev;
        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            if(curr->next!=nullptr){
                minHeap.push(curr->next);
            }
            prev->next = curr;
            prev = curr;
        }
        return head->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = nullptr;

        // comparison kaise kar raha hoga 
        priority_queue<ListNode* , vector<ListNode*> , greater<ListNode*>> minHeap;

        // boo kaise bataung ki boo kis list kaa node tha
        for(auto list : lists){
            minHeap.push(list);
        }

        priority_queue<ListNode* , vector<ListNode*> , greater<ListNode*>> minH;
        minH = minHeap;

        while(!minH.empty()){
            cout<<minH.top()->val<<endl;
            minH.pop();
        }
        

        ListNode * prev = new ListNode(-1);
        head = prev;
        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            if(curr && curr->next!=nullptr){
                minHeap.push(curr->next);
            }
            prev->next = curr;
            prev = curr;
            minHeap.pop();
        }
        return head->next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = nullptr;

        // comparison kaise kar raha hoga 
        priority_queue<ListNode* , vector<ListNode*> , cmp> minHeap;

        for(auto node : lists){
            //**Isko sochna muskil hai ki jab khaali hoga uske liye bhi chalega waha agar comparison hoga then error because koi memory hai hii  nhi aur usse access kar rahe hoo

            if(node)
                minHeap.push(node);
        }

        ListNode * prev = new ListNode(-1);
        head = prev;
        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            if(curr && curr->next!=nullptr){
                minHeap.push(curr->next);
            }
            prev->next = curr;
            prev = curr;
            minHeap.pop();
        }
        return head->next;
    }
};
int main()
{
     
    return 0;
}
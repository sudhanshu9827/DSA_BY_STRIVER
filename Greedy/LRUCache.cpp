#include <bits/stdc++.h>
using namespace std;

// class LRUCache{
//     int capacity;
//     unordered_map<int , pair<int , int>>ump;
//     int time = 0;
//     int size = 0;
//     public:
//     LRUCache(int cap){
//         capacity = cap;
//     }

//     int get(int key){
//         //need to return the value
//         if(ump.find(key)!=ump.end()){
//             ump[key].second = time;
//             time++;
//             return ump[key].first;
//         }
//     }

//     void put(int key , int value){
//         time++;
//         if(ump.find(key)!=ump.end()){
//             ump[key].first = value;
//             ump[key].second = time;
//         }
//         else{
//             if(size == capacity){
//                 // someone ko too nikalna padega jiska sabse kam time hai usko nikaal doo 
//                 for()
//                 //Wait a minute this will not give time complexity O(1)
//             }
//         }
//     }


// };
 

// Essa question kar chuka hu dimaag me bhi aaya tha phir soccha linked list me too traverse karna padega dhundne ke liye but nhi yrr hashmap me bhi too store karwa sakte hai 

// very good intution i can say 

// Their are multiple issues that i faced first second hope second time no error 

class node {
    public:
        int val;
        int key;
        node * next;
        node * prev;

        node(int v , int k){
            val = v; key = k;  next = NULL;prev = NULL;
        }
};

class LRUCache{
    int capacity;
    node * head;
    node * tail;
    //why dont you link the head and tail

    unordered_map<int , node*> ump;
    public:
        LRUCache(int cap){
            capacity = cap;
            head = new node(-1 , -1);
            tail = new node(-1 , -1);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key){
            if(ump.find(key)!=ump.end()){
                node * curr = ump[key];

                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                curr->next = head->next;
                head->next->prev = curr;
                head->next = curr;
                curr->prev = head;

                return curr->val;
            }

            return -1;
        }

        void put(int key , int value){
            if(capacity == 0) return;
            //yeh edge case abb dimaag me aana chahiye
            if(ump.find(key)!=ump.end()){
                // just ussko hatao aaage lagao 
                node * curr = ump[key];

                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                curr->next = head->next;
                head->next->prev = curr;
                head->next = curr;
                curr->prev = head;
                
                curr->val = value;
            }

            else{
                // not in the list
                node * curr = new node(value , key);

                ump[key] = curr;

                curr->next = head->next;

                head->next->prev = curr;
                head->next = curr;
                curr->prev = head;

                if(ump.size() > capacity){
                    node * deletedNode = tail->prev;
                    tail->prev = tail->prev->prev;
                    tail->prev->next = tail;
                    ump.erase(deletedNode->key);
                    delete(deletedNode);
                }
            }
        }

};

int main()
{
     
    return 0;
}
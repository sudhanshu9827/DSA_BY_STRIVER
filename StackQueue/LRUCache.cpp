#include <bits/stdc++.h>
using namespace std;

//Not completed yet

class LRUCache {
    class node{
        public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int k ,int value){
            key = k;
            val = value;
            next = NULL;
            prev = NULL;
        }
    };
public:
    int cap;
    unordered_map<int , node*> ump;
    node* head;
    node* tail;
    LRUCache(int capacity){
        // abb node yaha create hoga kyuki issi koo baar baar call 
        cap = capacity;
        head = new node(0 , 0);
        tail = new node(0 , 0);
    }
    
    int get(int key) {
        if(ump.find(key)!=ump.end()){
            del(key);
            insert(key);
            return ump[key]->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(ump.find(key)!=ump.end())del(key);
        node * newNode = new node(key , value);

        insert(key);
        ump[key] = newNode;

        if(ump.size() > cap){
            node * lru  = tail->prev;
            del(lru->key);
            ump.erase(lru->key);
            delete(lru);
        }
    }

    void del(int key){
        node * curr = ump[key];
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }

    void insert(int key){
        node * curr = ump[key];
        curr->next = head->next;
        head->next->prev = curr;
    }
};

 
int main()
{
     
    return 0;
}
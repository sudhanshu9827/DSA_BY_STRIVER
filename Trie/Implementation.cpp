#include <bits/stdc++.h>
using namespace std;

// we will have structure for trie data set 

// when will i use trie 

// => simple intution 
// prefix-based retrieval of strings,
// TC : O(m) where m is the length of the string  
//  It is best suited for auto-complete systems, spell checkers, IP routing 
struct Node{
    Node * links[26];
    bool flag;

    // firstly we should have to initialize it will every link to NULL

    Node(){
        for(int i = 0 ; i < 26; i++){
            links[i] = NULL;
        }
        flag = false;
    }


    bool containsKeyWord(char ch){
        if(links[ch -'a']!=NULL) return true;
        return false;
    }

    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isLast(){
        return flag == true;
    }

};

class Trie {
    Node * root;
public: 
    Trie() {
        // create a new node 
        root = new Node();
    }
    
    void insert(string word) {
        // find it in root 
        Node * node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKeyWord(word[i])){
                // now putt this word in list and create a new referencing node 
                Node * newNode = new Node;
                node->put(word[i] , newNode);
                node = newNode;
            }
            else{
                node = node->get(word[i]);
            }
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKeyWord(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        // at the end we get true return true
        return node->isLast();
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!node->containsKeyWord(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }
};


int main() {
    
    return 0;
}
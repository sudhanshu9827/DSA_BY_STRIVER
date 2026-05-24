#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node * links[26];
    int flag;;
    int prefixCount;

    // firstly we should have to initialize it will every link to NULL

    Node(){
        for(int i = 0 ; i < 26; i++){
            links[i] = NULL;
        }
        flag = 0;
        prefixCount = 0;

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

    void delReference(char ch){
        links[ch -'a'] = NULL;
    }

    void setEnd(){
        flag++;
    }

    void decEnd(){
        flag--;
    }

    bool isLast(){
        return flag >= 1;
    }

    void incCount(){
        prefixCount++;
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
            node->incCount();
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

    int countWordsEqualTo(string word){
        Node * node = root;
        for(int i = 0 ; i < word.size();i++){
            if(!node->containsKeyWord(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->flag;
    }

    int countWordsStartingWith(string prefix){
        Node* node = root;
        int i = 0;
        for(i = 0 ; i < prefix.size(); i++){
            if(!node->containsKeyWord(prefix[i]))return 0;
            node = node->get(prefix[i]);
        }

        return node->prefixCount;
    }

    void erase(string word){
        //for erasing word should be present first 

        // if last ki reference me kuch bhi nhi hai then should delete this reference otherwise just decrease the count

        if(!search(word))return;
        else{
            // Now delete 
            Node * node = root;
            Node* next;
            int i;

            for(i = 0 ; i < word.size() ; i++){
                next = node->get(word[i]);
                next->prefixCount--;
                node = next;
            }

            node->flag--;
            // check all NULL thoo nhi hogaye otherwise delete this reference
            //just check the count 
        }

    }
};

int main() {
    
    return 0;
}
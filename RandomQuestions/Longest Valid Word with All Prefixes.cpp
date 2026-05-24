#include <bits/stdc++.h>
using namespace std;

// For prefix computation and checking trie should be best 

struct Node{
    Node *links[26];
    bool flag;

    Node(){
        for(int i = 0 ; i < 26 ; i++){
            links[i] = NULL;
        }
        flag = false;
    }

    bool containsChar(char ch){
        if(links[ch - 'a']==NULL) return false;
        return true;
    }

    void put(char ch , Node * newNode){
        links[ch - 'a'] = newNode;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    } 
};

class Trie{
    public:
    Node * root;
    Trie(){
        root = new Node();
    }

    void insertWord(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsChar(ch)){
                //now made a reference and put new node to that reference 
                node->put(ch , new Node);
                node = node->get(ch);
            }
            else{
                node = node->get(ch);
            }
        }
        node->flag = true; // last node 
    }

    bool searchWord(string& word){
        Node * node = root;

        for(char ch : word){
            if(!node->containsChar(ch)) return false;
            node = node->get(ch);
        }

        return node->flag == true;
    }

    bool searchPrefix(string prefix){
        Node * node = root;

        for(char ch : prefix){
            if(!node->containsChar(ch))return false;

            node= node->get(ch);
        }

        return true;
    }
};

class Solution {

    static bool comp(const string& word1 ,const string& word2){
        if(word1.size()!=word2.size())return word1.size() < word2.size();
        else return word1 < word2;
    }

    string longestValidWord(vector<string>& words) {
        // #sort the words by length
        int n = words.size();
        sort(words.begin() , words.end() , comp);

        Trie t;

        for(int i = 0 ; i < n ; i++){
            t.insertWord(words[i]);
        }

        // Now all the words have successfully insert just check its every prefix exist or not 

        int wordSize = 0;
        string finalWord = "";

        for(int i = 0 ; i < n ; i++){
            string prefix = "";
            int j;
            int currWordSize = words[i].size();
            for(j = 0 ; j < currWordSize; j++){
                char ch = words[i][j];
                prefix +=ch;
                if(!t.searchWord(prefix))break;
            }
            if(j == currWordSize){
                if(wordSize < currWordSize){
                    wordSize = currWordSize;
                    finalWord = words[i];
                }
            }
        }
        return finalWord;
    }
};


int main() {


    
    return 0;
}
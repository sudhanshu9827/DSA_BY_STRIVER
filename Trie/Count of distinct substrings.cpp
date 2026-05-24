#include <bits/stdc++.h>
using namespace std;

// BF : just find all the substring and save it into the set 
// TC : O(N2 log(m)); where m is the length of the string m is varying here we cannot compute the exact time complexity 

// This solution gives TLE 

// What about SC : O(n2)=> for total number of substrings and assume avarage size is something about n/2 then O(n3) somewhat
class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        set<string> ss;

        for(int i = 0 ; i < n ; i++){
            string sub = "";
            for(int j = i; j < n ; j++){
                sub+=s[j];
                ss.insert(sub); // dont forget in set insert take O(logn) Time complexity 
            }
        }

        return ss.size();
    }
};

// what you do enhance the tc of soln 

// prefix ka use hoo raha hai jab trie ka dimaag me aata hai 

// s = "ababa"  trie me store kara denge all values then check karlo kitne nodes hai bus jitne nodes honge utni hii different substring hongin what say 
// Does it take less time complexity then above lets try it first 



// IT WORKS 
struct Node{
    Node * links[26];
    
    Node(){
        for(int i = 0 ; i < 26 ; i++){
            links[i] = NULL;
        }
    }

    bool isPresent(char ch){
        if(links[ch - 'a']!=NULL)return true;
        return false;
    }

    void put(char ch , Node * newNode){
        links[ch - 'a'] = newNode;
    }

    Node * get(char ch){
        return links[ch - 'a'];
    }
};


class Trie{
    public:
    Node * root;
    int countNode = 0;

    Trie(){
        root = new Node();
    }


    void insertWord(string& word){
        Node * node = root;

        for(char ch : word){
            if(!node->isPresent(ch)){
                node->put(ch , new Node());
                node = node->get(ch);
                countNode++;
            }
            else{
                node = node->get(ch);
            }
        }
    }
};



class Solution {
  public:
    int countSubs(string& s) {
        // code here
        int n = s.size();

        Trie t;

        string word = "";
        for(int i = n - 1 ; i >=0 ; i--){
            word+=s[i];
            reverse(word.begin(), word.end());
             t.insertWord(word);
            reverse(word.begin() , word.end());
            
        }

        return t.countNode;
    }
};

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Solution {
public:
    int countDistinctSubstrings(string &s) {
        Node* root = new Node();
        int cnt = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            Node* node = root;

            for (int j = i; j < n; j++) {
                if (!node->containsKey(s[j])) {
                    node->put(s[j], new Node());
                    cnt++;
                }

                node = node->get(s[j]);
            }
        }

        return cnt + 1;
    }
};

int main() {
    
    return 0;
}
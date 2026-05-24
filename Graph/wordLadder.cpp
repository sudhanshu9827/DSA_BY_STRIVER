#include <bits/stdc++.h>
using namespace std;

// ek letter different hai then we can have the edge aur traverse karke agar me final node hai ustak pahuch gaya too my work is almost done 

// usse edges banana is also a difficult task 


// wrong direction 
// // class Solution {
// //     void storeFreq(string s , unordered_map<char , int>& freq){
// //         for(char ch : s){
// //             freq[ch]++;
// //         }
// //     }

// //     int checkSimilar(unordered_map<char , int>& mp1 , unordered_map<char , int>& mp2){
// //         int similar = 0;

// //         for(auto it1 : mp1){
// //             for(auto it2:mp2){
// //                 if(it1 == it2){

// //                 }
// //             }
// //         }
// //     }

// // public:
// //     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
// //         bool isPresent = false;
// //         for(string st : wordList){
// //             if(st == endWord)isPresent = true;
// //         }

// //         if(!isPresent)return 0;

// //         // store word saath me har letter ki freq 


// //         unordered_map<string , unordered_map<char , int>> strFreq;

// //         for(string st : wordList){
// //             unordered_map<char , int> f;
// //             storeFreq(st , f);
// //             strFreq[st] = f;
// //         }

// //         if(strFreq.find(beginWord) == strFreq.end()){
// //             unordered_map<char , int> f;
// //             storeFreq(beginWord , f);
// //             strFreq[beginWord] = f;
// //         }

// //         unordered_map<string , vector<string>> ump;


// //         for(auto it : strFreq){
// //             auto [st , mp] = it;
// //             for(auto it : strFreq){
// //                 auto [st2 , mp2] = it;

// //                 if(st!=st2){
                    
// //                 }
// //             }
// //         }

// //         // now start travering 

// //         int count = 0;

// //         queue<string> q;

// //         q.push(beginWord);

// //         while(!q.empty()){

// //         }
// //     }
// // };


// BFS lagega pata hai then boo edge wala thinking hatakar directly bfs bhi too laga sakta hu 
// start karo start se har character ko change kar kar ke dekh loo if exist in wordList then usko queue me push kara doo jaise hii endWord mill jaaye return the level

//if nhi mille return zero means queue joo hai empty hoo jaaye 
//edge naa banate hue bhi kaam wahi karna 

//but baar baar ek hii me ghumte rahega agar mene boo specific string hatai nhi too 

// vector se hatana order ko kharab karna aur idhar udhar kar dena then set yaa too unordered_set bana loo 

//joo preferable hoo

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;

        unordered_set<string> words(wordList.begin() , wordList.end());

        q.push({beginWord , 1});

        if(words.find(beginWord)!=words.end()){
            words.erase(beginWord);
        }

        while(!q.empty()){
            auto [word , level] = q.front();
            q.pop();

            if(word == endWord)return level;

            int size = word.size();

            for(int i = 0 ; i < size ; i++){
                char orignal = word[i];
                // one more slight optimization instead of taking string you can take word[i] and store which character need to change 

                for(char ch = 'a' ; ch <='z' ; ch++){
                    word[i] = ch;

                    if(words.find(word)!=words.end()){
                        words.erase(word);
                        q.push({word , level + 1});
                    }
                }
                word[i] = orignal;
            }
        }

        return 0;
    }
};


int main()
{
     
    return 0;
}
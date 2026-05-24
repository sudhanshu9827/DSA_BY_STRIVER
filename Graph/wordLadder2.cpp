#include <bits/stdc++.h>
using namespace std;


// We need to find all the shortest paths 

// sabse pehle too list koo daalte chalo naa joo bhi ek ke differece se aa raha hai 

// ek though yeh bhi aata hai dubara aa raha hoga then dubara me kyu lunga i want minimum distance path



// TODO ; This is also correct but not completed 

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;

        vector<vector<string>> ans;

        q.push({beginWord});

        // hatane ke baare me nhi sochunga too ---> <--- essa hii chalta jaayega 

        // yaa too pura unordered_map but map karna kisse hai mujhe too access karna hai 

        //too unordered_set laga doo 

        unordered_set<string> wordSet(wordList.begin() , wordList.end()); // Hashed 

        // check begin word exist too nhi kar raha 

        if(wordSet.find(beginWord)!=wordSet.end()){
            wordSet.erase(beginWord);
        }

        vector<string> ele;

        int minLen = 0;

        while(!q.empty()){

            for(string st : ele){
                wordSet.erase(st);
            }
            ele.clear();

            int size = q.size();

            for(int j = 0 ; j < size ; j++){

                vector<string> v = q.front();
                q.pop();

                // checking one character change exist or not 

                string lastWord = v.back();

                if(lastWord == endWord){
                    if(!minLen){
                        ans.push_back(v);
                        minLen = v.size();
                    }

                    else if(minLen == v.size()){
                        ans.push_back(v);
                    }
                }

                for(int i = 0 ; lastWord.size() ; i++){
                    char orignal = lastWord[i];
                    for(char ch = 'a' ; ch<='z' ; ch++){
                        lastWord[i] = ch;

                        if(wordSet.find(lastWord)!=wordSet.end()){
                            v.push_back(lastWord);

                            q.push(v);

                            ele.push_back(lastWord);
                            v.pop_back();
                        }
                    }
            }

            }
        }
        return ans;
    }
};
 


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;

        vector<vector<string>> ans;

        q.push({beginWord});

        // hatane ke baare me nhi sochunga too ---> <--- essa hii chalta jaayega 

        // yaa too pura unordered_map but map karna kisse hai mujhe too access karna hai 

        //too unordered_set laga doo 

        unordered_set<string> wordSet(wordList.begin() , wordList.end()); // Hashed 

        // check begin word exist too nhi kar raha 

        vector<string> usedOnLevel;

        int level = 0;

        while(!q.empty()){
                vector<string> v = q.front();
                q.pop();

                // checking one character change exist or not 

                if(v.size() > level){
                    level++;
                     for(string st : usedOnLevel){
                         wordSet.erase(st);
                     }
                     usedOnLevel.clear();
                }

                string lastWord = v.back();

                if(lastWord == endWord){
                    if(ans.size() == 0){
                        ans.push_back(v);
                    }

                    else if(ans[0].size() == v.size()){
                        ans.push_back(v);
                    }
                }

                for(int i = 0 ;i <  lastWord.size() ; i++){
                    char orignal = lastWord[i];
                    for(char ch = 'a' ; ch<='z' ; ch++){
                        lastWord[i] = ch;

                        if(wordSet.find(lastWord)!=wordSet.end()){
                            v.push_back(lastWord);

                            q.push(v);

                            usedOnLevel.push_back(lastWord);
                            v.pop_back();
                        }
                    }
                    lastWord[i] = orignal;
                }
        }
        return ans;
    }
};


//! Optimizing the soln 

// although in above soln i am putting all the sequence into the memory which will leads to outOfMemory as well 

// unneccesary things bhi daal rahe hai koi sence nhi uskka 

// agar sochu mere paas last pata hai aur baha se path hai then it is quite be simpler 

// last se usse pehle chalte aao starting tak 

// Method pending rakhtu hu par yupps i will do it 

int main()
{
     
    return 0;
}
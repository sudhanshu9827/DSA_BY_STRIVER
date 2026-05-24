#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(int n , vector<string>& words , string currWord){
        if(n == 0){
            words.push_back(currWord);
            return;
        }

        if(currWord.empty()){
            solve(n - 1 , words , currWord + 'a');
            solve(n - 1 , words , currWord + 'b');
            solve(n - 1 , words , currWord + 'c');
        }

        else{
            int currSize = currWord.size();
            char lastChar = currWord[currSize - 1];

            if(lastChar == 'a'){
                solve(n - 1 , words , currWord + 'b');
                solve(n - 1 , words , currWord + 'c');
            }
            else if(lastChar == 'b'){
                solve(n - 1 , words , currWord + 'a');
                solve(n - 1 , words , currWord + 'c');
            }
            else{
                solve(n - 1 , words , currWord + 'a');
                solve(n - 1 , words , currWord + 'b');
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> words;
        solve(n , words ,"");

        sort(words.begin() , words.end());

        if(words.size() > k)return "";
        return words[k-1];
    }
};

int main() {
    
    return 0;
}
// Two concepts i learn from the this quetion iterative approach 
// 1. i can putt different vector data like in map <int , vector> this vector of different size no matter 
// size should not be give in prio 

// if i want character in my string only one how do i do that directly it quite not be possible 
// so , string (1 , char) it will hold charcter in the string 

#include <bits/stdc++.h>
using namespace std;


// Approach - 1
class Solution {
public:
    void display(vector<string> arr){
        for(string i : arr){
            cout << i << " ";
        }
        cout << "\n";
    }

    vector<string> appendCharacter(vector<string>ans , vector<char> arr){
        vector<string> final;
        for(int i = 0 ; i< ans.size() ; i++){
            string s = ans[i];
            for(int j = 0 ; j < arr.size() && arr[j]!='0' ; j++){
                final.push_back(s + arr[j]);
            }
        }
        return final;
    }
    vector<string> letterCombinations(string digits) {
        map<int, vector<char>> mp;
        mp[2] = {'a', 'b', 'c' };
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[6] = {'m', 'n', 'o'};
        mp[5] = {'j', 'k', 'l'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        int first = digits[0] - '0';
        for(int i = 0 ; i < mp[first].size() && mp[first][i]!='0'; i++){
            ans.push_back(string(1 ,mp[first][i]));
        }
        int n= digits.size();
        for(int i = 1 ; i < n ; i++){
            ans = appendCharacter(ans, mp[digits[i]-'0']);
        }
        return ans;
    }
};

// Recursive approach 
// How can i think recursive approach
// all add their character and call other 
//untill all digits gets exausted 
//recursive implementation can make the life easier

void recursiveLetterCombination(int idx , const vector<string> & combos , vector<string>& ans , string s , string digits){
    if(idx == digits.size()){
        // Add the current combination to the answer
        ans.push_back(s);
        return;
    }

    int digit = digits[idx] - '0';
    for(int i = 0 ; i < combos[digit].size();i++){
        recursiveLetterCombination(idx+1 , combos , ans , s + combos[digit][i] ,digits);
    }
}


 
int main()
{
    string digits = "23";
    Solution s;
    vector<string> ans;
    ans = s.letterCombinations(digits);
    s.display(ans);


    return 0;
}
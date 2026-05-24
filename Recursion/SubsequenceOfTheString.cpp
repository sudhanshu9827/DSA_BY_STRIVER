// What is the intution behind the question ?
// => similar to the subset question it except empty string
// => either take the character or not take the character 
// => Can represent in binary if 0 dont take the character otherwise take it 

// For Example :- 
// s = "abc"
// 000 - > empty 
// 001->take c only 
// 010 ->take b only 
// 011-> take b and c both

// like that for n length string we have 2^n subsequences -1(empty string)

// Very nice question when think recuresively make sense 
// Why recursion 
// Beacuse we can make a tree like structure is a hint 
// And here we have to choices either take the element or ignote the element

#include <bits/stdc++.h>
using namespace std;



// Iterative 
vector<string> Subsequence(string s){
    int n = s.size();
    
    int total_subset = 1<<n;
    vector<string> ans;

    for(int i = 1 ; i<total_subset ; i++){
        string temp = "";
        for(int j = 0  ; j < n ; j++){
            if(i & (1<<j)){
                // why this 1<<j 
                // checking every bit is up or not up take it
                temp+=s[j];
            }
        }
        ans.push_back(temp);
    }
    return ans;
}


void SubsequenceRecursive(string s , int index , string substring, vector<string>&res){
    if(index == s.size()){
        res.push_back(substring);
    }


    // take a character 
    substring+=s[index];
    SubsequenceRecursive(s , index + 1 , substring , res);

    // Popping the character 
    substring.pop_back();
    SubsequenceRecursive(s , index + 1 , substring , res);
}


// Recursive 

 
int main()
{
    vector<string> vs = Subsequence("abc");
    for(string s:vs){
        cout<<s<<" ";
    }
    return 0;
}
// Intution : 
// when first element add into the stack
//when zero previously 1 and 0 both add recursive step 
// when already 1 onl zero can be added 

// 3 
//       1      0
//      /      / \
//     0      1   0
//    / \    /   / \
//   1   0  0   1   0


#include <bits/stdc++.h>
using namespace std;

void AddBinaryString(vector<string>& ans , int n , string s , char last){
    if(n==0){
        ans.push_back(s);
        return;
    }
    // what can i do ]
    AddBinaryString(ans , n - 1 , s+"0" ,'0');

    if(last!='1')
        AddBinaryString(ans , n - 1 , s+"1" ,'1');
    // Decrementing the n twice is the major issue 

}

// What is my learning 
// I do i basic mistake in running recursion 
//Sending directly integer rather than character

 
int main()
{
    int n;cin>>n;
    vector<string> ans;
    AddBinaryString(ans , n , "" ,'0');


    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}




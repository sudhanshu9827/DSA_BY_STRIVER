#include <bits/stdc++.h>
using namespace std;

// 2 cheeze sikhne ko milli \
want to reinitalize again use 

// ** fill 

// and bhai diyaan rakho kya cheez loop ke ander hoo rahi hai aur kyaa bahar 

// Question ke constraints padoo 

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> freq(26);

//         int n = s.size();
//         int maxi = 0;
//         int tempMax = 0;
//         for(int i = 0 ; i < n ; i++){
//             if(!freq[s[i]]){
//                 tempMax+=1;
//                 freq[s[i]] = 1;
//             }

//             else{
//                 maxi = max(maxi , tempMax);
//                 tempMax = 0;
//                 freq.clear();
//             }
//         }

//         loop se bahar nikalkar bhi too upgrade karna padega dont you get it 
//     }
// };


// wrong 2 

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char , int> freq;

//         int n = s.size();
//         int maxi = 0;
//         int tempMax = 0;
//         for(int i = 0 ; i < n ; i++){
//             if(!freq[s[i]]){
//                 tempMax+=1;
//                 freq[s[i]] = 1;
//                 // cout<<"+"<<s[i]<<endl;
//             }
//             else{
//                 // cout<<s[i]<<endl;
//                 maxi = max(maxi , tempMax);
//                 tempMax = 0;
//                 freq.clear();
//             }
//         }
//         maxi = max(maxi , tempMax);
//         return maxi;
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> freq;
        int start = 0;

        int n = s.size();
        int maxi = 0;
        int i;
        for(i = 0 ; i < n ; i++){
            if(!freq[s[i]]){
                freq[s[i]] = 1;
            }
            else{
                // cout<<s[i]<<endl;
                maxi = max(maxi , i - start);

                for(int j = start ; j<i; j++){
                    freq[j] = 0;
                }
                start = i;
                freq[s[i]] = 1;
            }
        }
        maxi = max(maxi , start - i);
        return maxi;
    }
};
 
int main()
{
     
    return 0;
}
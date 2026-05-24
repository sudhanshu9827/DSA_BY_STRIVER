#include <bits/stdc++.h>
using namespace std;


// This code i did . Not correct what if abcabc yaha cab bhi ek possible window hai jisske agal bagal dekh rahe hai right 

// incorrect Solution
// socha teekh tha pehli baari me bhi but ussi ke saath ban rahe the phir ussi ko le liye toda galt direction me chala gaya  
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int l = 0, r = 0, n = s.size(), count = 0;
//         vector<int> abc(3);
//         bool flag = false;
//         while (r < n) {
//             abc[s[r] - 'a']++;

//             if (abc[0] && abc[1] && abc[2]) {
//                 flag = true; 
//                 while (abc[0] > 0 && abc[1] > 0 && abc[2] > 0) {
//                     l++;
//                     abc[s[l] - 'a']--;
//                 }
//                 break;
//             }
//             r++;
//         }

//         if (!flag && abc[0] && abc[1] && abc[2]) {
//             while (abc[0] > 0 && abc[1] > 0 && abc[2] > 0) {
//                 l++;
//                 abc[s[l] - 'a']--;
//             }
//         }

//         l = l - 1;
//         if (l < 0)
//             l = 0;
//         int right = (n - 1 - r);
//         count += 1 + l + right + l * right;
//         return count;
//     }
// };

// basic question tha but i dont know why i took yudge time 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0 , r = 0 , n = s.size() , count = 0;
        vector<int> abc(3 , 0);
        int left = 0;
        while(r < n){
            abc[s[r] - 'a']++;
            while(abc[0] && abc[1] && abc[2]){
                count += n - r;
                abc[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() , count = 0;
        vector<int> lastseen(3 , -1);
        for(int i = 0 ; i < n; i++){
            lastseen[s[i] - 'a']++;
            count+= 1 + min(lastseen[0] , min(lastseen[1] , lastseen[2]));
        }
        return count;
    }
};
int main()
{
     
    return 0;
}
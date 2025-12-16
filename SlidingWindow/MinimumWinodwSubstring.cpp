#include <bits/stdc++.h>
using namespace std;

//Confusion of varaible hoo rahi hai usko diyaan rakhna padega

class Solution {
public:
    string minWindow(string s, string t) {
        // brute force generate all the string and then check whether 
        int m = s.size(), n = t.size();
        if(n > m)return "";
        unordered_map<int , int> freq , freq2; 
        for(char ch : t){
            freq[ch]++;
        }
        int contain = 0 , minLen = INT_MAX;
        string ans ="";
        for(int i = 0; i < m ; i++){
            contain = 0;
            freq2 = freq;
            bool found = false;
            for(int j = i ; j < m ; j++){
                if(freq2.find(s[j])!=freq2.end() && freq2[s[j]] > 0){
                    cout<<s[j];
                    contain++;
                }
                freq2[s[j]]--;
                if(contain == n){
                    // cout<<contain<<";"<<j<<":"<<i<<endl;
                    found = true;
                    if(j - i + 1 < minLen){
                        minLen = j - i + 1;
                        ans = s.substr(i , j - i + 1);
                    }
                    break;
                }
            }
            if(!found)break;
            cout<<endl;
        }
        return ans;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size() , n = t.size();
        if(m < n)return "";

        // using sliding window 
        int l = 0 , r = 0 , minLen = INT_MAX;
        string minS = "";

        unordered_map<char , int> freqT , freqS;
        int contain = 0;
        for(auto ch : t){
            freqT[ch]++;
        }

        while(r < m){
            freqS[s[r]]++;
            if(freqT.find(s[r])!=freqT.end() && freqS[s[r]]== freqT[s[r]]){
                // cout<<contain<<endl;
                contain++;
            }
            // freqS[s[r]]++;
            if(contain == freqT.size()){
                cout<<"sanau"<<endl;
                while(freqT.find(s[l])==freqT.end() || freqS[s[l]] > freqT[s[l]]){
                    freqS[s[l]]--;
                    l++;
                }
                if(minLen > r - l + 1){
                    minS= "";
                    for(int i = l ; i <= r ; i++){
                        minS+=s[i];
                    }
                    minLen = r - l + 1;
                }
                // ek hii nhi hai samjho  multiple hai agar usse kam hoagai kisse jitne pehle waale me the tabhi
                if(--freqS[s[l]] == 0){
                    freqS.erase(s[l]);
                }
                if(freqT.find(s[l]) != freqT.end() && freqS[s[l]] < freqT[s[l]]){
                    contain--;
                }
                l++;
            }
            r++;
        }
        return minS;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        // optimal 
        // ek window me kaam  kar raha hui
        int m = s.size() , n = t.size();
        int l = 0 , r = 0 , contain = 0;
        int minLen = INT_MAX;
        string ans = "";

        unordered_map<char , int>freq(256 , 0);

        for(char ch : t){
            freq[ch]++;
        }
        
        while(r < m){
            if(freq[s[r]] > 0)contain++;
            if(freq.find(s[r])!=freq.end() && freq[s[r]] > 0)
                freq[s[r]]--;

            while(contain == n){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    ans = s.substr(l , minLen);
                }
                if(freq.find(s[r])!=freq.end() && ++freq[s[l++]] > 0)contain--;
            }
            r++;
        }
        return ans;
    }
};

// Optimal 
// Gives MLE
class Solution {
public:
    string minWindow(string s, string t) {
        // optimal 
        // ek window me kaam  kar raha hui
        int m = s.size() , n = t.size();
        int l = 0 , r = 0 , contain = 0;
        int minLen = INT_MAX;
        string ans = "";

        vector<int> freq(256 , 0);

        for(char ch : t){
            freq[ch]++;
        }
        
        while(r < m){
            if(freq[s[r]] > 0)contain++;
            freq[s[r]]--;

            while(contain == n){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    ans = s.substr(l , minLen);
                }
                if(--freq[s[l++]] > 0)contain--;
            }
            r++;
        }
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
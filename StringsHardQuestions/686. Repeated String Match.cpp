#include <bits/stdc++.h>
using namespace std;


// first thought yeh aata hai ki first character jaha match hoga wahi se match karate chalo 
// cycle khumate chalo 

// but there are multiple possiblilities jaha match hoo sakta hai 

// sabko dekhenge too gaye phir too 


// what other think we can do 

// I tried by myself and succeed Now try the actuall Genuis mind behind the question Rabin-Karp Algorithm 

class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        int n = a.size();
        int m = b.size();

        // find b inside a 

        // check for every occurence of first character is quite difficult 

        if(m == 0)return 0;

        vector<int> positions;

        for(int i = 0 ; i < n ; i++){
            if(a[i] == b[0])positions.push_back(i);
        }

        if(!positions.size()) return -1;

        // all the posible position are inside the backet now 


        // if i finish substring found

        for(int pos : positions){
            int i = 0;
            int cnt = 1;

            while(i < m){
                if(pos == n)cnt++;

                pos = pos % n;

                if(a[pos] == b[i]){
                    pos++;
                    i++;
                }
                else break;
            }

            if(i == m) return cnt;
        }

        return -1;

    }
};




int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        
        int start = 1 , end = n;
        
        vector<int> ans;
        
        while(start <  n){
            ans.push_back(end--);
            ans.push_back(start++);
        }
        
        if(n & 1)ans.pop_back();
        
        reverse(ans.begin() , ans.end());
        
        for(int i : ans){
            cout<<i<<" ";
        }
    }

    return 0;
  
}
#include <bits/stdc++.h>
using namespace std;

void solve(int n , string s){
    int count = 0;
    int i = 1;

    int firstSize= 0;
    int start = 0;


    while(i < n){
        if(s[i - 1] >= s[i]){
            if(!count){
                start = i;
            }
            while(i < n && s[i-1] >= s[i]){
                i++;
            }

            if(!count)firstSize = i - start + 1;
            if(i!=n)
                count++;
        }
        i++;
    }

    // cout<<endl<<count<<"   "<<endl;
    if(count & 1){
        cout<<"Alice\n";
        cout<<firstSize<<"\n";
        for(int i = 0 ; i < firstSize; i++){
            cout<<start + i<<" ";
        }
        cout<<"\n";
    }

    else cout<<"Bob\n";
}
 
int main()
{
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        solve(n , s);
    }
     
    return 0;
}
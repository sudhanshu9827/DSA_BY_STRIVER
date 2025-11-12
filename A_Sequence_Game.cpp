#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int> num(n);
        for(int i = 0 ; i < n;i++){
            cin>>num[i];
        }
        int x; cin>>x;
        int min = *min_element(num.begin() , num.end());
        int max = *max_element(num.begin() , num.end());

        if(x > max || x < min)cout<<"No"<<"\n";
        else cout<<"Yes"<<"\n";

    }
     
    return 0;
}
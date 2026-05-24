#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++){
            cin>>nums[i];
        }
        if(nums[0] || nums[n-1])cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t; cin>>t;
    while(t--){
        long long n , c , k; cin>>n>>c>>k;

        vector<long long> nums(n);
        for(int i = 0 ; i < n ; i++){
            cin>>nums[i];
        }
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n; i++){
            if(c < nums[i]){
                break;
            }
            else{
                if(c - nums[i] <= k){
                    k-=(c-nums[i]);
                    c = 2*c;
                }
                else{
                    c+=nums[i] + k;
                    k = 0;
                }
            }
        }
        cout<<c<<"\n";
    }
    return 0;
}
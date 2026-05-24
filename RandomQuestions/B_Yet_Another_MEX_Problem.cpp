#include <bits/stdc++.h>
using namespace std;

 
int main()
{
    int t; cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++){
            cin>>nums[i];
        }

        sort(nums.begin() , nums.end());

        vector<int> dup;

        int i = 0;

        while(i < n - 1){
            dup.push_back(nums[i]);
            while(i < n-1 && nums[i] == nums[i+1])i++;
                i++;
        }
        if(nums[n-2]!=nums[n-1])dup.push_back(nums[n-1]);

        i = 0;

        bool ander = false;

        i = 0;

        while(i < k-1 && i < dup.size()){
            if(i != dup[i]){
                ander = true;
                cout<<i<<endl;
                break;
            }
            i++;
        }
        if(!ander)cout<<i<<endl;
    }
     
    return 0;
}
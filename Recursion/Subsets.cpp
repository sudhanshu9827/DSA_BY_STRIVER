#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> v){
    for(int i = 0 ; i< v.size() ; i++){
        cout<<"["<<" ";
        for(int j = 0  ; j< v[i].size() ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<" "<<"]"<<"\n";
    }
}

// Iterative approach 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // First find the number of subsets;
        // 2^n
        vector<vector<int>> ans;
        int n = nums.size();
        int subsets = 1<<n;
        for(int i = 0 ; i < subsets ; i++){ //(0-2^n-1)
            vector<int> add;
            for(int j = 0 ; j < n ; j++){
                if(i & (1<<j))
                    add.push_back(nums[j]);
            }
            ans.push_back(add);
        }
        return ans;
    }
};


// Recursive method 
void createSubset(vector<int> nums , int index , vector<int>& subset , vector<vector<int>>& res){
    if(index == nums.size()){
        res.push_back(subset);
        return;
    }

    //Take the element
    subset.push_back(nums[index]);
    createSubset(nums , index +  1 , subset , res);

    //Dont take the element
    subset.pop_back();
    createSubset(nums , index +  1 , subset , res);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;

    createSubset(nums , 0 , subset , res);
    return res;
}
 
int main()
{
    int n;cin>>n;
    vector<int> val(n);
    for(int i = 0; i < n ;i++){
        cin>>val[i];
    }
    Solution sol;
    vector<vector<int>> ans = sol.subsets(val);
    
    display(ans);
    return 0;
}
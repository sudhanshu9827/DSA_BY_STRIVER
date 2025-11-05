#include <bits/stdc++.h>
using namespace std;
 
// Approach : 1
class Solution {
    void generateSubset(int index , vector<int>&nums , set<vector<int>> &ans , vector<int>& sub){
        if(index == nums.size()){
            ans.insert(sub);
            return;
        }

        sub.push_back(nums[index]);
        generateSubset(index + 1 , nums , ans , sub);
        sub.pop_back();
        generateSubset(index+1 , nums , ans , sub);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin() , nums.end());
        generateSubset(0 , nums , ans , sub);
        vector<vector<int>> res;
        for(auto vec:ans){
            res.push_back(vec);
        }
        return res;
    }
};


// I have difficutly in thinking with recursuion and this is loop as well 
// perfect all things but pushing onto the codition but need to push everytime recursive call this will slight change 

// Aproach 2 ;
class Solution {
    void generateSubset(int index , vector<int>&nums , vector<vector<int>> &ans , vector<int>& sub){
        ans.push_back(sub);
        for(int i = index ; i< nums.size() ; i++){
            if(i > index && nums[i] == nums[i-1])continue;
            sub.push_back(nums[i]);
            generateSubset(i + 1 , nums , ans,  sub);
            sub.pop_back();
            // essa logic likhna hai jisse not take hoo jaaye
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin() , nums.end());
        generateSubset(0 , nums , ans , sub);
        // vector<vector<int>> res;
        // for(auto vec:ans){
        //     res.push_back(vec);
        // }
        return ans;
    }
};



int main()
{
     
    return 0;
}
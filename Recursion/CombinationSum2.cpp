// I did this question with think unique lets try set 
// yes this apprach is correct 
// but the answer still wrong try to validate it why 

#include <bits/stdc++.h>
using namespace std;

// Approach 1 
// time overhead for every possible soluion implementing sorting which is worst 

// issme sorting karke kaam hoo raha hai but bina kare nahi pata nhi kyui 
// class Solution {

//     void GenerateCombination(set<vector<int>>& res , vector<int>&subset , const vector<int>& candidates , int target , int index){
//         //base case
//         if(index == candidates.size()){
//             if(target==0){
//                 sort(subset.begin() , subset.end());
//                 res.insert(subset);
//             }
//             return;
//         }

//         if(candidates[index] <= target){
//             subset.push_back(candidates[index]);
//             GenerateCombination(res , subset , candidates , target - candidates[index] , index + 1);
//             subset.pop_back();
//         }

//         // dont take the element 

//         GenerateCombination(res , subset , candidates , target , index + 1);

//     }  
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> res;
//         vector<int> subset;
//         GenerateCombination(res , subset ,  candidates , target ,0);
//         vector<vector<int>> ans;
//         for(auto val : res){
//             ans.push_back(val);
//         }
//         return ans;
//     }
// };

class Solution {
    void findCombination(int ind , int target , vector<int>& arr , vector<vector<int>> & res , vector<int>& ds){
        if(target==0){
            
            res.push_back(ds);
            return;
        }

        for(int i = ind ; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1])continue; // i > ind what does it mean it simply mean take duplicate when its start of next level 
            if(arr[i] > target)break; // the all elements are sorted if one of the element is higher all are right to it are also higher so break it 
            ds.push_back(arr[i]);
            findCombination(i+1 , target - arr[i] , arr , res , ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        findCombination(0 , target , candidates , res , subset);
    }
};
 
// int main()
// {
     
//     return 0;
// }
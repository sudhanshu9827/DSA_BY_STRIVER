// What i learn 
// A slight difference can confuse the question i took more than a hour and just see the
// solution and came up that both yesterday problem is same with slight difference 
// // now from today recursive call without make recusrsive graph never works 


#include <bits/stdc++.h>
using namespace std;

class Solution {
    void StoreAllSum(vector<vector<int>> &res, int index, vector<int> &subset, vector<int> &candidates, int target)
    {
        // Base case
        if (index == candidates.size())
        {
            if (target == 0)
                res.push_back(subset);
            return;
        }

        // Take the element if it doesn't exceed target
        if (candidates[index] <= target)
        {
            subset.push_back(candidates[index]);
            StoreAllSum(res, index, subset, candidates, target - candidates[index]);
            subset.pop_back();
        }

        // Don’t take the element
        StoreAllSum(res, index + 1, subset, candidates, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> subset;
        StoreAllSum(res, 0, subset, candidates, target);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (auto &vec : result)
    {
        cout << "[ ";
        for (int x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

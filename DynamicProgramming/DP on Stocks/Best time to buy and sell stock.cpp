#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int prof = 0;

        for(int i = 0 ; i < prices.size(); i++){
            if(buy > prices[i]){
                buy = prices[i];
            }

            prof = max(prof , prices[i] - buy);
        }

        return prof;
    }
};

int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int buy = INT_MAX;
        int prof = 0;

        for(int i = 0 ; i < prices.size() - 1; i++){
            if(prices[i] < prices[i + 1]){
                prof+=(prices[i + 1] - prices[i]);
            }
        }

        return prof;
    }
};

int main() {
    
    return 0;
}
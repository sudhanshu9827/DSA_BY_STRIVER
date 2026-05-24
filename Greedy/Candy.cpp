#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int , int>> ratingIndex;

        for(int i = 0 ; i < n ; i++){
            ratingIndex.push_back({ratings[i] , i});
        }

        sort(ratingIndex.begin() , ratingIndex.end());

        vector<int> candies(n , 0);
        int maxCandy = 0 , index , maxCandyNeighbour;;
        for(int i = 0 ; i < n ; i++){
            index = ratingIndex[i].second;
            maxCandyNeighbour = 0;

            if(index >= 1 && ratings[index]!=ratings[index - 1] ){
                maxCandyNeighbour = candies[index - 1];
            }

            if( index < n - 1 && ratings[index]!=ratings[index + 1]){
                maxCandyNeighbour = max(maxCandyNeighbour , candies[index +  1]);
            }

            candies[index] = maxCandyNeighbour + 1;
            maxCandy+= maxCandyNeighbour + 1;
        }

        return maxCandy;
    }
};
 
int main()
{
     
    return 0;
}
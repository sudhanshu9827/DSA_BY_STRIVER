#include <bits/stdc++.h>
using namespace std;

// Took time 1st time may be difficult to understand as well 

class Solution {

    void dfs(vector<vector<int>>& image , int sr , int sc , int color , int m , int n , int startColor){
        if(sr < 0 || sc < 0 || sr >= m || sc >=n )return;

        image[sr][sc] = color;

        if(sr + 1 < m && image[sr+1][sc] == startColor && color!=startColor)
            dfs(image , sr + 1 , sc , color , m , n , startColor);
        if(sr - 1 >= 0 && image[sr-1][sc] == startColor && color!=startColor)
            dfs(image , sr - 1 , sc , color , m , n , startColor);
        if(sc + 1 < n && image[sr][sc + 1] == startColor && color!=startColor)
            dfs(image , sr , sc + 1 , color , m , n , startColor);
        if(sc - 1 >= 0 && image[sr][sc - 1] == startColor && color!=startColor)
            dfs(image , sr , sc - 1 , color , m , n , startColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int startColor = image[sr][sc];

        dfs(image , sr , sc , color , m , n , startColor);

        return image;
    }
};
 
int main()
{
     
    return 0;
}
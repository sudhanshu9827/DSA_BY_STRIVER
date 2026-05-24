#include <bits/stdc++.h>
using namespace std;

// I dont believe i did a mistake in this easy question but sometimes mistake teach us well 
// from now onwords i check my code instead of correct atleast 2 - 3 diffent types of test case soo it will give me accurat result 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int pointS = 0 , pointG = 0;

        while(pointS < s.size() && pointG < g.size()){
            if(s[pointS] >= g[pointG]){
                pointS++;pointG++;
            }
            else if(s[pointS] < g[pointG])pointS++;
            else break;
        }
        return pointG;
    }
};
 
int main()
{
     
    return 0;
}
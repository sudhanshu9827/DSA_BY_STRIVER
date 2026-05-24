// Think about base condition twice 
// Dont see the soliution if you already did it 

#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

#define vvi vector<vector<int>>

class Solution {

    void findPath(int row , int col , int n , vector<string>& ans , string& s , vvi & maze){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        
        if(row<0 || col <0 || row>=n ||col>=n || maze[row][col] == 2 || maze[row][col] == 0){
            return;
        }
        maze[row][col] = 2;
        s.push_back('U');
        findPath(row - 1 , col , n , ans , s , maze);
        s.pop_back();
        s.push_back('D');
        findPath(row + 1  , col , n , ans , s , maze);
        s.pop_back();
        s.push_back('L');
        findPath(row , col + 1 , n , ans , s , maze);
        s.pop_back();
        s.push_back('R');
        findPath(row  , col - 1 , n , ans , s , maze);
        s.pop_back();
        maze[row][col] = 1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if(maze[n-1][n-1]==0) return ans;
        string s;
        findPath(0 , 0 , n , ans , s , maze);
        sort(ans.begin() , ans.end());
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
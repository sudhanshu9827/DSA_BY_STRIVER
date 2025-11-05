//Mistakes 
// Forget about checking negative i and j 
// fass raha hai boo clear hai baar baar -> <- essa hoo raha hai 
// How can i mark in same call visited soo it will not go back their
//link : https://leetcode.com/problems/word-search/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkExist(int i , int j ,  int m , int n, const vector<vector<char>>& board , string &word, int index){
        if(i >= m || j >=n || i < 0 || j <0){
            return;
        }

        if(index == word.size()){
            return true;
        }
        if(board[i][j] == word[index]){
            return checkExist(i+1 , j , m , n ,board , word , index + 1)
            || checkExist(i , j+1 , m , n , board , word , index+1)
            || checkExist(i-1 , j , m , n , board , word , index + 1)
            || checkExist(i , j-1 , m , n , board , word ,index + 1);
        }

        else{
            return checkExist(i+1 , j , m , n ,board , word , 0)
            || checkExist(i , j+1 , m , n , board , word , 0)
            || checkExist(i-1 , j , m , n , board , word , 0)
            || checkExist(i , j-1 , m , n , board , word ,0);
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(checkExist(0 , 0, m , n , board , word))
            return true;
        return false;
    }
};
 
int main()
{
     
    return 0;
}
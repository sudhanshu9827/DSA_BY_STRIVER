//Mistakes 
// Forget about checking negative i and j 
// fass raha hai boo clear hai baar baar -> <- essa hoo raha hai 
// How can i mark in same call visited soo it will not go back their
//link : https://leetcode.com/problems/word-search/


#include <bits/stdc++.h>
using namespace std;

// This Solution is not copmpleted and i dont know why this soln not works
// I will work on this solution later on 
class Solution {
    bool checkExist(int i , int j ,  int m , int n, vector<vector<char>>& board , string& word, int index){
        if(i >= m || j >=n || j <0 || i <0 || board[i][j]=='#'){
            return false;
        }

        if(index == word.size()){
            return true;
        }

        bool top , down , left , right;

        char temp = board[i][j];
        board[i][j] = '#';
        if(temp== word[index]){
            top =  checkExist(i , j+1 , m , n ,board , word , index+1);
            down = checkExist(i , j - 1 , m , n ,board , word , index+1);
            left = checkExist(i-1 , j , m , n ,board , word , index+1);
            right = checkExist(i+1 , j , m , n ,board , word , index+1);

            board[i][j] = temp;
            return top||down||left||right;
        }

        else{
            top =  checkExist(i , j+1 , m , n ,board , word , 0);
            down = checkExist(i , j - 1 , m , n ,board , word , 0);
            left = checkExist(i-1 , j , m , n ,board , word , 0);
            right = checkExist(i+1 , j , m , n ,board , word , 0);

            board[i][j] = temp;

            return top || down ||left||right;
        }

        board[i][j] = temp;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(checkExist(0 , 0, m , n , board , word , 0))
            return true;
        return false;
    }
};


// What we are doing in this solution from every index checking is their any possible path 

class Solution2 {

    bool searchNext(vector<vector<char>> &board, string word, int row, int col, 
    int index, int m, int n) {

        // if index reaches at the end that means we have found the word
        if (index == word.length())
            return true;

        // Checking the boundaries if the character at which we are placed is not 
        //the required character
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != 
        word[index] or board[row][col] == '!')
            return false;

        // this is to prevent reusing of the same character
        char c = board[row][col];
        board[row][col] = '!';

        // top direction
        bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
        // right direction
        bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
        // bottom direction
        bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
        // left direction
        bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

        board[row][col] = c; // undo change

        return top || right || bottom || left;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(searchNext(board , word , 0 , 0 , 0 , m , n))
                    return true;
            }
        }
        return false;
    }
};
 
int main()
{
     
    return 0;
}
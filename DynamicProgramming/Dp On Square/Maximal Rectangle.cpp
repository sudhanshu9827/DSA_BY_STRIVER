#include <bits/stdc++.h>
using namespace std;

// Histogram wala dubara karana hai 

// Intuitve hai but mujhe pehli baar me nhi aaya 

// laga ki haa question kiya hai essa but relate nhi hua 

class Solution {
    int largestRectangeInHistogram(vector<int>& histo){
        int n = histo.size();

        stack<int> st;

        int maxA = 0;

        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];

                st.pop();

                int width;

                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }

                maxA = max(maxA , height * width);
            }
            st.push(histo[i]);
        }

        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        vector<int> height(m);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1)height[j]++;
                else height[j] = 0;
            }

            int area = largestRectangeInHistogram(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main() {
    
    return 0;
}
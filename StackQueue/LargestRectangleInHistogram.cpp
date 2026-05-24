#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> NextSmaller(vector<int>& heights){
        //i want index so store index naa
        int n = heights.size();
        vector<int> NextSmallerElement(n);
        stack<int> index;
        for(int i = n - 1 ; i >=0 ; i--){
            while(!index.empty() && heights[i] <= heights[index.top()]){
                index.pop();
            }
            if(index.empty()){
                NextSmallerElement[i] = n;
                index.push(i);
            }
            else{
                NextSmallerElement[i] = index.top();
                index.push(i);
            }
        }

        return NextSmallerElement;
    }

    vector<int> PreviousSmaller(vector<int>& heights){
        //i want index so store index naa
        int n = heights.size();
        vector<int> PreviousSmallerElement(n);
        stack<int> index;
        for(int i = 0 ; i < n; i++){
            while(!index.empty() && heights[i] <= heights[index.top()]){
                index.pop();
            }
            if(index.empty()){
                PreviousSmallerElement[i] = -1;
                index.push(i);
            }
            else{
                PreviousSmallerElement[i] = index.top();
                index.push(i);
            }
        }

        return PreviousSmallerElement;
    }


public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NextSmallerElement = NextSmaller(heights);
        vector<int> PreviousSmallerElement = PreviousSmaller(heights);
        int ans = 0;
        int area = 0;
        for(int i = 0 ; i < n ; i++){
            cout<<NextSmallerElement[i]<<" "<<PreviousSmallerElement[i]<<endl;
            area = heights[i] * (NextSmallerElement[i] - PreviousSmallerElement[i] - 1);
            ans = max(ans , area);
        }
        return ans;
    }
};
 
 
int main()
{
     
    return 0;
}
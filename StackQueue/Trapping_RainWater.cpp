#include <bits/stdc++.h>
using namespace std;

// By analysing itna samjha ki dono taraf usse badda hai kii nhi yeh dekh lo tabhi water trap hoo raha hoga 
// Brute force approach giving TLE
//TC: O(n2);
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 1 ; i < n -1 ; i++){
            int col1 = 0 , col2 = 0;
            int j = i - 1;
            while(j >= 0){
                if(height[j] > height[i]){
                    col1 = max(col1 , height[j]);
                }
                j--;
            }
            if(col1){
                j = i + 1;
                while(j < n){
                    if(height[j] > height[i]){
                        col2 = max(col2 , height[j]);
                    }
                    j++;
                    if(col2 >= col1)break;
                }
                if(col2) ans+= min(col1 , col2) - height[i];
            }
        }
        return ans;
    }
};

// Aproach 2:
// Optimize using suffix prefix sum but i do it something another way

// can you came up with the approach which takes SC : O(1) Interviewer and TC: O(n);


class Solution {
    vector<int> AfterHighestElement(vector<int> &arr){
        int n = arr.size();
        int maxi = arr[n - 1];
        vector<int> ahe(n);
        ahe[n - 1] = -1;
        for(int i = n - 2; i >= 0 ; i--){
             if(arr[i] < maxi){
                ahe[i] = maxi; 
             }
             else{
                ahe[i] = -1;
                maxi = arr[i];
             }
        }
        return ahe;
    }

    vector<int> BeforeHighestElement(vector<int> &arr){
        int n = arr.size();
        int maxi = arr[n - 1];
        vector<int> bhe(n);
        bhe[0] = -1;
        for(int i = 1 ; i < n  ; i++){
             if(arr[i] < maxi){
                bhe[i] = maxi; 
             }
             else{
                bhe[i] = -1;
                maxi = arr[i];
             }
        }
        return bhe;
    }


    
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ahe = AfterHighestElement(height);
        vector<int> bhe = BeforeHighestElement(height);
        int ans = 0;
        for(int i = 0 ; i< n ; i++){
            int nextHigh = ahe[i];
            int beforeHigh = bhe[i];
            if(ahe[i]!=-1 && bhe[i]!=-1)
                ans += min(nextHigh , beforeHigh) - height[i];
        }
    }
};


// Most optimal approach is still pending 

class Solution {
public:
    int trap(vector<int>& height) {
        int lmax ,rmax , total ;
        lmax = rmax = total = 0;
        int l = 0;
        int n = height.size();
        int r = n - 1;

        while(l < r){
            if(height[l] <= height[r]){
                if(lmax > height[l]){
                    total += lmax - height[l];
                }
                else{
                    lmax = height[l];
                }
                l++;
            }

            else{
                if(rmax > height[r]){
                    total += rmax - height[r];
                }

                else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// wrote the code correct but pitfall are currPos can go to negative how will i deal with negative in dp
// only 2 test cases are missing rest is okay

// soo toda complicated code bhi likha hai mene usse bhi simpler bana sakte hai

// can we use offset like suppose startpos = 1 but k = 4

// then -3 tak jaa sakta hai 5 {-3 , 5} range which is actually 8 startPos + 2*k is write

class Solution
{
    int mod = 1e9 + 7;
    int solve(int sp, int ep, int currPos, int rem, vector<vector<int>> &dp, int offset)
    {
        if (currPos < 0)
            return 0;
        if (rem == 0 && currPos == ep)
            return dp[currPos + offset][rem] = 1;

        if (rem == 0)
        {
            return dp[currPos + offset][rem] = 0;
        }

        if (dp[currPos + offset][rem] != -1)
            return dp[currPos + offset][rem];

        // if(abs(ep - sp) > rem)return 0;

        int ways = (solve(sp, ep, currPos + 1, rem - 1, dp, offset) + solve(sp, ep, currPos - 1, rem - 1, dp, offset)) % mod;
        return dp[currPos + offset][rem] = ways;
    }

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        // why dont you try all the possiblilites
        int diff = abs(endPos - startPos);
        if (diff > k || ((diff & 1) && !(k & 1)) || (!(diff & 1) && k & 1))
        {
            cout << "YOO";
            return 0;
        }

        // now applying recursive approach
        // vector<VECint> dp(k + 1 , -1);
        int offset = k;
        int last = startPos + 2 * k;
        vector<vector<int>> dp(last + 1, vector<int>(k + 1, -1));
        // vector<vector<int>> dp;

        return solve(startPos, endPos, startPos, k, dp, offset);
    }
};

class Solution
{
    int mod = 1e9 + 7;
    int solve(int sp, int ep, int currPos, int rem, vector<vector<int>> &dp, int offset)
    {
        // if(currPos < 0)return 0;
        if (rem == 0)
            return dp[currPos + offset][rem] = currPos == ep;

        if (dp[currPos + offset][rem] != -1)
            return dp[currPos + offset][rem];

        if (abs(ep - currPos) > rem)
            return 0;

        int ways = (solve(sp, ep, currPos + 1, rem - 1, dp, offset) + solve(sp, ep, currPos - 1, rem - 1, dp, offset)) % mod;
        return dp[currPos + offset][rem] = ways;
    }

public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        // why dont you try all the possiblilites
        int diff = abs(endPos - startPos);
        if (diff > k || ((diff & 1) && !(k & 1)) || (!(diff & 1) && k & 1))
        {
            return 0;
        }
        int offset = k;
        int last = startPos + 2 * k;
        vector<vector<int>> dp(last + 1, vector<int>(k + 1, -1));

        return solve(startPos, endPos, startPos, k, dp, offset);
    }
};

int main()
{

    return 0;
}
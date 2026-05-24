#include <bits/stdc++.h>
using namespace std;

// Find the number of ways in which expression is true

// memoization soln
class Solution
{
    int solve(string exp, int i, int j, int isTrue, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
                exp[i] == 't';
            else
                exp[i] == 'f';
        }

        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ways = 0;
        for (int k = i + 1; k <= j - 1; j += 2)
        {

            int lt = solve(exp, i, k - 1, 1, dp);
            int rt = solve(exp, k + 1, j, 1, dp);
            int lf = solve(exp, i, k - 1, 0, dp);
            int rf = solve(exp, k + 1, j, 0, dp);

            if (exp[k] == '&')
            {
                if (isTrue)
                {
                    ways = ways + lt * rt;
                }
                else
                {
                    ways = ways + lf * rt + lt * rf + lf * rf;
                }
            }

            else if (exp[k] == '|')
            {
                if (isTrue)
                {
                    ways = ways + lf * rt + lt * rf + lt * rt;
                }
                else
                {
                    ways = ways + lf * rf;
                }
            }

            else
            {
                if (isTrue)
                {
                    ways = ways + lf * rt + rf * lt;
                }
                else
                {
                    ways = ways + lf * rf + rt * lt;
                }
            }
        }

        return dp[i][j][isTrue] = ways;
    }

public:
    int booleanExpression(string exp)
    {
        int n = exp.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        return solve(exp, 0, n - 1, 1, dp);
    }
};

// converting the code tabulation

class Solution
{
    int solve(string exp)
    {
        int n = exp.size();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));

        for (int i = 0; i < n; i++)
        {
            dp[i][i][0] = exp[i] == 'f';
            dp[i][i][1] = exp[i] == 't';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                int ways = 0;
                for (int isTrue = 0; isTrue < 2; isTrue++)
                {
                    for (int k = i + 1; k <= j - 1; k++)
                    {
                        int lt = dp[i][k - 1][1];
                        int rt = dp[k + 1][j][1];
                        int lf = dp[i][k - 1][0];
                        int rf = dp[k + 1][j][0];

                        if (exp[k] == '&')
                        {
                            if (isTrue)
                            {
                                ways = ways + lt * rt;
                            }
                            else
                            {
                                ways = ways + lf * rt + lt * rf + lf * rf;
                            }
                        }

                        else if (exp[k] == '|')
                        {
                            if (isTrue)
                            {
                                ways = ways + lf * rt + lt * rf + lt * rt;
                            }
                            else
                            {
                                ways = ways + lf * rf;
                            }
                        }

                        else
                        {
                            if (isTrue)
                            {
                                ways = ways + lf * rt + rf * lt;
                            }
                            else
                            {
                                ways = ways + lf * rf + rt * lt;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return dp[n - 1][0][1];
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Just need to add minimum character in starting to make the string pallindrome

// what am i doing ?
// just checking pehele character se kitna bada pallindromw possible hai
// akela charater always possible

// TLE for only 2 test case   BAAKI SAB OKK HAI
class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();

        string ans = "";

        int i;
        for (i = n - 1; i >= 0; i--)
        {
            int start = 0;
            int curr = i;
            while (start < curr)
            {
                if (s[start] != s[curr])
                    break;
                else
                {
                    start++;
                    curr--;
                }
            }

            if (start >= curr)
            {
                // found a string
                //  of 0 to i length
                ans = s.substr(0, i);
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            ans.insert(ans.begin(), s[j]);
        }

        return ans;
    }
};

// We can do it by kmp algorithm just

// string + # + rev(string)

// with this we can find the mathching character from starting that we think in above soln in the last block of prefix_fun table
// then just directly add remaining in reverse order

class Solution
{
    vector<int> prefix_fun(string s)
    {

        int n = s.size();

        vector<int> pi(n, 0);

        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];

            while (j > 0 and s[i] != s[j])
            {
                j = pi[j - 1];
            }

            if (s[i] == s[j])
                j++;

            pi[i] = j;
        }

        return pi;
    }

public:
    string shortestPalindrome(string s)
    {
        int m = s.size();
        string revS = s;
        reverse(revS.begin() , revS.end());
        string temp = s + '#' + revS;

        vector<int> prefix = prefix_fun(temp);

        int n = prefix.size();

        int cnt = prefix[n - 1];

        cout<<cnt<<endl;

        string ans = "";

        for(int i = m-1 ; i >=cnt ; i--){
            ans+=s[i];
        }

        return ans+s;
    }
};

//Intution and above soln is not correct yet exahust do it at evening/ tomorrow

int main()
{

    return 0;
}
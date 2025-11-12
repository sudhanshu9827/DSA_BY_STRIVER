// Link : https://leetcode.com/problems/expression-add-operators/
// i Literally wrote 128 lines of code for a single problem 
// Its working but WITH TLE for small cases


#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
    int EvaluateString(string s)
    {
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '*')
            {
                int temp = (s[i - 1] - '0') * (s[i + 1] - '0');
                s.erase(s.begin() + i - 1, s.begin() + i + 2);
                s.insert(i - 1, to_string(temp));
            }
            else
                i++;
        }
        // cout<<s<<endl;
        int ans = 0;
        if (s[1] == '+' || s[1] == '-')
        {
            ans = s[0] - '0';
            i = 1;
        }
        else
        {
            string tmp = string(1, s[0]);
            tmp += s[1];
            ans += stoi(tmp);
            // cout<<ans;
            i = 2;
        }

        // cout<<ans;

        while (i < s.size())
        {
            if (s[i] == '+')
            {
                i++;
                string curr = "";
                while (i < s.size() && s[i] != '+' && s[i] != '-')
                {
                    curr += s[i];
                    // cout<<s[i]<<"s[i]"<<endl;
                    i++;
                    // cout<<"hii"<<curr<<" curr  ";
                    // cout<<s[i]<<"s[i]"<<endl;
                }
                ans += stoi(curr);
                // cout<<i<<"->"<<ans<<endl;
            }
            else if (s[i] == '-')
            {
                i++;
                string curr = "";
                while (i < s.size() && s[i] != '+' && s[i] != '-')
                {
                    curr += s[i];
                    i++;
                }
                ans -= stoi(curr);
            }
            // cout<<ans;
        }
        // cout<<ans;
        return ans;
    }

    void addoper(string num, int target, string &s, ll current, vector<string> &ans, int index)
    {
        if (index == num.size())
        {
            if (target == EvaluateString(s))
            {
                ans.push_back(s);
            }
            return;
        }

        // add , mul , sub
        ll next = num[index] - '0';
        s.push_back('+');
        s.push_back(num[index]);
        addoper(num, target, s, current + next, ans, index + 1);
        s.pop_back();
        s.pop_back();

        s.push_back('-');
        s.push_back(num[index]);
        addoper(num, target, s, current - next, ans, index + 1);
        s.pop_back();
        s.pop_back();

        s.push_back('*');
        s.push_back(num[index]);
        addoper(num, target, s, current * next, ans, index + 1);
        s.pop_back();
        s.pop_back();
    }

public:
    vector<string> addOperators(string num, int target)
    {
        ll current = num[0] - '0';
        vector<string> ans;
        string s;
        s.push_back(num[0]);
        addoper(num, target, s, current, ans, 1);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> v = s.addOperators("232" , 8);
    for(string i  : v){
        cout<<i<<" ";
    }
    return 0;
}
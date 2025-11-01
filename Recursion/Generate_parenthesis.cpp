// I clearly see the tree of parenthesis soo apply recusion is the better thinking 
// What mistake i did 
// Rather than using count i am using balance here but it also reduse its not correct
// after than i realize i need to maintain the count of '(' parenthesis 

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void AddParenthesis(vector<string>& ans, int n, int balance, string s, int count) {
        // Base condition: if the string length reaches 2*n
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // If we can still add '('
        if (count < n)
            AddParenthesis(ans, n, balance + 1, s + "(", count + 1);

        // If there is an unmatched '(' to balance
        if (balance)
            AddParenthesis(ans, n, balance - 1, s + ")", count);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        AddParenthesis(ans, n, 0, "", 0);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "All combinations of balanced parentheses:\n";
    for (auto &s : result) {
        cout << s << "\n";
    }

    return 0;
}

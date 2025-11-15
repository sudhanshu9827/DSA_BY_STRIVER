// Everyone knows this but code i usually forgot or why dont i write the code at the time i dont even get it
// but its really very simple

// approach:
// if character directy add it into the string
// if ( or  ) need to think
// if( operator hoo sakta hai naa) haa tab kya karoge
// precedence kaise banaoge yeh bhi too sochna padega
// Numbering de dunga precedence koo yaa too koi unique character


// For infix to prefix 
// 1. Reverse the whole string find the postfix expression with one change for same presedence let them stay into the stack 


#include <bits/stdc++.h>
using namespace std;

bool CheckCh(char c)
{
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int prec(char oper)
{
    if (oper == '^')
        return 3;
    else if (oper == '*' || oper == '/')
        return 2;
    else if (oper == '+' || oper == '-')
        return 1;
    return -1;
}

string InfixToPostfix(string s)
{
    string ans;
    int n = s.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        // if character
        if (CheckCh(s[i]))
            ans += s[i];

        else if (s[i]=='(')
            st.push('(');

        else if (s[i]==')')
        {
            // can you please pop the elements
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            // abb operator aa gaya
            // precedence too check karni hai
            // agar koi operator aaya too usse jaad yaaa utni precedence rakhne waale saare nikal jaayenge
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    cout<<InfixToPostfix(exp);
    return 0;
}
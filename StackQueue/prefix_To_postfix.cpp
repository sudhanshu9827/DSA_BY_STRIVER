#include <bits/stdc++.h>
using namespace std;

bool CheckCh(char c)
{
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
        return true;
    return false;
}

string Prefix_To_Postfix(string s){
    reverse(s.begin() , s.end());
    stack<string> st;

    for(int i = 0 ; s[i]!='\0' ; i++){
        if(CheckCh(s[i])){
            st.push(string(1 , s[i]));
        }

        else{
            string oper1 = st.top();
            st.pop();

            string oper2 = st.top();
            st.pop();

            st.push(oper1 + oper2 + s[i]);
        }
    }

    return st.top();
}
 
int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Postfix Expression: " << Prefix_To_Postfix(prefix) << endl;
    return 0;
    return 0;
}
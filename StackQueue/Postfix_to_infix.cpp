// Sab pata hai tabhi nhi kar raha string ko push karo naa stack me kya problem hai 

// prefix to infix me just reverse karna hai oper1 + s[i] + oper2 karna hai 

#include <bits/stdc++.h>
using namespace std;

bool CheckCh(char c)
{
    if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
        return true;
    return false;
}

string PostfixToInfix(string s){
    stack<string> st;
    // string ke saath khelo too size mat bolo \0 bolo naa 
    for(int i = 0 ; s[i]!='\0'; i++){
        if(CheckCh(s[i])){
            st.push(string(1 , s[i]));
        }
        else{
            //operand hai 
            string opr1 = st.top();
            st.pop();
            string opr2 = st.top();
            st.pop();
            st.push(opr2 + s[i] + opr1);
        }
    }

    return st.top();
}
 
int main()
{
    string exp = "ab*c+";
    cout << PostfixToInfix(exp);
    return 0;

}
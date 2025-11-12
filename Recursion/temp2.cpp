#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s = "abc";
    string temp = "14";
    s.insert(2 , "bs");
    s.erase(s.begin() , s.begin()+2);     
    cout<<s;
    return 0;
}
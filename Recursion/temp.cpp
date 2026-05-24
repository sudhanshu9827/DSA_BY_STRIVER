#include <bits/stdc++.h>
using namespace std;

int EvaluateString(string s)
{
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == '*')
        {
            int temp = (s[i - 1] - '0') * (s[i + 1]-'0');
            s.erase(s.begin() + i - 1, s.begin() + i + 2);
            s.insert(i - 1 ,to_string(temp));
        }
        else i++;
    }
    // cout<<s<<endl;
    int ans = 0;
    if(s[1] == '+' || s[1] == '-'){
        ans = s[0] - '0';
        i = 1;
    }
    else{
        string tmp = string(1 , s[0]);
        tmp +=s[1];
        ans += stoi(tmp);
        // cout<<ans;
        i = 2;
    }

    // cout<<ans;

    while(i < s.size()){
        if(s[i] == '+'){
            i++;
            string curr = "";
            while(i < s.size() && s[i]!= '+' && s[i]!='-'){
                curr+=s[i];
                // cout<<s[i]<<"s[i]"<<endl;
                i++;
                // cout<<"hii"<<curr<<" curr  ";
                // cout<<s[i]<<"s[i]"<<endl;
            }
            ans+=stoi(curr);
            // cout<<i<<"->"<<ans<<endl;
        }
        else if(s[i] == '-'){
            i++;
            string curr = "";
            while(i < s.size() && s[i]!= '+' && s[i]!='-'){
                curr+= s[i];
                i++;
            }
            ans-=stoi(curr);
        }
        // cout<<ans;
    }
    // cout<<ans;
    return ans;
}

int main()
{
    string s = "9+10";
    cout<<EvaluateString(s);
    return 0;
}
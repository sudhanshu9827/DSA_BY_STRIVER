#include <bits/stdc++.h>
using namespace std;

// What i forgot
// in erase range me joo last me hota hai include nhi hota
// jo element delete hii nhi hoo raha usko kyu hatana
// while true () naa chalate hue agar pair gayab hoo raha hai then bus ek peeche jaakar dekh raha hu dubrara pair too nhi ban raha

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int i = 0;

        while (i < (int)asteroids.size() - 1)
        {

            if (asteroids[i] > 0 && asteroids[i + 1] < 0)
            {

                if (asteroids[i] == abs(asteroids[i + 1]))
                {
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                }
                else if (asteroids[i] > abs(asteroids[i + 1]))
                {
                    int temp = asteroids[i];
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    asteroids.insert(asteroids.begin() + i, temp);
                }
                else
                {
                    int temp = asteroids[i + 1];
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    asteroids.insert(asteroids.begin() + i, temp);
                }

                // MINIMAL BUT CRITICAL CHANGE:
                // Move back 1 step to catch chain reactions and avoid full rescans
                if (i > 0)
                    i--;
            }
            else
            {
                i++;
            }
        }

        return asteroids;
    }
};

// using stack
// Approach : 2

// What was the problem i face 

// I get to know about what i use && then || due left to right  && some codiion || some condition || then this (&&)<- due to left to right have higher priority


class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        stack<int> st;

        int n = asteroids.size();
        for (int i = 0; i < n; i++)
        {
            bool equal_or_less= false;
            while (!st.empty() && (st.top() > 0 && asteroids[i] < 0))
            {
                if (abs(st.top()) == abs(asteroids[i]))
                {
                    equal_or_less = true;
                    st.pop();
                    break;
                }
                else if (abs(st.top()) < abs(asteroids[i]))
                {
                    equal_or_less = false;
                    st.pop();
                }

                else{
                    equal_or_less = true;
                    break;
                }
            }
            if(!equal_or_less)st.push(asteroids[i]);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}
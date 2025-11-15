#include <bits/stdc++.h>
using namespace std;

// What i forgot 
// in erase range me joo last me hota hai include nhi hota 
//jo element delete hii nhi hoo raha usko kyu hatana 
// while true () naa chalate hue agar pair gayab hoo raha hai then bus ek peeche jaakar dekh raha hu dubrara pair too nhi ban raha 


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i = 0;

        while (i < (int)asteroids.size() - 1) {

            if (asteroids[i] > 0 && asteroids[i + 1] < 0) {

                if (asteroids[i] == abs(asteroids[i + 1])) {
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                }
                else if (asteroids[i] > abs(asteroids[i + 1])) {
                    int temp = asteroids[i];
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    asteroids.insert(asteroids.begin() + i, temp);
                }
                else {
                    int temp = asteroids[i + 1];
                    asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    asteroids.insert(asteroids.begin() + i, temp);
                }

                // MINIMAL BUT CRITICAL CHANGE:
                // Move back 1 step to catch chain reactions and avoid full rescans
                if (i > 0) i--;
            }
            else {
                i++;
            }
        }

        return asteroids;
    }
};

int main()
{
     
    return 0;
}
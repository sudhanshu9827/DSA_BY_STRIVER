#include <bits/stdc++.h>
using namespace std;

// Wrong for duplicate values
class Solution
{
    bool HandsOfStraight(vector<int> &hands, int groupSize)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(hands.begin(), hands.end());

        while (!minHeap.empty())
        {
            int curr = minHeap.top();
            for (int i = 0; i < groupSize; i++)
            {
                if (!minHeap.empty())
                {
                    if (curr != minHeap.top())
                        return false;
                }
                else
                    return false;
                curr++;
                minHeap.pop();
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        sort(hand.begin() , hand.end());
        unordered_map<int, vector<int>> val;

        for (int i = 0; i < hand.size(); i++)
        {
            val[hand[i]].push_back(i);
        }

        vector<int> visited(hand.size(), 0);

        for (int i = 0; i < hand.size(); i++)
        {
            int index;
            if (!visited[i])
            {
                int curr = hand[i];
                for (int j = 0; j < groupSize; j++)
                {
                    // cout<<curr<<endl;
                    if (val.find(curr) != val.end())
                    {
                        // cout<<curr<<endl;
                        index = val[curr].front();
                        cout<<index<<endl;
                        val[curr].erase(val[curr].begin());
                        if (val[curr].size() == 0)
                            val.erase(curr);
                        visited[index] = 1;
                    }
                    else
                        return false;
                    curr++;
                }
            }
        }
        return true;
    }
};

// TUF Soltuion next time issi se karunga 
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // If total cards can't be divided evenly, return false
        if (hand.size() % groupSize != 0) return false;

        // Store the frequency of each card
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Create an iterator pointing to the beginning of the frequency map
        auto it = freq.begin();

        // Loop through all keys in the map
        while (it != freq.end()) {

            // Skip cards that are already used up
            if (it->second == 0) {
                ++it;
                continue;
            }

            // Store the starting card of the group
            int start = it->first;

            // Number of times we need to form this group
            int count = it->second;

            // Try to form a group of consecutive cards of size groupSize
            for (int i = 0; i < groupSize; ++i) {

                // If the current required card is missing or doesn't have enough frequency
                if (freq[start + i] < count) return false;

                // Decrease the frequency for current card
                freq[start + i] -= count;
            }

            // Move the iterator to the next element
            ++it;
        }

        // All groups formed successfully
        return true;
    }
};

int main()
{

    return 0;
}
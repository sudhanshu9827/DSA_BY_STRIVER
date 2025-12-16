#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char t : tasks)
            freq[t - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int countMax = 0;

        for (int f : freq) {
            if (f == maxFreq)
                countMax++;
        }

        int intervals = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), intervals);
    }
};

// Not able to find mine self mistake this is the major issue 

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // like maximum frequency waala uper rakhte hai heap me teekh hai lekar pop kar do kab tak jab tak usska n cycle puri naa hoo jaaye
        vector<int> freq(26);
        for(int task : tasks)freq[task - 'A']++;

        priority_queue<int> maxHeapTask(freq.begin() , freq.end());
        // abb me kehe raha hu usski cycle purri hone tak baapas nhi laaunga 
        int time = 0;
        // pehle jaayega aur pehele bahar niklega 
        // queue<freqOfElement , timeAtwhichenter>
        queue<pair<int , int>> freqTime; 
        while(!maxHeapTask.empty() || !freqTime.empty()){
            time++;
            int freqTask = 0;
            if(!maxHeapTask.empty()){
                freqTask = maxHeapTask.top() - 1;
                maxHeapTask.pop();
                cout<<freqTask<<endl;
            }
            else cout<<"AnderNHIGaya"<<endl;

            if(freqTask > 0){
                freqTime.push({freqTask , time});
            }

            if(!freqTime.empty()){
                if(time - freqTime.front().second == n){
                    maxHeapTask.push(freqTime.front().first);
                    freqTime.pop();
                }
            }
        }
        return time;
    } 
};

 
int main()
{
     
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Learning characters ko graph me representation 

//Remember  

// Todo  : do it again ! nice one very intutive

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // what i think initially ki saare z tak le leta hu boo bhi kar sakte the phir extra check karna padta 

        int n = words.size();

        vector<set<int>> adj(26);

        vector<bool> exist(26);

        for(auto word : words){
            for(char ch : word){
                exist[ch - 'a'] = true;
            }
        }

        // Adjacency list 
        for(int i = 0 ; i < n - 1 ; i++){
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size() , word2.size());

            // if(word1.size() > word2.size())return "";
            int j;
            for(j = 0 ; j < len ; j++){
                if(word1[j]!=word2[j]){
                    adj[word1[j] - 'a'].insert(word2[j] - 'a');
                    break;
                }
            }
            // Edge case 
            if(j == len){
                if(word1.size() > word2.size())return "";
            }
        }

        vector<int>indegree(26 , 0);
        
        for(int i = 0 ; i < 26 ; i++){
            for(auto v : adj[i]){
                indegree[v]++;
            }
        }

        // Topological sort 

        queue<int> q;

        string ans = "";

        for(int i = 0 ; i < 26 ; i++){
            if(exist[i] && indegree[i] == 0){
                q.push(i);
            }
            // cout<<indegree[i]<<" ";
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            ans+='a' + curr;

            for(auto v : adj[curr]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        for(int i = 0 ; i < 26; i++){
            // cout<<indegree[i]<<" ";
            if(indegree[i]>0){
                return "";
            }
        }
        
        // cout<<ans;
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
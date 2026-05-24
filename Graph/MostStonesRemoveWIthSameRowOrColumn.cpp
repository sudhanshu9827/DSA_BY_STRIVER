#include <bits/stdc++.h>
using namespace std;

// I get an idea that disjoint set is used in this question because dynamically daal rahe ultimate parent ka bhi use hai 

// but it said [xi , yi] is any thing but in size or parenting we assume to be concecutive if any thing then how may i deal with this stuff 


// Conceptually doing wrong 
// Think more 

// class DisjointSet{
//     vector<int> rank , parent , size;
//     public:
//         // constructor 
//         DisjointSet(int n){
//             rank.resize(n + 1 , 0); // to work with both zero as well as 1 based indexing
//             parent.resize(n + 1);
//             size.resize(n + 1 , 1);

//             for(int i = 0 ; i < n ; i++){
//                 parent[i] = i;
//             }
//         }

//         int findPar(int node){
//             if(node == parent[node]){
//                 return node;
//             }

//             return parent[node] = findPar(parent[node]); // This is where we used path compression
//         }

//         void unionByRank(int u , int v){
//             int ulp_u = findPar(u);
//             int ulp_v = findPar(v);

//             if(ulp_u == ulp_v) return ;

//             if(rank[ulp_u] < rank[ulp_v]){
//                 // soo smaller guy gets attached 
//                 parent[ulp_u] = ulp_v;
//             }

//             else if(rank[ulp_u] > rank[ulp_v]){
//                 parent[ulp_v] = ulp_u;
//             }

//             else{
//                 // if both the ranks are equall can attack anbody with anyone 
//                 parent[ulp_v] = ulp_u;
//                 rank[ulp_u]++;
//             }
//         }

//         void unionBySize(int u , int v){
//             int ulp_u = findPar(u);
//             int ulp_v = findPar(v);

//             if(ulp_u == ulp_v)return;

//             if(size[ulp_u] < size[ulp_v]){
//                 parent[ulp_u] = ulp_v;
//                 size[ulp_v]+=size[ulp_u];
//             }

//             else{
//                 parent[ulp_v] = ulp_u;
//                 size[ulp_u]+=size[ulp_v];
//             }
//         }
// };

// // agar n le lunga too n nodes hai boo nodes too pata hii nhi hai kitne hai kitne nhi yaha 
// // n waha nodes hai 

// // yaha stones matlb jisse me edge consider kar raha hu boo hai 

// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {

//         vector<int> present(1e4 + 1 , 0);

//         for(auto st : stones){
//             int u = st[0];
//             int v = st[1];

//             present[u] = 1;
//             present[v] = 1;
//         }

//         int numNodes = 0;

//         for(int i = 0 ;  i <= 1e4 ; i++){
//             if(present[i]){
//                 numNodes++;
//             }
//         }

//         DisjointSet ds(numNodes);

//         for(auto st : stor(v);

//             if(ulp_u == ulp_v) return ;

//             if(rank[ulp_u] < rank[ulp_v]){
//                 // soo smaller guy gets attached 
//                 parent[ulp_u] = ulp_v;
//             }

//             else if(rank[ulp_u] > rank[ulp_v]){
//                 parent[ulp_v] = ulp_u;
//             }
// nes){
//             int u = st[0];
//             int v = st[1];

//             ds.unionBySize(u , v);
//         }

//         int count = 0;

//         for(int i = 0 ; i < numNodes ; i++){
//             if(ds.findPar(i) == i){
//                 count++;
//             }
//         }

//         return stones.size() - 1;
//     }
// };




// component waali cheez dimaag me aai thi 

// bilkul base se chaloge tabhi jaakar samjh me aayega actuall me lagana kya hai dont be raTA totha 

// how do i represent represent nodes based on there cordinate like (xi , yi)

// what striver is doing take row and column as a node 



class DisjointSet{
    vector<int> rank , parent , size;
    public:
        // constructor 
        DisjointSet(int n){
            rank.resize(n + 1 , 0); // to work with both zero as well as 1 based indexing
            parent.resize(n + 1);
            size.resize(n + 1 , 1);

            // yaha n ko equal me nhi likha tha
            for(int i = 0 ; i <= n ; i++){
                parent[i] = i;
            }
        }

        int findPar(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findPar(parent[node]); // This is where we used path compression
        }

        void unionByRank(int u , int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v) return ;

            if(rank[ulp_u] < rank[ulp_v]){
                // soo smaller guy gets attached 
                parent[ulp_u] = ulp_v;
            }

            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }

            else{
                // if both the ranks are equall can attack anbody with anyone 
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u , int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v)return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }

            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto st : stones){
            maxRow = max(maxRow , st[0]);
            maxCol = max(maxCol , st[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);


        //We need to take care which are used otherwise joo use nhi hai boo bhi aa jaayenge
        // taking unordered_map to track which are stored 
        // unordered_map<int , int> track;  it is not a good practise 
        unordered_set<int> track;
        
        for(auto st : stones){
            track.insert(st[0]);
            track.insert(st[1] + maxRow + 1);
            ds.unionBySize(st[0] , st[1] + maxRow + 1);
        }

        // now just need to check ultimate parent 

        int count = 0;

        for(auto tr : track){
            if(ds.findPar(tr) == tr){
                count++;
            }
        }
        return stones.size() - count;
    }
};


// Different approach 

// By dfs how do we create the graph very intutive 



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // Adjacency list to store graph connections
        vector<vector<int>> adjacencyList(n);

        // Build the graph: Connect stones that share the same row or column

        // This is very intutive try to get the idea 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        vector<bool> visited(n, false);

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of
        // connected components
        return n - numOfConnectedComponents;
    }

private:
    // DFS to visit all stones in a connected component
    void depthFirstSearch(vector<vector<int>>& adjacencyList,
                          vector<bool>& visited, int stone) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
};

int main() {
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// karne se pehle test cases too soch loo warna time bhi barwaad aur question bhi nhi hoga 

// like duplicate ke liye fail hoo raha hai program 
//think just think harder array me hamesha duplicare null , 0 ke baare me sochna hii hai \\

// Heap se karne kaa koi tareeka samjh nhi aa raha  aur two 
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int> ans;
        
        int sizeA = a.size();
        int sizeB = b.size();
        
        sort(a.rbegin() , a.rend());
        sort(b.rbegin() , b.rend());
        
        int currMaxA ;
        int currMaxB ;
        
        int currMaxPointA = 0;
        int currMaxPointB = 0;
        
        while(k--){
            
            int currMaxA = a[currMaxPointA];
            int currMaxB = b[currMaxPointB];
            
            ans.push_back(currMaxA + currMaxB);
            
            int nextMaxPointA = currMaxPointA + 1;
            int nextMaxPointB = currMaxPointB + 1;
            
            while(k && nextMaxPointA < sizeA && nextMaxPointB < sizeB){
                if(currMaxA + a[nextMaxPointB] > currMaxB + b[nextMaxPointA]){
                    ans.push_back(currMaxA + b[nextMaxPointB]);
                    nextMaxPointB++;
                }
                else{
                    ans.push_back(currMaxB + a[nextMaxPointA]);
                    nextMaxPointA++;
                }
                k--;
            }
            while(k && nextMaxPointA < sizeA){
                ans.push_back(currMaxB + a[nextMaxPointA]);
                k--;
            }
            
            while(k && nextMaxPointB < sizeB){
                ans.push_back(currMaxA + b[nextMaxPointB]);
                k--;
            }
            
            currMaxPointA++;
            currMaxPointB++;
        }
        
        return ans;
    }
};


// Heap ke baare me sochna toda difficult hai 
// sort kar diya sum joo pehle ka aayega wahi maximum hoga yeh pata hai
//abb joo maximum ko pop kara rahe uske behalf par yaa too (i j+1) wala pair max hoga yaa (i + 1 , j) wala harr case me yaa too joo pehle hi heap me hai boo bhi max hoo sakta hai 
//kar pointer walla kaam hii rahe hai but consideration se 

// [10 , 9 , 5 , 3 ,7] & [6 6 3 2 2] uper waal me 6 6 doo hai then ussme dikkat aa rahi thi 
// but heap me boo consider dono 6 6 ko kar lega ek 10 se saath bhi aur ek hii 9 ke saath bhi 

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        //sort both the array
        sort(a.begin() , a.end() , greater<int>());
        sort(b.begin() , b.end() , greater<int>());

        // priority_queue me 3values ko store karna hai kya laago tuple laga sakte hai 
        priority_queue<tuple<int , int , int>> maxHeap;

        // <sum , a->i , b->j> 

        set<pair<int , int>> visited;

        maxHeap.push({a[0] + b[0] , 0 , 0});
        visited.insert({0 , 0});

        vector<int> ans;

        while(k-- && !maxHeap.empty()){
            auto [sum , i , j] = maxHeap.top();

            ans.push_back(sum);

            maxHeap.pop();

            // push karna (i , j + 1)

            if(j + 1< b.size() && !visited.count({i , j+1})){
                maxHeap.push({a[i] + b[j+1] , i , j+1});
                visited.insert({i , j + 1});
            }

            if(i + 1 < a.size() && !visited.count({i+1 , j})){
                maxHeap.push({a[i+1] + b[j] , i+1 , j});
                visited.insert({i + 1 , j});
            }
        }
        return ans;
    }
};
 
int main()
{
     
    return 0;
}
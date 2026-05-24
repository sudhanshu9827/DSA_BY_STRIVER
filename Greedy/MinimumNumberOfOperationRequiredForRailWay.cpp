#include <bits/stdc++.h>
using namespace std;


// prev waali train bethi hai isska matlb yeh todi hai ki joo beech me train aai hai boo bhi beti rahe 
// 900 ->920
// 917->918
// 919->921
// issme beech waali train jaa chuki hai ussko consider karna hii nahi tha 

// Completely wrong Solution and approach
// class Solution{
//     public:
//         int minNumberStation(vector<int>& arr , vector<int>& dep){
//             vector<pair<int , int>> departure;
//             int n = arr.size();

//             for(int i = 0 ; i  < n ; i++){
//                 departure.push_back({dep[i] , i});
//             }
//             vector<int> newArr(arr);
//             sort(departure.begin() , departure.end());

//             // based on dep sort arrival 
//             int index;
//             for(int i = 0 ; i < n ; i++){
//                 index = departure[i].second;
//                 arr[index] = newArr[i];
//             }

//             int prevDepartureTime = departure[0].first;
//             int count = 1;
//             int ans = 1;
//             for(int i = 1 ; i < n; i++){
//                 if(arr[i] > prevDepartureTime)count = 1;
//                 else{
//                     count++;
//                     prevDepartureTime = departure[i].first;
//                     ans = max(ans , count);
//                 }
//             }

//             return ans;
//         }
// };


// Ask to Yourself does order really matter to us 

// station is like a box ussme kuch daal diya aur kuch nikal liya boo same hona todina zaruri hai 

// Am i right 


class Soluion{
    public:
        int minNumberStation(vector<int>& arr , vector<int>& dep){
            int n = arr.size();

            sort(arr.begin() , arr.end());
            sort(dep.begin() , dep.end());

            // int prevDep = dep[0];
            int count = 0;
            int ans = 0;
            int currArrIndex = 0;
            int prevDepIndex = 0;

            while(currArrIndex < n && prevDepIndex){
               if(arr[currArrIndex] <= arr[prevDepIndex]){
                count++;
                ans = max(ans , count);
                currArrIndex++;
               }

               else{
                    count--;
                    prevDepIndex++;
               }
            }
            return ans;
        }
};

int main()
{
     
    return 0;
}
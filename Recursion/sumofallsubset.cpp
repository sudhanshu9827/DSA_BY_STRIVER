#include <bits/stdc++.h>
using namespace std;

void display(vector<int> arr){
    for(int i : arr){
        cout << i << " ";
    }
    cout << "\n";
}

void findSum(int index , vector<int> &ans , const vector<int>& v , int sum){
    if(index == v.size()){
        ans.push_back(sum);
        return;
    }

    findSum(index + 1 , ans , v , sum + v[index]);

    findSum(index + 1 , ans , v , sum);
}
 
int main()
{

    vector<int> v = {3 , 1 , 2};
    sort(v.begin() , v.end());
    vector<int> ans;
    findSum(0 ,  ans , v , 0);
    sort(ans.begin() , ans.end());
    display(ans);
    return 0;
}
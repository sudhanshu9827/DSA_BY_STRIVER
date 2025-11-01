// this is simple just checking the sum i know the basic concept of subsequence 
// What if i want only one answer of subsequence how can i do that 
//you can check directly by flag but it is not recommended
// Rather than it 


#include <bits/stdc++.h>
using namespace std;
// bool flag = false; But this is not good to create a global variable 

void FindSubsequenceSumK(vector<int> arr, int s, int sum, vector<int>& subsequence, int index, vector<vector<int>>& res) {
    if (index == arr.size()) {
        if (s == sum ) {
            res.push_back(subsequence);
            // flag = true;
        }
        return; 
    }

    // pick the element
    subsequence.push_back(arr[index]);
    s += arr[index];
    FindSubsequenceSumK(arr, s, sum, subsequence, index + 1, res);

    // not pick the element
    subsequence.pop_back();
    s -= arr[index];
    FindSubsequenceSumK(arr, s, sum, subsequence, index + 1, res);
}

// print only 1 answer 

bool FindSubsequenceSumK_(vector<int> arr, int s, int sum, vector<int>& subsequence, int index, vector<vector<int>>& res) {
    if (index == arr.size()) {
        if (s == sum) {
            res.push_back(subsequence);
            // flag = true;
            return true;
        }
        return false; 
    }

    // pick the element
    subsequence.push_back(arr[index]);
    s += arr[index];
    if(FindSubsequenceSumK_(arr, s, sum, subsequence, index + 1, res) == true){
        return true;
    }

    // not pick the element
    subsequence.pop_back();
    s -= arr[index];
    if(FindSubsequenceSumK_(arr, s, sum, subsequence, index + 1, res)){
        return true;
    }

    return false;
}

// What if i just need to count the subsequence 

// structure is almost same for type of recursion 

int _FindSubsequenceSumK(vector<int> arr, int s, int sum, vector<int>& subsequence, int index) {
    if (index == arr.size()) {
        if (s == sum ) {
            // res.push_back(subsequence);
            // flag = true;
            return 1;
        }
        return 0;
    }

    // pick the element
    subsequence.push_back(arr[index]);
    s += arr[index];
    int left = _FindSubsequenceSumK(arr, s, sum, subsequence, index + 1);

    // not pick the element
    subsequence.pop_back();
    s -= arr[index];
    int right = _FindSubsequenceSumK(arr, s, sum, subsequence, index + 1);

    return left + right;
}

int main() {
    vector<int> arr = {4, 5, 3, 6, 7, 1, 2};
    int sum = 8;
    vector<vector<int>> res;
    vector<int> sub;

    FindSubsequenceSumK(arr, 0, sum, sub, 0, res);

    cout << "Subsequences with sum = " << sum << ":\n";
    for (auto& seq : res) {
        cout << "[ ";
        for (auto x : seq) cout << x << " ";
        cout << "]\n";
    }

    FindSubsequenceSumK_(arr, 0, sum, sub, 0, res);

    cout<<"Only one answer"<<endl;
    cout << "Subsequences with sum = " << sum << ":\n";
    for (auto& seq : res) {
        cout << "[ ";
        for (auto x : seq) cout << x << " ";
        cout << "]\n";
    }
    cout<<_FindSubsequenceSumK(arr , 0 , sum , sub , 0);


    return 0;
}

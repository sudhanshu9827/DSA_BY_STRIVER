#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums , int n , int curr_index , int step){
    if(step <= 0){
        return 0;
    }
    
    // i can choose different options 
    // like 1st take the element 
    int take  , notTake , take_left_go = 0 , take_right_go ,notTake_left_go= 0 , notTake_right_go = 0;
    
    
    if(curr_index < n){
        take_right_go =nums[curr_index] +  solve(nums , n , curr_index + 1 , step - 2);
        notTake_right_go = solve(nums , n , curr_index + 1 , step - 1);
    }
    
    if(curr_index > 0){
        Take_left_go = nums[curr_index] + solve(nums , n , curr_index - 1 , step - 2);
        notTake_right_go = sovle(nums , n , curr_index - 1 , step - 1);
    }
    
    
    take = max(take_right_go , Take_left_go);
    notTake = max(notTake_right_go , notTake_left_go);
    
    int ans = max(take , notTake);
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n , k; cin>>n>>k;
	    vector<int> nums(n);
	    
	    for(int i = 0 ; i < n ; i++){
	        cin>>nums[i];
	    }
	    
	    for(int i = 0 ; i < n ; i++){
	        cout<<solve(nums , n, i , k )<<" ";
	    }
	}

}

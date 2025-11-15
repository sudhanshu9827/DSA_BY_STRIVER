// I need to perform the operation basically on stack and getMIn in O(1);
// Basically min take O(n) time while scanning throughout the stack 
// But what basically in do is store yet min element

// Redefination why i am redefine the things take care from the next time 

#include <bits/stdc++.h>
using namespace std;



// Aproach : 1  
// took TC : O(1)
// Take SC: O(2n);

// Interviewer can you optimize the space complexity 

class MinStack {
    vector<pair<int , int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push_back({val , val});
        }

        else{
            int mini = st.back().second;

            int mini = min(val , mini);

            st.push_back({val , mini});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};



// Aproach : 2 (OPTIMIZE)
// Okk having minimum element as a variable but  how will i account the pop operation also pop the min element but it still saying me it is pop 
//Very important and intutive also 

// so some how i need to find the way such that i can store the current minimum and if pop i got the prevmin

// so i have my current min i have my prev min also make an equation with both of them and store it onto stack because mini is with me and this eqn is also with me just putt it back and find the answer 


// striver eqn : 2 * val - prevmin = newVal 
// IN this i definitely say :



// if min value needs to be change 
// val < min 
// val - min < 0
// add val on both the side 
// 2 val - min < val 
// newVal < val 
// so always newval is always less that the val 


// I say any eqn which allow me to get prevmin 

// This intution is wrong 
// like val - prevmin = newval why not ? 
// i can also say the same thing 
// val < min
// newval < 0 but other values may also be less than zero does -2 0 -1 min = -2 but -1 is also less than zero does it mean merko mera min badlna hai nhi 
// not get it try to run it for 
// -2 0 -3 
// -2 0 -1



class MinStack {
    stack<int> st;
    int mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }

        else{
            if(mini < val)st.push(val);
            else{
                st.push(2 * val - mini);
                mini = val;
            }
        }
    }   
    
    void pop() {
        if(st.empty())return;
        
        if(st.top() >= mini)st.pop();
        else{
            // if chotta 
            mini = 2 * mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())return -1 ;
        
        if(st.top() >= mini) return st.top();
        
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
int main()
{
     
    return 0;
}
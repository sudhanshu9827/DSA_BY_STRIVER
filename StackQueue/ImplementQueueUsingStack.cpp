#include <bits/stdc++.h>
using namespace std;


// Actually we can implement queue using stack in the two ways 
// 1. Make push Expensive 
// or 
// 2. Make pop expensive 


class Queue1{
    stack<int> st1 , st2;

    public:
    
    void push(int element){
        st1.push(element);
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

    int pop(){
        int temp;
        if(!st2.empty()){
            temp = st2.top();
        } 
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            temp = st2.top();
        }
        st2.pop();
        return temp;
    }

   int peek(){
    int temp;
        if(st2.empty()){
             while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        temp = st2.top();
        return temp;
    }
};

int main()
{
     
    return 0;
}
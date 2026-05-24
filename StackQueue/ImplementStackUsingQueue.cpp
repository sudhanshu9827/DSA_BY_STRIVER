#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
    public:

    void push(int element){
        
        // what i am thinking push the element the again push the element that are before the current element 
        int n = q.size();
        q.push(element);
        for(int i = 0 ; i < n ; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int temp = q.front();
        return temp;
    }

    int top(){
        return q.front();
    }

};

int main()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(8);

    cout<<s.pop();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int size_ = 10;

class st{
    public:
    int arr[size_];
    int top = -1;

    void push(int element){
        if(top == size_ - 1){
            cout<<"Overflow\n";
        }
        else
            arr[++top] = element;
    }

    int pop(){
        if(top < 0){
            cout<<"Underflow\n";
        }
        else{
            top--;
            return arr[top];
        }
    }

    int peek(){
        if(top < 0){
            cout<<"underflow";
        }
        else{
            return arr[top];
        }
    }

    void display(){
        for(int i = 0 ; i <= top ; i++){
            cout<<arr[i];
        }
    }
 };

int main()
{

    st s;
    s.push(3);
    s.push(8);
    cout<<s.peek();
}
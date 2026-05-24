#include <bits/stdc++.h>
using namespace std;


// Bina dimaag lagaye aage badd rahaa tha galat hoo gaya 
// Always remember what are you doing?
//and why are you doing?
// Is their any other way which performs better

class Node{
    public:
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Queue{
    Node * start;
    Node * end;
    int size;

    public:

    Queue(){
        start = NULL;
        end = NULL;
        size = 0;
    }

    // I want to make this Unexpensive in the term of time

    bool isEmpty(){
        return(start==NULL);
    }

    void push(int element){
        // soo directly add it
        Node * newNode = new Node(element); 
        if(isEmpty()){
            start = end = newNode;
        }

        else{
            end -> next = newNode;
            end = newNode;
        }
        size++;
    }


    int pop(){
        if(!start)return -1;
        
        Node* queueNode = start;
        int queueValue = start->data;

        start = start->next;
        delete(queueNode);
        size--;
        return queueValue;
    }

    int peek(){
        if(!start) return -1;
        return start->data;
    }
};

int main()
{
    Queue qu;
    qu.push(7);
    qu.push(8);
    qu.push(10);
    cout<<qu.pop();
    cout<<"\n"<<qu.pop();
    return 0;
}
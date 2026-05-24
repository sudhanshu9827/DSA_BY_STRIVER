#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{

    Node *top = nullptr;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int element)
    {
        Node *newNode = new Node(element);
        newNode->next = nullptr;
        top = newNode;
        size++;
    }

    int pop()
    {
        if (!top)
            return -1;

        int t = top->data;
        Node *stackNode = top;
        top = top->next;
        delete stackNode;
        size--;
        return t;
    }

    int peek()
    {
        if (!top)
            return -1;
        return top->data;
    }
};

int main()
{
    Stack st;
    st.push(4);
    st.push(8);
    cout << st.pop();
    return 0;
}
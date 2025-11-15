#include <bits/stdc++.h>
using namespace std;


// get to know that a = b = -1  kiya jaa sakta hai 

const int size_ = 10;

class Qu {
public:
    int arr[size_];
    int start = -1;
    int end = -1;

    bool isEmpty() {
        return (start == -1);
    }

    bool isFull() {
        return ((end + 1) % size_) == start;
    }

    void push(int element) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty()) {
            start = end = 0;
        } else {
            end = (end + 1) % size_;
        }

        arr[end] = element;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }

        if (start == end) {
            start = end = -1;
        } else {
            start = (start + 1) % size_;
        }
    }
};
 
int main() {
    Qu q;
    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}

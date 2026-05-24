#include <bits/stdc++.h>
using namespace std;

class BinaryHeap
{
    // maximum capacity
    int capacity;

    int size;

    int *arr;

public:
    BinaryHeap(int cap)
    {
        capacity = cap;

        size = 0;

        arr = new int[capacity];
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    void Insert(int x)
    {
        if (size == capacity)
        {
            cout << "Binary heap Overflow" << endl;
            return;
        }

        // Insert a new Value;

        arr[size++] = x;

        int k = size - 1;

        // fix heap property

        while (k > 0 && arr[parent(k)] < arr[k])
        {
            swap(arr[parent(k)], arr[k]);
            k = parent(k);
        }
    }

    void Heapify(int i)
    {
        int largest = i;
        if (left(i) < size && arr[left(i)] > arr[largest])
            largest = left(i);
        if (right(i) < size && arr[right(i)] > arr[largest])
            largest = right(i);

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            Heapify(largest);
        }
    }

    int getMax()
    {
        return arr[0];
    }

    int ExtractMax()
    {
        if (size <= 0)
            return INT_MIN;

        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int maxi = arr[0];

        arr[0] = arr[size - 1];

        Heapify(0);
        return maxi;
    }

    void decreaseKey(int i, int val)
    {
        arr[i] = val;

        Heapify(i);
    }

    void increaseKey(int i, int val)
    {
        arr[i] = val;

        while (i > 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i)
    {
        increaseKey(i, INT_MAX);
        ExtractMax();
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinaryHeap h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Max Value is:" << h.getMax() << endl;

    h.Insert(30);

    cout << "Min Value is: " << h.getMax() << endl;

    h.decreaseKey(3, 40);
    cout << "Min Value is: " << h.getMax() << endl;

    h.ExtractMax();
    cout << "Min Value is: " << h.getMax() << endl;

    h.Delete(0);
    cout << "Min Value is: " << h.getMax() << endl;

    return 0;
}
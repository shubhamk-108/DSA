/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.


Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class MyCircularDeque
{
private:
    int *arr;
    int front, size, capacity;

public:
    MyCircularDeque(int k)
    {
        arr = new int[k];
        capacity = k;
        size = 0;
        front = 0;
    }

    bool insertFront(int value)
    {
        if (size == capacity)
            return false;

        front = (front - 1 + capacity) % capacity;
        arr[front] = value;

        size++;
        true;
    }

    bool insertLast(int value)
    {
        if (size == capacity)
            return false;
        int rear = (front + size) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }
    bool deleteFront()
    {
        if (size == 0)
            return false;
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
        int rear = (front + size - 1) % capacity;
        int res = arr[rear];
        size--;
        return true;
    }

    int getFront()
    {
        if (size == 0)
            return -1;

        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    bool isEmpty()
    {
        return size ==0;
    }

    bool isFull()
    {
        return size==capacity;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
| Operation   | Time |
| ----------- | ---- |
| insertFront | O(1) |
| insertRear  | O(1) |
| deleteFront | O(1) |
| deleteRear  | O(1) |
| frontEle    | O(1) |
| rearEle     | O(1) |

Space Complexity
O(capacity)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Core idea
You are implementing a Deque (Double Ended Queue) using a circular array.
Instead of shifting elements (which is costly), you:
keep track of a front index
keep track of size
compute rear index on the fly
This allows:
insertion/deletion from both ends
in O(1) time
Key Invariants (Very Important)
front → index of the current front element
size → number of elements currently in deque
rear index is not stored, it is calculated as
rear = (front + size - 1) % capacity


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class myDeque
{
private:
    int *arr;        // Dynamic array to store deque elements
    int front;       // Index of front element
    int size;        // Current number of elements
    int capacity;    // Maximum capacity of deque

public:
    // Constructor
    myDeque(int cap)
    {
        capacity = cap;
        size = 0;
        front = 0;
        arr = new int[capacity];
    }

    // Delete element from front
    int deleteFront()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }

        int res = arr[front];              // Store front element
        front = (front + 1) % capacity;    // Move front circularly
        size--;
        return res;
    }

    // Insert element at front
    void insertFront(int x)
    {
        if (size == capacity)
        {
            cout << "Deque is full\n";
            return;
        }

        // Move front backward circularly
        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    // Insert element at rear
    void insertRear(int x)
    {
        if (size == capacity)
        {
            cout << "Deque is full\n";
            return;
        }

        // Calculate rear index
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    // Delete element from rear
    int deleteRear()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }

        // Calculate rear index
        int rear = (front + size - 1) % capacity;
        int res = arr[rear];
        size--;
        return res;
    }

    // Get front element
    int frontEle()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int rearEle()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }

        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Circular Array / Circular Buffer


*/

/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.



Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
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

class MyCircularQueue
{
public:
    int size = 0;
    int capacity ;
    int *arr;
    int front = 0;

    MyCircularQueue(int k)
    {
        capacity = k;
        arr = new int[capacity];
    }

    ~MyCircularQueue()
    {
        delete [] arr;
    }

    bool enQueue(int value)
    {
        if(isFull())
            return false;
        int rear = (front + size) % capacity;
        arr[rear] = value;   
        size++;    
        return true;    
    }

    bool deQueue()
    {
        if(isEmpty())
            return false;
        front = (front + 1) % capacity;
        size--;
        return true;        
    }

    int Front()
    {
        if(isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if(isEmpty())
            return -1;
        int rear = (front + size - 1) % capacity; 
        return arr[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};


//___________________________________________________________________________________________________________________________________________
// Important thing about dequeue and printing queue. 
//we are not deleting something here. aRe we overwriting it . See bool deQueue() method
//___________________________________________________________________________________________________________________________________________

/*

👉 Yes — we are NOT deleting the value.
👉 We are logically removing it by moving front.
👉 That value will be overwritten later.

Why no “delete” is needed
Your queue is backed by:
int* arr = new int[capacity];


This memory is allocated once.
Individual elements are not dynamically allocated, so there is nothing to delete per element.

What “deQueue” really means
Dequeue = stop considering the front element as part of the queue.
That’s it.
We do this by:
Moving front forward
Decreasing size


Question:
although not requirement of queue but wont it create problem if we wanted to print queue elements.
At that time the value which was suppose to overwrite will also get printed.

Answer:

👉 No, it will NOT create a problem
👉 Only elements inside the logical queue range are printed
👉 Old values exist in memory but are ignored
Printing a queue never means printing the whole array.
The key idea you must lock in 🔑
Queue is defined by front and size, NOT by raw array contents.
Anything outside that range is not part of the queue, even if data is still there.
How to correctly print queue elements
If someone wanted to print the queue, they would do it like this:

void printQueue()
{
    for (int i = 0; i < size; i++)
    {
        int idx = (front + i) % capacity;
        cout << arr[idx] << " ";
    }
}

are we going to print size number of elements starting from front
Yes — exactly that ✅
*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
All operations are O(1):
enQueue
deQueue
Front
Rear
isEmpty
isFull

Space Complexity
O(k) where k = capacity

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea
Use a circular array to implement a queue efficiently.
Why circular?
When elements are removed from front, space becomes free
Instead of shifting elements (O(n)), we reuse space using modulo
Key variables
front → points to first element
size → tells how many elements are present
rear → calculated dynamically:
rear = (front + size) % capacity
Why track size?
Easily detect:
empty → size == 0
full → size == capacity
No ambiguity between empty and full states
This is the cleanest circular queue design.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class MyCircularQueue
{
public:
    int size = 0;        // current number of elements
    int capacity;        // max size of queue
    int *arr;            // array to store elements
    int front = 0;       // index of front element

    MyCircularQueue(int k)
    {
        capacity = k;
        arr = new int[capacity];
    }

    ~MyCircularQueue()
    {
        delete[] arr;    // free allocated memory
    }

    bool enQueue(int value)
    {
        // if queue is full, insertion not possible
        if (isFull())
            return false;

        // calculate rear index using circular logic
        int rear = (front + size) % capacity;
        arr[rear] = value;

        size++;          // increase size after insertion
        return true;
    }

    bool deQueue()
    {
        // if queue is empty, deletion not possible
        if (isEmpty())
            return false;

        // move front circularly
        front = (front + 1) % capacity;
        size--;          // decrease size after deletion
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;

        // rear is last inserted element
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Data Structure Design
└── Circular Queue
Or you can say:
“This problem is solved using the circular array + two-pointer (front + size) pattern.”



*/

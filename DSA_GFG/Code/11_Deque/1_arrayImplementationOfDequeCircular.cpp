/*

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

class myDeque
{
private:
    int *arr;
    int front, size, capacity;

public:
    myDeque(int cap)
    {
        capacity = cap;
        size = 0;
        front = 0;
        arr = new int[capacity];
    }

    int deleteFront()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    void insertFront(int x)
    {
        if (size == capacity)
        {
            cout << "Deque is full\n";
            return;
        }

        front = (front - 1 + capacity) % capacity;
        arr[front] = x;
        size++;
    }

    void insertRear(int x)
    {
        if (size == capacity)
        {
            cout << "Deque is full\n";
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    int deleteRear()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        int rear = (front + size - 1) % capacity;
        int res = arr[rear];
        size--;
        return res;
    }

    int frontEle()
    {
        if (size == 0)
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
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

int main()
{
    myDeque dq(4);

    dq.insertRear(10);
    dq.insertFront(20);
    dq.insertRear(30);

    cout << "Front: " << dq.frontEle() << ", Rear: " << dq.rearEle() << endl;

    dq.deleteFront();
    cout << "Front: " << dq.frontEle() << ", Rear: " << dq.rearEle() << endl;

    dq.deleteRear();
    cout << "Front: " << dq.frontEle() << ", Rear: " << dq.rearEle() << endl;

    return 0;
}
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

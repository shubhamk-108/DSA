/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class MyQueue
{
public:
    stack<int> st1;
    stack<int> tempSt;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (st1.empty())
            st1.push(x);
        else
        {
            while (!st1.empty())
            {
                int a = st1.top();
                tempSt.push(a);
                st1.pop();
            }
            st1.push(x);
            while (!tempSt.empty())
            {
                int a = tempSt.top();
                st1.push(a);
                tempSt.pop();
            }
        }
    }

    int pop()
    {
        int a = st1.top();
        st1.pop();
        return a;
    }

    int peek()
    {
        int a = st1.top();
        return a;
    }

    bool empty()
    {
        return st1.empty();
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time: 
| Operation | Time     |
| --------- | -------- |
| `push()`  | **O(n)** |
| `pop()`   | **O(1)** |
| `peek()`  | **O(1)** |
| `empty()` | **O(1)** |

space:
Space Complexity

O(n)
Two stacks storing at most n elements.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Key idea
Always keep the front of the queue at the top of st1
Make push() expensive so that:
Old elements remain above new ones
Then pop() and peek() become O(1)
How push(x) works:
Move all elements from st1 → tempSt
Push new element x into st1
Move all elements back from tempSt → st1
👉 This ensures the oldest element stays on top, maintaining FIFO order.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class MyQueue
{
public:
    stack<int> st1;     // Main stack (front of queue at top)
    stack<int> tempSt;  // Temporary stack used during push

    MyQueue()
    {
    }

    // Push element to the back of the queue
    void push(int x)
    {
        // If queue is empty, push directly
        if (st1.empty())
            st1.push(x);
        else
        {
            // Move all existing elements to temp stack
            while (!st1.empty())
            {
                int a = st1.top();
                tempSt.push(a);
                st1.pop();
            }

            // Push new element
            st1.push(x);

            // Restore elements back to st1
            while (!tempSt.empty())
            {
                int a = tempSt.top();
                st1.push(a);
                tempSt.pop();
            }
        }
    }

    // Remove and return front element
    int pop()
    {
        int a = st1.top(); // front of queue
        st1.pop();
        return a;
    }

    // Return front element
    int peek()
    {
        return st1.top();
    }

    // Check if queue is empty
    bool empty()
    {
        return st1.empty();
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

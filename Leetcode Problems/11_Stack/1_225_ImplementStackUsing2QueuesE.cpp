/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.


Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

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

class MyStack
{
public:
    queue<int> q1;
    queue<int> tempQ;

    MyStack()
    {
    }

    void push(int x)
    {
        if (q1.empty())
            q1.push(x);
        else
        {
            while (!q1.empty())
            {
                int a = q1.front();
                tempQ.push(a);
                q1.pop();
            }
            q1.push(x);
            while (!tempQ.empty())
            {
                int a = tempQ.front();
                q1.push(a);
                tempQ.pop();
            }
        }
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time:
| Operation | Time     |
| --------- | -------- |
| `push()`  | **O(n)** |
| `pop()`   | **O(1)** |
| `top()`   | **O(1)** |
| `empty()` | **O(1)** |


space:O(n)
Because you are using two queues to store n elements.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
You are simulating a stack (LIFO) using queues (FIFO).
Key idea:
Always keep the stack top at the front of q1
Make push() costly so that:
The most recently pushed element comes to the front
Then pop() and top() become O(1) operations
How push(x) works:
Move all existing elements from q1 to tempQ
Push the new element x into q1
Move all elements back from tempQ to q1
👉 This reverses order so that new element is at the front



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class MyStack
{
public:
    queue<int> q1;     // Main queue representing the stack
    queue<int> tempQ;  // Temporary queue used during push

    MyStack()
    {
    }

    // Push element onto stack
    void push(int x)
    {
        // If stack is empty, directly push
        if (q1.empty())
            q1.push(x);
        else
        {
            // Move all elements from q1 to tempQ
            while (!q1.empty())
            {
                int a = q1.front();
                tempQ.push(a);
                q1.pop();
            }

            // Push new element first (it should be on top)
            q1.push(x);

            // Move back all old elements after x
            while (!tempQ.empty())
            {
                int a = tempQ.front();
                q1.push(a);
                tempQ.pop();
            }
        }
    }

    // Remove and return top element
    int pop()
    {
        int x = q1.front(); // Top of stack
        q1.pop();
        return x;
    }

    // Return top element
    int top()
    {
        return q1.front();
    }

    // Check if stack is empty
    bool empty()
    {
        return q1.empty();
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

“Stack using Queue – Push Heavy Pattern”


*/

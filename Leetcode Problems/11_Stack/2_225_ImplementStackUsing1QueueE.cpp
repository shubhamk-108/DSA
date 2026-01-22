/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include<queue>
#include <algorithm>
#include <climits>
using namespace std;


class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        if (q.empty())
            q.push(x);
        else
        {
            q.push(x);
            for (int i = 1; i <= q.size() - 1; i++)
            {
                int a = q.front();
                q.pop();
                q.push(a);
            }
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
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
| `top()`   | **O(1)** |
| `empty()` | **O(1)** |


Space Complexity
O(n) — only one queue storing n elements

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


You are implementing a stack (LIFO) using only one queue (FIFO).
Core idea:
After every push(x), rotate the queue so that:
x comes to the front
This ensures:
top() → front of queue
pop() → front of queue
How push(x) works:
Push x into the queue
Rotate the previous elements behind x
Pop front and push it back size−1 times
👉 This places the new element at the front, simulating stack behavior.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


class MyStack
{
public:
    queue<int> q;  // Single queue to simulate stack

    MyStack()
    {
    }

    // Push element onto stack
    void push(int x)
    {
        // If empty, just push
        if (q.empty())
            q.push(x);
        else
        {
            // Step 1: push new element
            q.push(x);

            // Step 2: rotate previous elements behind x
            for (int i = 1; i <= q.size() - 1; i++)
            {
                int a = q.front(); // take front element
                q.pop();           // remove it
                q.push(a);         // push it back
            }
        }
    }

    // Remove and return top element
    int pop()
    {
        int x = q.front(); // top of stack
        q.pop();
        return x;
    }

    // Return top element
    int top()
    {
        return q.front();
    }

    // Check if stack is empty
    bool empty()
    {
        return q.empty();
    }
};


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

“Stack using Queue – Push Heavy (Single Queue Rotation)”
*/


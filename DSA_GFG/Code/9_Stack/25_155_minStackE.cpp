/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
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

class MinStack
{
public:
    long long minVal;
    stack<long long> st;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val >= minVal)
                st.push(val);
            else
            {
                long long flag = 2LL * val - minVal;
                st.push(flag);
                minVal = val;
            }
        }
    }

    void pop()
    {
        if (st.top() >= minVal)
            st.pop();
        else
        {
            long long flag = st.top();
            int prevMin = 2 * minVal - flag;
            minVal = prevMin;
            st.pop();
        }
    }

    int top()
    {
        if (st.top() < minVal)
            return minVal;
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //___________________________________________________________________________________________________________________________________________
// Problem Explanation/ Intuition
//___________________________________________________________________________________________________________________________________________

/*

You want a stack that supports:

push

pop

top

getMin

👉 All in O(1) time and O(1) extra space

So you cannot store another stack of minimums.

Key idea behind the trick

When you push a new element that becomes the new minimum, you must:

Remember the old minimum

Still store only one number in the stack

So we cleverly encode both values into one number.

Why encoding is needed

Suppose current minimum is:

min = 5


Now you push:

x = 3   (new minimum)


You need:

To update min = 3

To remember the old min 5 so you can restore it when popping

But you’re not allowed extra space 😬

The encoding trick

When x < min, instead of pushing x, you push:

encoded = 2*x - min


Then update:

min = x

Why does this work?

Let’s plug in numbers.

Before push
min = 5

Push 3
encoded = 2*3 - 5 = 1
stack.push(1)
min = 3


So the stack now has 1, not 3.

⚠️ Important observation:

encoded < new min


Because:

2*x - oldMin < x   (since x < oldMin)


This is the signal that the value is encoded.

How do we detect encoded values?

When popping or peeking:

if top < min


→ this value is encoded, not a real stack value.

Recovering the previous minimum (the magic part)

When popping an encoded value:

encoded = 2*x - oldMin
current min = x


Rearrange:

oldMin = 2*x - encoded


So during pop:

previousMin = 2*min - top
min = previousMin


✨ Old minimum restored!

Walk-through example (very important)
Operations
push(5)
push(3)
push(2)

Step by step

| Operation | Stack     | min |
| --------- | --------- | --- |
| push(5)   | [5]       | 5   |
| push(3)   | [5, 1]    | 3   |
| push(2)   | [5, 1, 1] | 2   |

Pop()

Top = 1 < min (2) → encoded

previousMin = 2*2 - 1 = 3
min = 3


Stack → [5, 1]

Pop()

Top = 1 < min (3) → encoded

previousMin = 2*3 - 1 = 5
min = 5


Stack → [5]

Pop()

Top = 5 ≥ min → normal pop

How top() works

If:

top < min

Then the actual top value is min, not top.
Because encoded values never represent real data.

Intuition in one line
We store a “fake smaller number” to signal that the minimum changed, and use algebra to recover the old minimum later.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time:
| Operation | Complexity |
| --------- | ---------- |
| push      | O(1)       |
| pop       | O(1)       |
| top       | O(1)       |
| getMin    | O(1)       |


Space Complexity
O(1) auxiliary space


Only one stack is used.
No extra data structures like another stack.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Problem requirement

Design a stack that supports:

push

pop

top

getMin

👉 All in O(1) time and O(1) extra space.

Core idea
We store normal values in the stack unless a new value becomes the new minimum.
When a new value val is smaller than the current minimum:
We encode it using
flag = 2*val - oldMin

Push this encoded value into the stack
Update minVal = val
This encoded value:
Is always smaller than the new min
Acts as a marker that the minimum changed
Stores enough information to recover the old minimum later

How pop works
If top ≥ minVal → normal value, just pop
If top < minVal → encoded value
→ restore previous minimum using:
oldMin = 2*currentMin - encoded
How top works
If top < minVal → actual top is minVal
Else → top is normal

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class MinStack
{
public:
    long long minVal;       // Stores current minimum
    stack<int> st;          // Stack to store elements (normal or encoded)

    MinStack()
    {
    }

    void push(int val)
    {
        // If stack is empty, initialize min
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            // Normal push if value does not change minimum
            if (val >= minVal)
                st.push(val);
            else
            {
                // Encode value to store old minimum implicitly
                long long flag = 2LL * val - minVal;
                st.push(flag);

                // Update minimum
                minVal = val;
            }
        }
    }

    void pop()
    {
        // Normal value case
        if (st.top() >= minVal)
            st.pop();
        else
        {
            // Encoded value found → restore previous minimum
            long long flag = st.top();
            long long prevMin = 2 * minVal - flag;
            minVal = prevMin;
            st.pop();
        }
    }

    int top()
    {
        // If encoded value, real top is current minimum
        if (st.top() < minVal)
            return minVal;

        // Otherwise return normal value
        return st.top();
    }

    int getMin()
    {
        return minVal;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern name
Mathematical Encoding / In-place State Encoding

*/

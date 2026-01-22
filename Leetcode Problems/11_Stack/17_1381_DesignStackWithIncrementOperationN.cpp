/*
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.


Example 1:

Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
Explanation
CustomStack stk = new CustomStack(3); // Stack is Empty []
stk.push(1);                          // stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.push(3);                          // stack becomes [1, 2, 3]
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
stk.increment(5, 100);                // stack becomes [101, 102, 103]
stk.increment(2, 100);                // stack becomes [201, 202, 103]
stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
stk.pop();                            // return -1 --> Stack is empty return -1.
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
class CustomStack
{
public:
    vector<int> vec;
    int maxSize;
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
    }

    void push(int x)
    {
        if (vec.size() < maxSize)
            vec.push_back(x);
    }

    int pop()
    {
        if (vec.empty())
            return -1;
        int res = vec.back();
        vec.pop_back();
        return res;
    }

    void increment(int k, int val)
    {
        int i =0;
        while (i <vec.size() && k > 0)
        {
            vec[i] += val;
            i++;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
| Operation   | Complexity |
| ----------- | ---------- |
| `push`      | O(1)       |
| `pop`       | O(1)       |
| `increment` | O(k)       |

🔹 Space Complexity

O(maxSize) → vector stores up to maxSize elements.


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Use vector<int> vec to simulate a stack.
vec.back() → top of stack.
vec[0] → bottom of stack.
Operations

Operation
| Operation           | How it works in your code                                      |
| ------------------- | -------------------------------------------------------------- |
| `push(x)`           | Add `x` to stack only if `vec.size() < maxSize`.               |
| `pop()`             | Remove and return top element, return `-1` if stack is empty.  |
| `increment(k, val)` | Add `val` to the bottom `k` elements (`vec[0]` to `vec[k-1]`). |

Constraints Handling
Max size is enforced in push.
Stack underflow handled in pop.
Increment does not exceed current stack size (while i < vec.size() && k > 0).

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class CustomStack
{
public:
    vector<int> vec;   // vector simulates the stack
    int maxSize;       // maximum allowed size of the stack

    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
    }

    // Push x onto stack if there is space
    void push(int x)
    {
        if (vec.size() < maxSize)
            vec.push_back(x);
    }

    // Pop the top element, return -1 if empty
    int pop()
    {
        if (vec.empty())
            return -1;
        int res = vec.back();
        vec.pop_back();
        return res;
    }

    // Increment the bottom k elements by val
    void increment(int k, int val)
    {
        int i = 0;
        while (i < vec.size() && k > 0)
        {
            vec[i] += val; // update bottom elements
            i++;
            k--;
        }
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Simulation / Stack Design Pattern
Simulates stack behavior with additional constraints (maxSize and bottom-k increment).
Classic design + stack simulation problem.

*/

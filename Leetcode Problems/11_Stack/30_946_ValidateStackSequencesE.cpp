/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.



Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

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

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int j = 0;

        for (int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);

            while(!st.empty() && j < popped.size() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return (st.empty());
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {4, 5, 3, 2, 1};
    cout << sol.validateStackSequences(v1, v2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n)
Each element is pushed once.
Each element is popped once.
Total operations ≤ 2n.
🧠 Space Complexity
O(n)
Stack may hold all elements in the worst case.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Core idea
You simulate the stack operations directly using an auxiliary stack.
Key observation
At any moment:
The stack represents the current state after pushing some elements.
If the top of the stack matches the next element in popped, you must pop it.
Strategy
Iterate through the pushed array.
Push each element onto the stack.
After every push, keep popping while:
the stack is not empty, and
the top matches the current element in popped.
At the end, if the stack is empty, the pop sequence is valid.
This ensures that all stack operations follow valid LIFO rules.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;   // simulates the real stack
        int j = 0;       // index for popped sequence

        // Iterate over pushed elements
        for (int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]); // push current element

            // Pop while top matches the next element to pop
            while (!st.empty() &&
                   j < popped.size() &&
                   st.top() == popped[j])
            {
                st.pop();
                j++; // move to next element in popped
            }
        }

        // If stack is empty, the sequence is valid
        return st.empty();
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

🔹 Stack Simulation Pattern


*/

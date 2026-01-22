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

// I guess there is no naive solution
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int i = 0; // index for pushed

        for (auto x : popped)
        {
            int eleToBePopped = x;

            while ((st.empty() || st.top() != x) && i < pushed.size())
            {
                st.push(pushed[i]);
                i++;
            }

            if (st.top() != eleToBePopped)
                return false;
            else
                st.pop();
        }
        return st.empty();
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


ime Complexity

O(n)

Each element is pushed once

Each element is popped once

Total operations ≤ 2n

4️⃣ Space Complexity

O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Idea
We simulate the stack operations exactly as they would happen.
We are given the order of pushed elements.
We must check whether the popped order is possible using a stack.
Strategy:
Maintain a stack to simulate pushes and pops.
Keep an index i pointing to the next element to be pushed.
For each element in popped:
Push elements from pushed until:
the stack top equals the current element to be popped, or
there are no more elements to push.
If the stack top is still not equal, the sequence is invalid.
Otherwise, pop the element.
If all pops are valid, return true.
This directly mimics real stack behavior.


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
        stack<int> st;
        int i = 0; // index for pushed array

        // Process each element in popped order
        for (auto x : popped)
        {
            // Push elements until we can pop x
            while ((st.empty() || st.top() != x) && i < pushed.size())
            {
                st.push(pushed[i]);
                i++;
            }

            // If top is not the required element, sequence is invalid
            if (st.top() != x)
                return false;

            // Pop the required element
            st.pop();
        }

        // If all pops were valid
        return true;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Used
🔹 Stack Simulation / Greedy Stack Pattern


*/

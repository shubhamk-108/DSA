/*
You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Greater Element (PGE).

The Previous Greater Element (PGE) of an element x is the first element that appears to the left of x in the array and is strictly greater than x.


Note: If no such element exists, assign -1 as the PGE for that position.

Examples:

Input: arr[] = [10, 4, 2, 20, 40, 12, 30]
Output: [-1, 10, 4, -1, -1, 40, 40]
Explanation:
For 10, no elements on the left, so answer is -1.
For 4, previous greater element is 10.
For 2, previous greater element is 4.
For 20, no element on the left greater than 20, so answer is -1.
For 40, no element on the left greater than 40, so answer is -1.
For 12, previous greater element is 40.
For 30, previous greater element is 40.
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
    vector<int> preGreaterEle(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                res[i] = -1;
                st.push(arr[i]);
            }
            else
            {
                while (!st.empty() && st.top() <= arr[i])
                {
                    st.pop();
                }
                if (st.empty())
                    res[i] = -1;
                else
                    res[i] = st.top();

                st.push(arr[i]);
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {10, 4, 2, 20, 40, 12, 30};
    vector<int> res = sol.preGreaterEle(v);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(N)
Each element is pushed once
Each element is popped once
Even though there’s a while loop, total operations are bounded by 2N.

💾 Space Complexity
O(N)
Stack can store up to N elements in worst case (strictly decreasing array)
Result array also uses O(N)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal:
For every element, find the nearest greater element on its left.
Idea:
Traverse the array from left to right
Maintain a monotonic decreasing stack
The stack stores only useful candidates for previous greater elements
At each element arr[i]:
Remove all elements from the stack that are ≤ arr[i]
They are useless because they can never be previous greater for current or future elements
After popping:
If stack is empty → no previous greater → answer = -1
Else → stack top is the previous greater element
Push arr[i] into the stack

🧠 Why this works
Stack always remains strictly decreasing
Top of stack is always the closest greater element on the left
Every element is pushed once and popped once


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> preGreaterEle(vector<int> &arr)
    {
        int n = arr.size();

        // Stack to store candidates for previous greater elements
        stack<int> st;

        // Result array
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            // Remove all elements smaller than or equal to current
            // because they cannot be previous greater for arr[i]
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }

            // If stack becomes empty, no greater element exists on left
            if (st.empty())
                res[i] = -1;
            else
                // Top of stack is nearest greater element on the left
                res[i] = st.top();

            // Push current element for future comparisons
            st.push(arr[i]);
        }
        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Monotonic Stack (Decreasing Stack)  
More specifically:
Previous Greater Element
Direction: Left
Order maintained: Decreasing


*/

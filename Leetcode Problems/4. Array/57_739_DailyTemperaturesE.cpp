/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number
of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep
answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Explanation:
Day 0 → 73 → Next warmer temp is 74 (after 1 day)
Day 1 → 74 → Next warmer temp is 75 (after 1 day)
Day 2 → 75 → Next warmer temp is 76 (after 4 days)
Day 3 → 71 → Next warmer temp is 72 (after 2 days)
Day 4 → 69 → Next warmer temp is 72 (after 1 day)
Day 5 → 72 → Next warmer temp is 76 (after 1 day)
Day 6 → 76 → No warmer temp → 0
Day 7 → 73 → No warmer temp → 0

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        if (temperatures.empty())
            return {};
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if (!st.empty())
                res[i] = (st.top() - i);
            else // stack is empty and this is optional as res is initialised with 0.
                res[i] = (0);

            st.push(i);
        }

        return res;
    }
};


int main()
{
    Solution sol;
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = sol.dailyTemperatures(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric               | Analysis                                               |
| :------------------- | :----------------------------------------------------- |
| **Time Complexity**  | `O(n)` — each index is pushed and popped at most once. |
| **Space Complexity** | `O(n)` — for the stack and result array.               |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We traverse the temperature list from right to left, since we need to know future (next) warmer days.
We maintain a monotonic decreasing stack of indices:
The temperatures of these indices are strictly decreasing from bottom to top.
For each day i:
Pop all indices where temperatures[st.top()] <= temperatures[i], since those days cannot be the “next warmer” for i or for any earlier day.
After popping, if the stack isn’t empty, the top index st.top() represents the next warmer day.
→ res[i] = st.top() - i.
Push i onto the stack (it may serve as the “warmer day” for earlier days).
Return the result.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        if (temperatures.empty())
            return {};

        vector<int> res(n, 0); // stores days to wait; initialized to 0
        stack<int> st;         // stack stores indices, not temperatures

        // Traverse from rightmost day to leftmost
        for (int i = n - 1; i >= 0; i--)
        {
            // Pop all days that are not warmer than the current day
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            // If stack is not empty, top index is the next warmer day
            if (!st.empty())
                res[i] = st.top() - i;
            // else part is optional because res[i] is already 0

            // Push current day's index for future comparisons
            st.push(i);
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Monotonic Stack (Decreasing Stack) —
This is the optimal and canonical solution pattern for:

Next Greater Element
Trapping Rain Water
Stock Span Problem
Daily Temperatures


*/

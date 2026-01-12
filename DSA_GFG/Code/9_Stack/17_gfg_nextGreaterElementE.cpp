/*
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.

Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
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
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans[i] = -1;
                st.push(arr[i]);
            }
            else
            {
                while (!st.empty() && st.top() <= arr[i])
                    st.pop();
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 2, 4};
    vector<int> res = sol.nextLargerElement(v);
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
Each element is pushed onto the stack once
Each element is popped once
Total operations ≤ 2N.

4️⃣ Space Complexity
O(N)
Stack can store up to N elements in the worst case
Result array uses O(N) space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Idea

Traverse the array from right to left
Maintain a monotonic decreasing stack
Stack stores only useful candidates for next greater elements
🔑 Key Observation
While moving from right to left, the stack always contains elements greater than the current element and closest to it on the right.

Pop all elements from the stack that are ≤ arr[i]
They can never be the next greater for arr[i] or any element to its left
After popping:
If stack is empty → no greater element on the right → answer = -1
Else → stack top is the next greater element
Push arr[i] into the stack as a candidate for elements on the left


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();

        // Stack to store candidates for next greater elements
        stack<int> st;

        // Result array
        vector<int> ans(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Remove all elements smaller than or equal to current
            // because they cannot be the next greater for arr[i]
            while (!st.empty() && st.top() <= arr[i])
                st.pop();

            // If stack is empty, no greater element exists on right
            if (st.empty())
                ans[i] = -1;
            else
                // Top of stack is the nearest greater element on the right
                ans[i] = st.top();

            // Push current element as candidate for elements on the left
            st.push(arr[i]);
        }
        return ans;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



🔹 Monotonic Stack
More specifically:
Type: Monotonic Decreasing Stack
Problem Category: Nearest Greater Element
Traversal: Right → Left
*/

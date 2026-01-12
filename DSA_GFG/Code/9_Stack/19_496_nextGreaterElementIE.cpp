/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> ump;
        stack<int> st;
        vector<int> ans(m);

        for (int i = 0; i < m; i++)
        {
            ump[nums1[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                if (ump.count(nums2[i]))
                    ans[ump[nums2[i]]] = -1;

                st.push(nums2[i]);
            }
            else
            {
                while (!st.empty() && st.top() <= nums2[i])
                    st.pop();
                if (ump.count(nums2[i]))
                {
                    if (st.empty())
                        ans[ump[nums2[i]]] = -1;
                    else
                        ans[ump[nums2[i]]] = st.top();
                }
                st.push(nums2[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {4, 1, 2};
    vector<int> v2 = {1, 3, 4, 2};
    vector<int> res = sol.nextGreaterElement(v1, v2);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n + m)
Each element pushed/popped once
n is dominant term so time :O(n)
Time Complexity: O(n + m)
Since nums1 is a subset of nums2 (m ≤ n), it can also be written as O(n).

Space: O(n + m)
(Stack + HashMap + result)
n is dominant term so time :O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


nums1 is a subset of nums2

For each element in nums1, find its next greater element in nums2

If it doesn’t exist, return -1

✅ Approach
🧠 Key Observations
nums1 is a subset of nums
Next greater element depends on relative position in nums2
Brute force would be too slow (O(m × n))

🔑 Optimized Strategy
Map elements of nums1 to their indices
So we know where to store the answer
Traverse nums2 from right to left
Maintain a monotonic decreasing stack
For each element in nums2:
Remove all elements smaller than or equal to it from the stack
If the element exists in nums1, assign:
-1 if stack is empty
Otherwise, stack top as next greater element
Push the current element onto the stack

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        // Map to store: value in nums1 -> its index
        unordered_map<int, int> ump;

        // Stack to maintain a monotonic decreasing order
        stack<int> st;

        // Result array for nums1
        vector<int> ans(m);

        // Store index of each element in nums1
        for (int i = 0; i < m; i++)
        {
            ump[nums1[i]] = i;
        }

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // Remove all elements smaller than or equal to current
            // because they cannot be the next greater element
            while (!st.empty() && st.top() <= nums2[i])
                st.pop();

            // If current element exists in nums1
            if (ump.count(nums2[i]))
            {
                // If stack is empty, no next greater element
                if (st.empty())
                    ans[ump[nums2[i]]] = -1;
                else
                    // Top of stack is the next greater element
                    ans[ump[nums2[i]]] = st.top();
            }

            // Push current element as a candidate for left elements
            st.push(nums2[i]);
        }

        return ans;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

🔹 Monotonic Stack + Hash Map
Stack → Next Greater logic
Map → Fast lookup for required elements


*/

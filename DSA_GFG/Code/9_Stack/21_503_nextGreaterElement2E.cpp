/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.



Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans[i % n] = -1;
                st.push(nums[i % n]);
            }
            else
            {
                while (!st.empty() && st.top() <= nums[i % n])
                    st.pop();
                if (st.empty())
                    ans[i % n] = -1;
                else
                    ans[i % n] = st.top();
                st.push(nums[i % n]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {1,2,3,4,3};
    vector<int> res = sol.nextGreaterElements(v);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Why?
Loop runs 2n times → still linear
Each element is:
pushed once
popped once
Total stack operations ≤ 2n.

4️⃣ Space Complexity
O(n)
Stack can hold up to n elements

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Key Idea
The array is circular, so elements at the end can look to the beginning.
To simulate circular behavior, we traverse the array twice.
Use a monotonic decreasing stack to efficiently find next greater elements.
🔁 Strategy
Traverse indices from 2*n - 1 down to 0
Use i % n to map back to the original array index
Maintain a stack such that:
Stack always stores elements greater than the current one
For each element:
Remove all smaller or equal elements from stack
Stack top (if exists) is the next greater element
Otherwise, answer is -1
Push current element into the stack

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();

        // Result array, initialized with -1
        vector<int> ans(n, -1);

        // Stack to maintain monotonic decreasing order
        stack<int> st;

        // Traverse array twice (to simulate circular nature)
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int curr = nums[i % n];

            // Remove all elements smaller than or equal to current
            // They cannot be the next greater element
            while (!st.empty() && st.top() <= curr)
                st.pop();

            // If stack is not empty, top is next greater element
            if (!st.empty())
                ans[i % n] = st.top();
            else
                ans[i % n] = -1;

            // Push current element for future comparisons
            st.push(curr);
        }
        return ans;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Monotonic Stack (Decreasing Stack)
More specifically:
Next Greater Element
Circular Array Handling
Amortized O(n) stack processing

*/

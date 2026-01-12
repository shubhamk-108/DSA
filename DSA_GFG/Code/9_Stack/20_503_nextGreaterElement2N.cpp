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
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {

            for (int j = 1; j < n; j++)
            {

                // Checking for next greater element
                if (arr[i] < arr[(i + j) % n])
                {
                    res[i] = arr[(i + j) % n];
                    break;
                }
            }
        }

        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {0, 1, 0, 3, 12};
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
Outer loop → O(n)
Inner loop → O(n) (checks at most n−1 elements)
✅ Total Time: O(n²)
4️⃣ Space Complexity
Result array → O(n)
No extra data structures
✅ Total Space: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Problem

Next Greater Element II (Circular Array)

For each element, find the next greater element in a circular traversal.
If none exists, return -1.
1️⃣ Approach (Brute Force)
🧠 Intuition
For every index i:
Look at the elements to the right
If the end is reached, wrap around to the start
Check at most n−1 elements
The first element greater than arr[i] is the answer
If no such element exists, keep -1
This follows the problem statement directly.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> nextGreater(vector<int> &arr)
    {
        int n = arr.size();

        // Result array initialized with -1
        vector<int> res(n, -1);

        // Fix the current element
        for (int i = 0; i < n; i++)
        {
            // Check next n-1 elements in circular manner
            for (int j = 1; j < n; j++)
            {
                // (i + j) % n handles circular indexing
                // First element greater than arr[i] is the answer
                if (arr[i] < arr[(i + j) % n])
                {
                    res[i] = arr[(i + j) % n];
                    break; // stop at the nearest greater
                }
            }
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

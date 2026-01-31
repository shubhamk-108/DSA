/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (auto x : res)
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
Each index is pushed once
Each index is popped at most once
Total operations are linear

Space Complexity
O(k)
Why?
Deque stores at most k indices (window size)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

🔑 Core Idea

This problem is solved using a Monotonic Deque.
We maintain a deque that:
stores indices (not values)
is kept in decreasing order of values
always has the maximum element of the current window at the front
Step-by-step Approach
For every index i in the array:

1️⃣ Remove out-of-window indices
If the index at the front is outside the current window [i-k+1, i], remove it.

2️⃣ Maintain decreasing order
Remove all indices from the back whose values are smaller than the current element, because they can never be the maximum again.

3️⃣ Insert current index
Push the current index to the back of the deque.

4️⃣ Record the answer
Once the window size reaches k, the front of the deque gives the maximum element.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;   // stores indices, not values

        for (int i = 0; i < n; i++)
        {
            // 1️⃣ Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // 2️⃣ Maintain decreasing order in deque
            // Remove all smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // 3️⃣ Add current index
            dq.push_back(i);

            // 4️⃣ Once first window is formed, record the maximum
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Primary Pattern
Monotonic Deque
🏷️ Secondary Patterns
Sliding Window
Greedy



*/

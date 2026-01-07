/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
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
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin() + (n-k), nums.end());
        reverse(nums.begin(), nums.begin() + (n-k));
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> v = {7, 12, 9, 3, 1, 8, 5};
    sol.rotate(v, 3);
    for (auto x : v)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity = O(n)
Space Complexity = O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
To rotate an array nums right by k steps:
You want to move the last k elements to the front while keeping their internal order.
You can achieve this using three reversals:
Reverse the last k elements (they’ll later move to the front).
Reverse the first n−k elements (the remaining part).
Reverse the entire array to restore the correct order.
This reordering works because it effectively swaps the two parts [A | B] → [B | A].

*/

//___________________________________________________________________________________________________________________________________________
// Example
//___________________________________________________________________________________________________________________________________________

/*
Why reverse

Rotate [1,2,3,4,5,6,7] right by k=3 → [5,6,7,1,2,3,4]
[1,2,3,4 | 5,6,7]  →  [5,6,7 | 1,2,3,4]. Look carefully we have to reverse this two blocks.
[1,2,3,4,5,6,7] → [7,6,5,4,3,2,1]



*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        // Step 1: Reverse the last k elements
        // Example: [1,2,3,4,5,6,7] → [1,2,3,4,7,6,5]
        reverse(nums.begin() + (n - k), nums.end());

        // Step 2: Reverse the first n - k elements
        // Example: [1,2,3,4,7,6,5] → [4,3,2,1,7,6,5]
        reverse(nums.begin(), nums.begin() + (n - k));

        // Step 3: Reverse the entire array
        // Example: [4,3,2,1,7,6,5] → [5,6,7,1,2,3,4]
        reverse(nums.begin(), nums.end());
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// The Meaning of “Rotation by k”
//___________________________________________________________________________________________________________________________________________


/*


If you have an array of length n, rotating it to the right by k steps means each element moves right k positions, 
and if it goes past the end, it wraps around to the front.
💡 Why k % n Works
If k is larger than n, you’ve basically gone around the circle multiple times.
Think of it like a clock ⏰:
A clock has 12 hours.
If the time is 2:00 and you move ahead 14 hours, where do you end up?
→ 14 % 12 = 2 → You’re back at 4:00.
So moving 14 hours is the same as moving 2 hours — because every 12 hours, the pattern repeats.

*/
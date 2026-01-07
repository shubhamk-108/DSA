/*
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
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
    int countCompleteSubarrays(vector<int> &nums)
    {

        int n = nums.size();
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();

        unordered_map<int, int> um;

        int right = 0;
        int leftErasePtr = 0;

        while (right < n)
        {
            um[nums[right]]++;

            while (um.size() == totalUnique)
            {
                res += n - right;
                um[nums[leftErasePtr]]--;
                if (um[nums[leftErasePtr]] == 0)
                {
                    um.erase(nums[leftErasePtr]);
                }
                leftErasePtr++;
            }
            right++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 1, 2, 2};
    cout << sol.countCompleteSubarrays(v);
}




//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________

/*

Step 2: Initialize sliding window
unordered_map<int,int> um; // frequency map
int right = 0;             // right end of window
int leftErasePtr = 0;      // left end of window


um tracks how many times each number appears in the current window [leftErasePtr, right].

right will expand the window.

leftErasePtr will shrink the window when needed.

Step 3: Expand the window
while (right < n) {
    um[nums[right]]++;

Add nums[right] to the frequency map.

Now the window contains numbers [leftErasePtr, right].

Step 4: Shrink the window while complete
while (um.size() == totalUnique) {
    res += n - right;
    um[nums[leftErasePtr]]--;
    if (um[nums[leftErasePtr]] == 0) um.erase(nums[leftErasePtr]);
    leftErasePtr++;
}

Explanation:

um.size() == totalUnique → current window has all unique elements, so it’s a complete window.

Count subarrays starting at leftErasePtr and ending anywhere from right to n-1:

res += n - right;

Why n - right?

If your window ends at index right, all extensions to the right are still complete, because adding extra elements won't remove unique numbers.

Example: [1,2,3] is complete, [1,2,3,4] is also complete.

Shrink from the left:

um[nums[leftErasePtr]]--;
if (um[nums[leftErasePtr]] == 0) um.erase(nums[leftErasePtr]);

Remove the leftmost number from the window.
If its count becomes 0, remove it from um.
This ensures the window no longer counts that element after shrinking.
Step 5: Move right pointer
right++;

Expand the window to include the next element.
Repeat until the window covers the entire array.

*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n)
Each element is added and removed from the frequency map at most once, so linear time.
Space Complexity: O(n)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Approach

First, find the total number of unique elements in nums using a unordered_set. This is the number of distinct elements a "complete subarray" 
must contain.
Use a sliding window approach with two pointers:
right expands the window by including nums[right].
leftErasePtr shrinks the window from the left while the window still contains all unique elements.
Maintain a frequency map um for elements in the current window.
Whenever the window contains all unique elements (um.size() == totalUnique), count all subarrays ending at or after right:
res += n - right;
This works because extending the subarray beyond right still keeps it complete.
Shrink the window from the left until it no longer contains all unique elements.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums) {

        int n = nums.size();
        int res = 0;

        // Count total unique elements in the array
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();

        unordered_map<int, int> um; // frequency map for sliding window

        int right = 0;          // right end of window
        int leftErasePtr = 0;   // left end of window

        while (right < n) {
            um[nums[right]]++; // include current element in window

            // Shrink window from left while all unique elements are present
            while (um.size() == totalUnique) {
                // All subarrays starting at leftErasePtr and ending at [right..n-1] are complete
                res += n - right;

                // Remove leftmost element from window
                um[nums[leftErasePtr]]--;
                if (um[nums[leftErasePtr]] == 0) {
                    um.erase(nums[leftErasePtr]);
                }
                leftErasePtr++;
            }
            right++;
        }
        return res;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*
Sliding Window + Hash Map Frequency Count
*/


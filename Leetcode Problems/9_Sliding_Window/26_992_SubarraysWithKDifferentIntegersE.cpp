/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
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
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSubarrays = 0;

        unordered_map<int, int> freq;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            freq[nums[right]]++;

            while (freq.size() > k)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            maxSubarrays += right - left + 1;
            right++;
        }
        return maxSubarrays;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return (solve(nums, k) - solve(nums, k - 1));
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 1, 2, 3};
    cout << sol.subarraysWithKDistinct(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// My approach
//___________________________________________________________________________________________________________________________________________

/*

consider example: {1,2,1,2,3} and k = 1
Now there are n*(n+1) / 2 total subarrays in which at 1st number 1 subarray will be there, at 2nd number 2 subarrays will be there,
at 3rd number 3 subarrays will be there and so on. That is total length of subarrays will be there ending at current number.
{1,2,1,2,3} total 15 subarrays possible.
{1,2,3,4,5} subarray ending at each number 1+2+3+4+5 = 15.

Now consider valid  sliding window and there subarrays ending at last element. 
1,2 = (1,2) , Ending at 2
2,1 = (2,1) , (1)
1,2,3 = (1,2,3) , (2, 3), (3) , Ending at 3
1,2,1,2 = (1,2,1,2), (2,1,2), (1,2), (2)
2,3 = (2,3), (3)

Now if you observe, when we take k (no of unique ele) as 2 then we got subarrays for k = 2 means having 2 unique elements and k = 1 means 
having 1 unique elements.

If we would have taken k = 5 then we whould have got k = 5, k = 4, k = 3 and so on till k = 1. But we only need k = 5. We dont need k = 4,3,2,1.
So now imagine that if we again apply same sliding window code for k- 1 that is for k = 4 then we would got subarrays with k = 4,3,2 and 1.
So find subarrays for k = 5 and then to delete unnecessary subarrays from k = 5, find another subarrays for k-1 that is 4 and subtract k and k-1
subarrays count.



*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n)
Each element enters and leaves the sliding window at most once
Hash map operations average O(1).

Space Complexity: O(K).
Hash map stores at most K distinct elements in the window
Worst-case: O(n) if every number is distinct.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

To find the number of subarrays with exactly K distinct integers`, we use a classic trick:
exactly K distinct = at most K distinct − at most (K − 1) distinct
So the real challenge is to compute:
"How many subarrays have at most K distinct integers?"
We use a sliding window:
Expand right pointer and include elements into the window.
Use a hash map freq to count occurrences of each number.
If the number of distinct elements becomes more than K, shrink the window using left++.
For every valid window (≤ K distinct):
All subarrays ending at right and starting anywhere from left to right are valid.
So add (right − left + 1) to the count.
Finally:
answer = atMost(K) – atMost(K – 1)

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Function to count subarrays with AT MOST k distinct integers
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        int countSubarrays = 0;

        unordered_map<int, int> freq; // stores frequency of each number in window
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            // expand window by including nums[right]
            freq[nums[right]]++;

            // if window has more than k distinct numbers → shrink from left
            while (freq.size() > k)
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            // all subarrays ending at 'right' and starting from [left ... right] are valid
            countSubarrays += (right - left + 1);
        }

        return countSubarrays;
    }

    // exactly K distinct = atMost(K) - atMost(K - 1)
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1);
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window Pattern → “Variable Window”, also called Two Pointers

This problem is a classic example of:

🔹 Sliding Window with "at most K constraint"
🔹 Using frequency map + shrinking window
🔹 Exact K by using atMost(K) - atMost(K−1)


*/

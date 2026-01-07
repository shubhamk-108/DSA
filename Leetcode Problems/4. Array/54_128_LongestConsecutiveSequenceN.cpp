/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3

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
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int Finalcount = 0;
        int currentCount = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] + 1)
                currentCount++;
            else
            {
                Finalcount = max(Finalcount, currentCount);
                currentCount = 1;
            }
        }
        Finalcount = max(Finalcount, currentCount);
        return Finalcount;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {100,4,200,1,3,2};
    cout << sol.longestConsecutive(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n log n) — sorting dominates
Space: O(1) — in-place sort
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort the array.
Iterate through it, counting consecutive sequences.
Skip duplicates.
Track and update the maximum sequence length.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Edge case: if array is empty, no sequence exists
        if (nums.empty())
            return 0;

        // Step 1: Sort the array so that consecutive elements come together
        sort(nums.begin(), nums.end());

        int Finalcount = 0;     // Stores the length of the longest sequence found so far
        int currentCount = 1;   // Tracks the current consecutive sequence length

        // Step 2: Traverse through the sorted array
        for (int i = 0; i < nums.size(); i++)
        {
            // Skip duplicates to avoid breaking the streak unnecessarily
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 3: If the current number is exactly 1 greater than the previous
            // it continues the consecutive sequence
            if (i > 0 && nums[i] == nums[i - 1] + 1)
            {
                currentCount++; // Extend current sequence
            }
            else
            {
                // Sequence breaks → update longest and reset counter
                Finalcount = max(Finalcount, currentCount);
                currentCount = 1; // Start a new sequence from current element
            }
        }

        // Step 4: After loop ends, check the last sequence as well
        Finalcount = max(Finalcount, currentCount);

        // Step 5: Return the longest consecutive sequence length
        return Finalcount;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Sorting + Linear Scan (Naive Consecutive Sequence Finder)

*/

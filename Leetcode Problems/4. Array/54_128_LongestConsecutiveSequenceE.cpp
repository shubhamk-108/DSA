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

        int Finalcount = 0;
        int n = nums.size();

        unordered_set<int> us(nums.begin(), nums.end());


        for (int x : us)
        {
            if (us.find(x - 1) != us.end())
                continue;

            int start = x;
            int currentCount = 1;
    
            start++;
            while (us.find(start) != us.end())
            {
                start++;
                currentCount++;
            }
            Finalcount = max(currentCount, Finalcount);
        }
        return Finalcount;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n) average case
(Each element is inserted and looked up in O(1) on average.)

💾 Space Complexity
O(n) for the unordered_set
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Store all elements in a hash set (unordered_set) to enable O(1) lookups and remove duplicates automatically.
Iterate through each element x in the set.
If (x - 1) exists, skip this number since it’s not the start of a sequence.
If (x - 1) does not exist, treat x as the start of a new sequence.
Count forward (x + 1, x + 2, …) while those numbers exist in the set.
Track the maximum streak length found using Finalcount.
Return Finalcount at the end.
This ensures each number is visited only once during counting.

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
        int Finalcount = 0;           // stores overall max sequence length
        int n = nums.size();          // total elements

        unordered_set<int> us(nums.begin(), nums.end()); // O(n) insert, removes duplicates

        for (int x : us)
        {
            // skip if there's a smaller consecutive number before x
            if (us.find(x - 1) != us.end())
                continue;

            int start = x;
            int currentCount = 1;     // length of current sequence

            // count forward as long as next consecutive numbers exist
            while (us.find(start + 1) != us.end())
            {
                start++;
                currentCount++;
            }

            // update max sequence length
            Finalcount = max(currentCount, Finalcount);
        }
        return Finalcount;             // return the longest sequence length
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Hashing / Set-based Sequence Detection Pattern
→ A classic pattern where a hash set is used to detect sequence boundaries and count consecutive elements efficiently.


*/

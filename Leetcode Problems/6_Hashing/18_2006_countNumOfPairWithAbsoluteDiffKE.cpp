/*
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.


Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
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
        int countKDifference(vector<int> &nums, int k)
        {
            int n = nums.size();
            unordered_map<int, int> um;
            int count = 0;
            for (auto x : nums)
            {
                int required_1 = (x - k);
                int required_2 = (x + k);

                if (um.count(required_1))
                    count += um[required_1];

                if (um.count(required_2))
                    count += um[required_2];

                um[x]++;
            }
            return count;
        }
    };

    int main()
    {
        Solution sol;
        vector<int> v = {1, 2, 2, 1};
        cout << sol.countKDifference(v, 1);
        return 0;
    }

    //___________________________________________________________________________________________________________________________________________
    // Timespace
    //___________________________________________________________________________________________________________________________________________

    /*
    Time Complexity → O(n)
    Single pass through array
    Hash map operations average O(1)
    Space Complexity → O(n)
    Hash map stores frequencies of elements

    */

    //___________________________________________________________________________________________________________________________________________
    // Approach
    //___________________________________________________________________________________________________________________________________________

    /*

    You use a hash map (frequency map) to efficiently count how many values have appeared so far that can form a pair with the current 
    element x such that:

    |x – y| = k
    This equation means the valid y values are
    y = x - k
    y = x + k
    For each number x:
    You check how many times x - k has appeared → add to count.
    You check how many times x + k has appeared → add to count.
    Then you insert/update x in the map.
    This ensures all valid pairs are counted in one pass.


    */

    //___________________________________________________________________________________________________________________________________________
    // Code
    //___________________________________________________________________________________________________________________________________________

    /*

    class Solution
    {
    public:
        int countKDifference(vector<int> &nums, int k)
        {
            unordered_map<int, int> um;  // frequency map
            int count = 0;

            for (auto x : nums)
            {
                // values that can form |x - y| = k
                int required_1 = x - k;
                int required_2 = x + k;

                // if x - k occurred previously, add its frequency
                if (um.count(required_1))
                    count += um[required_1];

                // if x + k occurred previously, add its frequency
                if (um.count(required_2))
                    count += um[required_2];

                // store current number in map
                um[x]++;
            }

            return count;
        }
    };



    */

    //___________________________________________________________________________________________________________________________________________
    // Pattern used
    //___________________________________________________________________________________________________________________________________________

    /*

    ✔ Hashing / Frequency Map
    (Also known as "Count Using Hash Map" or "Complement Lookup")


    */

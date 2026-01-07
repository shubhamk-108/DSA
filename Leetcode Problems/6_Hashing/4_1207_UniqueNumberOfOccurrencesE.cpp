/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

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
    bool uniqueOccurrences(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            um[nums[i]]++;
        }

        unordered_set<int> us;
        for (auto &p : um)
        {
            int value = p.second;
            if (us.count(value))
                return false;
            us.insert(value);
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 2, 1, 1, 3};
    cout << sol.uniqueOccurrences(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity → O(n)
Counting: O(n)
Checking unique frequencies: O(k) where k is number of distinct numbers (≤ n)
Overall O(n)
Space Complexity → O(n)
unordered_map stores distinct numbers
unordered_set stores distinct frequencies
Worst case both store O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Count how many times each number appears using an unordered_map<int,int>.
Store each occurrence-count in an unordered_set<int>.
If at any point a count already exists in the set → two numbers have the same frequency → return false.
If all frequencies are unique → return true.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool uniqueOccurrences(vector<int> &nums)
    {
        // Count of total numbers
        int n = nums.size();

        // Map to store frequency of each number
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            um[nums[i]]++;   // increment frequency for nums[i]
        }

        // Set to check if any frequency repeats
        unordered_set<int> us;
        for (auto &p : um)  // iterate over each (number, frequency) pair
        {
            int value = p.second;  // frequency of the number

            // If this frequency already exists, it is not unique
            if (us.count(value))
                return false;

            // Otherwise insert this frequency into the set
            us.insert(value);
        }

        // All frequencies were unique
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Hashing / Frequency Counting Pattern


*/

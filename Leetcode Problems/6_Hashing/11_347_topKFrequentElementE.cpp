/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++)
        {
            um[nums[i]]++;
        }

        vector<pair<int, int>> v(um.begin(), um.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> res = sol.topKFrequent(v, 2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

time:
Building the map:            O(n)
Converting map to vector:    O(n)
Sorting by frequency:        O(n log n)
Final extraction:            O(k)
-------------------------------------
Total:                       O(n log n)


space:
Hash map:     O(n)
Vector:       O(n)
Output:       O(k)
--------------------
Total:        O(n)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Key = number
Value = count of occurrences
Convert the map into a vector of pairs {number, frequency}.
Sort this vector by frequency in descending order using a lambda comparator.
Take the first k elements from this sorted vector and return their numbers.
This solution is efficient and widely accepted on LeetCode (though not the most optimal).
Time = O(n log n), Space = O(n).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Step 1: Count frequency of each number
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            um[nums[i]]++; // increment count
        }

        // Step 2: Convert map to vector of {num, freq}
        vector<pair<int, int>> v(um.begin(), um.end());

        // Step 3: Sort by frequency in descending order
        sort(v.begin(), v.end(),
             [](auto &a, auto &b)
             {
                 return a.second > b.second; // higher freq comes first
             });

        // Step 4: Take the first k most frequent numbers
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first); // push the number
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Hash Map + Sorting (Frequency Sorting Pattern)

Count frequencies → Hash Map

Sort by frequencies → Custom Sort

This is a classic “Hashing + Sorting” frequency-based pattern.

Not the optimal one (optimal is Bucket Sort, O(n)),
but your solution is still correct and accepted.



*/

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
        sort(nums.begin(), nums.end(), greater<int>());

        vector<pair<int, int>> freq;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
            freq.push_back({nums[i], count});
        }

        // Sort by frequency descending
        sort(freq.begin(), freq.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        vector<int> res;
        int count = 0;
        unordered_set<int>us;
        for(auto x: freq)
        {
            if(!(us.count(x.first)))
            {
                res.push_back(x.first);
                count++;
                if(count == k)
                    return res;
                us.insert(x.first);
            }
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
Brute frequency count:  O(n²)
Sorting freq array:     O(n log n)
Total:                  O(n²)

space:
freq vector:    O(n)
set:            O(n)
Total:          O(n)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For every element in the array, count how many times it appears.
Use a nested loop → check each number against every other number.
Store the pair {number, frequency} in a vector.
Sort the vector by frequency in descending order.
Walk through the sorted vector, and pick the top k unique numbers.
Use a set to avoid duplicate numbers.
Return those k numbers.
This is the pure brute-force approach: do everything manually without maps or buckets.


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

        // Brute force freq array: store {num, freq}
        vector<pair<int, int>> freq;

        // Count frequency of each element using nested loops => O(n^2)
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
            // Store (element, its frequency)
            freq.push_back({nums[i], count});
        }

        // Sort pairs by frequency decreasing
        sort(freq.begin(), freq.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        vector<int> res;
        unordered_set<int> used; // to ensure we pick unique numbers

        // Pick top k unique frequent elements
        for (auto &x : freq)
        {
            // x.first = number, x.second = frequency
            if (!used.count(x.first))
            {
                res.push_back(x.first);
                used.insert(x.first);

                if (res.size() == k)
                    return res;
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


Brute force counting (nested loops)
Sorting based on frequency (custom comparator)
So the pattern is
Brute Force + Custom Sort

*/

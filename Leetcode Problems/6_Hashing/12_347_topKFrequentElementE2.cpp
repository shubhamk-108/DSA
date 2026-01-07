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

        vector<vector<int>> bkt(n+1);

        for (auto &x : um)
        {
            int num = x.first;
            int freq = x.second;

            bkt[freq].push_back(num);
        }

        vector<int> res;

        for (int i = bkt.size() - 1; i >= 1 && res.size() < k; i--)
        {
            for (auto x : bkt[i])
            {
                res.push_back(x);
                if (res.size() == k)
                    break;
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

Time Complexity:

O(n)
Breakdown:
Building frequency map → O(n)
Filling bucket array → O(n)
Collecting k elements → O(n)
No sorting → no n log n.
Space Complexity:
O(n)
Because:
Frequency map stores at most n unique elements
Bucket array stores all elements exactly once
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Create a bucket array of size n + 1.
Index of bucket = frequency
Example: if 5 occurs 3 times → place 5 in bucket[3]
Iterate buckets from highest frequency to lowest.
Pick numbers until you collected k elements.
This avoids sorting and achieves true O(n).


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

        // Step 1: Count the frequency of each number
        unordered_map<int, int> um;
        for (int x : nums)
            um[x]++;

        // Step 2: Bucket where index = frequency
        // Maximum frequency of any number is n
        Bucket size must be n + 1, because frequency can be from 1 to n.
        vector<vector<int>> bkt(n + 1);

        for (auto &p : um) {
            int num = p.first;
            int freq = p.second;
            bkt[freq].push_back(num);
        }

        // Step 3: Traverse buckets from high freq to low freq
        // no element here occurs 0 time. So 0th bkt will alwats be empty that is why go uptp 1.
        vector<int> res;
        for (int f = n; f >= 1 && res.size() < k; f--) {
            for (int num : bkt[f]) {
                res.push_back(num);
                if (res.size() == k)
                    break;  // stop if we have top k
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

Bucket Sort + Hash Map
This is a classic Bucket Sort pattern combined with frequency counting using a hash map.
Common for problems like:
Top K Frequent Elements
Sort by frequency
Grouping by frequency

*/

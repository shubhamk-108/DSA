/*
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).



Example 1:

Input
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
Output
[null, 1, 2]

Breaks down like this:
"RangeFreqQuery" → call constructor with [[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]]
That means the array arr = [12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]
Constructor does not return anything, so the output for this is always null
"query" → call query(1, 2, 4)
That means count how many times 4 occurs from index 1 to 2.
arr[1..2] = [33,4] → 4 occurs once → returns 1
"query" → call query(0, 11, 33)
arr[0..11] = entire array → 33 occurs twice → returns 2

Explanation
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.

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

class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (!mp.count(value))
            return 0;

        vector<int> &vec = mp[value];
        int count = 0;

        for (int x : vec)
        {
            if (x > right)
                break;

            if (x >= left)
                count++;
        }
        return count;
    }
};

int main()
{
    vector<int> v = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery sol(v);
    // vector<int> v = {0, 1, 0, 3, 12};

    cout << sol.query(0, 11, 33);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Preprocessing: O(n)
Each query: O(k), where k = occurrences of value
Worst case: if all numbers equal, k = n → O(n) per query.
This is why the binary search version is preferred (O(log n)).
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This is the brute-force approach for LC 2080 but optimized with preprocessing.
Step 1 — Preprocessing (Constructor)
We build a map:
value → list of indices where it appears

Example:
arr = [12,33,4,56,22,2,34,33,22,12,34,56]

Map will look like:

33 → [1, 7]
22 → [4, 8]
12 → [0, 10]
...

This helps answer frequency queries faster.
Step 2 — Query(left, right, value)
To answer:
How many times does `value` appear in [left, right]?

We:
Retrieve the vector of all positions where value occurs
Loop through the indices
Count only those x such that left ≤ x ≤ right
Stop early if x > right because indices are sorted

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> mp; // value → sorted list of indices

    RangeFreqQuery(vector<int> &arr)
    {
        // Build the map: store all occurrences of each value
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i); // push the index where this value appears
        }
    }

    int query(int left, int right, int value)
    {
        // If value never occurred, frequency is 0
        if (!mp.count(value))
            return 0;

        vector<int> &vec = mp[value]; // get all positions where value occurs
        int count = 0;

        // Loop through all stored indices
        for (int x : vec)
        {
            if (x > right)
                break;              // since indices are sorted, stop early

            if (x >= left)          // count only those in the range
                count++;
        }
        return count;               // return total frequency in [left, right]
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

A very common Leetcode pattern:
Pre-store all positions where each value occurs
For each query, check how many positions lie in the required range


*/

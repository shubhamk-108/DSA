/*
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.



Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.

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
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> freq;
        vector<bool> isUsed(n, false);
        for (int i = 0; i < n; i++)
        {
            if (isUsed[i])
                continue;
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    isUsed[j] = true;
                }
            }

            freq.push_back({arr[i], count});
        }

        sort(freq.begin(), freq.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second > b.second; });

        int res = 0;
        int removed = 0;

        for (auto x : freq)
        {
            removed += x.second;
            res++;

            if (removed >= n / 2)
                return res;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    cout << sol.minSetSize(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity ⏱️
Frequency calculation (nested loops): O(n²)
Sorting unique elements: O(k log k), where k ≤ n
Greedy traversal: O(k)
✅ Overall Time Complexity:
O(n²)

4️⃣ Space Complexity 💾
freq vector → O(n)
isUsed vector → O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Goal: Remove the minimum number of distinct elements such that at least half of the array elements are removed.
Steps:
Traverse the array and count frequency of each unique element using brute force.
Use a isUsed array to ensure each element’s frequency is counted only once.
Store (value, frequency) pairs in a vector.
Sort the vector in descending order of frequency.
Greedily remove elements with the highest frequency first.
Stop when removed elements ≥ n/2.
This follows the idea:
Remove the elements that give the maximum reduction first.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();

        // Stores (value, frequency)
        vector<pair<int, int>> freq;

        // Marks indices already counted
        vector<bool> isUsed(n, false);

        // Brute-force frequency calculation
        for (int i = 0; i < n; i++)
        {
            // Skip if this element was already counted
            if (isUsed[i])
                continue;

            int count = 0;

            // Count frequency of arr[i]
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    isUsed[j] = true; // mark as processed
                }
            }

            // Store unique element and its frequency
            freq.push_back({arr[i], count});
        }

        // Sort elements by decreasing frequency
        sort(freq.begin(), freq.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second > b.second;
             });

        int res = 0;      // number of distinct elements removed
        int removed = 0;  // total elements removed

        // Greedy removal
        for (auto x : freq)
        {
            removed += x.second;
            res++;

            if (removed >= n / 2)
                return res;
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Greedy + Frequency Counting
Count how much each element contributes
Sort by contribution
Pick the biggest contributors first
This exact pattern appears in:
LC 1338 – Reduce Array Size to The Half
Top K Frequent Elements
Task Scheduling / Load Reduction problems

*/

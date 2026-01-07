/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in
arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        map<int, int> mp;
        for (auto x : arr1)
            mp[x]++;
        vector<int> res;

        for (int i = 0; i < n2; i++)
        {
            while (mp[arr2[i]] > 0)
            {
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        for (auto &x : mp)
        {
            while (x.second > 0)
            {
                res.push_back(x.first);
                x.second--;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> v2 = {2, 1, 4, 3, 9, 6};
    vector<int> res = sol.relativeSortArray(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Your code uses a map<int,int>, which is a balanced BST (Red-Black Tree).
Because of this, every insertion / lookup / decrement is O(log n) — NOT O(1).
That is the key to understanding the complexity.

Time Complexity
Building map → O(n1 log n1)
Processing arr2 → O(n2 * log n1)
Processing remaining elements → O(n1 log n1)
Total = O(n1 log n1).


✅ 1. Building the map
for (auto x : arr1)
    mp[x]++;

For each element of arr1:
mp[x] needs to either find x or insert it.
In a map (RB-tree), this costs O(log k), where k is current size of map.
Worst case, map grows to size n1.
So the full loop cost:
𝑂(𝑛1.log 𝑛 )
NOT O(n).
If you want O(n) building, you must use unordered_map.

2. Processing arr2 elements
while(mp[arr2[i]] > 0)
{
    res.push_back(arr2[i]);
    mp[arr2[i]]--;
}


Accessing mp[arr2[i]] is O(log n1) each time
But total number of these operations equals sum of frequencies of arr2 elements in arr1.
That is ≤ n1.
So this step’s total:
O(n1⋅logn1)

3. Processing the remaining elements
for(auto &x : mp)
{
    while(x.second > 0)


Iterating map is O(m) where m = number of distinct keys.

But the inner loop total runs EXACTLY n1 times (because each frequency is decremented to 0).

Access to each node (x.first, x.second) is O(1) once iterator is there.

So the work:

Stepping through map nodes: O(m)

Pushing elements: O(n1)

Total:
O(m+n1)=O(n1)

This part is not the bottleneck.

⭐ FINAL TIME COMPLEXITY

O(n1logn1)+O(n1logn1)+O(n1)

That simplifies to:
🔥 O(n1 log n1)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Build a frequency map
map<int, int> automatically keeps numbers sorted.
Each key → value count in arr1.

First output all elements that appear in arr2
Because arr2 defines the custom order.
For each element in arr2, push it into result as many times as it appears in arr1.

Then output remaining elements in sorted order
map keeps keys sorted, so you simply iterate and push (key) count times.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        // Frequency map for all elements in arr1.
        // Using map keeps keys sorted automatically.
        map<int, int> mp;
        for (auto x : arr1)
            mp[x]++;

        vector<int> res;

        // First place elements that appear in arr2,
        // following the exact order of arr2.
        for (int i = 0; i < n2; i++)
        {
            // Push arr2[i] as many times as it appears in arr1.
            while (mp[arr2[i]] > 0)
            {
                res.push_back(arr2[i]);
                mp[arr2[i]]--;   // decrement frequency
            }
        }

        // Now place all remaining elements of arr1
        // in sorted order (map already keeps them sorted).
        for (auto &x : mp)      // x.first = value, x.second = frequency
        {
            while (x.second > 0)
            {
                res.push_back(x.first); // push remaining values
                x.second--;
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




*/

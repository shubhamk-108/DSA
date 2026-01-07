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
#include <map>
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

        vector<pair<int, int>> freq_vec;
        unordered_map<int, int> freq_mp;

        for (int i = 0; i < n; i++)
        {
            freq_mp[arr[i]]++;
        }

        for (auto &x : freq_mp)
        {
            freq_vec.push_back({x.second, x.first});
        }

        sort(freq_vec.rbegin(), freq_vec.rend());

        int res = 0;
        int removed = 0;

        for (auto &x : freq_vec)
        {
            removed += x.first;
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

⏱ Time Complexity
Frequency counting: O(n)
Sorting frequencies: O(k log k)
(where k = number of distinct elements, k ≤ n)
Overall: O(n log n)

🧠 Space Complexity
Hash map + vector storage: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Count frequencies of each number in the array.
Store frequencies in a separate list.
Sort frequencies in descending order.
Greedily remove numbers with the highest frequency first.
Stop once at least half of the elements are removed.
Why this works:
Removing a number with higher frequency removes more elements at once.
To minimize the number of distinct elements removed, we always choose the maximum impact option first.
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

        // Stores (frequency, value)
        vector<pair<int, int>> freq_vec;

        // Frequency map: value -> count
        unordered_map<int, int> freq_mp;

        // Step 1: Count frequency of each number
        for (int i = 0; i < n; i++)
        {
            freq_mp[arr[i]]++;
        }

        // Step 2: Move frequencies into a vector
        for (auto &x : freq_mp)
        {
            freq_vec.push_back({x.second, x.first});
        }

        // Step 3: Sort by frequency in descending order
        // (pair sorts by first element by default)
        sort(freq_vec.rbegin(), freq_vec.rend());

        int res = 0;      // number of distinct integers removed
        int removed = 0;  // total elements removed so far

        // Step 4: Greedily remove largest frequencies first
        for (auto &x : freq_vec)
        {
            removed += x.first; // add frequency
            res++;              // one distinct number removed

            // Step 5: Stop when at least half elements are removed
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
More precisely:
Greedy Strategy: remove elements with the highest frequency first
Why Greedy works: locally optimal choice (max removal) leads to global optimum (min distinct removals)


*/

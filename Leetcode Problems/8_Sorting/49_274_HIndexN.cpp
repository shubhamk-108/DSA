/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.



Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
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
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();

        int potentialHIdx = n;

        sort(citations.rbegin(), citations.rend());

        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (citations[i] >= potentialHIdx)
                    count++;
                else
                    break;
            }

            if (count >= potentialHIdx)
                return potentialHIdx;
            else
                potentialHIdx--;
        }
        return 0;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {3, 0, 6, 1, 5};
    cout << sol.hIndex(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
⏱️ Time Complexity
Sorting: O(n log n)
Outer loop: O(n)
Inner loop: O(n)
➡️ Total Time = O(n²)
(The nested counting dominates)

📦 Space Complexity
No extra data structures used
Sorting is done in place
➡️ Space = O(1) (ignoring sort stack)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The h-index can be at most n (number of papers).
Try all possible h-index values starting from the maximum possible (n) down to 0.
For each candidate h, count how many papers have at least h citations.
If exactly h papers satisfy this condition, then that h is the answer.
Return the first (largest) valid h.
Why descending order helps:
Sorting citations in descending order allows us to stop counting early once we see a value < h.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // Total number of papers
        int n = citations.size();

        // Maximum possible h-index is n
        int potentialHIdx = n;

        // Sort citations in descending order
        sort(citations.rbegin(), citations.rend());

        // Try all possible h-index values from n down to 1
        for (int j = 0; j < n; j++)
        {
            int count = 0;

            // Count how many papers have at least 'potentialHIdx' citations
            for (int i = 0; i < n; i++)
            {
                if (citations[i] >= potentialHIdx)
                    count++;
                else
                    // Since array is sorted descending,
                    // no further elements can satisfy the condition
                    break;
            }

            // If exactly 'potentialHIdx' papers satisfy the condition,
            // we found the h-index.
            //geater sign beacause we need at least , so maximum does not matter.
            if (count >= potentialHIdx)
                return potentialHIdx;
            else
                // Try the next smaller possible h-index
                potentialHIdx--;
        }

        // If no valid h-index found
        return 0;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force + Sorting + Exhaustive Checking

More specifically:
Brute Force Enumeration
Trying all possible h-index values

Sorting for Early Termination
Enables breaking the inner loop early

*/

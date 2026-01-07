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

        int hIdx = 0;

        sort(citations.rbegin(), citations.rend());

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (citations[j] >= j + 1)
                hIdx = j + 1;
            else
                break;
        }
        return hIdx;
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

Time Complexity
Sorting: O(N log N)
Single pass: O(N)
➡️ Overall: O(N log N)

📦 Space Complexity
No extra data structures used
Sorting done in-place
➡️ O(1) auxiliary space (ignoring sort recursion stack)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The h-index is at most n (number of papers).
Sort the citations in descending order.
Traverse the sorted array.
At index j, there are exactly j + 1 papers considered.
If the j-th paper has at least j + 1 citations, then j + 1 is a valid h-index.
Keep updating the h-index while the condition holds.
Stop as soon as the condition fails (further values cannot work).
The largest valid j + 1 is the answer.


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
        // Number of papers
        int n = citations.size();

        // h-index can be at most n
        int hIdx = 0;

        // Sort citations in descending order
        sort(citations.rbegin(), citations.rend());

        // Traverse sorted citations
        for (int j = 0; j < n; j++)
        {
            // If there are (j + 1) papers with at least (j + 1) citations
            if (citations[j] >= j + 1)
                hIdx = j + 1;   // Update h-index
            else
                // Once condition fails, further indices won't satisfy it
                break;
        }

        // Return the maximum valid h-index found
        return hIdx;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


More specifically:
Sorting to impose order
Greedy update of h-index
Invariant:

At index j, there are exactly j + 1 papers

*/

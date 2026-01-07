/*
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].



Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
Example 2:

Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
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


// This is wrong brute. I  think the correct brute also needed to build sorted array first.
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int n = heights.size();

        int mismatch = 0;

        for (int i = 0; i < n; i++)
        {
            int elePosition = 0;
            for (int j = 0; j < n; j++)
            {
                if (heights[j] < heights[i] || (heights[j] == heights[i] && j < i))
                {
                    elePosition++;
                }
            }

            if (elePosition != i)
                mismatch++;
        }
        return mismatch;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 1, 4, 2, 1, 3};
    cout << sol.heightChecker(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Outer loop → O(n)
Inner loop → O(n)
❌ Overall Time Complexity:
O(n²)

4️⃣ Space Complexity
No extra data structures used
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

1. Find smaller elements from current element in the whole array. And for equal number we just have to check equal number occuring before
the currently traversing element and we dont check any further for equal element. Because any way we are going to place it after out current
number. But for previously occured equal number we do have to consider it.
2. Imagine that we have counter all smaller element than currently traversed elements and we have to place those elements before our
currently traverse element then we place those smaller elements and then we place our that currently traverse elements.
For ex we have found 4 smaller element then we plave those smaller elements from index 0 to 3 and our currenlty traversing element will
come at index 4 which was i.
3. So whenever smaller and equal element count is not equal to i then that element is mismatched element.

Determine where heights[i] should appear in the sorted array.
To do that:
Count all elements smaller than heights[i] (from the entire array).
Count equal elements that appear before index i (to handle duplicates).
The total count gives the expected position of heights[i] in sorted order.
If the expected position is not equal to i, that element is misplaced.
Count such mismatches and return the result.
This simulates sorting without actually sorting.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int n = heights.size();

        // Count of misplaced elements
        int mismatch = 0;

        // Check each element's correct sorted position
        for (int i = 0; i < n; i++)
        {
            int elePosition = 0;

            // Compare with all elements
            for (int j = 0; j < n; j++)
            {
                // Count smaller elements
                // Count equal elements that appear before index i
                if (heights[j] < heights[i] ||
                    (heights[j] == heights[i] && j < i))
                {
                    elePosition++;
                }
            }

            // If expected position differs from current index
            if (elePosition != i)
                mismatch++;
        }

        return mismatch;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Brute-Force Simulation Pattern
Simulates sorted positions mathematically
Uses pairwise comparison
No sorting or auxiliary arrays



*/

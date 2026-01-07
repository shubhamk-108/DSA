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

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> temp(heights.begin(), heights.end());
        sort(temp.begin(), temp.end());

        int misMatch = 0;

        for (int i = 0; i < n; i++)
        {
            if (heights[i] != temp[i])
                misMatch++;
        }
        return misMatch;
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
Time Complexity
Copy array → O(n)
Sorting → O(n log n)
Comparison loop → O(n)
✅ Overall Time Complexity:
O(n log n)

4️⃣ Space Complexity
Extra array temp of size n
✅ Space Complexity:
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


The problem asks how many students are not standing in the correct order if heights were sorted in non-decreasing order.
Create a copy of the original heights array so we don’t modify it.
Sort the copied array to get the expected correct order.
Compare the original array with the sorted array index by index.
Count how many positions have different values → those students are misplaced.
Return the mismatch count.

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
        // Store size of the array
        int n = heights.size();

        // Create a copy of the original heights array
        vector<int> temp(heights.begin(), heights.end());

        // Sort the copied array to get expected order
        sort(temp.begin(), temp.end());

        // Variable to count mismatched positions
        int misMatch = 0;

        // Compare original and sorted arrays
        for (int i = 0; i < n; i++)
        {
            // If height is not in correct position
            if (heights[i] != temp[i])
                misMatch++;
        }

        // Return total number of mismatches
        return misMatch;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Sorting + Comparison Pattern



*/

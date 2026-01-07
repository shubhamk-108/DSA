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

        vector<int> countSort(101, 0);

        for (int i = 0; i < n; i++)
        {
            countSort[heights[i]]++;
        }

        vector<int> expected(n);
        int k = 0;

        for (int i = 1; i <=100; i++)
        {
            int freq = countSort[i];

            for (int j = 0; j < freq; j++)
            {
                expected[k] = i;
                k++;
            }
        }

        int misMatch = 0;

        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
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
Counting frequencies → O(n)
Building expected array → O(n)
Comparing arrays → O(n)
✅ Overall Time Complexity:
O(n)

4️⃣ Space Complexity
Frequency array of size 101 → O(1)
Expected array of size n → O(n)

✅ Overall Space Complexity:
O(n)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The problem asks how many students are not in the position they would be in after sorting heights.
Since heights[i] is in the range 1 to 100, use Counting Sort instead of comparison sorting.
Create a frequency array countSort where each index represents a height and stores how many times it occurs.
Using this frequency array, rebuild the expected sorted array.
Compare the original heights array with the expected array index by index.
Count how many positions differ and return that count.


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
        // Number of students
        int n = heights.size();

        // Frequency array for heights (1 to 100)
        vector<int> countSort(101, 0);

        // Count frequency of each height
        for (int i = 0; i < n; i++)
        {
            countSort[heights[i]]++;
        }

        // Array to store the expected sorted order
        vector<int> expected(n);
        int k = 0;

        // Build sorted array using counting sort
        for (int i = 1; i <= 100; i++)
        {
            int freq = countSort[i];

            // Place 'i' freq times in expected array
            for (int j = 0; j < freq; j++)
            {
                expected[k] = i;
                k++;
            }
        }

        // Count mismatched positions
        int misMatch = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != expected[i])
                misMatch++;
        }

        // Return total mismatches
        return misMatch;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Counting Sort / Frequency Array Pattern
This pattern is used when:
Input values lie in a small fixed range
You want better than O(n log n) time
Commonly used in:
Height / score problems
Bucket-based sorting
Frequency counting tasks

*/

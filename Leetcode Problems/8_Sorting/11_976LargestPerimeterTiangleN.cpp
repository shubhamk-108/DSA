/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0

Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation:
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
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
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 3)
            return 0;
        int ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] > nums[k])
                    {
                        if (nums[j] + nums[k] > nums[i])
                        {
                            if (nums[i] + nums[k] > nums[j])
                                ans = max(ans, (nums[i] + nums[j] + nums[k]));
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {8, 1, 0, 4, 5};
    cout << sol.largestPerimeter(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Trianle property. 
//___________________________________________________________________________________________________________________________________________

/*

Triangle Property (Triangle Inequality)
For any triangle with sides a, b, and c:
The sum of any two sides must be strictly greater than the third side.

Mathematically:

a + b > c
a + c > b
b + c > a

This rule is called the Triangle Inequality Property.
If sides are satisfying this property then triangle is valid.
Simplification using sorting
If you sort the sides:

a ≤ b ≤ c
Then:
Checking a + b > c is enough
The other two conditions are automatically satisfied

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Three nested loops → O(n³)


🧠 Space Complexity
Uses only a few variables → O(1) (constant extra space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

If the array has fewer than 3 elements, a triangle cannot be formed → return 0.
Generate all unique triplets (i, j, k) such that i < j < k.
For every triplet:
Check the triangle inequality rule:

a + b > c
b + c > a
a + c > b

If valid, compute the perimeter.
Track and return the maximum perimeter found.
This guarantees correctness because every possible triangle is checked.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();

        // A triangle needs at least 3 sides
        if (n < 3)
            return 0;

        int ans = 0;

        // Pick first side
        for (int i = 0; i < n - 2; i++)
        {
            // Pick second side (after i)
            for (int j = i + 1; j < n - 1; j++)
            {
                // Pick third side (after j)
                for (int k = j + 1; k < n; k++)
                {
                    // Check triangle inequality conditions
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[j] + nums[k] > nums[i] &&
                        nums[i] + nums[k] > nums[j])
                    {
                        // Valid triangle → update maximum perimeter
                        ans = max(ans, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }

        return ans;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force / Exhaustive Search
Tries all possible combinations
*/

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
        sort(nums.begin(), nums.end());
        for (int i = n - 3; i >= 0; i--)
        {
            // look triangle property in comments below.
            if (nums[i] + nums[i + 1] > nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 1, 2};
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
3️⃣ Time Complexity
Sorting the array → O(n log n)
Single backward traversal → O(n)
✅ Overall Time Complexity:
O(n log n)

4️⃣ Space Complexity
Sorting is done in place
No extra data structures used
✅ Space Complexity:
O(1)  (ignoring recursion stack of sort)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

A valid triangle must satisfy the triangle inequality:
the sum of the two smaller sides must be greater than the largest side.
Sort the array so that side lengths are in non-decreasing order.
To get the largest perimeter, start checking from the largest possible sides.
For each triplet (nums[i], nums[i+1], nums[i+2]) (from right to left):
If nums[i] + nums[i+1] > nums[i+2], a valid triangle is found.
Return the perimeter of the first valid triangle, since it will be the maximum.
If no triplet forms a triangle, return 0.



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

        // Sort the array to apply triangle inequality
        sort(nums.begin(), nums.end());

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
        // Check triplets starting from the largest values
        for (int i = n - 3; i >= 0; i--)
        {
            // Triangle condition: sum of two smaller sides > largest side
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                // Return the largest possible perimeter
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        // No valid triangle found
        return 0;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Greedy + Sorting Pattern
Sorting helps apply the triangle inequality correctly.
Greedy choice: always try the largest possible sides first.
The first valid triangle found guarantees the maximum perimeter.

*/

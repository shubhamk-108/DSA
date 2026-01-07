/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
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
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        long long i = 1;
        while (i * i <= x)
        {
            i++;
        }
        return i - 1;
    }
};

int main()
{
    Solution sol;

    cout << sol.mySqrt(9);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(√x)

Because you increment i from 1 up to around sqrt(x).

Space Complexity: O(1)

No extra data structures used.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Handle the special case x = 0 → return 0.
Start with i = 1.
Keep increasing i while i² ≤ x.
The moment i² > x happens, the previous number i - 1 is the floor square root.
Return i - 1.
This mimics how you'd manually check squares.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int mySqrt(int x)
    {
        // Special case: the square root of 0 is 0
        if (x == 0)
            return 0;

        long long i = 1;

        // Increase i until i*i becomes greater than x
        // The first i for which i*i > x means the answer is i-1
        while (i * i <= x)
        {
            i++;
        }

        // i*i is now greater than x, so the floor sqrt is i-1
        return i - 1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



✔️ Brute Force / Linear Search on Value
*/

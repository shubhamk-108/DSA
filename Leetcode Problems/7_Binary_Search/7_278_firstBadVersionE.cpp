/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.



Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// dummy function
bool isBadVersion(int version)
{
    return true;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

// this program can only be run in LC because they have implemented the isBadVersion problem.
int main()
{
    Solution sol;
    cout << sol.firstBadVersion(15);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// why not low<=high
//___________________________________________________________________________________________________________________________________________
/*
while (low <= high)
and inside:


if (isBadVersion(mid))
    high = mid;
else
    low = mid + 1;
Why this causes TLE
Suppose low = 1, high = 2

mid = 1

isBadVersion(1) = true

You do high = mid = 1

Next iteration:
low = 1, high = 1
mid = 1
isBadVersion(1) = true
high = mid = 1

This will cause infinite loop because high is not moving now.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(log n) → Binary search reduces search space by half each iteration.

🧠 Space Complexity

O(1) → Only uses a few integer variables.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Binary Search over versions from 1 to n.
Compute mid each iteration.
Call the API isBadVersion(mid):
If true → first bad is at mid or before → set high = mid
If false → first bad is after → set low = mid + 1
Loop until low == high.
Return low → the first bad version.
Why it works:
Binary search narrows the range to the smallest index where isBadVersion returns true.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;

        // Standard binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is bad using the provided API
            if (isBadVersion(mid))
                high = mid;       // first bad is at mid or left
            else
                low = mid + 1;    // first bad is after mid
        }

        // low points to the first bad version
        return low;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Binary Search on Answer / First True in Boolean Array
LC278 is a classic example of this pattern.
Similar to LC35 (Search Insert Position):
There we searched for first index where nums[i] >= target
Here we search for first index where isBadVersion(i) == true

*/

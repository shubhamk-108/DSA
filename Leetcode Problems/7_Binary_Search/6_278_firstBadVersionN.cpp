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
        for (int i = 1; i <= n; i++)
        {
            if (isBadVersion(i))
                return i;
        }
        return n;
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
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n) → may need to check every version in the worst case.
🧠 Space Complexity
O(1) → only uses an integer variable.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Start from version 1 and iterate to n.
For each version, call isBadVersion(version)
The first version that returns true is the first bad version.
Return that version.
This works because versions are sequentially ordered: once a bad version appears, all later versions are bad.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution {
public:
    int firstBadVersion(int n) {
        // Loop through versions 1 to n
        for (int i = 1; i <= n; i++) {
            if (isBadVersion(i))   // API call to check if version is bad
                return i;          // return first bad version
        }
        
        return n; // Just a fallback (won't be reached due to constraints)
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-force / Linear Scan


*/

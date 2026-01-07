/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
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
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();

        int num = 1;

        int i = 0;

        while (i < n && k > 0)
        {
            if (num == arr[i])
                i++;
            else
                k--;
            num++;
        }

        while (k--)
        {
            num++;
        }
        return num - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 4, 7, 11};
    cout << sol.findKthPositive(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(n + k)
Worst case, you scan the entire array: O(n)
If k remains after finishing array, you count additional numbers: O(k)

Space: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
We want the k-th missing positive number.
Idea:
Start from num = 1 (the first positive number).
Pointer i goes through the array.
For each number num:
If it matches arr[i], then it's NOT missing → move to next array element.
Otherwise, this number is missing → reduce k.
Continue until we’ve reduced k to 0.
If we finish the array, just keep counting missing numbers until k becomes 0.
This is the clean brute-force way:
▶ scan natural numbers
▶ compare with array
▶ count missing ones



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int num = 1;   // current positive number we are checking
        int i = 0;     // pointer for arr

        // Go through array while we still haven't found k missing numbers
        while (i < n && k > 0)
        {
            if (num == arr[i])
            {
                // 'num' exists in the array → not missing
                i++;   // move to next array element
            }
            else
            {
                // 'num' is NOT in the array → this is a missing number
                k--;   // reduce k-th missing count
            }
            num++;     // move to next positive number
        }

        // If array is finished but k still > 0,
        // keep going through natural numbers until k becomes 0
        while (k--)
        {
            num++;
        }

        // 'num' is 1 ahead of the actual answer
        return num - 1;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
✔ Two Pointers
One pointer on arr (i)
One pointer tracking natural numbers (num)



*/

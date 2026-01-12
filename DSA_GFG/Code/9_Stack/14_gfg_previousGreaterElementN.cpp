/*
You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Greater Element (PGE).

The Previous Greater Element (PGE) of an element x is the first element that appears to the left of x in the array and is strictly greater than x.


Note: If no such element exists, assign -1 as the PGE for that position.

Examples:

Input: arr[] = [10, 4, 2, 20, 40, 12, 30]
Output: [-1, 10, 4, -1, -1, 40, 40]
Explanation:
For 10, no elements on the left, so answer is -1.
For 4, previous greater element is 10.
For 2, previous greater element is 4.
For 20, no element on the left greater than 20, so answer is -1.
For 40, no element on the left greater than 40, so answer is -1.
For 12, previous greater element is 40.
For 30, previous greater element is 40.
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
vector<int> preGreaterEle(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        res[i] = -1; // default if no greater element found

        // Check all elements to the left of i
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                res[i] = arr[j];
                break; // nearest greater found
            }
        }
    }
    return res;
}
};




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(N²)
Space: O(N) (result array only)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For every index i:
Start from i-1
Move left until:
You find an element > arr[i] → that is the answer
OR you reach the beginning → answer = -1
This mimics how a human would solve it without optimization.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

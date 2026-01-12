/*
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.

Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
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
    vector<int> nextLargerElement(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[i] = -1; // default if no greater element exists

            // check elements to the right of i
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    ans[i] = arr[j];
                    break; // nearest greater found
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 2, 4};
    vector<int> res = sol.nextLargerElement(v);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(N²)
For each element, we may scan the remaining array.

💾 Space Complexity
O(N)
Only the result array is used.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For every element arr[i]:
Look to the right
Find the first element greater than arr[i]
If found → that is the answer
If not found → -1
This directly follows the problem statement, no optimization.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = -1; // default if no greater element exists

        // check elements to the right of i
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break; // nearest greater found
            }
        }
    }
    return ans;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

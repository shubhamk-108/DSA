/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
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
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int n = digits.size();
        int carry = 1;
        int unitDigit;
        int num;

        for (int i = n - 1; i >= 0; i--)
        {
            num = digits[i] + carry;
            unitDigit = num % 10;
            carry = num / 10;
            res.push_back(unitDigit);
        }

        if (carry == 1)
        {
            res.push_back(1);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {7, 3, 9};
    // vector<int> v = {9, 9, 9};
    vector<int> res = sol.plusOne(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n), where n  is the number of digits, since each digit is visited exactly once.​

Space Complexity
O(n), as a new result vector is created (could be O(1) if modified in-place, but this version creates a new vector

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the array from the last digit to the first.
Add 1 (as a carry) to the current digit.
Keep track of carry and unit digit.
store digit mod 10 and update carry to digit/10.
Push calculated unit digit to a result vector.
After the loop, if there's any remaining carry, add it to the result.
Reverse the result to get the proper order (since digits were processed right to left).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Function to add 1 to the number represented by digits array
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int n = digits.size();
        int carry = 1; // Start carry as 1 because we need to add one

        // Traverse digits from last to first
        for (int i = n - 1; i >= 0; i--)
        {
            int num = digits[i] + carry; // Add carry to current digit
            int unitDigit = num % 10;    // Extract the unit digit
            carry = num / 10;            // Update carry for next iteration
            res.push_back(unitDigit);    // Store the unit digit
        }

        // If there is any carry left (for cases like [9,9,9] => [1,0,0,0])
        if (carry == 1)
        {
            res.push_back(1);
        }

        // Currently, res is in reverse order so we need to reverse it
        reverse(res.begin(), res.end());

        // Return the final result
        return res;
    }
};


*/

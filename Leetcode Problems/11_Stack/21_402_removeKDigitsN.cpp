/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
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
    string removeKdigits(string num, int k)
    {

        for (int i = 0; i < k && !num.empty(); i++)
        {
            bool isDeleted = false;
            for (int j = 0; j + 1 < num.size(); j++)
            {
                if (num[j] > num[j + 1])
                {
                    num.erase(num.begin() + j);
                    isDeleted = true;
                    break;
                }
            }
            if (!isDeleted && !num.empty())
                num.pop_back();
        }

        int i = 0;
        while (i < num.size() && num[i] == '0')
            i++;

        num = num.substr(i);
        return num.empty() ? "0" : num;
    }
};

int main()
{
    Solution sol;
    string s = "1432219";
    int k = 3;
    cout << sol.removeKdigits(s, k);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Understanding
//___________________________________________________________________________________________________________________________________________

/*

We want to keep digits in increasing order. That is smaller number should be on left because left is most significant digit.
So smaller to the left, the better it is.
Ex: 1 4 increasing order
here comes 3. and order breaks 1 4 3 so we have to remove one of them so we will remove larger which is at the top of stack
and it is at left side so it will have most value according to unit place value so we will remove 4 which is top of stack.
It becomes 1 3 and so on.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
⏱️ O(n²) (worst case)
Outer loop runs k times
Each iteration:
Scan → O(n)
erase() → O(n)
So overall:
O(k×n)≈O(n^2)

Space Complexity
📦 O(1) (extra space)
No auxiliary data structures used


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea
To make the number smallest after removing k digits:
Remove one digit at a time
At each step:
Scan from left to right
Remove the first digit that is greater than the next digit
If no such digit exists, remove the last digit
Why this works:
A larger digit on the left has higher place value
Removing it gives a smaller number than removing digits later
Repeat this process k times.
After all deletions:
Remove leading zeros
If the string becomes empty, return "0"

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        // Repeat deletion k times
        for (int i = 0; i < k && !num.empty(); i++)
        {
            bool isDeleted = false;

            // Find the first decreasing pair
            for (int j = 0; j + 1 < num.size(); j++)
            {
                if (num[j] > num[j + 1])
                {
                    // Remove the larger digit
                    num.erase(num.begin() + j);
                    isDeleted = true;
                    break;
                }
            }

            // If no decreasing pair found, remove last digit
            if (!isDeleted && !num.empty())
                num.pop_back();
        }

        // Remove leading zeros
        int i = 0;
        while (i < num.size() && num[i] == '0')
            i++;

        num = num.substr(i);

        // If result is empty, return "0"
        return num.empty() ? "0" : num;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

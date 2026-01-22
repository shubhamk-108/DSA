/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Key rules to remember
You are not allowed to rearrange digits
You must remove exactly k digits
Smaller digits on the left are more important than big digits later

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
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

// string is used to simulate stack behaviour
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();
        string stac = "";

        for (int i = 0; i < n; i++)
        {
            if (stac.empty())
            {
                stac.push_back(num[i]);
            }
            else
            {
                while (!stac.empty() && stac.back() - '0' > num[i] - '0' && k>0)
                {
                    stac.pop_back();
                    k--;
                }
                stac.push_back(num[i]);
            }
        }

        while(k>0  && !stac.empty())
        {
            stac.pop_back();
            k--;
        }

        int i = 0;
        while(i < stac.size() && stac[i]=='0' )
            i++;

        stac = stac.substr(i);
        return stac.empty() ? "0" : stac;
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
⏱️ O(n)
Each digit is:
Pushed once
Popped at most once
Total operations ≤ 2n
4️⃣ Space Complexity
📦 O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________
/*

We want the smallest possible number after removing exactly k digits without changing order.
Key idea (Greedy)
If a digit is larger than the digit after it, removing it will make the number smaller.
We should remove such digits as early as possible (left side has higher place value).
Strategy
Use a monotonic increasing stack (implemented using a string).
Traverse digits from left to right.
For each digit:
While the stack top is greater than the current digit and k > 0, pop the stack.
Push the current digit
If k is still left, remove digits from the end
Remove leading zeros.
If result is empty, return "0"



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
        int n = num.length();
        string stac = "";  // Acts as a monotonic increasing stack

        for (int i = 0; i < n; i++)
        {
            // Remove larger digits from stack if current digit is smaller
            // and we still have removals left
            while (!stac.empty() && k > 0 && stac.back() > num[i])
            {
                stac.pop_back();
                k--;
            }

            // Push current digit into stack
            stac.push_back(num[i]);
        }

        // If k removals still remain, remove digits from the end
        while (k > 0 && !stac.empty())
        {
            stac.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < stac.size() && stac[i] == '0')
            i++;

        stac = stac.substr(i);

        // If all digits removed, return "0"
        return stac.empty() ? "0" : stac;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Greedy + Monotonic Stack
More specifically:
Greedy → Remove digits that locally minimize the number
Monotonic Increasing Stack → Maintains increasing order of digits



*/

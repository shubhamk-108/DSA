/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range.
Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.



Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:
Input: s = "0-1"
Output: 0
Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:
Input: s = "words and 987"
Output: 0
Explanation:

Reading stops at the first non-digit character 'w'.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while (i < n && s[i] == '0')
            i++;

        string digits = "";
        while (i < n && isdigit(s[i]))
        {
            digits.push_back(s[i]);
            i++;
        }

        if (digits.empty())
        {
            return 0;
        }

        long long res = 0;
        for (int j = 0; j < digits.length(); j++)
        {
            res = res * 10 +( digits[j] - '0');
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;
        }

        return (int)(sign * res);
    }
};

int main()
{
    Solution sol;
    string s1 = "words and 987";

    cout << sol.myAtoi(s1);

    return 0;
}


// timespace

/*


*/


// code

/*

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int i = 0;

        // --- Step 1: Ignore leading whitespace ---
        // Move the index 'i' past any space characters at the beginning of the string.
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // --- Step 2: Determine the sign ---
        // Check if the current character is a '+' or '-'.
        int sign = 1; // Assume positive by default.
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            // If it's a '-', set the sign multiplier to -1.
            if (s[i] == '-')
                sign = -1;
            // Move past the sign character.
            i++;
        }

        // This part is unnecessary and can be handled by the main digit loop.
        // It skips leading zeros, but the conversion logic `res = res * 10 + digit`
        // handles this automatically.
        // while (i < n && s[i] == '0')
        //     i++;

        // --- Step 3: Read digit characters ---
        // 'digits' will store the sequence of valid number characters.
        string digits = "";
        // Loop as long as we are within the string and the character is a digit.
        while (i < n && isdigit(s[i]))
        {
            digits.push_back(s[i]);
            i++;
        }

        // If no digits were found after spaces and sign, the result is 0.
        if (digits.empty())
        {
            return 0;
        }

        // --- Step 4: Convert digits to integer and handle overflow ---
        // Use 'long long' to temporarily hold a value larger than INT_MAX
        // to detect overflow.
        long long res = 0;
        for (int j = 0; j < digits.length(); j++)
        {
            // Build the number: multiply the current result by 10 and add the new digit.
            // (digits[j] - '0') converts char '5' to int 5.
            // this is explained in detail below.
            res = res * 10 + (digits[j] - '0');

            // Check for overflow on each step.
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            // For negative numbers, check for underflow.
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;
        }

        // --- Step 5: Apply the sign and return ---
        // Cast the final 'long long' result back to 'int'.
        return (int)(sign * res);
    }
};


*/



//res = res * 10 + (digits[j] - '0');

/*
1. digits[j]
digits is a string, so digits[j] is a character (e.g., '5', '4', '9').

2. digits[j] - '0'
Characters in C++ are stored as ASCII codes.

'0' → 48

'1' → 49

'2' → 50

…

'9' → 57

So subtracting '0' shifts it to its numeric value:

'5' - '0' = 53 - 48 = 5

'9' - '0' = 57 - 48 = 9

That’s how you convert a char digit → integer digit. ✅

3. res * 10 + digit
Suppose we’re parsing the string "549":

Start: res = 0

First digit '5':

cpp
Copy code
res = 0 * 10 + 5 = 5

*/
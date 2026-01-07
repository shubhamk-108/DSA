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

        int i= 0;

        while(i < n && s[i]==' ')
        {
            i++;
        }

        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            if(s[i] == '-')
            {
                sign = -1;
            }
            i++;
        }

        long long res = 0;

        while(i < n &&  isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');
            if(sign == 1 && res > INT_MAX)
                return INT_MAX;
            if(sign == -1 && -res < INT_MIN)
                return INT_MIN;
            i++;
        }

        return (int)(sign * res);
    }
};

int main()
{
    Solution sol;
    string s1 = "-42";

    cout << sol.myAtoi(s1);

    return 0;
}

// timespace

/*
Complexity Analysis
Time Complexity: O(n)

The algorithm performs a single pass through the input string s. The index i is only ever incremented, ensuring that each character of the 
string is visited at most once.
Therefore, the runtime is directly proportional to the length of the string, making the time complexity O(n).

Space Complexity: O(1)

This solution is highly space-efficient. It only uses a few variables (n, i, sign, res) to store the state of the conversion.
The amount of memory used does not depend on the length of the input string s. It is constant.

*/

// code


/*

class Solution
{
public:
    int myAtoi(string s)
    {
        // Get the length of the string for loop boundary checks.
        int n = s.length();
        // 'i' will be our pointer to traverse the string.
        int i = 0;

        // --- Step 1: Ignore all leading whitespace ---
        // Advance 'i' as long as it's within bounds and points to a space character.
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // --- Step 2: Check for a sign character ('+' or '-') ---
        // Default sign is positive.
        int sign = 1;
        // Check if the current character is a sign.
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            // If it's a '-', set the sign to negative.
            if (s[i] == '-')
            {
                sign = -1;
            }
            // Move past the sign character to start processing digits.
            i++;
        }

        // --- Step 3: Convert number and handle overflow in a single loop ---
        // Use 'long long' to store the result temporarily. This allows us to detect
        // when the number exceeds the 32-bit integer range before it overflows.
        long long res = 0;

        // Loop as long as 'i' is in bounds and points to a digit.
        while (i < n && isdigit(s[i]))
        {
            // Build the number:
            // 1. Multiply the current result by 10 to shift digits to the left.
            // 2. Add the new digit (s[i] - '0' converts char to int).
            res = res * 10 + (s[i] - '0');

            // --- Real-time Overflow/Underflow Check ---
            // If the number is positive and exceeds INT_MAX, clamp it.
            if (sign == 1 && res > INT_MAX)
                return INT_MAX;
            // If the number is negative and goes below INT_MIN, clamp it.
            // We compare -res with INT_MIN because 'res' itself is positive.
            if (sign == -1 && -res < INT_MIN)
                return INT_MIN;
            
            // Move to the next character.
            i++;
        }

        // --- Step 4: Apply the sign and cast to int ---
        // Multiply the final number by its sign and cast it back to an integer.
        return (int)(sign * res);
    }
};

*/
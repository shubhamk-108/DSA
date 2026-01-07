/*
Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5

operators allowed: +,-,*,/.
Parenthesis not allowed.

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
    int calculate(string s)
    {
        int n = s.length();
        vector<int> numbers;
        vector<char> operators;

        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');

            if (!isdigit(s[i]) && s[i] != ' ')
            {
                numbers.push_back(num);
                operators.push_back(s[i]);
                num = 0;
            }

            if (i == n - 1)
                numbers.push_back(num);
        }

        for (int i = 0; i < operators.size(); )
        {
            if (operators[i] == '*' || operators[i] == '/')
            {
                int num1 = numbers[i];
                int num2 = numbers[i + 1];
                int res;
                if (operators[i] == '*')
                    res = num1 * num2;
                else
                    res = num1 / num2;
                numbers[i] = res;
                numbers.erase(numbers.begin() + i + 1);
                operators.erase(operators.begin() + i);
            }
            else
            {
                i++;
            }
        }

        int final_res = numbers[0];
        for (int i = 0; i < operators.size(); i++)
        {
            if(operators[i] == '+')
                final_res += numbers[i+1];
            else
                final_res -= numbers[i+1];
        }

        return final_res;
        
    }
}

;

int main()
{
    Solution sol;
    string s = "4+8*3/2+1";
    cout << sol.calculate(s);
    return 0;
}

//______________________________________________________________________________________________________________________
// Timespace
//______________________________________________________________________________________________________________________

/*

| Step             | Operation                   | Complexity | Reason                            |
| ---------------- | --------------------------- | ---------- | --------------------------------- |
| Parsing          | Build numbers and operators | **O(n)**   | One linear scan                   |
| Handling * and / | Repeated `erase()`          | **O(n²)**  | Each erase shifts elements        |
| Handling + and - | Simple traversal            | **O(n)**   | Sequential                        |
| **Total Time**   |                             | **O(n²)**  | Due to repeated erase             |
| **Space**        |                             | **O(n)**   | For storing numbers and operators |

erase is O(n) itself that is why it is O(n^2) without nested loop.
*/

//______________________________________________________________________________________________________________________
// Approach
//______________________________________________________________________________________________________________________

/*


Parse the string

Extract all numbers and operators separately using two vectors:
numbers → stores integers,
operators → stores +, -, *, /.
Handle * and /
Since * and / have higher precedence, evaluate them first.
When you compute one, replace the two operands with the result and erase the used operator and number from vectors.
Handle + and -
After step 2, only + and - are left.
Simply iterate from left to right and perform these operations sequentially.
Return the final result.




*/

//______________________________________________________________________________________________________________________
// Code
//______________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();
        vector<int> numbers;       // stores all numbers from expression
        vector<char> operators;    // stores all operators (+, -, *, /)

        int num = 0;
        // Step 1: Extract numbers and operators
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0'); // build multi-digit numbers

            // if we find an operator (not space or digit)
            if (!isdigit(s[i]) && s[i] != ' ')
            {
                numbers.push_back(num);
                operators.push_back(s[i]);
                num = 0; // reset for next number
            }

            // push last number
            if (i == n - 1)
                numbers.push_back(num);
        }

        // Step 2: Handle * and /
        for (int i = 0; i < operators.size();)
        {
            if (operators[i] == '*' || operators[i] == '/')
            {
                int num1 = numbers[i];
                int num2 = numbers[i + 1];
                int res;

                if (operators[i] == '*')
                    res = num1 * num2;
                else
                    res = num1 / num2; // integer division (truncates toward 0)

                numbers[i] = res; // replace first number with result
                numbers.erase(numbers.begin() + i + 1); // remove used number
                operators.erase(operators.begin() + i); // remove used operator
                // do NOT increment i — because after erase, next operator shifts left
            }
            else
            {
                i++; // increment only if no erase happened
                //why i++ is seperately incremented.
                // the thing is we are earsaing elements in above if block.  you are modifying a vector while iterating through it using an index. 
                // This causes your loop to skip elements, leading to incorrect calculations.
                // suppose one element got erased then the next element will get shifted to left but we are doing i++ then.
                // So the next element will be skipped and that i++ will point to next to next element of our current element being erased.
                // That is why in above if block if we deletes element then do not increment i because after deletion next elemnet is still
                // pointing that i. So increment only when none gets deleted.
            }
        }

        // Step 3: Handle + and -
        int final_res = numbers[0];
        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '+')
                final_res += numbers[i + 1];
            else
                final_res -= numbers[i + 1];
        }

        return final_res;
    }
};



*/

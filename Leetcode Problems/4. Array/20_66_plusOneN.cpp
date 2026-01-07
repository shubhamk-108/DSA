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
        long long num = 0;

        for (int i = 0; i < n; i++)
        {
            num = num * 10 + digits[i];
        }
        num++; 
       
        while(num>0)
        {
            res.push_back(num % 10);
            num = num / 10;
            
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
// Important note
//___________________________________________________________________________________________________________________________________________

/*

there is a brute force solution for LeetCode 66, but it is not recommended for this problem due to inefficiency for large numbers. 
The brute force idea is:
Convert the entire digits array to an integer (or string), perform the actual arithmetic addition (+1), then split the result back into an 
array of digits.

It converts the whole array of digits into a single integer (long long num), adds 1, and then you would need to convert num back to a digit array.
The main concerns:
It may overflow for large input (the number of digits can be up to 100).
For input with 20+ digits, even long long can't store the number correctly.
LeetCode test cases are often designed to check for overflow (inputs like [9,9,...,9] up to length 100).

This code fails for large digit arrays due to integer overflow.
Not interview-approved for critical code; only use for discussing algorithm possibilities or as a first hacky attempt.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time complexity: 
O(n)

Building the number from the digit array is 
O(n)

Extracting digits is 
O(n)

Reversing is 
O(n)

Total: 
O(n)​

Space complexity: 
O(n) for result vector​

Warning: This code is correct only for small input sizes (where the number fits in a long long). For large digit arrays (length > 18), the 
conversion will overflow and the result will be invalid. For all possible test cases, the carry simulation approach is preferred.​


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This code uses the brute force “number conversion” approach:
It converts the input digit array into an actual integer (using a long long type), by multiplying and accumulating each digit 
(num = num * 10 + digits[i]).​
It then adds one to this integer (num++).
Finally, it repeatedly extracts digits from the result using % 10 and pushes them to a new result vector, and finally reverses the order to 
obtain the final digit array.​


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res;
        int n = digits.size();
        long long num = 0;

        // Convert digit array to integer
        for (int i = 0; i < n; i++)
        {
            num = num * 10 + digits[i]; // Accumulate value
        }
        num++; // Add one

        // Convert integer back to digit array
        while(num > 0)
        {
            res.push_back(num % 10); // Extract last digit
            num = num / 10;          // Remove last digit
        }
        reverse(res.begin(), res.end()); // Digits pushed in reverse order
        return res;
    }
};



*/

/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
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
    bool isHappy(int n)
    {
        vector<int> sumOfDigits;

        while (true)
        {
            sumOfDigits.push_back(n);
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            if (sum == 1)
                return true;
            else
            {
                for (int i = 0; i < sumOfDigits.size(); i++)
                {
                    if(sum == sumOfDigits[i])
                        return false;
                }
                
            }
            n= sum;
        }
    }
};

int main()
{
    Solution sol;
    int n = 19;
    cout << sol.isHappy(n);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Let k = length of the sequence before repeating (≤243).
Each iteration:
Compute sum-of-squares → O(log n) (number of digits)
Linear search in sumOfDigits → O(k)
Total time: O(k × log n × k) ≈ O(k² log n)
Space Complexity
Stores the vector of previously seen numbers → O(k) ≤ O(243) → practically O(1)

that extra k in time comes from below. suppose the sum generates 10 different numbers. so sumOfDigit will have 10 numbers in the vector and 
for each time you generate one sum you have to loop in that vector. so if you generate 10 sums then you will loop into that vector for 10 times 
but the vector itself has the size of 10 or upto 10 as we sequentially move towards 10 numbers which gives us time time k*k which is k^2. And 
then we need log(n) to compute each sum which is overall k^2 lon(n) time where n is the value of number and not length of number and k is the 
total number of sum we generated during process .


*/



//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Keep a vector sumOfDigits to store all previously seen numbers.
Compute the sum of squares of digits for n.
Check if the sum is 1 → happy number.
Otherwise, check the vector linearly to see if the number has appeared before.
If yes → cycle detected → return false.
Update n and repeat.
Essentially, it’s the same logic as the hashing approach, but instead of using an unordered_set for O(1) lookup, you use a 
vector with O(k) linear search.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool isHappy(int n)
    {
        // Vector to store all previously generated numbers
        // Used to detect cycles (repeated numbers)
        vector<int> sumOfDigits;

        // Keep generating next numbers until we find 1 (happy) or repeat (unhappy)
        while (true)
        {
            // Add current number to the vector
            sumOfDigits.push_back(n);

            // Compute sum of squares of digits of n
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;   // Extract last digit
                sum += digit * digit; // Square it and add to sum
                n /= 10;              // Remove last digit
            }

            // If sum is 1, we found a happy number
            if (sum == 1)
                return true;
            else
            {
                // Check if the sum has appeared before
                // Linear search through the vector
                for (int i = 0; i < sumOfDigits.size(); i++)
                {
                    if(sum == sumOfDigits[i])
                        return false; // Cycle detected, not a happy number
                }    
            }

            // Update n for next iteration
            n = sum;
        }
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Simulation → compute sum-of-squares sequence
Cycle detection by brute-force / linear search → check if the number repeats


*/

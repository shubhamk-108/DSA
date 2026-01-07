/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".



Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Explanation:
Jewels = {a, A}
Stones = a A A b b b b
Count how many stones are jewels:
a → jewel → count = 1
A → jewel → count = 2
A → jewel → count = 3
b → not jewel
b → not jewel
b → not jewel
b → not jewel
Output:3

Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0

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
    int numJewelsInStones(string jewels, string stones)
    {
        int n1 = jewels.size();
        int n2 = stones.size();
        int count = 0;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if(jewels[i] == stones[j])
                    count++;
            }
            
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string j = "aA";
    string s = "aAAbbbb";
    cout << sol.numJewelsInStones(j, s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity:
👉 O(n1 × n2)
n1 = number of jewel characters
n2 = number of stone characters
Nested loops → quadratic time.
Space Complexity:

👉 O(1)
No extra data structures, constant space.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Loop through every character in jewels.
For each jewel character, loop through every character in stones.
If characters match, increment the count.
Return the total count.
This checks all possible pairs (jewel vs stone), which is why it’s brute force.

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


Brute Force / Nested Iteration

*/

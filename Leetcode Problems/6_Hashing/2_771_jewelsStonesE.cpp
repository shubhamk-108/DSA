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

        unordered_set<char> us(jewels.begin(), jewels.end());
        int count = 0;

        for (auto c : stones)
        {
            if (us.count(c))
                count++;
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

👉 O(m + n)
m = length of jewels
n = length of stones
Building the set takes O(m), scanning stones takes O(n).

Space Complexity:
👉 O(k)
Where k ≤ number of unique characters in jewels (max 52 for a–z, A–Z).
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Insert all characters from jewels into an unordered_set<char> so we can check membership in O(1) time.
Iterate through each character in stones.
For every stone, check if it exists in the set of jewels.
If yes → increment the counter.
Return the final count.
This avoids unnecessary frequency maps and gives the simplest + fastest solution.

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

Hashing / Hash Set Lookup
Using a hash set to perform O(1) membership check for each stone.


*/

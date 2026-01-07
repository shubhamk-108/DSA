/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.



Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        char res = '$';
        for (int i = 0; i < n; i++)
        {
            if (letters[i] > target)
            {
                res = letters[i];
                break;
            }
        }
        return res == '$' ? letters[0] : res;
    }
};

int main()
{
    Solution sol;
    vector<char> v = {'c', 'f', 'j'};
    cout << sol.nextGreatestLetter(v, 'a');
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric    | Complexity                  |
| --------- | --------------------------- |
| **Time**  | O(n) → linear search        |
| **Space** | O(1) → constant extra space |



*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Iterate through the letters array from start to end.
For each letter, check if it is strictly greater than target.
The first such letter is the answer → break the loop.
If no letter is greater than target, return letters[0] (wrap-around).

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        char res = '$'; // placeholder for answer

        // Check each letter sequentially
        for (int i = 0; i < n; i++)
        {
            if (letters[i] > target)
            {
                res = letters[i]; // first letter greater than target
                break;            // stop searching
            }
        }

        // If no letter > target, wrap around to first letter
        return res == '$' ? letters[0] : res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Linear Search / Brute Force


*/

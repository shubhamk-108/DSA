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

        int low = 0;
        int high = n - 1;
        char res = '$';

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (letters[mid] <= target)
                low = mid + 1;
            else if (letters[mid] > target)
            {
                high = mid - 1;
                res = letters[mid];
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
| **Time**  | O(log n) → binary search    |
| **Space** | O(1) → constant extra space |



*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We are given a sorted array of characters letters and a target character.
Goal: Return the smallest character in letters that is strictly greater than target.
Use binary search to efficiently find the first character greater than target.
Steps:
Initialize low = 0, high = n-1, res = '$' (placeholder).
While low <= high:
Compute mid = low + (high - low)/2.
If letters[mid] <= target, move low = mid + 1.
Else, store letters[mid] as a possible answer and move high = mid - 1.
After the loop, check res:
If still '$', no letter > target → return letters[0] (wrap-around).
Else return res.


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

        int low = 0, high = n - 1;
        char res = '$'; // placeholder for result

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (letters[mid] <= target)
            {
                // mid is less than or equal to target → move right
                low = mid + 1;
            }
            else
            {
                // mid is greater than target → possible answer
                res = letters[mid];
                high = mid - 1; // try to find smaller letter > target
            }
        }

        // If no letter > target was found, wrap around to the first letter
        return res == '$' ? letters[0] : res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Sorted Array

Variant: Find First Element Greater than Target / Upper Bound


*/

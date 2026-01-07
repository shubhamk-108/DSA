/*

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the
smallest in lexicographical order among all possible results.
Example 1:
Input: s = "bcabc"
Output: "abc"
Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

input: s = "cbacdcbc"
| Step | Remaining String              | Chosen | Reason                                                                           |
| ---- | ----------------------------- | ------ | -------------------------------------------------------------------------------- |
| 1    | `cbacdcbc`                    | `a`    | `'a'` is the smallest letter that still allows us to include `'b','c','d'` later |
| 2    | remaining after `a` → `cdcbc` | `c`    | `'c'` is next smallest that allows `'d','b'` after it                            |
| 3    | remaining after `c` → `dcbc`  | `d`    | `'d'` next smallest, `'b'` still after it                                        |
| 4    | remaining after `d` → `bc`    | `b`    | `'b'` is the only one left                                                       |

__________________
Example number 5:
__________________
Input: bcabc
outputL abc
explanation:
take b. res = b
tace c. res = bc
we are going to take a but before that a will ask last char are you biggeer than m. If it says yes then also check that
are you (means last char of res) occuring after the index of a or are you occuring in the future as well. 
If it says yes to both the condition then only pop last char of res and then push current char. 
So pop c and then pop b. Make sure mark these c and b removed char index false in the is_visited_array. YOu will see this in below code.
If it says no to above two condition then keep those last chars c and b in the res as it is.
So we have removed c and b from res because it will going to occur in future as well.
So add a in res. Till now res is , res = a
then add b of index 3
then add c of index 4
so final res = abc.

*/

/*

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
    string removeDuplicateLetters(string s)
    {
        vector<bool>is_char_taken(26,false);
        vector<int>very_last_occuring_index(26,0);

        string res = "";

        for (int i = 0; i < s.length(); i++)
        {
            very_last_occuring_index[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            if(is_char_taken[(s[i] - 'a')])
                continue;

            while(!res.empty() && res.back() > s[i] && very_last_occuring_index[res.back() - 'a'] > i )
            {
                is_char_taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            is_char_taken[s[i] - 'a'] = true;
        }
        return res;
        
    }
};
int main()
{
    Solution sol;
    string s = "cbacdcbc";
    cout << sol.removeDuplicateLetters(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Each character is pushed and popped at most once from the result (stack).
The while loop overall processes each char a limited number of times.

Space Complexity
O(1) (constant)
Only 26 letters

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
After reading below approach please read example number 5 in the problem statement at the very beginnig.

Record last index of every character (so we know if it appears again later).
Use a stack (here, res string) to build the final answer.
Use a visited array (is_char_taken) to check if a character is already in the result.
Iterate over the string:
If current char already taken → skip.
While stack is not empty, and
top of stack > current char, and
the top char appears again later,
→ pop it out (to make result smaller).
Push current char and mark it taken.
Return the stack (string) as final answer.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // To mark if a character is already in the result
        vector<bool> is_char_taken(26, false);

        // To store the last occurrence index of each character
        vector<int> very_last_occuring_index(26, 0);

        // This will act as our stack (building the result)
        string res = "";

        // Step 1: Record the last index of every character
        for (int i = 0; i < s.length(); i++)
        {
            very_last_occuring_index[s[i] - 'a'] = i;
        }

        // Step 2: Traverse the string
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // If character is already taken, skip it
            if (is_char_taken[c - 'a'])
                continue;

            // please read example 5 in the problem statement.
            // Before adding the current char we have to check that last char of res string is smaller. If it is larger then
            // we will remove it but we will only remove it if that last char is gping to appear in the future so that 
            // we can add that removed char later and this way we can maintiain lexographic order.
            // But if that .ast char of string is not appearing in the future then we dont remove that char. We keep it as 
            // it is and we add current char in the res even if it last char is larger than current char and that is not 
            // lexicographically allowed.
            // Step 3: Maintain lexicographic order (Monotonic Increasing)
            // While stack not empty, and last char > current char,
            // and that last char appears again later — pop it.
            while (!res.empty() && res.back() > c && very_last_occuring_index[res.back() - 'a'] > i)
            {
                is_char_taken[res.back() - 'a'] = false; // mark popped char as unused
                res.pop_back(); // remove from stack
            }

            // It it passes the above two conditons then add that current char to the res.
            // Step 4: Add current character to result
            res.push_back(c);
            is_char_taken[c - 'a'] = true;
        }

        // Step 5: Return the final result
        return res;
    }
};


*/

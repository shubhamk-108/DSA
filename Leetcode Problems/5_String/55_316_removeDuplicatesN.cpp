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
        // I did not write the solution because it seems harder to me.
        // But you can explain this in interview:
        /*
        Brute-force approach (conceptual explanation)

        You can say this:  
        A brute-force solution would be to generate all possible subsequences of the string, because each subsequence naturally preserves the
        original order of characters.
        From all those subsequences, we would filter out only those that contain each distinct character exactly once.
        Then we would pick the lexicographically smallest string among those valid ones.

        🧩 Example (to show understanding)
        For example, if s = "cbacdcbc",
        we would generate all subsequences of it (like "c", "b", "cb", "ca", "cad", "acdb", etc.),
        keep only the ones that contain 'a', 'b', 'c', 'd' exactly once,
        and among those, choose the smallest lexicographically.
        The answer in that case would be "acdb".

        Brute-force time complexity

        | Step                                       | What happens                                                                    | Complexity |
        | ------------------------------------------ | ------------------------------------------------------------------------------- | ---------- |
        | Generate all subsequences                  | Each character can either be included or excluded → `2^n` possible subsequences | **O(2ⁿ)**  |
        | Check if subsequence has all unique chars  | Need to scan each subsequence (O(n))                                            | **O(n)**   |
        | Compare lexicographically among candidates | negligible compared to above                                                    | —          |

        
        */
    }
};

int main()
{
    Solution sol;
    // string s = "abcaabbcd";
    string s = "cbacdcbc";
    cout << sol.removeDuplicateLetters(s);
    return 0;
}

//______________________________________________________________________________________________________________________
// Timespace
//______________________________________________________________________________________________________________________

/*



*/

//______________________________________________________________________________________________________________________
// Approach
//______________________________________________________________________________________________________________________

/*




*/

//______________________________________________________________________________________________________________________
// Code
//______________________________________________________________________________________________________________________

/*




*/

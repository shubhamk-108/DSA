/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:
Input: s = "([])"
Output: true
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


class Solution {
public:
    bool isValid(string s) {
        // brute feels hard so i did not do it. Just read the appraoch and time complexity of this brtue to tell in interview
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

4️⃣ Time & Space Complexity (VERY IMPORTANT)
⏱ Time Complexity
Finding a pair → O(n)
Removing a pair → O(n)
Done up to ~n times
➡ Overall: O(n²)
🧠 Space Complexity
O(1) extra space (in-place string modification)




*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

“One brute force idea is to repeatedly remove valid adjacent bracket pairs like (), [], {} from the string.
If after all possible removals the string becomes empty, it’s valid; otherwise, it’s invalid.”
That’s it.
No code needed.
3️⃣ Approach of this brute (to SAY, not to code)
Brute Approach (verbal)
While the string keeps changing:
Find any adjacent valid pair: (), [], {}.
Remove it from the string.
Stop when no more pairs can be removed.
If the string is empty → valid.
Otherwise → invalid.



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




*/

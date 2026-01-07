/*
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.



Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".

Problem Summary

You are given a list of log strings.
Each log has 2 parts:

<identifier> <content>


Example:

dig1 8 1 5 1
let1 art can

🔵 There are 2 types of logs:
1. Letter-logs

Content contains only letters.

Example:

let1 art can
let2 own kit dig

2. Digit-logs

Content contains numbers.

Example:

dig1 8 1 5 1
dig2 3 6

🎯 Your Task: Reorder the logs by these rules
Rule 1 — Letter-logs come first

All logs with letters in content must appear at the top.

Rule 2 — Letter-logs are sorted lexicographically by content

Example:

"log1 act car"
"log2 act zoo"


Sorted by content:

act car
act zoo

Rule 3 — If contents are identical, sort by identifier

Example:

a1 art zero
b3 art zero


Sort by identifier → a1 comes before b3.

Rule 4 — Digit-logs remain in the same order

Digit-logs are not sorted.
Their relative order stays the same as input.

Example:
Input:

dig1 8 1 5 1
dig2 3 6


Output (same order):

dig1 8 1 5 1
dig2 3 6


Example 2:

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
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
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        int n = nums.size();
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 1, 0, 3, 12};
    cout << sol.frequencySort(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

if correct , please give me approach of code, comment my code, then say time and space and then tell which pattern is used to solve problem.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




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

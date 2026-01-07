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
        int n = logs.size();

        vector<pair<string, string>> letter;
        vector<pair<string, string>> digitt;

        for (int i = 0; i < n; i++)
        {

            string id = "";
            string content = "";

            int j = 0;

            while (j < logs[i].length() && logs[i][j] != ' ')
            {
                id += logs[i][j];
                j++;
            }

            j++;
            content = logs[i].substr(j);

            if (!content.empty() && isdigit(content[0]))
                digitt.push_back({id, content});
            else
                letter.push_back({id, content});
        }

        auto letterComparator = [&](auto &a, auto &b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first < b.first;
        };

        sort(letter.begin(), letter.end(), letterComparator);

        vector<string> res;

        for (auto &x : letter)
        {
            res.push_back(x.first + ' ' + x.second);
        }
        for (auto &x : digitt)
        {
            res.push_back(x.first + ' ' + x.second);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> s = {"let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"};
    vector<string> res = sol.reorderLogFiles(s);
    for (auto x : res)
        cout << x << "\n";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Splitting logs → O(N)
Sorting letter logs
Let M = number of letter logs
Sorting takes O(M log M)
String comparison can take up to O(L)
Final: O(M log M * L)
(This is the standard complexity for LC937)
Rebuilding result → O(N)
👉 Total: O(M log M * L)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Split logs into two groups
letter logs → content starts with a letter
digit logs → content starts with a digit
Store logs as pairs → (identifier, content)
This makes sorting easier.
Sort letter logs using custom rules
First by content (lexicographically)
If contents match → compare identifier
Digit logs remain in the same order (stable)
Reconstruct logs back into string format
Combine identifier + " " + content.
Return:
all sorted letter logs
followed by original-order digit logs

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        int n = logs.size();

        // Will store letter logs as {identifier, content}
        vector<pair<string, string>> letter;
        
        // Will store digit logs as {identifier, content}
        vector<pair<string, string>> digitt;

        // Step 1: Split each log into (identifier, content)
        for (int i = 0; i < n; i++)
        {
            string id = "";
            string content = "";
            int j = 0;

            // Extract identifier (everything until the first space)
            while (j < logs[i].length() && logs[i][j] != ' ')
            {
                id += logs[i][j];
                j++;
            }

            j++; // Skip the space after identifier

            // Extract content (rest of the string)
            content = logs[i].substr(j);

            // Classify the log:
            // If content starts with a digit → digit log
            // Else → letter log
            if (!content.empty() && isdigit(content[0]))
                digitt.push_back({id, content});
            else
                letter.push_back({id, content});
        }

        // Step 2: Sort only letter logs using custom rules
        // Rule 1: Sort by content lexicographically
        // Rule 2: If contents are equal, sort by identifier
        auto letterComparator = [&](auto &a, auto &b)
        {
            if (a.second != b.second)
                return a.second < b.second; // Compare content
            else
                return a.first < b.first;   // Contents equal → compare IDs
        };

        sort(letter.begin(), letter.end(), letterComparator);

        // Step 3: Build final result
        vector<string> res;

        // Add all sorted letter logs
        for (auto &x : letter)
        {
            res.push_back(x.first + ' ' + x.second);
        }

        // Add digit logs in the SAME ORDER as original (no sorting)
        for (auto &x : digitt)
        {
            res.push_back(x.first + ' ' + x.second);
        }

        return res; // Final reordered logs
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Custom Sorting + String Parsing
The problem combines two patterns:
1. String Parsing
Identify the part before the first space → identifier
Identify the content after the space → content
Check first character of content to classify type
2. Custom Comparator Sorting
Need to sort based on content then identifier
Requires a custom lambda sorting rule
This is a classic pattern for problems involving:
Processing logs
Splitting strings
Sorting based on custom rules



*/

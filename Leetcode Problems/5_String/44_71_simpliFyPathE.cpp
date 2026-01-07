/*
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.
Example 1
Input: path = "/home/"
Output: "/home"
Explanation:
The trailing slash should be removed
Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation:
Multiple consecutive slashes are replaced by a single one.
Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:
A double period ".." refers to the directory up a level (the parent directory).
Example 4:
Input: path = "/../"
Output: "/"
Explanation:
Going one level up from the root directory is not possible.
Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation:
"..." is a valid name for a directory in this problem.

*/

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <climits>
#include <sstream>

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> vector_ans_building;
        stringstream ss(path);
        string current_word;
        string res;

        while (getline(ss, current_word, '/'))
        {
            if (current_word.empty() || current_word == ".")
                continue;
            else if (current_word == "..")
            {
                if (!vector_ans_building.empty())
                    vector_ans_building.pop_back();
                else
                    continue;
            }
            else // (current_word != ".." && current_word != ".")
                vector_ans_building.push_back(current_word);
        }

        if (vector_ans_building.empty())
            return "/";

        for (auto x : vector_ans_building)

            res += '/' + x;

        return res;
    }
};

int main()
{
    Solution sol;
    // string s = "/.../a/../b/c/../d/./";
    string s = "/../";
    cout << sol.simplifyPath(s);
    // sol.simplifyPath(s);

    return 0;
}



// timespace:

/*
Splitting the path:
You iterate once through all characters in path using getline().
Each character is processed exactly once.
✅ O(n)
Processing each token (push/pop):
Each token (directory name) is pushed or popped at most once.
✅ O(k) where k is number of tokens, and k ≤ n.
Building the final string:
You iterate once through the stack and append to res.
✅ O(n)
✅ Total Time Complexity
O(n) + O(k) + O(n) = O(n)
✅ Final Time Complexity: O(n)
(where n = length of the input string)


💾 Space Complexity Analysis
Let’s count extra space used:
vector<string> vector_ans_building:
In the worst case, every directory name is stored.
✅ O(n) (sum of all string lengths)
stringstream and current_word:
Both take O(n) in total temporary memory.
✅ O(n)
Result string res:
Built at the end, also up to O(n).
✅ O(n)
✅ Final Space Complexity: O(n)

*/


// understanding


/*

Input
path = "/.../a/../b/c/../d/./"
We need to simplify it according to Unix path rules.
🔹 Rules reminder
"." means current directory — ignore it.
".." means go up one directory — remove the last valid folder from the path.
Multiple slashes (//) count as one /.
Other names (like "a", "b", "...", etc.) are valid directory names, not special symbols — unless exactly "." or "..".
🔹 Step-by-step breakdown
Let’s parse the path component by component:
/.../a/../b/c/../d/./
Split by /, ignoring empty parts:
["...", "a", "..", "b", "c", "..", "d", "."]
Now we’ll process this using a stack (that’s what the algorithm usually does):
Step 1:
part = "..." → not "." or "..", so it’s a valid folder name
➜ stack = ["..."]
Step 2:
part = "a" → valid folder name
➜ stack = ["...", "a"]
Step 3:
part = ".." → go up one level → pop last folder "a"
➜ stack = ["..."]
Step 4:
part = "b" → valid folder name
➜ stack = ["...", "b"]
Step 5:
part = "c" → valid folder name
➜ stack = ["...", "b", "c"]
Step 6:
part = ".." → go up one level → pop last folder "c"
➜ stack = ["...", "b"]
Step 7:
part = "d" → valid folder name
➜ stack = ["...", "b", "d"]
Step 8:
part = "." → ignore (current directory)
➜ stack remains = ["...", "b", "d"]
✅ Final Simplified Path
Join the stack with / and add a leading /:
/.../b/d
🔹 Explanation of where a and c went
a was removed because of the .. right after it → a/.. cancels out.
c was removed because of another .. right after it → c/.. cancels out.
✅ Final Output:
"/.../b/d"
Even though "..." looks like dots, it’s not special — it’s treated as a literal folder name.

What your algorithm does
Splits the path by '/' → O(n)
Processes each part once using a stack-like vector → O(n)
Joins the result into a final string → O(n)



*/


// code


/*


class Solution {
public:
    string simplifyPath(string path) {
        // Vector to store the "stack" of valid directory names
        vector<string> vector_ans_building;

        // Stringstream to help split the input path by '/'
        stringstream ss(path);
        string current_word;  // To hold each component while splitting
        string res;           // Final result string

        // Split the path by '/' and process each component
        while (getline(ss, current_word, '/')) {
            // Skip empty strings (caused by '//' or leading/trailing '/') 
            // and '.' which means "current directory"
            if (current_word.empty() || current_word == ".")
                continue;

            // If ".." is found, go up one directory (pop last element from stack)
            else if (current_word == "..") {
                if (!vector_ans_building.empty())
                    vector_ans_building.pop_back(); // Go up one level
                else
                    continue; // Already at root, do nothing
            }

            // Otherwise, it's a valid directory name; push it onto the stack
            else
                vector_ans_building.push_back(current_word);
        }

        // If after processing all components, stack is empty, return root "/"
        if (vector_ans_building.empty())
            return "/";

        // Build the final simplified path by joining stack elements with '/'
        for (auto x : vector_ans_building)
            res += '/' + x;

        // Return the result
        return res;
    }
};



*/
/*
The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.

Image:
 Example 1:
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
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
    int minOperations(vector<string> &logs)
    {
        int n = logs.size();
        stack<string>st;

        for(auto&ch:logs)
        {
            if(ch == "../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(ch == "./")
            {
                continue;
            }
            else
                st.push(ch);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    vector<string> v = {"d1/", "d2/", "../", "d21/", "./"};
    cout << sol.minOperations(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ O(n)
Each log is processed once
Stack operations are O(1)

🔹 Space Complexity
💾 O(n)
Stack can store up to n folder names in the worst case

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
This problem simulates folder navigation.
Key Idea:
Each folder move increases depth
"../" moves one level up
"./" does nothing
Use a stack to represent the current directory path.
Steps:
Initialize an empty stack
Traverse each log entry:
"../" → pop if possible
"./" → do nothing
Any other string → push to stack
Stack size at the end = current folder depth


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int n = logs.size();        // Number of logs (not required)
        stack<string> st;           // Stack to simulate directory levels

        // Process each log command
        for (auto &ch : logs)
        {
            // Move to parent directory
            if (ch == "../")
            {
                // Pop only if not already at root
                if (!st.empty())
                    st.pop();
            }
            // Stay in the same directory
            else if (ch == "./")
            {
                continue;
            }
            // Move into a child directory
            else
            {
                st.push(ch);
            }
        }

        // Current directory depth
        return st.size();
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

🎯 Stack / Simulation Pattern
This problem falls under:
Stack-based simulation
Path navigation problems
Undo / Backtracking-like behavior


*/

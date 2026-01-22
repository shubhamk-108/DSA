/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.



Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

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
    int calPoints(vector<string> &operations)
    {
        int n = operations.size();
        int sum = 0;
        stack<int> st;
        for (auto &ch : operations)
        {
            if (isdigit(ch[0]) || ch[0] == '-' && ch.size() > 1)
            {
                int x = stoi(ch);
                st.push(x);
                sum += x;
            }
            else if (ch == "+")
            {
                int top = st.top();
                st.pop();
                int secondTop = st.top();
                st.push(top);
                st.push(top + secondTop);
                sum += top + secondTop;
            }
            else if (ch == "D")
            {
                int top = st.top();
                st.push(2 * top);
                sum += 2 * top;
            }
            else if (ch == "C")
            {
                sum -= st.top();
                st.pop();
            }
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    vector<string> v = {"5", "2", "C", "D", "+"};
    cout << sol.calPoints(v);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Question
// but we can use two variable to store last 2 scores and one to hold sum. that way we can do in O(1) space. or is C the problem.
//  when we discard score we dont know then last 2 scores
//___________________________________________________________________________________________________________________________________________

/*
👉 Your intuition is correct:
"+" and "D" can be handled with last two variables
BUT "C" breaks O(1) space
So yes — "C" is the real problem.
["1","2","3","4","C","C","C"]
After three "C" operations:
You would need values from 3 steps ago
Two variables are fundamentally insufficient

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ Time Complexity
One pass over operations
O(n)

📦 Space Complexity
Stack stores all valid scores
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We process each operation one by one
Use a stack to store valid round scores
Maintain a running sum to avoid recomputing at the end
For each operation:
Number → push it to stack, add to sum
"+" → sum of last two scores
"D" → double the last score
"C" → remove the last score
The stack always represents the history of valid scores so far.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int sum = 0;           // Running total of scores
        stack<int> st;         // Stack to store valid round scores

        for (auto &ch : operations)
        {
            // Case 1: Number (positive or negative)
            if (isdigit(ch[0]) || (ch[0] == '-' && ch.size() > 1))
            {
                int x = stoi(ch);   // Convert string to integer
                st.push(x);
                sum += x;
            }
            // Case 2: "+"
            else if (ch == "+")
            {
                int top = st.top();    // Last score
                st.pop();
                int secondTop = st.top(); // Second last score

                st.push(top);                 // Restore last score
                st.push(top + secondTop);     // Push new score
                sum += top + secondTop;
            }
            // Case 3: "D"
            else if (ch == "D")
            {
                int top = st.top();
                st.push(2 * top);   // Double last score
                sum += 2 * top;
            }
            // Case 4: "C"
            else if (ch == "C")
            {
                sum -= st.top();    // Remove last score from sum
                st.pop();           // Remove last score from stack
            }
        }
        return sum;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Stack Simulation / History Tracking Pattern
*/

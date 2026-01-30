/*
The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.



Example 1:

Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
Example 2:

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int zerosCountOfStudents = 0;
        int onesCountOfStudents = 0;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 1)
                onesCountOfStudents++;
            else
                zerosCountOfStudents++;
        }

        for (int i = 0; i < sandwiches.size(); i++)
        {
            int currSandwich = sandwiches[i];

            if (currSandwich == 1)
            {
                if (onesCountOfStudents > 0)
                    onesCountOfStudents--;
                else if (onesCountOfStudents == 0)
                    return zerosCountOfStudents;
            }
            else
            {
                if (zerosCountOfStudents > 0)
                    zerosCountOfStudents--;
                else if (zerosCountOfStudents == 0)
                    return onesCountOfStudents;
            }
            
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    cout << sol.countStudents(students, sandwiches);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n)
One pass to count students
One pass to process sandwiches

💾 Space Complexity
O(1)
Only two counters used
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Count how many students want sandwich 0 and how many want sandwich 1.
Go through the sandwiches from top to bottom.
For each sandwich:
If at least one student wants it → serve it (decrement count).
If no student wants it → stop immediately.
Return the number of students left who couldn’t eat.
Key insight:
👉 The order of students does not matter, only the counts.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int zerosCountOfStudents = 0;
        int onesCountOfStudents = 0;

        // Count how many students prefer 0 and 1
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 1)
                onesCountOfStudents++;
            else
                zerosCountOfStudents++;
        }

        // Process sandwiches one by one
        for (int i = 0; i < sandwiches.size(); i++)
        {
            int currSandwich = sandwiches[i];

            if (currSandwich == 1)
            {
                // If there is a student who wants sandwich 1
                if (onesCountOfStudents > 0)
                    onesCountOfStudents--;
                else
                    // No student wants sandwich 1 → stop
                    return zerosCountOfStudents;
            }
            else // currSandwich == 0
            {
                // If there is a student who wants sandwich 0
                if (zerosCountOfStudents > 0)
                    zerosCountOfStudents--;
                else
                    // No student wants sandwich 0 → stop
                    return onesCountOfStudents;
            }
        }

        // All students ate
        return 0;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Greedy + Counting
Greedy: serve a sandwich if possible, otherwise stop
Counting: track how many students can eat each type
*/

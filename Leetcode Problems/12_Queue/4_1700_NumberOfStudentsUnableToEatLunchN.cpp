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
        queue<int> q;

        // Push all students into the queue
        for (int s : students)
            q.push(s);

        int i = 0;

        while (!q.empty() && i < sandwiches.size())
        {
            int oneCompleteRotation = q.size();
            bool eaten = false;

            while (oneCompleteRotation--)
            {
                if (q.front() == sandwiches[i])
                {
                    q.pop();
                    i++;
                    eaten = true;
                    break;
                }

                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
            if (!eaten)
                break;
        }
        return q.size();
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
Time Complexity
Worst-case: O(n²)
For each sandwich, we may rotate the entire queue once

💾 Space Complexity
O(n) — queue stores all students
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Put all students into a queue in the given order.
Use an index i to track the current sandwich.
For each sandwich:
Try to serve it by rotating the queue once completely.
If a student at the front wants the sandwich
They eat it and leave the queue.
Move to the next sandwich.
If no student eats the sandwich after one full rotation:
Stop — remaining students cannot eat.
Return the number of students left in the queue.
This approach directly follows the problem statement.


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
        queue<int> q;

        // Push all students into the queue in given order
        for (int s : students)
            q.push(s);

        int i = 0; // Index for current sandwich

        // Continue while there are students and sandwiches
        while (!q.empty() && i < sandwiches.size())
        {
            int oneCompleteRotation = q.size(); // Number of students to try
            bool eaten = false;                 // Tracks if sandwich is eaten

            // Try to serve current sandwich by rotating the queue once
            while (oneCompleteRotation--)
            {
                // If student at front wants the sandwich
                if (q.front() == sandwiches[i])
                {
                    q.pop();   // Student eats and leaves
                    i++;       // Move to next sandwich
                    eaten = true;
                    break;
                }
                else
                {
                    // Student goes to the back of the queue
                    q.push(q.front());
                    q.pop();
                }
            }

            // If no student ate the sandwich in a full rotation
            if (!eaten)
                break;
        }

        // Remaining students cannot eat
        return q.size();
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Queue Simulation (Brute Force)

Literal simulation of the process


*/

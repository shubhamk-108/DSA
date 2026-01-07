/*
You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).



Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]

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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // Sort: height descending, k ascending
        sort(people.begin(), people.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });

        vector<vector<int>> res;

        // Insert each person at index k
        for (auto &p : people)
        {
            res.insert(res.begin() + p[1], p);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {
        {7, 0},
        {4, 4},
        {7, 1},
        {5, 0},
        {6, 1},
        {5, 2}};

    vector<vector<int>> res = sol.reconstructQueue(v);
    for (auto &x : res)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Complexity

Time: O(n log n + n²) → O(n²)

Space: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Problem reminder
Each person is [height, k]
k = number of people with height ≥ this person standing in front.
Step 1: Sort people
We sort by:
height descending
if same height → k ascending
Why?
Tall people’s constraints depend only on other tall people
Short people do not affect tall people’s k
So we fix tall people first
After sorting:
Tallest → shortest
Step 2: Build the queue gradually
We start with an empty queue.
For each person [h, k] in sorted order:
Place them at index k in the current queue
That’s it.
Why placing at index k works
At the moment we place [h, k]:
Everyone already in the queue has height ≥ h
So index k means:
exactly k people ≥ h are before them
Future people:
Are shorter
Shorter people do not count
So the condition never breaks

*/

//___________________________________________________________________________________________________________________________________________
// Insert function
//___________________________________________________________________________________________________________________________________________

/*

Code lin
res.insert(res.begin() + k, person);
What it means in plain Englis
“Put this person at postion k, and push everyone from k onward one step to the right.”
⚠️ Nothing is overwritte
Example (important)
Current queue:
[ [7,0], [7,1] ]
Insert [6,1]:
res.insert(res.begin() + 1, {6,1});
Result:
[ [7,0], [6,1], [7,1] ]
What happened
[7,1] moved right
But that does not break its condition
[6,1] now has exactly one person ≥ 6 in front
Why shifting taller people backward is safe
Because:
Their condition depends on taller or equal people
A shorter person moving in front does not count
So:
Shifting taller people is harmless


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Pattern Used
Greedy
Sort + Inser
Process most constrained elements first
Invariant-based greedy

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern Used 
Greedy 
Sort + Insert 
Process most constrained elements first 
Invariant-based greedy

*/

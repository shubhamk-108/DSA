/*
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.
The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

2n people are already given and in that n goes to city A and other to city B
Yes — what you just said is 100% correct ✅
Let me restate it cleanly and align it with notation so there’s zero ambiguity.
Correct understanding (final, precise)
2N people are already given.
Out of those 2N people:
N must go to City A, and N must go to City B.
That is exactly what the problem says.
Apply this to the example
costs = {{10,20}, {30,200}, {400,50}, {30,20}};
costs.size() = 4
These 4 people = 2N
So:
2N = 4  →  N = 2
✔️ Send:
2 people → City A
2 people → City B

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
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size() / 2;

        int res = 0;

        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] - a[1] < b[0] - b[1]; });

        for (int i = 0; i < 2 * n; i++)
        {
            if(i<n)
                res+=costs[i][0];
            else
                res+=costs[i][1];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    cout << sol.twoCitySchedCost(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Comparator explanation
//___________________________________________________________________________________________________________________________________________
/*

What are a and b here?

Each element is:

a = {costA, costB}
b = {costA, costB}

So:
a[0] = cost to City A
a[1] = cost to City B

3️⃣ What does (a[0] - a[1]) mean?
This is the key insight.
diffA = a[0] - a[1];
Interpret the value:

| diff          | Meaning                                  |
| ------------- | ---------------------------------------- |
| very negative | A is **much cheaper** than B → prefers A |
| close to 0    | A and B are similar                      |
| very positive | B is **much cheaper** than A → prefers B |

So this number tells:
How painful it is to send this person to the “wrong” city

What the comparator is saying
return (a[0] - a[1]) < (b[0] - b[1]);

Read it in English:
“Put a before b if a has a stronger preference for City A than b.”
Because:
Smaller (A − B) ⇒ more negative ⇒ A is much cheaper

5️⃣ What happens after sorting?

After sorting:
People who strongly prefer City A come first
People who strongly prefer City B go to the end
Example sorted order:
[ strong A, weak A, neutral, weak B, strong B ]

6️⃣ How this solves the constraint (this is important)
Recall:
Total people = 2N
Must send exactly N to A and N to B
After sorting:
first N  → City A
last  N  → City B

Why is this optimal?
Because:
People at the front lose the most if sent to B
People at the back lose the most if sent to A
So we minimize total “sacrifice”.
7️⃣ Small dry run (your example)
costs = {{10,20}, {30,200}, {400,50}, {30,20}}

| Person | A   | B   | A−B  |
| ------ | --- | --- | ---- |
| 1      | 10  | 20  | -10  |
| 2      | 30  | 200 | -170 |
| 3      | 400 | 50  | +350 |
| 4      | 30  | 20  | +10  |

Sorted by A−B:

{-170}, {-10}, {+10}, {+350}
Assignments:
First 2 → City A
Last 2 → City B

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Sorting 2N people → O(N log N)
Single pass assignment → O(N)
✅ Overall: O(N log N)
Space Complexity
Sorting is in-place
Only a few variables used
✅ O(1) extra space (ignoring input)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



There are 2N people
Exactly N must go to City A and N to City B
For each person, compute how much extra cost we pay if we send them to A instead of B:
diff = costA − costB
Key idea:
People with very negative diff strongly prefer City A
People with very positive diff strongly prefer City B
Steps:
Sort people by (costA − costB)
Send:
First N people → City A
Remaining N people → City B
This minimizes total “penalty” from forced assignments

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        // N = number of people that must go to each city
        // Total people = 2N
        int n = costs.size() / 2;

        int res = 0;

        // Sort people by the difference between cost to A and cost to B
        // People who strongly prefer A come first
        // People who strongly prefer B go last
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b)
             { 
                 return (a[0] - a[1]) < (b[0] - b[1]); 
             });

        // Assign first N people to City A
        // Assign remaining N people to City B
        for (int i = 0; i < 2 * n; i++)
        {
            if (i < n)
                res += costs[i][0]; // cost to City A
            else
                res += costs[i][1]; // cost to City B
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Greedy + Sorting by Difference
More specifically:
Greedy choice: Assign people who lose the most if misassigned first
Sorting trick: Use (A − B) to quantify “loss”
Similar problems use the same pattern:
Job assignment with 2 choices
Interval-based greedy scheduling
Cost minimization with forced constraints

*/

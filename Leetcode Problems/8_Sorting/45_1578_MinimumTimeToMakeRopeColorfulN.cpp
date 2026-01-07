/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.


Example 1:

Diagram:

Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.


Example 2:

Diagram:

Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.

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
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = neededTime.size();
        vector<bool> used(n, false);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if(used[i])
                continue;

            int groupSum = neededTime[i];
            int groupMax = neededTime[i];

            for (int j = i + 1; j < n; j++)
            {
                if (colors[i] == colors[j])
                {
                    groupSum += neededTime[j];
                    groupMax = max(groupMax, neededTime[j]);
                    used[j] = true;
                }
                else
                    break;
            }
            res += groupSum - groupMax;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5};
    string colors = "abaac";
    cout << sol.minCost(colors, v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time complexity of that version is O(N) (more precisely, amortized O(N)).
Here’s the clean, final reasoning you can trust:
Even though there’s a nested loop, each index is processed at most once.
When a character is part of a group, it gets marked used.
Once marked, it is never revisited by the inner loop again.
The inner loop advances j across the array only once in total across the entire run.
If characters are distinct, the inner loop breaks immediately.
If characters are all the same, the inner loop runs once and all others are skipped.
So overall work is proportional to N, not N².
Final complexities
Time: O(N) (amortized)

4️⃣ Space Complexity 💾
used vector of size n
O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the string.
When you find an index not yet processed:
Treat it as the start of a group of consecutive same colors.
Scan forward while the color remains the same.
For that group:
Compute total neededTime (groupSum)
Track maximum neededTime (groupMax)
Add groupSum - groupMax to the result.
Mark all group indices as used so they are not processed again.
This follows the rule:
In each group, remove all balloons except the one with the maximum removal time.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = neededTime.size();

        // Marks indices already processed in a group
        vector<bool> used(n, false);

        int res = 0; // total minimum cost

        for (int i = 0; i < n; i++)
        {
            // Skip indices already included in a previous group
            if (used[i])
                continue;

            // Initialize current group sum and max
            int groupSum = neededTime[i];
            int groupMax = neededTime[i];

            // Expand group to the right while colors are same
            for (int j = i + 1; j < n; j++)
            {
                if (colors[i] == colors[j])
                {
                    groupSum += neededTime[j];
                    groupMax = max(groupMax, neededTime[j]);
                    used[j] = true; // mark as processed
                }
                else
                    break; // group ends when color changes
            }

            // Cost = remove all except the max-time balloon
            res += groupSum - groupMax;
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force: Nested scanning of consecutive groups
Greedy: Keep the balloon with maximum neededTime in each group


*/

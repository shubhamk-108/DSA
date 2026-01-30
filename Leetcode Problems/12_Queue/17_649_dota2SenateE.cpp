/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".



Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in round 1.
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.

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
    string predictPartyVictory(string senate)
    {
        int n = senate.length();
        queue<int> radiant, dire;

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        while (!radiant.empty() && !dire.empty())
        {
            int r = radiant.front();
            radiant.pop();
            int d = dire.front();
            dire.pop();

            if (r < d)
            {
                // Radiant bans Dire
                radiant.push(r + n);
            }
            else
            {
                // Dire bans Radiant
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
int main()
{
    Solution sol;
    string senate = "RDD";
    cout << sol.predictPartyVictory(senate);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Complexity
Time: O(n)
Space: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

High-level idea
We simulate the game round by round, making sure:
whoever comes earlier in the round acts first
banned senators are removed permanently
surviving senators come back in the next round
Instead of modifying the string, we track turns using indices.

📌 Step-by-Step Approach
Use two queues
radiant → indices of 'R'
dire → indices of 'D'
Initial scan
Traverse the string
Push indices into their respective queues
Simulate rounds
While both queues are non-empty:
Pop front from both queues
Compare indices
Smaller index acts first → bans the other
Push the winner back with index + n
This means “you’ll act again in the next round”
Termination
One queue becomes empty
The remaining party wins

🎯 Why index + n Works
Think of the senate as circular.
If a senator survives:
pushing index + n places them after all current senators
this perfectly simulates the next round
No extra round logic needed.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();

        // Store indices of R and D
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        // Simulate rounds
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d) {
                // Radiant bans Dire
                radiant.push(r + n);
            } else {
                // Dire bans Radiant
                dire.push(d + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Queue Simulation / Turn-Based Simulation



*/

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
        int rCount = 0, dCount = 0;

        // initial count
        for (char c : senate)
        {
            if (c == 'R')
                rCount++;
            else
                dCount++;
        }

        int i = 0;

        while (true)
        {
            // if one party finished
            if (rCount == 0)
                return "Dire";
            if (dCount == 0)
                return "Radiant";

            char curr = senate[i];
            int j = (i + 1) % senate.size();

            // find next opponent circularly
            while (senate[j] == curr)
            {
                j = (j + 1) % senate.size();
            }

            // update count of removed senator
            if (senate[j] == 'R')
                rCount--;
            else
                dCount--;

            // remove opponent
            senate.erase(senate.begin() + j);

            // fix index if needed
            if (j < i)
                i--;

            // move to next senator
            i = (i + 1) % senate.size();
        }
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

Time

Search opponent → O(n)
erase() → O(n)
Done ~n times
➡ O(n²)

Space
String storage → O(n)

isnt space O(1) . we are not taking any string. we are performing operation on given input string
es, you can argue it as O(1) auxiliary space
👉 But LeetCode / interviewers usually say O(n)

In this code:
string predictPartyVictory(string senate)

senate is passed by value
That already creates a copy of the input string
So you already have O(n) space, even before doing anything
➡ In this exact signature, space is O(n).
If the string were modified in-place?
If the function signature were:
string predictPartyVictory(string& senate)

Then:
No copy created
We reuse input memory
Only variables used:
rCount, dCount, i, j
➡ Auxiliary space = O(1) ✅

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Concept

Treat the senate as a list / string
Iterate senators in order
When a senator acts:
find the next available opponent
remove them from the list
Continue round by round until only one party remains

pseudocode:
list = senate characters
i = 0

while (list has both R and D):
    if list[i] == 'R':
        find next 'D' in circular manner
        remove it
    else:
        find next 'R'
        remove it
    i = (i + 1) % list.size()



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount = 0, dCount = 0;

        // initial count
        for (char c : senate) {
            if (c == 'R') rCount++;
            else dCount++;
        }

        int i = 0;

        while (true) {
            // if one party finished
            if (rCount == 0) return "Dire";
            if (dCount == 0) return "Radiant";

            char curr = senate[i];
            int j = (i + 1) % senate.size();

            // find next opponent circularly
            while (senate[j] == curr) {
                j = (j + 1) % senate.size();
            }

            // update count of removed senator
            if (senate[j] == 'R') rCount--;
            else dCount--;

            // remove opponent
            senate.erase(senate.begin() + j);

            // fix index if needed. It j got to starting index using modulo circular implementation then our currChar is ahead of j
            // and what we want to delete is before i. so even i will shift to the left. so i--. This is to ensure that when we do 
            // i = (i + 1) % senate.size(); then we are on correct next currChar.
            if (j < i) i--;

            // move to next senator
            i = (i + 1) % senate.size();
        }
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

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
        int n = people.size();
        vector<vector<int>> res(n, {-1, -1});

        sort(people.begin(), people.end());

        for (auto &x : people)
        {
            int peopleInFront = x[1];
            int height = x[0];
            int i = 0;

            while (i < n && peopleInFront != 0)
            {
                if (res[i][0] == -1)
                    peopleInFront--;
                else if (res[i][0] >= height)
                    peopleInFront--;
                i++;
            }

            if (peopleInFront == 0)
            {
                while (i < n && res[i][0] != -1)
                    i++;
                res[i] = x;
               
            }
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

// In interviews, this solution may raise questions like:
// “How do you know empty slots will always be filled correctly?”
// “Can you prove correctness?”
// That’s why interviewers prefer the descending + insert solution — it has a cleaner invariant.
// But again:
// Correct ≠ Preferred

//___________________________________________________________________________________________________________________________________________
// My understanding
//___________________________________________________________________________________________________________________________________________

/*

1. Sort in ascending order. 
2. Make empty result array to place answer vector.
3. Sorting in ascending because we have to place shorter first because if we place shorter in its correct position then 
we definitely know that ex 3,4 here 4 people will be ahead in queue for 3 so we will place 4 3 already in 5th position 
and here we know that 4 poeple will later come because we have sorted in ascending so we know that later we have greater 
or equal to 3 in the queue ahead.
3. We have to see how many poeple are there in the front. So if we get empty position or if there is greater or equal element
placed already then we use counter and add/subtract counter accodingly that these many poeple are ahead of us.
4. Now we saw how many poeple are ahead and we are about to place our new candidiate that time we have to check that 
is this position already filled, if yes we have to skip that position and place whereever we get empty position.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Sorting: O(n log n)
For each person:
Scan up to n
Total: O(n²)
Space Complexity
Result array: O(n)
Total: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Yes — your code is correct and accepted on LeetCode.
It is a valid greedy solution, though not the standard one most interviewers expect.
Important distinction:
✔️ Correct
⚠️ Harder to reason / explain
⚠️ Relies on empty-slot logic
But correctness-wise → YES.

2️⃣ Approach (your approach explained simply)
Core idea:
Sort people by (height asc, k asc)
Maintain a result array with empty slots
For each person:
Scan from left
Count:
empty positions (can be filled later by taller people)
or people with height ≥ current
When k becomes 0, place the person in the next empty slot
Why this works:
Shorter people are placed first
Empty slots guarantee room for taller people later
Taller people coming later will satisfy the k condition of shorter people
This approach is greedy with future reservation.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();

        // Result array initialized with empty slots
        vector<vector<int>> res(n, {-1, -1});

        // Sort by height ascending, then k ascending
        sort(people.begin(), people.end());

        // Process each person
        for (auto &x : people)
        {
            int peopleInFront = x[1]; // required count
            int height = x[0];
            int i = 0;

            // Scan the result array
            while (i < n && peopleInFront != 0)
            {
                // Empty slot → could be filled by taller person later
                if (res[i][0] == -1)
                    peopleInFront--;

                // Already placed person who is tall enough
                else if (res[i][0] >= height)
                    peopleInFront--;

                i++;
            }

            // Find the next empty slot to place current person
            if (peopleInFront == 0)
            {
                while (i < n && res[i][0] != -1)
                    i++;

                res[i] = x;
            }
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


✅ Greedy
✅ Sorting + Placement
✅ Constraint satisfaction using future reservation

Category:
Greedy with slot reservation

*/

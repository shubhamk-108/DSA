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
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

//___________________________________________________________________________________________________________________
// Understand why problem is greedy and then why factorial time etc
//___________________________________________________________________________________________________________________
/*

Problem reminder (in plain English)

Each person is (height h, k) where:

k = number of people in front of this person who have height ≥ h

We must arrange all people in one single line so that every person’s condition is satisfied.

Why this becomes a “try all combinations” problem (brute force)
Key difficulty

The constraint of one person depends on where other people stand.

For any person:

Their validity depends on who is before them

And how tall those people are

So you cannot check a person in isolation.

What brute force conceptually does

Brute force means:

“Try every possible queue arrangement and check which one satisfies all constraints.”

How many queue arrangements are possible?

If there are n people:

First position → n choices

Second position → n-1 choices

Third → n-2

...

Last → 1

Total arrangements:

n × (n-1) × (n-2) × ... × 1 = n!


That’s where factorial comes from.

Why we MUST try all permutations (no pruning in brute)

Let’s say you try to build the queue left to right.

At position 0:

You don’t know who should go first

Any person might be valid depending on future placements

Example:

(7,0)  (6,1)


If (6,1) goes first → invalid

If (7,0) goes first → valid

You can’t know this without trying.

Now imagine:

10 people

Each decision affects all future k values

👉 Every early choice can break future validity

So brute force cannot safely prune early.

Why checking ONE permutation costs extra time

For one arrangement:

For each person i:

Look at people in front

Count how many have height ≥ h

That is:

O(n) work per person
O(n) people
⇒ O(n²) per permutation

Final brute-force time complexity
Number of permutations = n!
Checking each permutation = O(n²)

Total = O(n! × n²)


This is completely infeasible.

Concrete numbers (this makes it real)

Even for n = 10:

10! = 3,628,800
3.6 million × 100 operations ≈ 360 million


LeetCode allows n up to 2000.

So brute force is:

Not slow — impossible

This is the KEY interview realization

You should say:

“Because each person’s constraint depends on relative positions of others, brute force would require enumerating all permutations of people. That is n! possibilities, and verifying each takes O(n²), making brute force infeasible.”

That sentence alone shows strong problem understanding.

Why greedy becomes necessary (preview)

Since:

Brute force is impossible

Constraints depend on relative order

We must:

Fix some people permanently first

So future choices don’t break past correctness

This is where greedy with sorting comes in.

Important reassurance

If you understand this explanation, then:

You understand the problem

You understand why brute is infeasible

You are thinking like an engineer

Coding is secondary.

*/

class Solution {
public:
    bool isValid(vector<vector<int>>& q) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            int h = q[i][0];
            int k = q[i][1];
            int count = 0;

            for (int j = 0; j < i; j++) {
                if (q[j][0] >= h)
                    count++;
            }

            if (count != k)
                return false;
        }
        return true;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end()); // needed for next_permutation

        do {
            if (isValid(people))
                return people;
        } while (next_permutation(people.begin(), people.end()));

        return {};
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
// My understanding
//___________________________________________________________________________________________________________________________________________

/*

1. next permutation will generate all possible permutations starting from sorting it.
2. Then it will give us something like this.
{4,4}, {5,0}, {5,2}, {6,1}, {7,0}, {7,1}
{4,4}, {5,0}, {5,2}, {6,1}, {7,1}, {7,0}
{4,4}, {5,0}, {5,2}, {7,0}, {6,1}, {7,1}
{4,4}, {5,0}, {5,2}, {7,0}, {7,1}, {6,1}
{4,4}, {5,0}, {5,2}, {7,1}, {6,1}, {7,0}
{4,4}, {5,0}, {5,2}, {7,1}, {7,0}, {6,1}
{4,4}, {5,0}, {6,1}, {5,2}, {7,0}, {7,1}
{4,4}, {5,0}, {6,1}, {5,2}, {7,1}, {7,0}
{4,4}, {5,0}, {6,1}, {7,0}, {5,2}, {7,1}
{4,4}, {5,0}, {6,1}, {7,0}, {7,1}, {5,2}

3. Any one of these is the final correct answer. SO we just have to check that is that permutation valid or not.

4. At the end we get this permutation [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]].

5. So we run two loops and first loop is from 0 to n but inner loop is from 0 to current element because we only care about front people
and any one permutation is the correct answer so only for correct one this condition will be correct and remaining will give us wrong 
as we want.

6. Just count in the loop that we have k number of elements in the front or not.

*/




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
me Complexity
Generating all permutations of n people: O(n!)
For each permutation, isValid() checks every person against all previous ones: O(n²) (to validate each new permutation)
Total Time Complexity: O(n! × n²) → exponential, only feasible for very small n.

Space Complexity
In-place permutations are generated, so O(1) extra space apart from input.
isValid() uses only constant extra variables.
Total Space Complexity: O(1)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

Sort the array initially: needed so next_permutation generates all permutations in lexicographical order.
Generate all permutations of the people vector using next_permutation.
For each permutation, check if it’s valid using isValid():
For each person i in the permutation, count how many people in front of them have height ≥ h.
If this count matches k (the number of people supposed to be in front), continue.
If any person fails this condition, the permutation is invalid.
Return the first valid permutation as the answer.
Key idea: Try every possible ordering (all permutations) until a valid one is found.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


class Solution {
public:
    bool isValid(vector<vector<int>>& q) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            int h = q[i][0];
            int k = q[i][1];
            int count = 0;

            for (int j = 0; j < i; j++) {
                if (q[j][0] >= h)
                    count++;
            }

            if (count != k)
                return false;
        }
        return true;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end()); // needed for next_permutation

        do {
            if (isValid(people))
                return people;
        } while (next_permutation(people.begin(), people.end()));

        return {};
    }
};


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*


Pattern used: Brute-force / Generate all possibilities
This is backtracking by enumeration of all permutations, checking constraints explicitly.
No greedy or sorting optimization is applied beyond preparing for next_permutation.

*/


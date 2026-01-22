/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.

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

// First read problem understanding below
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(asteroids[i]);
            else
            {
                bool isCurrAsteroidBursted = false;
                while ( !st.empty() &&  !isCurrAsteroidBursted && st.top() > 0 && asteroids[i] < 0  )
                {
                    if(abs(asteroids[i]) == abs(st.top()))
                    {
                        st.pop();
                        isCurrAsteroidBursted = true;
                    }
                    else
                    {
                        if (abs(st.top()) > abs(asteroids[i]))
                            isCurrAsteroidBursted = true;
                        else
                            st.pop();
                    }
                }
                if(!isCurrAsteroidBursted )
                    st.push(asteroids[i]);
            }
        }
        vector<int>res ;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 5, -6, 2, -1, 4};
    vector<int> res = sol.asteroidCollision(v);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Understand  the problem
//___________________________________________________________________________________________________________________________________________

/*
Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Problem rule (very important)
An asteroid collision only happens when:
a right-moving asteroid (> 0) is to the left of
a left-moving asteroid (< 0)
i.e. + followed by -
Asteroids moving in the same direction or away from each other never collide.
Given input
[3, 5, -6, 2, -1, 4]
Let’s simulate step by step, respecting order and direction.

Step-by-step simulation
1️⃣ 3
Stack: [3]

2️⃣ 5
Stack: [3, 5]

3️⃣ -6
Now collision can happen because:
5 (→) and -6 (←)
|−6| > |5| → 5 explodes
Stack becomes: [3]
Now again:
3 (→) and -6 (←)
|−6| > |3| → 3 explodes
Stack becomes: []
-6 survives
Stack: [-6]

4️⃣ 2
-6 (←) and 2 (→)
❌ No collision
They are moving away from each other
Stack: [-6, 2]

5️⃣ -1
Now collision possible:
2 (→) and -1 (←)
|2| > |1| → -1 explodes
Stack remains: [-6, 2]

6️⃣ 4
2 (→) and 4 (→)

❌ Same direction → no collision
Final stack:
[-6, 2, 4]

*/

//___________________________________________________________________________________________________________________________________________

// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n) ✔️
Reason:
Each asteroid is pushed once
Each asteroid is popped at most once
So total stack operations ≤ 2n.

Space Complexity
O(n) ✔️
Worst case: all asteroids move in same direction → all stored.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea

You simulate asteroid collisions in order, using a stack to represent the final stable asteroids seen so far.
Why stack?
Only the most recent asteroid can collide with the current one.
Once an asteroid is destroyed, it never comes back → stack is ideal.
Key observations you used
Collision happens only when:
stack top is moving right (> 0)
current asteroid is moving left (< 0)
One asteroid may cause multiple collisions → use a while loop.
Track whether the current asteroid survives using a flag.
Strategy
For each asteroid:
Try to collide it with stack top while collision is possible.
Resolve based on absolute sizes:
Equal → both destroyed
Larger survives
If current asteroid survives all collisions → push to stack.
Stack at the end represents the final answer.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> st; // stack stores surviving asteroids so far

        for (int i = 0; i < n; i++)
        {
            // Flag to track whether current asteroid is destroyed
            bool isCurrAsteroidBursted = false;

            
                // Collision is possible ONLY when:
                // - stack is not empty
                // - top of stack is moving right (> 0)
                // - current asteroid is moving left (< 0)
            
            while (!st.empty() &&
                   !isCurrAsteroidBursted &&
                   st.top() > 0 &&
                   asteroids[i] < 0)
            {
                // Case 1: equal size → both destroyed
                if (abs(asteroids[i]) == abs(st.top()))
                {
                    st.pop();                     // destroy stack top
                    isCurrAsteroidBursted = true; // destroy current
                }
                else
                {
                    // Case 2: stack asteroid is bigger → current destroyed
                    if (abs(st.top()) > abs(asteroids[i]))
                    {
                        isCurrAsteroidBursted = true;
                    }
                    // Case 3: current asteroid is bigger → stack top destroyed
                    else
                    {
                        st.pop();
                    }
                }
            }

            // If current asteroid survives all collisions, push it
            if (!isCurrAsteroidBursted)
                st.push(asteroids[i]);
        }

        // Convert stack to result vector (reverse order)
        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


🔹 Stack Simulation Pattern
(also called Collision / Elimination Stack)
Characteristics of this pattern:
Process elements left to right
Maintain a stack of valid survivors
Remove elements when a conflict condition occurs
Each element is pushed and popped at most once

Other problems using the same pattern:
LC735 – Asteroid Collision
LC402 – Remove K Digits
LC1047 – Remove All Adjacent Duplicates
LC84 – Largest Rectangle in Histogram
LC907 – Sum of Subarray Minimums

*/

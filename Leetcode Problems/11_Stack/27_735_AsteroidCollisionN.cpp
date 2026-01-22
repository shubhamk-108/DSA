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

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {        

        while (true)
        {
            int n = asteroids.size();
            bool isAsteroidBursted = false;

            for (int i = 0; i < n - 1; i++)
            {
                if (asteroids[i] > 0 && asteroids[i + 1] < 0)
                {
                    if (abs(asteroids[i]) == abs(asteroids[i + 1]))
                    {
                        asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                    }
                    else if (abs(asteroids[i]) < abs(asteroids[i + 1]))
                    {
                        asteroids.erase(asteroids.begin() + i);
                    }
                    else if (abs(asteroids[i]) > abs(asteroids[i + 1]))
                    {
                        asteroids.erase(asteroids.begin() + i + 1);
                    }
                    isAsteroidBursted = true;
                    break;
                }
            }
            if(isAsteroidBursted == false)
                break;
        }
        return asteroids;
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
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n²) (worst case)
Reason
Each erase() is O(n)
Up to n collisions can happen
n × n = O(n²)

🧠 Space Complexity
O(1) extra space
All operations are done in place

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea
You simulate asteroid collisions repeatedly until the system becomes stable.
How it works
Keep scanning the asteroid array from left to right.
Look for the only collision pattern:
asteroid[i] > 0  AND  asteroid[i+1] < 0
When a collision is found:
Compare absolute sizes.
Remove the smaller asteroid (or both if equal).
After one collision, restart scanning from the beginning.
Stop when a full pass causes no collision.
Why this works
Every collision strictly reduces the number of asteroids.
Eventually, no more adjacent (+ , -) pairs exist.
The remaining asteroids are the final state.


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
        // Keep simulating until no collision happens in a full pass
        while (true)
        {
            int n = asteroids.size();          // current size (must update every loop)
            bool isAsteroidBursted = false;    // tracks whether any collision happened

            // Scan adjacent asteroids
            for (int i = 0; i < n - 1; i++)
            {
                // Collision possible only when right-moving meets left-moving
                if (asteroids[i] > 0 && asteroids[i + 1] < 0)
                {
                    // Case 1: equal size → both destroyed
                    if (abs(asteroids[i]) == abs(asteroids[i + 1]))
                    {
                        asteroids.erase(asteroids.begin() + i,
                                        asteroids.begin() + i + 2);
                    }
                    // Case 2: right asteroid is smaller → destroyed
                    else if (abs(asteroids[i]) < abs(asteroids[i + 1]))
                    {
                        asteroids.erase(asteroids.begin() + i);
                    }
                    // Case 3: left asteroid is smaller → destroyed
                    else
                    {
                        asteroids.erase(asteroids.begin() + i + 1);
                    }

                    // A collision occurred → restart scanning
                    isAsteroidBursted = true;
                    break;
                }
            }

            // If no collision in this pass, system is stable
            if (!isAsteroidBursted)
                break;
        }

        return asteroids;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Simulation / Brute-Force Elimination Pattern
Characteristics:
Repeatedly apply rules
Modify data structure
Restart until stable



*/

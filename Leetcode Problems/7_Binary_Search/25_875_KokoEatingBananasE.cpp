/*

problem statement explained:
Koko loves to eat bananas. She has piles of bananas, where each piles[i] represents the number of bananas in that pile.
There is a guard who will return in H hours.
Koko chooses a fixed eating speed k bananas per hour.
How eating works
Every hour, she chooses one pile.
She eats k bananas from that pile.
If the pile has fewer than k bananas, she eats the entire pile and does NOT carry leftover time into another pile.
After she finishes (or empties) a pile, the hour ends.
Your Goal
Find the minimum integer speed k such that Koko can finish all banana piles within H hours.

📌 Example
Input:
piles = [3, 6, 7, 11]
H = 8

Explanation:

Try different speeds:

Speed k	Hours needed
1	3 + 6 + 7 + 11 = 27 hours
2	2 + 3 + 4 + 6 = 15 hours
3	1 + 2 + 3 + 4 = 10 hours
4	1 + 2 + 2 + 3 = 8 hours ✔
5	1 + 2 + 2 + 3 = 8 hours
6	1 + 1 + 2 + 2 = 6 hours

Minimum speed that allows ≤ 8 hours is 4.

What You Must Do
We need to choose k such that
total_hours_taken(k) <= H
And we want the minimum such k.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int i = 0; i < n; i++)
                hours += (piles[i] + mid - 1) / mid;

            if (hours <= h)
                high = mid;

            else if (hours > h)
                low = mid + 1;
        }
        return high;
    }
};

int main()
{
    Solution sol;
    // vector<int> v = {3, 6, 7, 11};
    vector<int> v = {0, 11, 23, 4, 20};
    cout << sol.minEatingSpeed(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// why binary seach for this quesiton
//___________________________________________________________________________________________________________________________________________


/*

✅ Intuition Behind the Solution (Why Binary Search?)
You are not searching inside an array.
You are searching for the answer (Koko’s eating speed).
This is the key idea.

🎯 Core Intuition

Koko can choose an eating speed k bananas/hour.
If she eats faster → she finishes sooner.
If she eats slower → she takes more time.

So clearly:
Eating speed k is directly connected to total hours.

And importantly:

If she can finish in h hours with speed k,
→ she will also finish with any higher speed (k+1, k+2, ...).

If she cannot finish with speed k,
→ she also cannot finish with any lower speed (k-1, k-2, ...).
This means the answer speed is:
The smallest speed for which hours ≤ h
This is a monotonic function.

⭐ Whenever the answer lies inside a monotonic range → use Binary Search on Answer
Koko problem fits this pattern:

speed k	hours needed
small k → hours too big	
bigger k → hours decreased	
much bigger k → hours small enough	

This is monotonically decreasing.
Binary search LOVES monotonic functions.

🧠 How to Recognize Binary Search on Answer Problems

Here is the mental cheat code:
✔️ If you are asked to find minimum or maximum value
✔️ within a range
✔️ and you can check whether a chosen value is valid
→ Binary Search on Answer.
This problem asks:

👉 "What is the minimum speed Koko must eat at so that she finishes in h hours?"
That matches the rule perfectly.

📌 When Binary Search Doesn't Come First in Mind — How to Build This Skill
Think like this:
Step 1 — Ask yourself:
“Am I asked to find a number X that makes some condition true?”
Here:
X = eating speed
Condition = finish in ≤ h hours
Yes → Binary search candidate.

Step 2 — Check monotonicity:
If speed too small → cannot finish
If speed big enough → can finish
If speed bigger → still possible
This is monotonic → perfect for binary search.

Step 3 — Determine range:
Minimum speed = 1
Maximum speed = max pile size
(If she eats max pile size per hour, she finishes that pile in 1 hour.)
*/

//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________

/*


Goal
Find the minimum eating speed k such that Koko finishes all bananas in ≤ h hours.

1️⃣ Search space (low & high)
Minimum speed:
low = 1

Maximum speed:
high = max(piles)
Because going faster than the largest pile is useless.

2️⃣ Check function
For a given speed mid, compute:
hours += ceil(piles[i] / mid)
Using integer math:
(piles[i] + mid - 1) / mid
If total hours:
✔ ≤ h
Speed is feasible → try smaller speed
high = mid

❌ > h
Speed too slow → increase speed. If we need too many hours means banana eating speed is too slow. So we have to increase the speed
hence we do low = mid + 1.
low = mid + 1

3️⃣ Termination

Binary search stops when:
low == high
Minimum speed found.

Return:
return high;
or
return low;
(Both same)

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time:
O(n log max(piles))

Space:
O(1)
*/



//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

1. Identify what we are searching for
We want to find the minimum speed Koko must eat so that she finishes all bananas in at most h hours.
So we search for a value k = speed.

2. Define the search space
Speed can range between:

1 banana/hour (slowest possible)

max(piles) bananas/hour
(fastest needed; more than this is useless)

So:
low = 1
high = max(piles)

3. Use Binary Search on the Answer
This problem uses the pattern:
✔ Binary Search on a Monotonic Function
Because:
As speed increases, hours needed decreases (monotonic)
As speed decreases, hours needed increases
This lets us apply binary search.

4. Test a middle speed
Pick mid = (low + high)/2 as a candidate speed.
Compute the number of hours Koko needs:
hours = Σ ceil(piles[i] / mid)
Using integer math:

ceil(a / b) = (a + b - 1) / b

5. Narrow the search
Case 1: hours <= h

Speed is enough (maybe even too high).
Try a smaller speed → move high = mid.

Case 2: hours > h

Speed is too slow.
Must eat faster → move low = mid + 1.

6. When low == high
The binary search converges to the minimum valid speed.
Return either:
return low;
or:
return high;
Both same.


*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        // Minimum possible speed = 1 banana per hour
        int low = 1;

        // Maximum possible speed = largest pile
        // Faster than this doesn't help (finishes that pile in 1 hour anyway)
        int high = *max_element(piles.begin(), piles.end());

        // Binary search on the answer (speed)
        while (low < high)
        {
            int mid = low + (high - low) / 2;  // candidate speed

            long long hours = 0;

            // Calculate how many hours Koko needs at speed = mid
            for (int i = 0; i < n; i++)
            {
                // Ceil of division using integer math:
                // ceil(piles[i] / mid) = (piles[i] + mid - 1) / mid
                hours += (piles[i] + mid - 1) / mid;
            }

            // If Koko can finish in h hours or less:
            // Try a smaller speed → move high left
            if (hours <= h)
                high = mid;

            // If she needs more hours than allowed:
            // mid speed is too slow → increase speed → move low right
            else
                low = mid + 1;
        }

        // low == high → minimum valid speed found
        return high;
    }
};


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer


*/

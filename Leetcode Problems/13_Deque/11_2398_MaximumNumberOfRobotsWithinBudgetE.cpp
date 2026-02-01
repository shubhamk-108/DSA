/*
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.



Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation:
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.

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
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        int left = 0, right = 0;
        deque<int> maxDq;
        int len = 0;
        vector<long long> prefixSum(n + 1, 0);
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + runningCosts[i];
        }

        for (right; right < n; right++)
        {
            while (!maxDq.empty() && chargeTimes[maxDq.back()] < chargeTimes[right])
                maxDq.pop_back();
            maxDq.push_back(right);

            while (left <= right)
            {
                long long windowSum =
                    prefixSum[right + 1] - prefixSum[left];

                int k = right - left + 1;

                long long cost =
                    chargeTimes[maxDq.front()] +
                    (long long)k * windowSum;

                if (cost <= budget)
                    break;

                if (maxDq.front() == left)
                    maxDq.pop_front();

                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {3, 6, 1, 3, 4};
    vector<int> v2 = {2, 1, 3, 4, 5};
    cout << sol.maximumRobots(v1, v2, 25);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Earlier my code was this but it says runtime error.
//___________________________________________________________________________________________________________________________________________

/*
 while (cost > budget && left <= right )
            {
                if (maxDq.front() == left)
                    maxDq.pop_front();
                left++;
                windwoSum = prefixSum[right + 1] - prefixSum[left];
                k = right - left + 1;
                cost = chargeTimes[maxDq.front()] + ((long long)k * windwoSum);
            }

Now here when left becomes equal to right then we again do left++ inside loop which make left crosses right. And if it crosses
right then there may be possibiities that we have empty deque which will lead in undefined behaviour because we are using
maxDq.front() in formula but it deque can be empty.

*/

//___________________________________________________________________________________________________________________________________________
// Intuition and explanation
//___________________________________________________________________________________________________________________________________________
/*

Step 0: What is this problem really asking?
You are given robots in a line (important).
For any contiguous group of robots [l … r], the total cost is:
max(chargeTimes[l..r])
+ (number of robots) * sum(runningCosts[l..r])
And you want:
the largest contiguous group whose cost ≤ budget
🔔 Keywords screaming at us:
contiguous → subarray
largest → maximize window length
cost depends on window content → sliding window
So we are hunting for the largest valid subarray.
🧠 Step 1: Why Sliding Window is inevitable
Brute force would try all subarrays:
O(n²) subarrays
computing cost each time → too slow
But notice something important:
When you expand the window, cost never decreases
Why?
max charge stays same or increases
sum of running costs increases
window size increases
That monotonic behavior is the green light for sliding window.
Sliding window rule
Expand right
If invalid → move left
Never move pointers backward
That’s why this is variable-size sliding window.

🧠 Step 2: What blocks a naïve sliding window?
To maintain window cost efficiently, we need:
Two things for [l..r]

1️⃣ Sum of runningCosts
Easy → prefix sum or running sum

2️⃣ Maximum chargeTime in window
❌ This is the real problem
If you recompute max every time → O(n) → total O(n²)
So we need:
A data structure that gives max of a sliding window in O(1)

start---------------------------------------------------------------------------------------------------------------------

🧠 Step 3: Why a Monotonic Deque?
This is the same mental jump as LC 1438.
In LC1438:
abs(max(nums[l..r]) - min(nums[l..r])) <= limit
You solved it using:
one deque for max (maxDq)
one deque for min (minDq)
Here:
cost = max(chargeTimes[l..r]) + ...
Only max is needed → one deque
🔹 How the deque works (intuitively)
We store indices, not values.
We maintain it in decreasing order of chargeTimes.
Why?
Front → maximum in window
Back → smaller, less useful elements

When adding a new element right
while back is smaller than chargeTimes[right]
    pop back
push right

Because:

If a new robot has higher chargeTime, the smaller ones behind it will never be max again.

What the above sentence mean:
suppose maxDq = {10,7,4} and new element coming chargetime[right] = 8. So remove 4 then 3 and maxDq becomes {10,8}.
Why this because once the 10 goes out of window while shrinking then we have to find new max. And if we would have kept
7 and 4 as well then 7 would be current max. But that is not true. In this window 8 should have been the max. So the current
element 8 is telling that in my presence 7 and 4 can never be larger in lifetime. 8 is saying i am the boss here once 10 goes.
Because after that i am the larger. That is why we remove 7 and 4. Beause out window stretches upto right and right consisit
of 8 as well and 8 is saying to 4 and 7 that you can not be greater after 10 goes out of window because i am the larger.
Now we have {10,8}. Now if 10 goes out of window then our next larger will become 8. Now you see in problem window is still
this {7,4,8} But here in this window 8 is the max element which we want while calculating cose and that is how deque is
helping here.

end---------------------------------------------------------------------------------------------------------------------


start---------------------------------------------------------------------------------------------------------------------


Exactly the same logic as LC1438.
When moving left
If the index at the front goes out of the window:
if front == left → pop it

How we know that the left index is at the front of dq. Because left pointer will come sequence wise and before that
right pointer has put the values in the deque in sequence as well. So Those values/indicies are at the front of the deque
will be having higher chances that they are the left index. So if it matches then we remove it from dequq because it is out of window now
and the next element in deque becomes the next larger element of the window.

end---------------------------------------------------------------------------------------------------------------------

Now the next max becomes available.
🧠 Step 4: Understanding the cost formula deeply
This is the part that feels “magical” at first.
Cost =
maxCharge + k * sumRunning
Where:
k = r - l + 1
sumRunning = runningCosts[l] + ... + runningCosts[r]
Think of it as:
One-time startup cost → max charge
Per-robot cost multiplied by group size
As window grows:
maxCharge → stays same or increases slowly
runningCosts → grows fast
multiplied by k → grows even faster
That’s why shrinking window works.
🧠 Step 5: Full sliding window logic (mental simulation)
Let’s walk the thought process, not code:

1️⃣ Start with empty window
2️⃣ Add robot right
3️⃣ Update:
max charge via deque
running cost sum
4️⃣ Compute cost
5️⃣ If cost ≤ budget → great, record window size
6️⃣ If cost > budget →
keep removing from left
update deque and sums
until window becomes valid again
7️⃣ Continue expanding
This guarantees:
every valid window is considered
longest one is found


start-------------------------------------------------------------------------------------------------------------------------
About prefix sum.

See here we added prefix sum of 0 as 0.
1️⃣3️⃣ Why are we taking prefixSum of 0 as 0. Wont it create problem with indices becasue now prefixsum[i] will contain prefix
sum from prefixSum[startPoint] to prefixSum[i-1].

take ex:
idx:        0 1 2 3  4   5  6  7  8
num :       3 4 8 9  1   2  3  4
prefixSum   0 3 7 15 24  25 27 30 34

prefixSum[j] - prefixSum[i] = prefixSum[endPoint] - prefixSum[startPoint]
If k = 22. .
Now at index 3 we complete sum 24 which is >= k. But to calculate sum of subarray we hva to subtract end - start. So this will
also have some start.
3+4+8+9 = 24. But we we subtract 24 - start prefixSum which is 3 we get 21. But that is not true because 3 itself is the part of
subarray. THat is why we need one zero if we want to consider complete subarray in future if any.
Now if we didn’t have prefixSum[0] = 0:
You would be forced to subtract something that belongs to the subarray, which breaks logic.

Why this: long long windwoSum = prefixSum[right + 1] - prefixSum[left];
See we want to include right and left both. But right's pointer prefix sum is in right + 1 due to the addition on 0 as prefix sum[0].
And left's prefix sum is in left + 1 pointer. prefixSum[left]; mhanje ithe left chi prefix sum already left+1 pointer madhe aahe
mhanje yat left and right doghe pn include aahe. And minus prefixSum[left]; mhanje left pointer chi prefix sum include kelya nantr
left pointer chya davya(left) bajula je pn aahe te aapan delete karnar aahot ani tevha aapalyala actual prefix sum bhetel including left and
right and other sum delete houn jail.


end-------------------------------------------------------------------------------------------------------------------------

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Each index is:
added to deque once
removed from deque once

⏱ Time Complexity
O(n)
4️⃣ Space Complexity
Prefix sum array → O(n)
Deque → O(n) in worst case

📦 Space Complexity
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key observation from the problem
For a window [left … right], total cost is:
max(chargeTimes[left..right])+ (window size) * sum(runningCosts[left..right])

So we need to:
maintain maximum charge time in the window
maintain sum of running costs
expand the window greedily
shrink it when budget is exceeded
Strategy
We use Sliding Window + Monotonic Deque.
right expands the window
left shrinks the window if cost exceeds budget
A monotonic decreasing deque stores indices of chargeTimes
→ front always gives max charge time in current window
Prefix sum allows O(1) running cost sum
This ensures we try all valid windows efficiently.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        int left = 0;              // Left pointer of sliding window
        int len = 0;               // Maximum length of valid window
        deque<int> maxDq;          // Monotonic deque to track max chargeTime
        vector<long long> prefixSum(n + 1, 0);  // Prefix sum of runningCosts

        // Build prefix sum to get sum of runningCosts in O(1)
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + runningCosts[i];

        // Right pointer expands the window
        for (int right = 0; right < n; right++)
        {
            // Maintain deque in decreasing order for max chargeTime
            while (!maxDq.empty() && chargeTimes[maxDq.back()] < chargeTimes[right])
                maxDq.pop_back();
            maxDq.push_back(right);

            // Shrink window from left until cost <= budget
            while (left <= right)
            {
                long long windowSum = prefixSum[right + 1] - prefixSum[left]; // sum of runningCosts in [left, right]
                int k = right - left + 1;                                     // number of robots in window
                long long cost = chargeTimes[maxDq.front()] + (long long)k * windowSum;

                if (cost <= budget)
                    break; // window valid, stop shrinking

                // Remove left index from deque if it is the max
                if (maxDq.front() == left)
                    maxDq.pop_front();

                left++; // shrink window
            }

            // Update maximum length of valid window
            len = max(len, right - left + 1);
        }

        return len;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Sliding Window (Variable Size)
🔹 Supporting patterns
Monotonic Deque → maintain max in window
Prefix Sum → O(1) range sum

*/

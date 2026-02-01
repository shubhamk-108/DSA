/*
Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
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


// Before understanding this solution please read below intuition and explanation. My comments added in that.
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        int len = INT_MAX;
        vector<long long> prefixSum(n + 1, 0);
        prefixSum[0] = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int j = 0; j <= n; j++)
        {

            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k)
            {
                len = min(len, j - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[j])
                dq.pop_back();
            dq.push_back(j);
        }
        return len == INT_MAX ? -1 : len;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 6, 1, 4, 2, 3, 1};
    cout << sol.shortestSubarray(v, 10);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Important : I tried solving this question using traditional sliding window expanding window icnreases sun and shrinking decreases sum.
//___________________________________________________________________________________________________________________________________________
/*

But this is only valid if the elements in the window are non negative. But in this problem there are negative numbers.
When we try to shrink the winow we do like sum -= nums[i] but here the nums[i] is already -, and, minus minus becomes plus so
shrinking increase the window sum rather than decreasing it so sliding winow is definitely not the answer here.

Wrong code :

int n = nums.size();
        int ans = INT_MAX;
        int j = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum >= k)
                ans = min(ans, i - j + 1);

            while (sum > k)
            {
                sum -= nums[j];
                j++;
            }
            if (sum == k)
                ans = min(ans, i - j + 1);
        }
        return ans == INT_MAX? -1 : ans;


*/

//___________________________________________________________________________________________________________________________________________
// Intuition Explanation. This is important in order to understand problem. Chatgpt explanation + my explanation
//___________________________________________________________________________________________________________________________________________

/*

LeetCode 862 — Shortest Subarray with Sum ≥ K
(The right way to understand it)
1️⃣ What the problem is REALLY asking
You are given:
an array nums (can contain negative numbers)
a number k
You need:
the shortest contiguous subarray whose sum ≥ k
If none exists → return -1.

2️⃣ Why naive / sliding window / Kadane fail
❌ Sliding window
Sliding window works only when:
expanding window → sum always increases
shrinking window → sum always decreases
Negative numbers break this rule.
So sliding window is invalid here.
❌ Kadane
Kadane finds:
maximum sum
not shortest length
and doesn’t enforce sum ≥ k
So also invalid.

3️⃣ The key transformation: Prefix Sum
Define:
prefix[0] = 0
prefix[i] = nums[0] + nums[1] + ... + nums[i-1]
Then:
sum of subarray [i .. j-1] = prefix[j] - prefix[i]
j is later index and i is earlier index.
We want:
prefix[j] - prefix[i] ≥ k
Rearranged:
prefix[i] ≤ prefix[j] - k
👉 For every j, we want to find a previous i such that:
prefix[i] is small enough
(j - i) is minimal

4️⃣ What problem this becomes
For each j, among all earlier i:
choose a prefix that is small
and as close to j as possible
This is the heart of the problem.

5️⃣ Why we use a DEQUE
We need a data structure that:
keeps candidates in order
allows removing useless candidates
gives us the best candidate quickly
That’s exactly what a deque does.
But we don’t keep all prefix indices — only the useful ones.

6️⃣ The MOST IMPORTANT IDEA: DOMINANCE
Suppose we have two prefix indices:
i1 < i2
prefix[i1] ≥ prefix[i2]
i1 chi index small aahe and i2 chi large. Say i1 index is 3 and i2 index is 5
aadhi aalelya i1 chi prefix sum large aahe ani nantar aalelya i2 chi small. Say i1 prefix sum = 30 and i2 = 10.

Question:
Will i1 ever give a better answer than i2?
Answer: Never.
Why?
For any future j:
prefix[j] - prefix[i2] ≥ prefix[j] - prefix[i1]
j chi prefix sum lets say = 70.

So i2:
gives greater or equal sum
gives shorter length
👉 i1 is dominated and should be removed forever.

Meaning:
i2 = smaller prefix sum if comes at later index
i1 = larger prefix sum if comes at earlier index.
say j prefix sum = 70.. Now prefix[j] - prefix[i] >= k , check this
i2 = 70 - 10 = 60
i1 = 70 - 30 = 40
Notice that, the smaller prefix sum creates larger difference between j and i means larger possibility that we canget our sum as >= k.
And the later the index comes means we can have shorted length subarray.
Now, the larger prefix sum creates smaller differnce between j and i. Means smaller possibility that we canget our sum as >= k.
And also the earlier the index , the larget the length of subarray.
So, mi lagech vichar krto ki, prefixSum[j] - prefixSum[i]... ya madhe ji i chi sum aahe ti jr smaller  asel tr balle balle hoil
karn apalyana j-i prefix sum cha differece jo k aahe to larger bhetel which is greaater possibility of >=k.
Ani jya i chi larger prefix sum hoti to tr smaller differece deil which may not be >=k. Ani in case hi value >= k asel jri
tri hi index aadhi aaleli aahe i2 peksha mahnje i1 cha subarray ha larger length cha subarray deil which we dont want.
That is why jevha jevha apalyala ashi current prefix sum bhetate ji earlier already  deque madhe aslelya prefix sum peksha smaller
asel tr apan deque madhe aslelya larger prefix sum kadhun gheto pop krto. Ani jevha current prefix sum peksha smaller prefix sum
deque madhe bhetate , tyachya pudhe hi current prefix sum jaun push krto. Ani asach monotoniq increasing deque tayar hoto.

7️⃣ Why the deque must be MONOTONIC INCREASING
Because we must never keep dominated prefix sums.
So in the deque:
prefix values must strictly increase
That guarantees:
every element is potentially useful
no wasted comparisons.
Wasted comparison kon hote? Je aapan varti dq madhun pop kele na tech. Je monotonic increasing order la break kar hote.
shortest length is preserved

8️⃣ Why we pop from the BACK when a smaller prefix arrives
Example:
prefix = [0, 2, 1]
When 1 arrives:
1 < 2
index of 1 is later
prefix value is smaller
So:
1 dominates 2
We pop 2.
This has nothing to do with:
negative numbers directly
skipping elements
starting after negatives
It’s purely:
dominance + optimality

9️⃣ What the “dip” means (very important)
People say:
“prefix is increasing… then there is a dip”
That dip means:
a better starting point appeared
smaller prefix at a later index
dominates all larger prefixes before it
So we clean the deque.

🔴 Role of negative numbers (finally clarified)
Negative numbers:
are NOT handled directly
are NOT skipped
They matter because they create dips in prefix sum.
Without negative numbers:
prefix is always increasing
deque never pops from back
sliding window would work
So:
Negative numbers are why this problem exists.

1️⃣0️⃣ Why we pop from the FRONT
If:
prefix[j] - prefix[dq.front()] ≥ k
We found a valid subarray.
Ekda valid subarray bhetala ki front chi index kadhun takayachi. Karan ty apoint pasun pudhe bharpur sare subarray hotil
pn tyanchi lenght hi vadhat ch rahil mhanje larger larger yet ch rahil so better to remove that index.
Now:
any future j' > j will give a longer subarray with same start
so this index will never produce a better answer again
Hence:
pop front and continue

1️⃣1️⃣ Full algorithm (mental steps)
For each j from 0 to n:
While deque not empty and
prefix[j] - prefix[dq.front()] ≥ k
update answer
pop front
While deque not empty and
prefix[j] ≤ prefix[dq.back()]
pop back (dominance)
Push j into deque

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

What adding sum 0 to prefixSum[0] changes.
Now prefixSum[i] will consist of prefixSum upto [i-1].
So in while loop we need one extra iteration. We go fron i<=n.
And we dont do j - i  + 1 this time to calculate length. We are already one iteration ahead so that one will be added automatically.
So length will be j - i only.


*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ Time Complexity
O(n)
Why?
Each index is pushed into deque once
Each index is popped at most once (front or back)
Total operations ≤ 2n.

🧠 Space Complexity
O(n)
Prefix sum array: n + 1
Deque: up to n + 1
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Problem reminder (core difficulty)
We need the shortest subarray whose sum ≥ k
Array can contain negative numbers
Sliding window fails because negatives break monotonicity

Key idea
Use prefix sums + monotonic deque.
Step-by-step approach
Step 1: Prefix Sum with boundary logic
We build:
prefixSum[i] = sum of nums[0 .. i-1]
So:
prefixSum[0] = 0
Size = n + 1
This allows:
sum of subarray [i .. j-1] = prefixSum[j] - prefixSum[i]
length = j - i

No special cases. Clean math.
Step 2: Use a deque to store candidate start indices
The deque stores indices of prefixSum, not array indices.
We maintain two invariants:
Deque is increasing by prefixSum value
Front of deque gives smallest prefixSum so far
Step 3: For each j
At prefix index j:

A) Try to shrink from the left
If:
prefixSum[j] - prefixSum[dq.front()] >= k
→ we found a valid subarray
→ update answer
→ pop front (because it won’t give a shorter subarray later)

B) Maintain monotonicity
If:
prefixSum[dq.back()] >= prefixSum[j]
→ pop back
Because the current prefix is better (smaller) for future subarrays.
C) Push current index j
It becomes a future candidate start.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Deque will store indices of prefixSum[]
        deque<int> dq;

        // Answer initialized to infinity
        int len = INT_MAX;

        // Prefix sum array of size n+1
        // prefixSum[i] = sum of nums[0..i-1]
        vector<long long> prefixSum(n + 1, 0);

        // Explicit but redundant (already 0)
        prefixSum[0] = 0;

        // Build prefix sum
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Iterate over all prefix indices
        for (int j = 0; j <= n; j++)
        {
            // Try to shrink window from the left
            // If current prefix minus smallest prefix >= k
            while (!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k)
            {
                len = min(len, j - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums in deque
            while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[j])
                dq.pop_back();

            // Add current prefix index
            dq.push_back(j);
        }

        return len == INT_MAX ? -1 : len;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

🟢 Primary Pattern
Monotonic Deque + Prefix Sum
This is a classic advanced pattern used in:


*/

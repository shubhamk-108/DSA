/*
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.



Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();

        unordered_map<int, int> freq;
        for (int x : arr)
            freq[x]++;

        vector<int> bucket(n + 1, 0);
        for (auto &p : freq)
            bucket[p.second]++;

        int removed = 0;
        int res = 0;

        for (int f = n; f >= 1; f--)
        {
            while (bucket[f] > 0)
            {
                removed += f;
                res++;
                bucket[f]--;
                if (removed >= n / 2)
                    return res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    cout << sol.minSetSize(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Explanation and Key observation
//___________________________________________________________________________________________________________________________________________
/*
Key observation

The maximum frequency of any number is n.
So instead of sorting, we can:
Count how many numbers appear 1 time, 2 times, … n times
Iterate from highest frequency to lowest

Idea
freq count → bucket[frequency]++
No sorting required.



We already know the greedy rule:

To remove the fewest distinct numbers, always remove the number that appears most frequently.

Instead of sorting frequencies (O(n log n)), this solution uses bucket sort to do it in O(n).

Step-by-step explanation
1️⃣ Get the size of the array
int n = arr.size();


We’ll need n:

To know what “half” means

To size our bucket array

2️⃣ Count frequency of each number
unordered_map<int,int> freq;
for(int x : arr)
    freq[x]++;


After this:

arr = [1,1,1,2,2,3]
freq = {
  1 -> 3
  2 -> 2
  3 -> 1
}


So far, same as your earlier solution.

3️⃣ Build the bucket array
vector<int> bucket(n + 1, 0);


What is bucket[i]?

Number of distinct values that appear exactly i times

Example:

freqs = [3, 2, 1]
bucket[1] = 1
bucket[2] = 1
bucket[3] = 1

4️⃣ Fill the buckets
for(auto &p : freq)
    bucket[p.second]++;


Using the earlier example:

bucket[1] = 1   // one number appears once
bucket[2] = 1   // one number appears twice
bucket[3] = 1   // one number appears three times


This replaces sorting.

5️⃣ Initialize greedy counters
int removed = 0;
int res = 0;


removed → total elements removed so far

res → how many distinct numbers we removed

6️⃣ Greedily remove from highest frequency to lowest
for(int f = n; f >= 1; f--) {


Why start from n?

Maximum possible frequency is n

We want largest frequency first

7️⃣ Remove all numbers with frequency f
while(bucket[f] > 0) {


If bucket[5] = 2, it means:

Two numbers each appear 5 times

We remove them one by one.

8️⃣ Update removed elements and count
removed += f;   // remove f elements
res++;          // removed one distinct number
bucket[f]--;


Each removal:

Deletes f elements at once

Increases number of removed distinct values by 1

9️⃣ Stop when at least half is removed
if(removed >= n/2)
    return res;


Problem says:

remove at least half, not exactly half

So >= is critical.

10️⃣ Final return (safety)
return res;


*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Counting frequencies: O(n)
Filling bucket: O(n)
Iterating bucket: O(n)
👉 Overall: O(n)

🧠 Space Complexity
Hash map + bucket array: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want to remove the minimum number of distinct integers.
To do that, we must remove numbers that eliminate the maximum number of elements at once.
So:
Count how often each number appears.
Instead of sorting frequencies, use bucket sort:
bucket[f] = how many numbers appear exactly f times.
Start removing numbers with the highest frequency first.
Keep removing until at least half of the array elements are gone.
This avoids sorting and gives an O(n) solution.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Count frequency of each number
        unordered_map<int,int> freq;
        for(int x : arr)
            freq[x]++;

        // Step 2: Bucket array
        // bucket[i] = number of distinct values appearing exactly i times
        vector<int> bucket(n + 1, 0);
        for(auto &p : freq)
            bucket[p.second]++;

        int removed = 0; // total elements removed
        int res = 0;     // number of distinct elements removed

        // Step 3: Greedy removal from highest frequency to lowest
        for(int f = n; f >= 1; f--) {
            // Remove all numbers that appear f times
            while(bucket[f] > 0) {
                removed += f;  // removing f elements
                res++;         // removing one distinct number
                bucket[f]--;

                // Stop once at least half the array is removed
                if(removed >= n / 2)
                    return res;
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

Greedy + Bucket Sort (Frequency Counting)
Greedy: Always remove the element with the highest frequency.
Bucket Sort: Frequencies are bounded (1 → n), so sorting is replaced by buckets.


*/

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.



Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
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
    vector<int> getSmallerEleLeft(vector<int> arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
                res[i] = -1;
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                    st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> getSmallerEleRight(vector<int> arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
                res[i] = n;
            else
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();

                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nextSmallerLeft = getSmallerEleLeft(arr,n);
        vector<int> nextSmallerRight = getSmallerEleRight(arr,n);

        long long sum = 0;
        int const MOD = 1e9+7;

        for (int i = 0; i < n; i++)
        {
            long long left = i - nextSmallerLeft[i];
            long long right = nextSmallerRight[i] - i;
            long long totalSubarraysIncludesMin = left * right;
            long long minSum = arr[i] * totalSubarraysIncludesMin;
            sum = (sum +  minSum) % MOD;
        }
        return sum;
        
    }
};

int main()
{
    Solution sol;
    // vector<int> v = {7, 9, 11, 3, 8, 7, 5, 1, 4, 6};
    vector<int> v = {71, 55, 82, 55};
    cout << sol.sumSubarrayMins(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Each element is pushed and popped once from stack
Left pass: O(n)
Right pass: O(n)
Final loop: O(n)

✅ Overall: O(n)
Space Complexity
nextSmallerLeft → O(n)
nextSmallerRight → O(n)
Stack → O(n)
✅ Overall: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Instead of enumerating all subarrays, we count how much each element contributes as the minimum.
For each element arr[i]:
Find the nearest smaller element on the left
Find the nearest smaller or equal element on the right
Count how many subarrays include arr[i] as their minimum
Add its contribution to the answer
Why this works
If arr[i] is the minimum:
We can choose any start in its valid left range
We can choose any end in its valid right range

So:
#subarrays = leftChoices × rightChoices
contribution = arr[i] × leftChoices × rightChoices

*/

//___________________________________________________________________________________________________________________________________________
// Egde case
//___________________________________________________________________________________________________________________________________________
/*

1. What is the “equal-to edge case”?
It happens when the array contains duplicate values.
Example:

[2, 2, 2]

Every subarray’s minimum is 2.
The danger is:
The same subarray might be counted more than once, or not counted at all.
2. Why duplicates are dangerous in LC907

LC907 counts:

sum of (minimum of every subarray)

But we compute this by:
sum of (each element's contribution)

So we must ensure:
Every subarray is assigned to exactly one element as its minimum.
Duplicates break this unless handled carefully.

3. The ownership problem (core idea)
When two equal elements exist:
... 2 .... 2 ...

And a subarray contains both:
[2, 2]


👉 Which 2 should claim this subarray?

If both claim it → double count ❌
If none claim it → missed count ❌

So we enforce an ownership rule.

4. The rule used in your solution
You chose:
Left side → strictly smaller (<)
Right side → smaller or equal (<=)
This means:
Among equal values, the leftmost element owns the subarrays.

5. Concrete example (VERY important)
Example:
arr = [2, 2]

All subarrays:

[2] (i=0)
[2] (i=1)
[2,2]

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    // Finds index of previous strictly smaller element for each index
    vector<int> getSmallerEleLeft(vector<int> arr, int n)
    {
        vector<int> res(n);
        stack<int> st; // stores indices, monotonic increasing stack

        for (int i = 0; i < n; i++)
        {
            // Remove elements that are greater than current
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            // If stack empty → no smaller element on left
            res[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return res;
    }

    // Finds index of next smaller OR EQUAL element for each index
    vector<int> getSmallerEleRight(vector<int> arr, int n)
    {
        vector<int> res(n);
        stack<int> st; // monotonic increasing stack

        for (int i = n - 1; i >= 0; i--)
        {
            // Pop elements >= current to handle duplicates
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack empty → no smaller element on right
            res[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        // Boundaries where arr[i] remains minimum
        vector<int> nextSmallerLeft  = getSmallerEleLeft(arr, n);
        vector<int> nextSmallerRight = getSmallerEleRight(arr, n);

        long long sum = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            // Number of choices on left and right
            long long left  = i - nextSmallerLeft[i];
            long long right = nextSmallerRight[i] - i;

            // Total subarrays where arr[i] is minimum
            long long totalSubarraysIncludesMin = left * right;

            // Contribution of arr[i]
            long long minSum = arr[i] * totalSubarraysIncludesMin;

            sum = (sum + minSum) % MOD;
        }

        return sum;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

1️⃣ Monotonic Stack Pattern
Used to find:
Previous smaller element
Next smaller element
2️⃣ Contribution Technique
Instead of iterating over subarrays:
Count how much each element contributes to the final answer
Full pattern name you can say:
“Monotonic stack + contribution technique”


*/

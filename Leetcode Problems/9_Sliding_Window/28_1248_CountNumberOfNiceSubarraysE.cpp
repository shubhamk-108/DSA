/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        int res = 0;

        unordered_map<int, int> um_prefixSum;
        int key = 0;
        int value = 1;
        um_prefixSum[key] = value; // this is as key : value = 0 : 1. That is 0 has appeared one time.when the prefix sum will
        // be exact k , for ex k is 2 and prefix sum is 2 then required will be 2-2 = 0. But we will not see 0 in the map
        // because to insert 0 that is never the case. So we have to insert it explicitely.

        int currentPrefixSum = 0;

        for (int i = 0; i < n; i++)
        {
            currentPrefixSum += nums[i] % 2;

            int required = currentPrefixSum - k;

            if (um_prefixSum.find(required) != um_prefixSum.end())
            {
                res += um_prefixSum[required];
            }

            um_prefixSum[currentPrefixSum]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3,2,5,8,5,7,9,4,4,3};
    cout << sol.numberOfSubarrays(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// why convert to parity bit nums[i] = nums[i] % 2 , array of 0 and 1
//___________________________________________________________________________________________________________________________________________

/*

If we convert this nums arrays to 0 and 1, 0 for even and odd for 1 then this question is count the subarray of ones having sum
equal to k. And then this question is exactly same as letcode 560. Count subarray sum equal to k.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
Single pass through the array.
Hash map operations (insert/find) are O(1) average.
Total: O(n)

📦 Space Complexity: O(n)
Hash map may store up to n different prefix sum values.
Prefix sum ues constant extra space.
Overall: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Convert each number to 0 or 1 using nums[i] % 2.
Maintain a running prefix sum:
prefix[i] = number of odd numbers from 0 to i
For each position, check how many previous prefix sums satisfy:

prefix[i] - prefix[j] = k
→ prefix[j] = prefix[i] - k

Use a hashmap to store how many times each prefix sum has appeared.
For each index:
if (prefix - k) exists in the map → add those counts to answer.
Update the hashmap with the current prefix.
This counts all subarrays ending at i with exactly k odd numbers.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;

        // HashMap to store count of prefix sums
        // prefixSumCount[x] = how many times prefix sum x has appeared
        unordered_map<int, int> prefixSumCount;

        // Important initialization:
        // prefix sum 0 has appeared once before processing any element.
        // This allows counting subarrays starting from index 0.
        prefixSumCount[0] = 1;

        int prefix = 0;  // running prefix sum of number of odd elements

        for (int i = 0; i < n; i++)
        {
            // Convert current number to parity:
            // even → 0, odd → 1
            prefix += nums[i] % 2;

            //SUPPOSE PREFIX SUM IS  7 at a point and k is 3  then to get the answer as k = 3 we do not need extra 4 from 7
            //that if we do 7 - 4 then we have 3. So we check have we seen this 4 earlier. If yes then see how many times that 4 has appeared.
            // If the 4 has appeared 5 times then we will have 5 more subarrays. You can dry run in notebook and see it. If 4 has appeared 
            // 2 times then we have 2 more subarrays. So we add these to our count or res as res += 2 or 5  or whatever.
            // I also notice that these subarrays are ending at j or right ptr in sliding window that is whatever point we are standing on currently.
            // This is the target prefix sum we want to find.
            // If prefix[j] == prefix - k,
            // then the subarray (j+1 to i) has exactly k odd numbers.
            int required = prefix - k;

            // If such a prefix exists, add how many times it has appeared.
            if (prefixSumCount.find(required) != prefixSumCount.end())
            {
                res += prefixSumCount[required];
            }

            // Store/update how many times current prefix has appeared
            prefixSumCount[prefix]++;
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Prefix Sum + HashMap For Subarray Sum = K”
This is the classic pattern used in:
Subarray Sum Equals K (LC560)
Binary subarray sum
Count subarrays with given cumulative property
Pattern characteristics:
Convert the problem into cumulative counts.
Store prefix counts in hash map.
Check (prefix - target) each time.


*/

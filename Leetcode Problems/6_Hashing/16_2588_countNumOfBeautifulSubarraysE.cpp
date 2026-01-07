/*
You are given a 0-indexed integer array nums. In one operation, you can:

Choose two different indices i and j such that 0 <= i, j < nums.length.
Choose a non-negative integer k such that the kth bit (0-indexed) in the binary representation of nums[i] and nums[j] is 1.
Subtract 2k from nums[i] and nums[j].
A subarray is beautiful if it is possible to make all of its elements equal to 0 after applying the above operation any number of times (including zero).

Return the number of beautiful subarrays in the array nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Note: Subarrays where all elements are initially 0 are considered beautiful, as no operation is needed.



Example 1:

Input: nums = [4,3,1,2,4]
Output: 2
Explanation: There are 2 beautiful subarrays in nums: [4,3,1,2,4] and [4,3,1,2,4].
- We can make all elements in the subarray [3,1,2] equal to 0 in the following way:
  - Choose [3, 1, 2] and k = 1. Subtract 21 from both numbers. The subarray becomes [1, 1, 0].
  - Choose [1, 1, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 0, 0].
- We can make all elements in the subarray [4,3,1,2,4] equal to 0 in the following way:
  - Choose [4, 3, 1, 2, 4] and k = 2. Subtract 22 from both numbers. The subarray becomes [0, 3, 1, 2, 0].
  - Choose [0, 3, 1, 2, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 2, 0, 2, 0].
  - Choose [0, 2, 0, 2, 0] and k = 1. Subtract 21 from both numbers. The subarray becomes [0, 0, 0, 0, 0].
Example 2:

Input: nums = [1,10,4]
Output: 0
Explanation: There are no beautiful subarrays in nums.

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
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> um;
        int prefixXor = 0;
        um[0]++;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            prefixXor ^= nums[i];
            if (um.find(prefixXor) != um.end())
            {
                res += um[prefixXor];
            }
            um[prefixXor]++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {4, 3, 1, 2, 4};
    cout << sol.beautifulSubarrays(v);
    return 0;
}

// This problem was simply  Count subarrays whose XOR is 0.
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n)
One loop
Hashmap operations average O(1)
Space: O(n)
Hashmap stores unique prefix XOR values (up to n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

A subarray is beautiful if after repeatedly removing bits (using XOR) all elements become 0.
This is equivalent to:
✔ The XOR of the entire subarray must be 0
Because repeatedly removing the same bit from all numbers cancels out only when all numbers have that bit an even number of times → XOR = 0.
✔ Using Prefix XOR:
Let
prefixXOR[i] = nums[0] XOR nums[1] XOR ... XOR nums[i]
A subarray L…R has XOR = 0 when:
prefixXOR[R] == prefixXOR[L-1]

So each time we see a repeated prefix XOR, it forms beautiful subarrays.
✔ Steps:
Maintain a running XOR.
Use a hashmap um to count how many times each prefixXOR occurred.
Each time we see prefixXor again:
Add its frequency to result.
Increase the frequency in the hashmap.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> um;   // hashmap to store frequency of prefix XORs
        int prefixXor = 0;
        um[0]++;                      // prefix XOR = 0 seen once (important base case)

        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            prefixXor ^= nums[i];     // update running XOR

            if (um.find(prefixXor) != um.end())
            {
                res += um[prefixXor]; // add number of previous same prefix XORs
            }

            um[prefixXor]++;          // increase frequency of this prefix XOR
        }

        return res;
    }
};

*/
//___________________________________________________________________________________________________________________________________________
// Dry run cum explanation
//___________________________________________________________________________________________________________________________________________

/*
vector<int> v = {4, 3, 1, 2, 4};
prefixXor will be:
for very first number do xor with 0 as we do in prefixSum and then onwareds to xor with next number.
4 xor 4 = 4
4 ^ 3 = 7
7 ^ 1 6
6 ^ 2 = 4
4 ^ 4 = 0
Theerefore prefixXor will be :
{4,7,6,4,0}.
Now add one more zero manually because when we get 0 while doing prefix sum then our answer will be valid but it wont give us valid 
because we have to xor in pair and this 0 will search for another 0 in the prefixXor map so that 0 ^ 0 become 0 which is a valid subarray and ans.

Now final prefixXor become:
{0,4,7,6,4,0}.

So now how to count how many beautiful subarray we have.
Notice that two similar numbers have xor as 0. So we just have to count that, if while traversing we are at 4 then check in the map that
have we already encountered 4, if yes then 4 ^ 4 will be 0 which is one valid subarary. count such instances.
0 ^0 = 0
4 ^ 4 = 0.
So here we have two beautiful subarrays.


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Prefix XOR + HashMap Pattern
This is the XOR-equivalent of the classic "prefix sum + hashmap" used in:
Subarray Sum Equals K
Count Zero XOR Subarrays
XOR-based frequency problems
It belongs to
🔹 “Prefix XOR + Hash Frequency Counting”
🔹 “XOR Trick”
🔹 “Hashing”
🔹 “Subarray XOR” pattern

*/

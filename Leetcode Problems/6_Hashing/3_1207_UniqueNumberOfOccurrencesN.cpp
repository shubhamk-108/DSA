/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

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
    bool uniqueOccurrences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n);
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (nums[i] == nums[j])
                    count++;
            }
            v[i] = count;
            count = 1;
        }

        for (int i = 0; i < v.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (v[i] == v[j] && nums[i] != nums[j])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 2, 1, 1, 3};
    cout << sol.uniqueOccurrences(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Counting frequency: O(n²)
Checking uniqueness: O(n²)
Total time:
#️⃣ O(n²)
Space Complexity
Frequency array v of size n → O(n)
Total space:
#️⃣ O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Step 1 — Compute frequency for each element
For every index i, scan the entire array and count how many elements are equal to nums[i].
Store this count in a vector<int> v, where v[i] = frequency of nums[i].
This takes O(n²) time.
Step 2 — Check if frequencies are unique
Now compare every frequency v[i] with every other frequency v[j].
If two different numbers have the same frequency, return false.
If no duplicates found, return true.
This again takes O(n²) time.
This is the simplest brute-force solution without using hash maps or sets.

*/

//___________________________________________________________________________________________________________________________________________
// why this condition && nums[i] != nums[j]
//___________________________________________________________________________________________________________________________________________

/*
This is because when counting frequency of every element same element got pushed in vector multiple times. So for ex 3 is appeared 5 times 
then there will be 5 entries of 3 in frequency vector because we used two loops. So at the time of checking duplicate frequency we 
have to make sure that both elements are different and if both elements are different and there frequency is same then return false.



*/
//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool uniqueOccurrences(vector<int> &nums)
    {
        int n = nums.size();

        // v[i] will store the frequency of nums[i]
        vector<int> v(n);

        // Will store frequency count for each nums[i]
        int count = 1;

        // ---- FIRST PART: compute frequency of each element ----
        for (int i = 0; i < n; i++)
        {
            // Compare nums[i] with every other element
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;          // skip comparing element with itself

                if (nums[i] == nums[j])
                    count++;           // increment if match found
            }

            v[i] = count;              // store the frequency of nums[i]
            count = 1;                 // reset count for next element
        }

        // ---- SECOND PART: verify if frequencies are unique ----
        for (int i = 0; i < v.size(); i++)
        {
            // Compare v[i] with every other v[j]
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;          // skip comparing with itself

                // If frequencies match BUT the numbers are different,
                // then the occurrences are not unique
                if (v[i] == v[j] && nums[i] != nums[j])
                    return false;
            }
        }

        // All frequencies were unique
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Pattern → Brute Force / Frequency Counting (Naive)
No hashing, no optimization — simply comparing all pairs.



*/

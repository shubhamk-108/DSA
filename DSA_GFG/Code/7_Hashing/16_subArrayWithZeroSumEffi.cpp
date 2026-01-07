// Input Array: [4, 2, -3, 1, 6]
// Reasoning: The subarray from index 1 to 3 is {2, -3, 1}. The sum is 2 + (-3) + 1 = 0. Since we found one such subarray, the answer is true.
// Output: true

#include <iostream>
#include <unordered_set>
#include<vector>
using namespace std;

bool subarrayWithZeroSum(int arr[], int n)
{
    unordered_set<int> us;
    vector<int> prefix_sum(n);
   

    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (prefix_sum[i] == 0 || arr[i] == 0)
        {
            return true;
        }
        
        if (us.find(prefix_sum[i]) != us.end())
            return true;
        else
            us.insert(prefix_sum[i]);
    }
    return false;
}

int main()
{
    // int arr1[] = {4, 3, -1, -2, 6};
    int arr1[] = {2,-2,4};

    int n = sizeof(arr1) / sizeof(arr1[0]);


    cout << subarrayWithZeroSum(arr1, n);

    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(n)

// logic_1


/*

Suppose the array is {4, 3, -1, -2, 3}. Its prefix sums will be {4, 7, 6, 4, 7}.

The key idea is this:

If a prefix sum value occurs more than once, it means there exists a subarray with sum = 0.

Why?
Take the subarray {3, -1, -2}. Its sum is 0.
Looking at the prefix sums: 4 → 7 → 6 → 4. Notice that the value 4 appears again.

The first 4 came from the sum up to index 0.

The second 4 came after including {3, -1, -2}.
Since the prefix sum returned to the same value, it means the elements in between contributed a net sum of 0.

Another way to see it: in {4, 7, 6, 4, 7}, when the second 4 appears, it’s as if we “reset” to the same total as before. That reset is 
only possible if the subarray in between adds up to 0.

Consider another example: {2, 0, 7}. The prefix sums are {2, 2, 9}.
Here, the prefix sum 2 repeats. This happens because the middle element 0 contributes nothing, meaning there is a subarray (just {0}) 
with sum 0.

There’s also another case:
If the prefix sum itself becomes 0 at any point, then a subarray with sum = 0 exists from the start up to that index.

For example: {2, -2, 5} → prefix sums {2, 0, 5}.
Here, we don’t see a repeated value, but the prefix sum at index 1 is 0.
That means the subarray {2, -2} sums to 0.

✅ In summary:

If a prefix sum value repeats, a zero-sum subarray exists.

If a prefix sum itself is 0, a zero-sum subarray exists.

*/




// logic 2: 




/*



// This function correctly checks if a subarray with a sum of 0 exists.
// It uses a two-pass approach: first building a prefix sum array,
// and then checking for the necessary conditions.
bool subarrayWithZeroSum(int arr[], int n) // 'sum' parameter is not needed
{
    // Handle the edge case of an empty array.
    if (n == 0)
    {
        return false;
    }

    unordered_set<int> us;
    // Correctly initialize a vector of size n to store prefix sums.
    vector<int> prefix_sum(n);

    // --- Pass 1: Build the prefix sum vector ---
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    // --- Pass 2: Check for zero-sum conditions ---
    for (int i = 0; i < n; i++)
    {
        // Condition 1: Check if any prefix sum is 0.
        // This covers all subarrays that start from index 0 and sum to 0.
        // Example: [3, -3, 5] -> prefix_sum[1] is 0.
        if (prefix_sum[i] == 0)
        {
            return true;
        }

        // Condition 2: Check if the current prefix sum has been seen before.
        // If us.find() does NOT return us.end(), it means we have a duplicate.
        // A duplicate prefix sum proves a subarray between the two occurrences sums to 0.
        if (us.find(prefix_sum[i]) != us.end())
        {
            return true;
        }
        
        // If no conditions are met, insert the current prefix sum into the set
        // to check against in future iterations.
        us.insert(prefix_sum[i]);
    }

    // If both loops complete without returning, no zero-sum subarray exists.
    return false;
}


*/
// Longest Common Span Of Subarray With Equal Sum In 2 Binary Arrays of same size
// Given 2 binary arrays. We have to find same sum from both the arrays. Indices of both the arrays should be same to find longest sum.
// consider size of both the subarray as same
// {0,1,0,0,0,0}
// {1,0,1,0,0,1}
// Op : 4
// explnation : in both the array index 1 to index 4 gives sum 1. So op is 4.
// index 0 to index 1 also give sum 1 but we need longest length of subarray

#include <iostream>
#include <algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(int arr1[], int arr2[], int n)
{
    unordered_map<int, int> um;

    int temp[n];
    for(int i = 0; i<n; i++)
        temp[i] = arr1[i] - arr2[i] ; 
    

    

    int so_far_prefix_sum = 0;

    int longest_length = 0;

    for (int i = 0; i < n; i++)
    {
        so_far_prefix_sum += temp[i];

        if (so_far_prefix_sum == 0)
            longest_length = max(longest_length, i + 1);

        if (um.find(so_far_prefix_sum) != um.end())
        {
            int current_length = i - um[so_far_prefix_sum];
            longest_length = max(longest_length, current_length);
        }
        else
        {
            um[so_far_prefix_sum] = i;
        }
    }

    return (longest_length);
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(arr1, arr2, n);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// logic 1
/*

we know that the we are finiding same sum from both the arrays having same indices of both the array.
means sum_of_arr1 from index i to j == sum_of_arr2 from index i to j
Now shift LHS RHS
sum_of_arr1 from index i to j - sum_of_arr2 from index i to j = 0 
means if we substract both the sum there should be 0 as answer.
means sum_of_arr1 from index i to j - sum_of_arr2 from index i to j == 0.
Now for the time being do not consider binary array, consider normal array.
a = {_, _, _, 5,3,1,2, _, _, _} , sum = 11
b = {_, _, _, 2,5,3,1, _, _, _}, sum = 11
This is our answer because it is giving us same sum
So from above formula sum_of_arr1 from index i to j - sum_of_arr2 from index i to j == 0. we did subtraction
{_, _, _, 3,-2,-2,1, _, _, _} Now if we add 3,-2,-2,1 we get 0.
So what do we understand from above observation.
We understand that,
create a temp array and store the difference of a and b array in that.
Now we have to find that where the sum is getting zero. Because whereever we get the sum as 0, that will be our answer.
So after making difference array we have to find where sum is zero. THat means this has reduced to subarray with sum zero problem,
which we have already solved.
We are not replacing zeros with -1 because that is no more a requirement because after difference we just have to find sum 0.



*/



// logic 2


/*



 * @brief Finds the length of the longest common span with an equal sum in two binary arrays.
 * 
 * @param arr1 The first binary array.
 * @param arr2 The second binary array.
 * @param n The size of both arrays.
 * @return int The length of the longest common span with an equal sum.
 * 
 * This function uses an efficient O(n) approach by transforming the problem.
 * 
 * The Core Idea:
 * 1. The condition `sum(arr1[i...j]) == sum(arr2[i...j])` is algebraically
 *    equivalent to `sum(arr1[i...j]) - sum(arr2[i...j]) == 0`.
 * 2. This can be rewritten as `sum(arr1[k] - arr2[k])` for k from i to j equals 0.
 * 3. We create a temporary array `temp` where `temp[k] = arr1[k] - arr2[k]`.
 * 4. The problem now becomes: "Find the length of the longest subarray in `temp`
 *    that has a sum of 0."
 * 5. This transformed problem is then solved using a hash map to store prefix sums.
 
int LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(int arr1[], int arr2[], int n)
{
    // Use an unordered_map to store the first index where a prefix sum is encountered.
    // Key: prefix_sum, Value: index
    unordered_map<int, int> um;

    // Step 1: Create the temporary difference array.
    // This is the crucial transformation that simplifies the problem.
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }
    
    // Initialize a variable to store the cumulative sum of the temp array.
    int so_far_prefix_sum = 0;

    // Initialize a variable to store the maximum length of the span found so far.
    int longest_length = 0;

    // Step 2: Iterate through the temp array, applying the "longest subarray with sum 0" pattern.
    for (int i = 0; i < n; i++)
    {
        // Add the current element of the temp array to the prefix sum.
        so_far_prefix_sum += temp[i];

        // Case 1: The prefix sum is 0.
        // This means the subarray from index 0 to the current index 'i' has a sum of 0.
        // This corresponds to a valid span of length (i + 1).
        if (so_far_prefix_sum == 0)
        {
            longest_length = max(longest_length, i + 1);
        }

        // Case 2: The prefix sum has been seen before.
        // If we find a prefix sum that is already in our map, it means the elements
        // *between* the previous occurrence and this one sum to 0.
        if (um.find(so_far_prefix_sum) != um.end())
        {
            // Calculate the length of this newly found span.
            int current_length = i - um[so_far_prefix_sum];
            // Update the longest_length if this span is the longest we've seen.
            longest_length = max(longest_length, current_length);
        }
        else // Case 3: The prefix sum is seen for the first time.
        {
            // Store this prefix sum and its index in the map. We only do this once
            // to ensure we always get the *earliest* index for a given sum,
            // which guarantees the *longest* possible span later on.
            um[so_far_prefix_sum] = i;
        }
    }

    // Return the final result.
    return longest_length;
}


*/
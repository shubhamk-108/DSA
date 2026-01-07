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

using namespace std;

int LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(int arr1[], int arr2[], int n)
{
    int longest_span = 0;

    for (int i = 0; i < n; i++)
    {
        int current_span = 0;

        int arr1_sum = 0;
        int arr2_sum = 0;

        for (int j = i; j < n; j++)
        {
            arr1_sum += arr1[j];
            arr2_sum += arr2[j];

            if (arr1_sum  == arr2_sum)
                longest_span = max(longest_span, j - i + 1 );
        }
    }

    return longest_span;
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout<<LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(arr1, arr2, n);

    return 0;
}


// Time Complexity: O(n²)
// Space Complexity: O(1)

// logic

/*


#include <iostream>
#include <algorithm> // Required for std::max

using namespace std;

/*
 * brief Calculates the length of the longest common span with the same sum in two binary arrays.
 * 
 * @param arr1 The first binary array.
 * @param arr2 The second binary array.
 * @param n The size of both arrays.
 * @return int The length of the longest common span.
 * 
 * This function uses a brute-force approach, which has a time complexity of O(n^2).
 * It works by checking every possible subarray in both arrays.
 * 
 * The logic is as follows:
 * 1. The outer loop selects a starting index 'i' for the subarrays.
 * 2. The inner loop selects an ending index 'j' for the subarrays, starting from 'i'.
 * 3. For each subarray defined by the span [i, j], it calculates the sum of elements
 *    in arr1 and arr2.
 * 4. If the sums are equal, it means we have found a common span with an equal sum.
 * 5. The length of this span (j - i + 1) is then compared with the longest span
 *    found so far, and the maximum value is kept.
 
int LongestCommonSpanOfSubarrayWithEqualSumIn2BinaryArrays(int arr1[], int arr2[], int n)
{
    // Initialize the variable to store the maximum length found so far.
    // If no common span is found, this will remain 0.
    int longest_span = 0;

    // Outer loop: Iterate through all possible starting points of a subarray.
    // 'i' will be the starting index of the span.
    for (int i = 0; i < n; i++)
    {
        // For each new starting point 'i', reset the sums for the subarrays.
        int arr1_sum = 0;
        int arr2_sum = 0;

        // Inner loop: Iterate through all possible ending points for the subarray that starts at 'i'.
        // 'j' will be the ending index of the span.
        // By starting 'j' from 'i', we ensure we check subarrays of all lengths,
        // including single-element subarrays (when j == i).
        for (int j = i; j < n; j++)
        {
            // Expand the current subarray by adding the element at index 'j' to the sums.
            arr1_sum += arr1[j];
            arr2_sum += arr2[j];

            // Check if the sum of elements from arr1[i...j] is equal to the sum of elements from arr2[i...j].
            if (arr1_sum == arr2_sum)
            {
                // If the sums are equal, we've found a valid common span.
                // Calculate its length. The length of a span from i to j is (j - i + 1).
                int current_span_length = j - i + 1;
                
                // Update the longest_span if the current span is longer than any we've seen before.
                longest_span = max(longest_span, current_span_length);
            }
        }
    }

    // After checking all possible subarrays, return the maximum length found.
    return longest_span;
}



*/
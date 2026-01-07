//  return length of  Longest subarray with given sum
// Input Array: [10, 5, 2, 7, 1, 9]
// Given Sum (k): 15
// Reasoning: There are two subarrays that sum to 15:
// {10, 5} has a length of 2.
// {5, 2, 7, 1} has a length of 4.
// Output: 4 (the length of the longest one)

#include <iostream>
#include <algorithm>

using namespace std;

int LengthOfLongestSubarrayWithGivenSum(int arr[], int n, int sum)
{
    int longest_length = 0;

    for (int i = 0; i < n; i++)
    {
        int current_length;
        int current_sum = arr[i];

        if (arr[i] == sum)
        {
            current_length = 1;
            longest_length = max(current_length, longest_length);
        }

        for (int j = i + 1; j < n; j++)
        {
            current_sum += arr[j];
            if (current_sum == sum)
            {
                current_length = j - i + 1;
                longest_length = max(current_length, longest_length);
            }
        }
    }
    return longest_length;
}

int main()
{
    int arr1[] = {10, 5, 2, 7, 1, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 15;

    cout << LengthOfLongestSubarrayWithGivenSum(arr1, n, sum);

    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(1)

// logic

/*

#include <iostream>
#include <algorithm> // Required for std::max
using namespace std;

// Function returns the length of the longest subarray with the given sum.
int lengthOfLongestSubarray(int arr[], int n, int sum)
{
    // Initialize the result to 0. If no subarray is found, this will be returned.
    int longest_length = 0;

    // The outer loop picks the starting index 'i' of a potential subarray.
    for (int i = 0; i < n; i++)
    {
        // For each starting index 'i', initialize a current sum for the new subarray.
        int current_sum = 0;

        // The inner loop starts from 'i' and expands to the right, forming all
        // possible subarrays that start at 'i'.
        for (int j = i; j < n; j++)
        {
            // Add the current element to the sum of the subarray.
            current_sum += arr[j];

            // Check if the sum of the subarray from 'i' to 'j' matches the target.
            if (current_sum == sum)
            {
                // If it matches, calculate the length of this subarray.
                int current_length = j - i + 1;
                // Update the longest_length if this subarray is the longest we've seen.
                longest_length = max(longest_length, current_length);
            }
        }
    }

    // After checking all possible subarrays, return the maximum length found.
    return longest_length;
}


*/
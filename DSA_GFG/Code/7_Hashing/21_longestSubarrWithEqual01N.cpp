// Length of longest subarray with equal number of zeros and ones

// arr[] = {1, 0, 1, 1, 1, 0, 0}
// Output:6
// Explanation:
// The longest subarray with an equal number of zeros and ones is {0, 1, 1, 1, 0, 0}, which starts at index 1 and ends at index 6.

// arr[] = {1, 1, 1, 1, 1}
// op = 0
// Explanation:
// There are no 0s in the array

#include <iostream>
#include <algorithm>

using namespace std;

int LengthOfLongestSubarrayWithEqualZerosAndOnes(int arr[], int n)
{
    int longest_length = 0;

    for (int i = 0; i < n; i++)
    {
        int current_zeros_length = 0;
        int current_ones_length = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                current_zeros_length++;
            else
                current_ones_length++;

            if (current_ones_length == current_zeros_length)
            {
                int length = j - i + 1;
                longest_length = max(length, longest_length);
            }
        }
    }
    return (longest_length);
}

int main()
{
    int arr1[] = {1, 0, 1, 1, 1, 0, 0};
    // int arr1[] ={1, 1, 1, 1, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << LengthOfLongestSubarrayWithEqualZerosAndOnes(arr1, n);

    return 0;
}


// Time Complexity: O(n²)
// Space Complexity: O(1)

// logic

/*

#include <algorithm> // Required for the max() function

// Function to find the length of the longest subarray with an equal number of 0s and 1s.
// arr[]: The input array of 0s and 1s.
// n: The size of the input array.
int LengthOfLongestSubarrayWithEqualZerosAndOnes(int arr[], int n)
{
    // This variable will store the maximum length found so far. Initialize it to 0.
    int longest_length = 0;

    // The outer loop picks a starting index 'i' for a potential subarray.
    // It will iterate through every possible starting point from the beginning to the end of the array.
    for (int i = 0; i < n; i++)
    {
        // For each new starting index 'i', reset the counts of 0s and 1s.
        int current_zeros_length = 0;
        int current_ones_length = 0;

        // The inner loop picks an ending index 'j' for the subarray that starts at 'i'.
        // This loop iterates from the starting index 'i' to the end of the array.
        // The combination of loops (i, j) generates every possible subarray.
        for (int j = i; j < n; j++)
        {
            // Examine the element at the current ending index 'j'.
            // Increment the respective counter for the subarray arr[i...j].
            if (arr[j] == 0)
                current_zeros_length++;
            else
                current_ones_length++;

            // After extending the subarray to index 'j', check if it has an equal number of 0s and 1s.
            if (current_ones_length == current_zeros_length)
            {
                // If the counts are equal, this is a valid subarray.
                // Calculate its length. The length of a subarray from index i to j is (j - i + 1).
                int length = j - i + 1;
                
                // Compare the length of this valid subarray with the longest one found so far
                // and update 'longest_length' if the current one is longer.
                longest_length = std::max(length, longest_length);
            }
        }
    }
    
    // After checking all possible subarrays, return the maximum length that was found.
    return (longest_length);
}



*/
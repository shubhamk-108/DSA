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
#include<vector>
#include<unordered_map>

using namespace std;

int LengthOfLongestSubarrayWithEqualZerosAndOnes(int arr[], int n)
{
    unordered_map <int, int> um;

    for(int i = 0; i<n; i++)
        arr[i] = arr[i] == 0 ? -1 : 1 ;
    
    int so_far_prefix_sum = 0;

    int longest_length = 0;
    
    for(int i = 0; i<n ; i++)
    {
        so_far_prefix_sum += arr[i];

        if(so_far_prefix_sum == 0)
            longest_length = max(longest_length, i+1);

        if(um.find(so_far_prefix_sum) != um.end())
        {
            int current_length = i - um[so_far_prefix_sum]; 
            longest_length = max(longest_length, current_length );
        }
        else
        {
            um[so_far_prefix_sum] = i ;
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
// You must see 18_subarrayWithGivenSumEffi.cpp Without doing that code first you will not understand this. Please watch that logic




// Time Complexity: O(n) because the code iterates through the array just once. Operations inside the loop (map insertion and lookup) take 
// constant time on average for an unordered_map.

// Space Complexity: O(n) because, in the worst-case scenario, all prefix sums could be unique, requiring the unordered_map to store 
// up to n entries.


// Logic :


/*



 * @brief Calculates the length of the longest subarray with an equal number of 0s and 1s.
 * 
 * @param arr The input array of integers (containing only 0s and 1s).
 * @param n The size of the input array.
 * @return int The length of the longest subarray found.
 * 
 * This function uses a clever technique to solve the problem in O(n) time.
 * 1. It transforms the problem by converting all 0s in the array to -1.
 *    Now, a subarray with an equal number of 0s and 1s is equivalent to a
 *    subarray whose elements sum to 0.
 * 2. It then iterates through the modified array, calculating the prefix sum at each step.
 * 3. An unordered_map (hash map) is used to store the first index where a
 *    particular prefix sum is encountered.
 * 4. If a prefix sum is encountered again, it means the elements between the two
 *    occurrences sum to 0. The length of this subarray is calculated and compared
 *    with the maximum length found so far.


int LengthOfLongestSubarrayWithEqualZerosAndOnes(int arr[], int n)
{
    // Create an unordered_map to store the first occurrence of each prefix sum.
    // Key: prefix_sum, Value: index
    unordered_map <int, int> um;

    // Step 1: Transform the array. Replace all 0s with -1.
    // This converts the problem into finding the longest subarray with a sum of 0.
    for(int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] == 0) ? -1 : 1;
    }
    
    // Initialize a variable to keep track of the cumulative sum of elements.
    int so_far_prefix_sum = 0;

    // Initialize a variable to store the maximum length of the subarray found so far.
    int longest_length = 0;
    
    // Step 2: Iterate through the modified array.
    for(int i = 0; i < n ; i++)
    {
        // Add the current element to the prefix sum.
        so_far_prefix_sum += arr[i];

        // Case 1: If the prefix sum is 0.
        // This means the subarray from index 0 to the current index 'i' has a sum of 0.
        // The length of this subarray is i + 1.
        if(so_far_prefix_sum == 0)
        {
            longest_length = max(longest_length, i + 1);
        }

        // Case 2: If the current prefix sum has been seen before.
        // The `find` method checks if the key `so_far_prefix_sum` exists in the map.
        if(um.find(so_far_prefix_sum) != um.end())
        {
            // If the sum has been seen before at index `um[so_far_prefix_sum]`,
            // it means the subarray between that previous index and the current index 'i'
            // has a sum of 0.
            // Calculate the length of this subarray.
            int current_length = i - um[so_far_prefix_sum]; 
            // Update the longest_length if this subarray is longer.
            longest_length = max(longest_length, current_length);
        }
        else // Case 3: If the current prefix sum is encountered for the first time.
        {
            // Store the prefix sum along with its index in the map.
            // We only store the *first* time we see a prefix sum, because this will
            // give us the longest possible subarray length when that sum is encountered again.
            um[so_far_prefix_sum] = i;
        }
    }
    
    // Return the maximum length found during the iteration.
    return longest_length;
}



*/
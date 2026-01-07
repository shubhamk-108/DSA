// Our Task: Given an array of integers of size 'n'. Our aim is to calculate the maximum sum of 'k' consecutive elements in the array.

// Examples :

// Input  : arr[] = {100, 200, 300, 400}
//          k = 2
// Output : 700

// Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
//          k = 4
// Output : 39
// We get maximum sum by adding subarray {4, 2, 10, 23}
// of size 4.

// Input  : arr[] = {2, 3}
//          k = 3
// Output : Invalid

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int maxKLengthSubarraySum(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1;
    }

    // 1. Calculate sum of the first window
    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }

    // 2. Initialize max_sum with the sum of the first window
    int max_sum = window_sum;

    // 3. Slide the window from k to the end of the array
    for (int i = k; i < n; i++)
    {
        // Add the current element and subtract the first element of the previous window
        window_sum += arr[i] - arr[i - k];
        
        // 4. Update the maximum sum found so far
        max_sum = std::max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    int arr[] = {100, 200, 300, 400};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << maxKLengthSubarraySum(arr, n, k);

    return 0;
}

// Time Complexity:  O(n)
// Auxiliary Space:  O(1)


// Logic:

// To understand the loops condition take a example array on paper and try dry run then you will automatically understand


// Next file: About sliding window approach
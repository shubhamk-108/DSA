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
using namespace std;

#include <algorithm> // Required for std::max
#include <climits>   // Required for INT_MIN

int maxKLengthSubarraySum(int arr[], int n, int k)
{
    if (k > n)
    {
        return -1; // Or handle error appropriately
    }

    int maxx = INT_MIN;

    for (int i = 0; i < n - k + 1; i++)
    {
        int current_sum = 0;

        for (int j = i; j < i + k; j++)
        {
            current_sum += arr[j];
        }

        maxx = std::max(maxx, current_sum);
    }
    return maxx;
}

int main()
{
    int arr[] = {100, 200, 300, 400};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << maxKLengthSubarraySum(arr, n, k);

    return 0;
}

// Time Complexity:  O(n * k)
// Auxiliary Space:  O(1)


// Logic:

// To understand the loops condition take a example array on paper and try dry run then you will automatically understand
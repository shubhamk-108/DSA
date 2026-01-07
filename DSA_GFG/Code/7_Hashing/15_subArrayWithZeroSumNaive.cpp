// Input Array: [4, 2, -3, 1, 6]
// Reasoning: The subarray from index 1 to 3 is {2, -3, 1}. The sum is 2 + (-3) + 1 = 0. Since we found one such subarray, the answer is true.
// Output: true

#include <iostream>
using namespace std;

bool subarrayWithZeroSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        int checkIfZero = arr[i];
        if(checkIfZero == 0)
            return true;

        for (int j = i + 1; j < n; j++)
        {
            checkIfZero = checkIfZero + arr[j];
            if (checkIfZero == 0)
                return true;
        }
    }
    return false;
}

int main()
{
    int arr1[] = {4, 2, -3, 1, 6};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 15;

    cout << subarrayWithZeroSum(arr1, n, sum);

    return 0;
}


// time space

/*
Time Complexity: O(n²)

Space Complexity: O(1)

*/



// logic:

/*

#include <iostream>
using namespace std;

// This function correctly checks if a subarray with a sum of 0 exists.
// It uses a brute-force approach by checking every possible subarray.
bool subarrayWithZeroSum(int arr[], int n) // 'sum' parameter is not needed
{
    // The outer loop picks the starting index 'i' of a potential subarray.
    for (int i = 0; i < n; i++)
    {
        // 'checkIfZero' will act as the running sum for subarrays starting at index 'i'.
        // It's initialized with the first element of the subarray.
        int checkIfZero = arr[i];

        // --- THE FIX ---
        // Immediately check if the single-element subarray {arr[i]} has a sum of 0.
        // This handles cases like [5, 0, 3].
        if (checkIfZero == 0)
            return true;

        // The inner loop iterates from the next element (i + 1) to the end of the array.
        // This loop builds subarrays of length 2 or more that start at index 'i'.
        for (int j = i + 1; j < n; j++)
        {
            // Add the next element to our running sum.
            checkIfZero = checkIfZero + arr[j];

            // Check if the sum of the subarray from index 'i' to 'j' is zero.
            if (checkIfZero == 0)
            {
                // If a zero-sum subarray is found, we can stop and return true.
                return true;
            }
        }
    }

    // If both loops complete without finding any zero-sum subarray,
    // we can conclude that none exists.
    return false;
}



*/
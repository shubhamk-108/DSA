// Our Task: Given a sequence arr[ ] of size n, Write a function int equilibrium(int[] arr, int n) that returns an equilibrium index
// (if any) or -1 if no equilibrium index exists.

// What is an Equilibrium Point?
// The equilibrium index of an array is an index such that the sum of elements at lower indexes (left side) is equal to the sum of elements at higher indexes(right side).

// Input: A[] = {-7, 1, 5, 2, -4, 3, 0}
// Output: 3 //index of 2
// 3 is an equilibrium index, because:
// A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

// Input: A[] = {1, 2, 3}
// Output: -1

// Input : {4, 2, -2}
// Output : 4
// Explanation: The left side of first index is considered as 0. That is we are considering there is 0 at the left of 4.
// so 4 is equilibrium because left of 4 is 0 and right of 4, sum is 0 ( 2 + (-2) )

#include <iostream>

using namespace std;

int equilibriumPoint(int arr[], int n)
{
    if (n == 0)
        return -1;

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    int prefix_sum[n];
    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int left_sum = 0;
    int right_sum = 0;

    for (int j = 0; j < n; j++)
    {
        right_sum = total_sum - prefix_sum[j];

        if (right_sum == left_sum)
            return j;

        left_sum += arr[j];
    }

    return -1;
}

int main()
{

    int arr[] = {-7, 1, 5, 2, -4, 3, 0} ;
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<equilibriumPoint(arr,n);

    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)


// Logic




/*





int equilibriumPoint(int arr[], int n)
{
    // If the array is empty, there is no equilibrium point.
    if (n == 0)
        return -1;

    // --- Step 1: Calculate the sum of all elements in the array ---
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    // --- Step 2: Calculate the prefix sum for the array ---
    // A prefix sum at index 'i' is the sum of all elements from 0 to i.
    // NOTE: `prefix_sum[n]` is a Variable Length Array (VLA), which is not standard C++.
    // A std::vector<int> would be the standard C++ approach.
    int prefix_sum[n];
    prefix_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    // --- Step 3: Iterate through the array to find the equilibrium point ---
    int left_sum = 0;  // Sum of elements to the left of the current index.
    int right_sum = 0; // Sum of elements to the right of the current index.

    // Loop through each element, considering it as a potential equilibrium point.
    for (int j = 0; j < n; j++)
    {
        // Calculate the sum of elements to the right of index 'j'.
        // This is done by subtracting the sum of elements up to 'j' (prefix_sum[j])
        // from the total sum of the array.
        right_sum = total_sum - prefix_sum[j];

        // Check if the sum of elements on the left equals the sum on the right.
        if (right_sum == left_sum)
            return j; // If they are equal, 'j' is the equilibrium point.

        // IMPORTANT: Update left_sum for the *next* iteration.
        // The current element arr[j] will be part of the left_sum for the next index (j+1).
        left_sum += arr[j];
    }

    // If the loop completes without finding an equilibrium point, return -1.
    return -1;
}

// The main function where the program execution begins.
int main()
{
    // Define a sample array to test the function.
    // For this array, the equilibrium point is at index 3.
    // Left sum: -7 + 1 + 5 = -1
    // Right sum: -4 + 3 + 0 = -1
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    
    // Calculate the number of elements in the array.
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function and print the result to the console.
    // The expected output is 3.
    cout << equilibriumPoint(arr, n);

    // Return 0 to indicate successful program execution.
    return 0;
}



Example Walkthrough: arr = {-7, 1, 5, 2, -4, 3, 0}
n = 7

total_sum = -7 + 1 + 5 + 2 - 4 + 3 + 0 = 0

prefix_sum = {-7, -6, -1, 1, -3, 0, 0}

Loop starts:

j = 0: left_sum = 0. right_sum = total_sum - prefix_sum = 0 - (-7) = 7. Not equal. left_sum becomes 0 + (-7) = -7.

j = 1: left_sum = -7. right_sum = total_sum - prefix_sum = 0 - (-6) = 6. Not equal. left_sum becomes -7 + 1 = -6.

j = 2: left_sum = -6. right_sum = total_sum - prefix_sum = 0 - (-1) = 1. Not equal. left_sum becomes -6 + 5 = -1.

j = 3: left_sum = -1. right_sum = total_sum - prefix_sum = 0 - (1) = -1. They are equal!

The function returns j, which is 3.

The program will output 3.


*/

#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int maxElement(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void radixsort(int arr[], int n)
{
    int mx = maxElement(arr, n);

    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {319, 212, 6, 8, 100, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}




// ---------------------------------------------------------------------------------------------


//time and space


/*

Let's define:
n as the number of elements in the input array.
d as the number of digits in the maximum element.
b as the base of the numbering system (which is 10 for decimal numbers).
Time Complexity: O(d * (n + b))
The radixsort function runs a loop d times (once for each digit of the largest number).
Inside this loop, it calls countingSort.
The countingSort function has four main loops:
Counting digit occurrences: O(n)
Calculating cumulative counts: O(b)
Building the output array: O(n)
Copying back to the original array: O(n)
The total time for one countingSort call is O(n + b).
Since countingSort is called d times, the total time complexity for Radix Sort becomes O(d * (n + b)).
When the number of digits d is constant (e.g., for 32-bit integers, d is at most 10) and b is also constant (10), the complexity is 
often simplified to O(n), making it a linear time sorting algorithm in practice for fixed-size integers.

Space Complexity: O(n + b)
The primary space usage comes from the countingSort function.
It requires an output array of size n to store the sorted elements temporarily.
It also requires a count array of size b (in this case, 10) to store the digit counts.
Therefore, the auxiliary space required is O(n + b).

*/

// --------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------

// logic


/*


Radix Sort Explained
Radix Sort is a non-comparative sorting algorithm that works by sorting integers digit by digit, starting from the least significant digit
(the one's place) and moving towards the most significant digit. To sort the digits at each place value, it uses a stable sorting algorithm 
as a subroutine, which in your case is Counting Sort.

The process is as follows:

Find the largest number in the array to determine the maximum number of digits (d).

Loop d times, from the least significant digit to the most significant.

In each iteration, use a stable sort (Counting Sort) to sort the array based on the current digit place (1s, 10s, 100s, etc.).


*/


//---------------------------------------------------------------------------------------



// commented code explained


/*


// Helper function to get the maximum value in arr[]
int maxElement(int arr[], int n)
{
    // Assume the first element is the maximum
    int mx = arr[0];
    // Iterate through the rest of the array
    for (int i = 1; i < n; i++)
        // If a larger element is found, update mx
        if (arr[i] > mx)
            mx = arr[i];
    // Return the largest element found
    return mx;
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know the number of digits
    int mx = maxElement(arr, n);

    // 'exp' is the exponent, representing the current digit's place value (1, 10, 100...)
    // The loop continues as long as there is a digit at the current place value for the max element.
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        // Call counting sort for the digit at the 'exp' place.
        // For example, when exp=1, it sorts by the units digit.
        // When exp=10, it sorts by the tens digit, and so on.
        countingSort(arr, n, exp);
    }
}




*/


//---------------------------------------------------------------------------------------

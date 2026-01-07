#include <iostream>
using namespace std;

int bSearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
        return bSearch(arr, low, mid - 1, x);

    else
        return bSearch(arr, mid + 1, high, x);
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60, 70}, n = 7;

    int x = 20;

    cout << bSearch(arr, 0, n - 1, x);
    return 0;
}

// Time: O(log n)
// Space:O(log n)

// Logic


/*



int bSearch(int arr[], int low, int high, int x)
{
    // Base case for the recursion: If the search interval is empty or invalid
    // (i.e., the lower bound is greater than the upper bound), the element
    // is not present in the array.
    if (low > high)
        return -1;

    // Calculate the middle index of the current search interval.
    // NOTE: This line contains a potential integer overflow bug. If `low` and `high`
    // are very large, their sum might exceed the maximum value for an `int`,
    // causing an error. A safer calculation is `mid = low + (high - low) / 2;`
    int mid = (low + high) / 2;

    // Check if the element at the middle index is the target value.
    if (arr[mid] == x)
        return mid; // If it is, the search is successful. Return the index.

    // If the target value 'x' is smaller than the middle element,
    // then it can only be present in the left half of the current interval.
    else if (arr[mid] > x)
        // Recursively call the search function on the left subarray (from 'low' to 'mid - 1').
        // NOTE: This line contains a typo. The function is named `bSearch` (capital 'S'),
        // but is being called as `bsearch` (lowercase 's'), which would cause a compilation error.
        return bSearch(arr, low, mid - 1, x);

    // Otherwise (if arr[mid] < x), the target value must be in the right
    // half of the current interval.
    else
        // Recursively call the search function on the right subarray (from 'mid + 1' to 'high').
        // NOTE: This line also contains the same case-sensitivity typo.
        return bSearch(arr, mid + 1, high, x);
}






*/






// Binary search, also known as half-interval search or logarithmic search, is an efficient algorithm used to find the
// position of a target value within a sorted array. It works by repeatedly dividing the search interval in half. If
// the value of the search key is less than the item in the middle of the interval, the search is narrowed to the
// lower half; otherwise, the search is narrowed to the upper half. This process continues until the value is
// found or the interval is empty.

// How Binary Search Works
// The binary search algorithm operates on the principle of divide and conquer. Here are the fundamental steps:

// Start with a sorted array: It is a prerequisite that the data collection is sorted for the algorithm to work correctly.

// Find the middle element: The algorithm compares the target value with the middle element of the array.

// Compare and narrow the search:

// If the target value matches the middle element, its position in the array is returned, and the search is complete.

// If the target value is less than the middle element, the search continues in the lower half of the array. The upper
//  half is eliminated from the search space.

// If the target value is greater than the middle element, the search continues in the upper half of the array. The lower
// half is eliminated.

// Repeat: This process of halving the search space is repeated until the target value is found or the remaining search
// space is empty, which indicates the target is not in the array.

// Implementation
// Binary search can be implemented in two primary ways:

// Iterative Method: This approach uses a loop to repeatedly narrow down the search range until the element is found or
// the range is empty. It generally has a space complexity of O(1).

// Recursive Method: This approach uses a function that calls itself, with the search range being passed as arguments.
// It follows the divide and conquer paradigm.

// Efficiency and Applications
// Binary search is significantly faster than linear search for large arrays, with a worst-case time complexity of O(log n),
//  where n is the number of elements in the array. This logarithmic time complexity makes it a very efficient searching
//  algorithm. However, the array must be sorted before binary search can be applied.

// Applications of binary search include:

// Searching for an element in a sorted data structure.

// Finding the next-smallest or next-largest element relative to a target in an array.

// Debugging linear code.

// It serves as a basis for more complex data structures like binary search trees and B-trees
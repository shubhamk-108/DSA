#include<iostream>
using namespace std;

int indexOfLastOccuranceInSortedArr(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (x > arr[mid])
            low = mid + 1;

        else if (x < arr[mid])
            high = mid - 1;

        else // This means arr[mid] == x
        {
            if (mid == high || arr[mid] != arr[mid + 1])
                return mid;

            else
                low = mid + 1;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {5, 10, 10, 10, 20}, n = 5;

    int x = 10;

    cout << indexOfLastOccuranceInSortedArr(arr, n, x);

    return 0;
}


// Time: O(log n)
// Space: O(1)

// Logic


/*


int indexOfLastOccuranceInSortedArr(int arr[], int n, int x)
{
    // Initialize the search space boundaries.
    int low = 0;
    int high = n - 1;

    // Continue the search as long as the `low` pointer is not past the `high` pointer.
    while (low <= high)
    {
        // Calculate the middle index safely to avoid integer overflow.
        int mid = low + (high - low) / 2;

        // If the target 'x' is greater than the middle element, then 'x' must be
        // in the right half of the search space.
        if (x > arr[mid])
        {
            // Move the `low` pointer to the right of `mid` to narrow the search.
            low = mid + 1;
        }
        // If 'x' is less than the middle element, it must be in the left half.
        else if (x < arr[mid])
        {
            // Move the `high` pointer to the left of `mid`.
            high = mid - 1;
        }
        // This `else` block executes when `arr[mid] == x`.
        // Now, we must determine if this is the *last* occurrence.
        else 
        {
            // It's the last occurrence if one of two conditions is true:
            // 1. `mid == n - 1`: The element is at the very end of the array.
            // 2. `arr[mid] != arr[mid + 1]`: The element to its immediate right is different (larger).
            //    (Note: your check `mid == high` also works perfectly here and is equivalent to `mid == n-1` when the match is the 
            // last element in the *entire* array).
            if (mid == n - 1 || arr[mid] != arr[mid + 1])
            {
                // We've found the last occurrence, so return its index.
                return mid;
            }
            else
            {
                // The element at `mid` is a match, but not the last one.
                // We must continue searching for the actual last occurrence in the right half.
                // We do this by discarding the current `mid` and everything to its left.
                low = mid + 1;
            }
        }
    }

    // If the while loop completes without returning, it means `low` has crossed `high`,
    // and the target value 'x' was not found in the array.
    return -1;
}


*/
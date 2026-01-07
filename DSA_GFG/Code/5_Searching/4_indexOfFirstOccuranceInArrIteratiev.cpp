#include <iostream>
using namespace std;

int indexOfFirstOccurance(int arr[], int n, int x)
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
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;

            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    int arr[] = {5, 10, 10, 10, 20}, n = 5;

    int x = 10;

    cout << indexOfFirstOccurance(arr, n, x);

    return 0;
}


// Time: O(log n)
// space: O(1)


// logic




 
/*


 
int indexOfFirstOccurance(int arr[], int n, int x)
{
    // Initialize the search space. `low` is the start of the array, and `high` is the end.
    int low = 0;
    int high = n - 1;

    // The loop continues as long as the search space is valid (low <= high).
    // If `low` becomes greater than `high`, the element is not in the array.
    while (low <= high)
    {
        // Calculate the middle index safely to prevent potential integer overflow.
        int mid = low + (high - low) / 2;

        // If the target 'x' is greater than the element at the middle, it means 'x'
        // must be in the right half of the current search space.
        if (x > arr[mid])
        {
            // Discard the left half by moving the `low` pointer past the middle element.
            low = mid + 1;
        }
        // If 'x' is less than the middle element, it must be in the left half.
        else if (x < arr[mid])
        {
            // Discard the right half by moving the `high` pointer before the middle element.
            high = mid - 1;
        }
        // This `else` block is executed if `arr[mid] == x`. Now we must check if it's
        // the *first* occurrence.
        else
        {
            // It is the first occurrence if either of these conditions is true:
            // 1. `mid == 0`: The element is at the very beginning of the array.
            // 2. `arr[mid - 1] != arr[mid]`: The element to its immediate left is different (smaller).
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                // We've found the first occurrence, so we can return its index and exit.
                return mid;
            }
            else
            {
                // The element at `mid` is a match, but not the first one.
                // We need to continue searching for the *actual* first occurrence in the left part.
                // We do this by discarding the current `mid` and everything to its right.
                high = mid - 1;
            }
        }
    }

    // If the while loop finishes without finding the element (i.e., low > high),
    // it means the target value 'x' is not present in the array.
    return -1;
}



*/
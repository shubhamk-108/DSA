// program to search in an infinite size array

#include <iostream>
#include <climits>
using namespace std;

int searchedInInfiniteSizeArr(int arr[], int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;

    while (arr[i] < x && arr[i] != INT_MAX )
        i = i * 2;
    
    if(arr[i] == x) return i;


    int low;
    int high;

    high = ( arr[i] == INT_MAX ) ? i -1 : i;
    low = (i/2) + 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{

    int arr[] = {1, 2, 3, 5, 5};

    int x = 42;

    cout << searchedInInfiniteSizeArr(arr, x);

    return 0;
}

// time: O(log (position_of_element) )
// space : O(1)

// Logic :


/*


int searchedInInfiniteSizeArr(int arr[], int x)
{
    // Handle the edge case where the target is the very first element.
    if (arr[0] == x)
        return 0;

    int i = 1;

    // --- Step 1: Find the search bounds with a safety check ---

    // Exponentially increase the index 'i' to find a potential upper bound.
    // The loop continues as long as the element at 'i' is less than our target.
    // CRITICAL SAFETY CHECK: `&& arr[i] != INT_MAX` is added to ensure we don't
    // go past the "logical" end of the array, preventing an out-of-bounds access
    // if the actual data is very short.
    // NOTE: A potential bug exists here. If `i` doubles to a value outside the
    // actual allocated size of `arr`, `arr[i]` will cause a crash *before* the
    // value can be checked.
    while (arr[i] < x && arr[i] != INT_MAX )
        i = i * 2;
    
    // OPTIMIZATION: If the exponential search happens to land exactly on our target,
    // we can return the index immediately without doing a binary search.
    if(arr[i] == x) return i;

    // --- Step 2: Carefully set the low and high bounds for binary search ---

    int low;
    int high;

    // Here, we determine the correct `high` bound using a ternary operator.
    // IF the loop stopped because we hit the end of the data (`arr[i] == INT_MAX`),
    // THEN the actual high bound must be the index before it (`i - 1`).
    // ELSE (if the loop stopped because `arr[i] >= x`), `i` itself is a valid high bound.
    high = ( arr[i] == INT_MAX ) ? i - 1 : i;

    // The `low` bound is the position right after the last known smaller element (`i/2`).
    low = (i/2) + 1;

    // --- Step 3: Perform a standard binary search on the calculated range ---

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    // If the binary search loop finishes without a match, the element is not in the array.
    return -1;
}


*/
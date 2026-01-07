// A element is a peak element if the element after that current_element and before that current_element is smaller.
// for 0th element and last element there is no need to check left and right side element resp.
// examples:
// {5,10,20,15,7}
// op = 20

// {10,20,15,23,90,67} op = 20 or 90
// {80,70,60} op = 80

#include <iostream>
using namespace std;

int peakElement(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return arr[mid];
        
        if( mid > 0 && arr[mid-1] >= arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }

    return -1;
}

int main()
{

    int arr[] = {5, 20, 40, 30, 20, 50, 60}, n = 7;

    cout << peakElement(arr, n);

    return 0;
}

// Time : O(log n)
// space : O(1)


// logic


/*


 * Efficiently finds a peak element in an array using binary search.
 
 * A peak element is an element that is greater than or equal to its immediate neighbors.
 * This algorithm works by checking the middle element. If its not a peak, it means
 * one of its neighbors is larger. The search is then narrowed to the half that
 * contains the larger neighbor, as a peak is guaranteed to exist in that direction.
 * This ensures O(log n) time complexity.
 *
 * @param arr The input array.
 * @param n The size of the array.
 * @return The value of a peak element. (A peak is always guaranteed to exist).
 


 
int peakElement(int arr[], int n)
{
    // Handle edge case for a single-element array, which is always a peak.
    if (n == 1)
        return arr;

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if the middle element is a peak.
        // A peak must be >= its left neighbor (if one exists).
        // A peak must be >= its right neighbor (if one exists).
        // The ORs handle the boundary conditions for the first and last elements.
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        {
            return arr[mid];
        }

        // If 'mid' is not a peak, we need to find which way the "slope" goes up.
        // We check the left neighbor first. The `mid > 0` check MUST come first
        // to prevent out-of-bounds access.
        if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            // If the left neighbor is greater, a peak is guaranteed in the left half.
            // So, we discard the right half.
            high = mid - 1;
        }
        else
        {
            // If the left neighbor is not greater, the right neighbor MUST be greater
            // (otherwise 'mid' would have been a peak).
            // A peak is guaranteed in the right half, so we discard the left half.
            low = mid + 1;
        }
    }

    // This line is technically unreachable because a peak is always guaranteed to be found.
    return -1; 
}


*/
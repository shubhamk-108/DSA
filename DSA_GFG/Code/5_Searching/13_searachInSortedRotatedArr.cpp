// In this problem we are given a sorted array that is rotated a certain number of times . Our task is to
// detect the presence of a given target element in the array 

#include <iostream>
#include <climits>
using namespace std;

int searchedInortedRotatedArray(int arr[],int n, int x)
{
    int high = n-1;
    int low = 0;

    while(low<=high)
    {
        int mid = low + (high - low ) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[low] <= arr[mid]) // if left half is sorted
        {
            if(x >= arr[low] && x < arr[mid] ) // if x lies in that range
            {
                high = mid-1;
            }
            else // left half is sorted but x doesnt lie in that half, Then
            {
                low = mid + 1;
            }
        }
        else // right half sorted
        {
            if(x > arr[mid] && x <= arr[high] ) // if x lies in that half
            {
                low  = mid + 1;
            }
            else //  right half is sorted but x doesnt lie in that half. Then, 
            {
                high = mid -1;
            }
        }
    }
    return -1;
}

int main() {
    

  int arr[] = {10, 20, 40, 60, 5, 8}, n = 6;
  
  int x = 5;

	cout << searchedInortedRotatedArray(arr, n, x);

	return 0;
}

// time : O(logn)
// space : O(1)



// logic




// he algorithm works by repeatedly doing three things in each step:

// Find the middle element.

// Identify which half is sorted. This is done by comparing arr[low] with arr[mid]. If arr[low] <= arr[mid], the left half is sorted. 
// Otherwise, the right half must be sorted.

// Decide where to search next:

// Once you have your sorted half, check if the target x falls within the numerical range of that sorted half.

// If yes, you can confidently discard the other half and continue your search within this sorted portion.

// If no, the target must be in the other, unsorted half. So, you discard the sorted half and search in the unsorted portion.

// This process guarantees that you correctly eliminate half of the search space in every iteration, preserving the O(log n) 
// time complexity of binary search.





/*



int searchedInortedRotatedArray(int arr[], int n, int x)
{
    int high = n - 1;
    int low = 0;

    // Standard binary search loop.
    while(low <= high)
    {
        // Calculate mid safely to avoid overflow.
        int mid = low + (high - low) / 2;

        // Case 1: The target is found at the middle. This is the simplest case.
        if (arr[mid] == x)
            return mid;

        // Case 2: The left half (from arr[low] to arr[mid]) is sorted.
        // This is true if the first element is less than or equal to the middle element.
        if (arr[low] <= arr[mid])
        {
            // Now, check if the target 'x' is within the range of this sorted left half.
            if(x >= arr[low] && x < arr[mid])
            {
                // If 'x' is in this range, we can safely discard the right half.
                high = mid - 1;
            }
            else
            {
                // If 'x' is NOT in this range, it must be in the unsorted right half.
                low = mid + 1;
            }
        }
        // Case 3: The left half is not sorted, which means the right half MUST be sorted.
        // The right half goes from arr[mid] to arr[high].
        else 
        {
            // Now, check if the target 'x' is within the range of this sorted right half.
            if(x > arr[mid] && x <= arr[high])
            {
                // If 'x' is in this range, we can safely discard the left half.
                low = mid + 1;
            }
            else
            {
                // If 'x' is NOT in this range, it must be in the unsorted left half.
                high = mid - 1;
            }
        }
    }

    // If the loop completes without finding 'x', the element is not in the array.
    return -1;
}



*/
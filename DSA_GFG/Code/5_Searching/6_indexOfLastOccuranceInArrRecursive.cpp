#include<iostream>
using namespace std;

int indexOfLastOccuranceInSortedArr(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    
    int mid = low + (high - low ) / 2;

    if(x > arr[mid])
    {
        return indexOfLastOccuranceInSortedArr(arr, mid + 1, high, x);
    }
    else if(x < arr[mid])
    {
        return indexOfLastOccuranceInSortedArr(arr, low, mid - 1, x);
    }
    else
    {
        if(mid == high || arr[mid] != arr[mid+1])
            return mid;
        else
            return indexOfLastOccuranceInSortedArr(arr, mid + 1, high , x);
    }
}

int main() {
    
    int arr[] = {5, 10, 10, 10, 10}, n = 5;
    

	int x = 10;
	
    cout<<indexOfLastOccuranceInSortedArr(arr, 0, 4, x);
	
	return 0;
}



// Time: O(log n)
// space: O(log n)


// Logic


/*

int indexOfLastOccuranceInSortedArr(int arr[], int low, int high, int x)
{
    // Base Case: If the search space is empty (low > high), the element is not found.
    if (low > high)
        return -1;
    
    // Calculate the middle index of the current search space safely.
    int mid = low + (high - low ) / 2;

    // --- Start of Binary Search Logic ---

    // If the target 'x' is greater than the middle element, it must be in the right subarray.
    if(x > arr[mid])
    {
        // Make a recursive call on the right half and return its result.
        return indexOfLastOccuranceInSortedArr(arr, mid + 1, high, x);
    }
    // If 'x' is less than the middle element, it must be in the left subarray.
    else if(x < arr[mid])
    {
        // Make a recursive call on the left half and return its result.
        return indexOfLastOccuranceInSortedArr(arr, low, mid - 1, x);
    }
    // This `else` block is reached if `arr[mid] == x`.
    // Now, we must check if this is the *last* occurrence of 'x'.
    else
    {
        // It is the last occurrence if one of two conditions is true:
        // 1. `mid == high`: The match is the last element in the current search space. This
        //    cleverly handles the boundary case for the end of the entire array without needing `n`.
        // 2. `arr[mid] != arr[mid+1]`: The element to the immediate right is different.
        // The logical OR (||) ensures `arr[mid+1]` is not accessed if `mid` is already the last element, preventing an out-of-bounds error.
        if(mid == high || arr[mid] != arr[mid+1])
            return mid; // This is the last occurrence. Return its index.
        else
            // If it's a match but not the last one, the actual last occurrence must be
            // to the right. Continue the search in the right subarray.
            return indexOfLastOccuranceInSortedArr(arr, mid + 1, high , x);
    }
}


*/
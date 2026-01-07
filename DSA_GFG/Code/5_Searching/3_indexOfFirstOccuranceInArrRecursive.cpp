#include<iostream>
using namespace std;

int indexOfFirstOccurance(int arr[], int low, int high, int x)
{
    if(low > high)
        return -1;
    
    // int mid = (low + high) /2;
    // this will cause interger overflow if numbers are too big. safer way to do it as below
    int mid = low + (high - low) / 2;

    
    if(x > arr[mid]) 
    {
        return indexOfFirstOccurance(arr, mid + 1, high, x);
    }
    else if(x < arr[mid])
    {
        return indexOfFirstOccurance(arr, low, mid - 1, x);
    }

    else // This means arr[mid] == x
    {
        if(mid == 0 || arr[mid] != arr[mid -1])
            return mid;
        
        else
            return indexOfFirstOccurance(arr, low, mid - 1, x);
    }
}

int main() {
    
    int arr[] = {5, 10, 10, 10, 20}, n = 5;

	int x = 10;
	
    cout<<indexOfFirstOccurance(arr, 0, 4, x);
	
	return 0;
}



// Time: O(log n)
// space: O(log n)

// Time Complexity: O(log n)
// The algorithm still works by halving the search space at each step. Even when a match is found (arr[mid] == x), the worst-case 
// scenario is that the function makes another recursive call to search the left half (indexOfFirstOccurance(arr, low, mid - 1, x)).
// This is just another step in the process of halving the array. Since the number of times you can halve an array of size n is log n, 
// the time complexity remains O(log n) for the best, average, and worst cases.

// Space Complexity: O(log n)
// Because this is a recursive implementation, it uses the program's call stack to store the state of each function call 
// (the parameters arr, low, high, and x). The maximum depth of the recursion is determined by how many times the array can be halved,
// which is log n. Therefore, the space complexity is O(log n).

// Logic:


/*


int indexOfFirstOccurance(int arr[], int low, int high, int x)
{
    // Base case for the recursion: If the lower bound exceeds the upper bound,
    // it means the search interval is empty and the element has not been found.
    if(low > high)
        return -1;
    
    // Calculate the middle index of the current search interval.
    // The commented-out line is prone to integer overflow if `low` and `high` are very large.
    // int mid = (low + high) / 2; 
    
    // This is the safer way to calculate the midpoint, as it avoids the risk of overflow.
    int mid = low + (high - low) / 2;

    // --- Start of Binary Search Logic ---

    // If the target 'x' is greater than the element at the middle index,
    // then 'x' must lie in the right half of the array.
    if(x > arr[mid]) 
    {
        // Recursively search the right subarray (from mid + 1 to high).
        // It's crucial to `return` the result from the recursive call.
        return indexOfFirstOccurance(arr, mid + 1, high, x);
    }
    // If the target 'x' is less than the element at the middle index,
    // then 'x' must lie in the left half of the array.
    else if(x < arr[mid])
    {
        // Recursively search the left subarray (from low to mid - 1).
        return indexOfFirstOccurance(arr, low, mid - 1, x);
    }

    // If neither of the above conditions is met, it means `arr[mid] == x`.
    // Now, we need to determine if this is the *first* occurrence.
    else 
    {
        // We've found the first occurrence if one of two conditions is true:
        // 1. `mid == 0`: The element is at the very beginning of the array.
        // 2. `arr[mid] != arr[mid - 1]`: The element to its immediate left is different. Remember array is sorted that means this element 
        // is the first occurance.
        if(mid == 0 || arr[mid] != arr[mid - 1])
            return mid; // This is the first occurrence, so return its index.
        
        // If we found a match at `mid`, but the element to its left is the same,
        // it's not the first occurrence. We must continue searching for the
        // actual first one in the left subarray.
        else
            return indexOfFirstOccurance(arr, low, mid - 1, x);
    }
}


*/
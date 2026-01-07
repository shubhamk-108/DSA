#include <iostream>
using namespace std;

int countOnes(int arr[], int n)
{
	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == 0)
			low = mid + 1;
		else
		{
			if(mid == 0 || arr[mid - 1] == 0)
				return (n - mid);
			else 
				high = mid -1;
		}
	}

	return 0;		
}

int main() {
    
   int arr[] = {0, 0, 1, 1, 1, 1}, n = 6;

   cout << countOnes(arr, n);

	return 0;
}

// time:O(log n)
// Space: O(1)

// logic


/*


int countOnes(int arr[], int n)
{
    // Initialize the search space for the binary search.
    int low = 0, high = n - 1;

    // The loop continues as long as there is a valid search space.
    while(low <= high)
    {
        // Calculate the middle index. Note: for extremely large arrays,
        // `low + (high - low) / 2` is safer to prevent potential integer overflow.
        int mid = (low + high) / 2;

        // If the middle element is 0, all elements to its left must also be 0.
        // Therefore, the first '1' (if it exists) must be in the right half.
        if(arr[mid] == 0)
        {
            // Discard the left half and continue searching on the right.
            low = mid + 1;
        }
        // This `else` block executes if `arr[mid] == 1`.
        else
        {
            // Now we need to check if this is the *first* '1'.
            // It's the first '1' if it's at the beginning of the array OR
            // if the element just before it is a '0'.
            if(mid == 0 || arr[mid - 1] == 0)
            {
                // We've found the index of the first '1'. The number of 1s is the
                // total number of elements minus the index of this first '1'.
                // For example, if n=5 and the first '1' is at index 2,
                // the 1s are at indices 2, 3, 4. The count is 5 - 2 = 3.
                return (n - mid);
            }
            // If we are at a '1', but the element before it is also a '1',
            // then the first '1' must be further to the left.
            else 
            {
                // Discard the right half and continue searching on the left.
                high = mid - 1;
            }
        }
    }

    // If the loop finishes, it means 'low' has crossed 'high' and no '1' was
    // ever found (the array contains only 0s). In this case, the count is 0.
    return 0;       
}


*/
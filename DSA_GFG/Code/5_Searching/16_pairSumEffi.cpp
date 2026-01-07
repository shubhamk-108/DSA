// In this particular problem, we are provided with a sorted array of integers. Our objective is to determine whether 
// there exists a pair of integers in the array that adds up to a given target value. Initially, we will explore a naive 
// solution with a time complexity of O(n^2), followed by an optimized approach utilizing the Two Pointer method. 

// array must be sorted

// we will use two pointer approach here

#include <iostream>
using namespace std;



bool getPairOfGivenSum(int arr[], int n, int x)
{   
    if(n<2)
        return false;
    
    int i = 0;
    int j = n-1;

    while(i<=j)
    {
        if(arr[i] + arr[j] == x)
            return true;
        if( arr[i]+arr[j] > x)
            j--;
        else
            i++;
    }
    return false;
}


int main()
{
    int arr[] = {2,5,8,12,30};
    int n = 5;
    int x = 17;

    cout<<getPairOfGivenSum(arr, n, x);

    return 0;

}


// time: O(n)
// space  O(1)

// Logic


/*




 * @brief Checks if a pair of elements with a given sum 'x' exists in a sorted array.
 * 
 * PRECONDITION: The input array `arr` MUST be sorted for this algorithm to work correctly.
 * This function uses the two-pointer technique to find the pair in O(n) time,
 * which is highly efficient.
 *
 * @param arr The sorted integer array to search within.
 * @param n The total number of elements in the array.
 * @param x The target sum for the pair.
 * @return `true` if a pair with the sum 'x' is found, otherwise `false`.
 

bool getPairOfGivenSum(int arr[], int n, int x)
{   
    // A pair requires at least two elements. If n < 2, no pair is possible.
    // BUG FIX: Changed from `n==1` and `return -1` to handle all small arrays
    // and return the correct boolean type.
    if(n < 2)
        return false;
    
    // Initialize the two pointers.
    // 'i' (the left pointer) starts at the beginning of the array.
    int i = 0;
    // 'j' (the right pointer) starts at the end of the array.
    int j = n - 1;

    // The loop continues as long as the left pointer is behind the right pointer.
    // We use 'i < j' to ensure we are always looking at two different elements.
    while(i < j)
    {
        // Calculate the sum of the elements at the two pointer positions.
        int currentSum = arr[i] + arr[j];

        // Case 1: The sum is exactly what we're looking for.
        if(currentSum == x)
            return true; // We found a pair, so we can exit immediately.
        
        // Case 2: The sum is too large.
        if(currentSum > x)
            // To decrease the sum, we must use a smaller number. Since the array
            // is sorted, we move the right pointer to the left.
            j--;
        
        // Case 3: The sum is too small.
        else // This means currentSum < x
            // To increase the sum, we must use a larger number. We move the
            // left pointer to the right.
            i++;
    }

    // If the loop finishes, it means the pointers have crossed (i >= j) and no
    // pair with the target sum was found.
    return false;
}



*/
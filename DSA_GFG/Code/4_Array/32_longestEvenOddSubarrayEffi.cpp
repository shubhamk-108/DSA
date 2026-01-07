// Our Task: Given an array a[ ] of N integers, the task is to find the length of the longest Alternating Even Odd subarray present in the array. 

// Examples: 

// Input: a[] = {1, 2, 3, 4, 5, 7, 9} 
// Output: 5 
// Explanation: 
// The subarray {1, 2, 3, 4, 5} has alternating even and odd elements.

// Input: a[] = {1, 3, 5} 
// Output: 1
// Explanation: 
// There are only odd numbers, so we can count any one of them.



#include<iostream>
#include<cmath>
using namespace std;

int longestEvenOddSubarrayCount(int arr[], int n)
{
    
    int count = 1;
    int result = 1;

    for(int i =1; i<n; i++)
    {

        if( (arr[i] % 2 == 0 && arr[i-1] %2 != 0) || (arr[i] % 2 != 0 && arr[i-1] %2 == 0))
        {
            count++;
            result = max(result, count);
           
        }
        else
            count = 1;

    }
    return result;

}

int main()
{   
    int arr[] = {1, 2, 3,3, 4, 5, 7, 9} ;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<longestEvenOddSubarrayCount(arr,n);
    return 0;
}





// Time Complexity: O(n),
// Space  : O(1)


// Logic



/*



int longestEvenOddSubarrayCount(int arr[], int n)
{
    // 'count' tracks the length of the CURRENT alternating subarray.
    // We initialize it to 1 because any single element is a valid subarray of length 1.
    int count = 1;

    // 'result' stores the MAXIMUM length found so far across the entire array.
    // It's also initialized to 1, as the minimum possible answer is 1.
    int result = 1;

    // Loop through the array starting from the second element (index 1).
    // We start at 1 so we can compare each element with the one before it (arr[i-1]).
    for(int i = 1; i < n; i++)
    {
        // Check if the current and previous elements have different parity (one is even, the other is odd).
        // This condition is true if:
        //  - The current element is even AND the previous is odd, OR
        //  - The current element is odd AND the previous is even.
        if( (arr[i] % 2 == 0 && arr[i-1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i-1] % 2 == 0) )
        {
            // If the alternating pattern continues, increment the length of the current subarray.
            count++;

            // Update the overall maximum result if the current subarray is longer than any we've seen before.
            // 'max' is a standard function that returns the larger of two values.
            result = max(result, count);
        }
        else // This 'else' block executes if the alternating pattern is broken.
        {
            // Resetting count if we dont satisfy conditions
            // If two adjacent elements are both even or both odd, the streak is over.
            // We reset the count to 1 because the new subarray starts with the current element.
            count = 1;
        }
    }

    // After checking all elements, 'result' holds the length of the longest subarray found.
    return result;
}

*/
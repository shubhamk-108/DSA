// Our Task: Given an array arr[], the task is to find the elements of a contiguous subarray of numbers that 
// has the largest sum.
// This code is also called as kadens algorithm
// Examples:


// Input: arr = [-2, -3, 4, -1, -2, 1, 5, -3]
// Output:7 
// Explanation: [4, -1, -2, 1, 5] 
// In the above input, the maximum contiguous subarray sum is 7 and the elements of the subarray are [4, -1, -2, 1, 5]


#include <iostream>
#include<cmath>
using namespace std;

int largestSubarraySum(int arr[], int n)
{
    int soFarMaxSubArrSum = arr[0];
    int finalMaxSubArrsum = arr[0];

    for(int i = 1; i<n; i++)
    {
        soFarMaxSubArrSum = max(soFarMaxSubArrSum + arr[i], arr[i]);
        finalMaxSubArrsum = max(soFarMaxSubArrSum, finalMaxSubArrsum);
    }
    return finalMaxSubArrsum;
}

 

int main()
{
    int arr[] ={-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<largestSubarraySum(arr, n);

    cout << " control ends " << " ";
    return 0;
}

// // Time complexity: O(n) 
// // Auxiliary Space: O(1)


// Logic 


/*



 The code you've provided is an implementation of Kadane's Algorithm, which is a highly efficient method for 
 finding the maximum sum of a contiguous subarray in a given array.

 int maxSum(int arr[], int n)
{
    // maxEnding stores the maximum sum of a subarray ending at the current position.
    int maxEnding = arr[0];
    
    // res stores the overall maximum sum found so far, across all subarrays.
    int res = arr[0];
    
    // We start from the second element (index 1) because the first element is already handled.
    for(int i = 1; i < n; i++)
    {
        // For each element, we make a choice:
        // 1. Either we extend the previous subarray by adding the current element (arr[i]).
        // 2. Or, we start a new subarray beginning with the current element.
        // We choose whichever option gives a larger sum.
        maxEnding = max(maxEnding + arr[i], arr[i]);
        
        // After updating the maximum sum ending at the current position,
        // we check if this new sum is greater than our overall maximum sum found so far.
        // If it is, we update our overall result.
        res = max(res, maxEnding);
    }
    
    return res;
}


*/


//---------------------------------------------------------------------------------------------------------


/*




maxEnding = max(maxEnding + arr[i], arr[i]);

This line represents the central decision of the algorithm. At each step i, we have two choices for the subarray that ends at this position:

Extend the previous best subarray: We can take the maximum subarray that ended at the previous position (i-1), which had a sum of 
maxEnding, and add the current element arr[i] to it. The new sum would be maxEnding + arr[i].

Start a new subarray: If the maximum sum of the subarray ending at the previous position (maxEnding) was negative, adding it to arr[i]
 will only decrease the value. In this case, it's better to "reset" and start a new subarray consisting only of the current element, arr[i].

By taking the max of these two options, we ensure that maxEnding always holds the largest possible sum for a subarray that concludes
 at the current position i.

The variable res is used to keep track of the overall maximum sum found anywhere in the array. After each step, we compare the 
current maxEnding with res and update res if maxEnding is larger.

Example Walkthrough
Let's trace the algorithm with the array arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}.


| i | arr\[i] | maxEnding + arr\[i] | max(maxEnding + arr\[i], arr\[i]) | maxEnding (after update) | res (after update) |
| - | ------- | ------------------- | --------------------------------- | ------------------------ | ------------------ |
| 0 | -2      | (initial)           | (initial)                         | -2                       | -2                 |
| 1 | 1       | -2 + 1 = -1         | max(-1, 1) = 1                    | 1                        | max(-2, 1) = 1     |
| 2 | -3      | 1 + (-3) = -2       | max(-2, -3) = -2                  | -2                       | max(1, -2) = 1     |
| 3 | 4       | -2 + 4 = 2          | max(2, 4) = 4                     | 4                        | max(1, 4) = 4      |
| 4 | -1      | 4 + (-1) = 3        | max(3, -1) = 3                    | 3                        | max(4, 3) = 4      |
| 5 | 2       | 3 + 2 = 5           | max(5, 2) = 5                     | 5                        | max(4, 5) = 5      |
| 6 | 1       | 5 + 1 = 6           | max(6, 1) = 6                     | 6                        | max(5, 6) = 6      |
| 7 | -5      | 6 + (-5) = 1        | max(1, -5) = 1                    | 1                        | max(6, 1) = 6      |
| 8 | 4       | 1 + 4 = 5           | max(5, 4) = 5                     | 5                        | max(6, 5) = 6      |


The loop finishes, and the function returns res, which is 6. The subarray with this sum is [4, -1, 2, 1].

This column  maxEnding (after update) is the subarray sum at contiguous location and we picked 6 from it.


*/



// Dry run for it on pen and paper you will understand
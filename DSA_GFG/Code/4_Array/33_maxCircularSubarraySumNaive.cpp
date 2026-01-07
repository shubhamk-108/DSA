// An array is called circular if we consider the first element as the next of the last element.                    
// Example: arr[ ] ={1, 2, 3} 
// The subarrays of this circular array can be: {1} {2} {3} {1, 2} {2, 3} {3, 1} {1, 2, 3} {2, 3, 1} {3, 1, 2}
// Examples: 

// Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
// Output: 22 
// Explanation: Subarray 12, 8, -8, 9, -9, 10 gives the maximum sum, that is 22.

#include <iostream>
#include <cmath>
using namespace std;

int maxCircularSubarraySum(int arr[], int n)
{
    int res = arr[0];

    for(int i =0; i<n; i++)
    {
        int currSum = arr[0];
        int currMax = arr[0];

        for(int j = 1; j<n; j++)
        {
            int index = (i+j) %n ;
            currSum += arr[j];
            currMax = max(currMax, currSum);

        }
        res = max(res, currMax);
    }
    return res;
}

int main()
{
    int arr[] = {8, -8, 9, -9, 10, -11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<maxCircularSubarraySum(arr,n);
    return 0;
}


// Time Complexity: O(n^2),
// Space  : O(1)

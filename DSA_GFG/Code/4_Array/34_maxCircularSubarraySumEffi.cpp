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


int normalMaxSum(int arr[], int n)
{
	int res = arr[0];
        
	int maxEnding = arr[0];

	for(int i = 1; i < n; i++)
	{
		maxEnding = max(maxEnding + arr[i], arr[i]);

		res = max(maxEnding, res);
	}
	
	return res;
}

int overallMaxSum(int arr[], int n)
{
	int max_normal = normalMaxSum(arr, n);

	if(max_normal < 0)
		return max_normal;

	int arr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		arr_sum += arr[i];

		arr[i] = -arr[i];
	}

	int max_circular = arr_sum + normalMaxSum(arr, n);

	return max(max_circular, max_normal);
}



int main() {
	
     int arr[] = {8, -4, 3, -5, 4}, n = 5;

     cout<<overallMaxSum(arr, n);
    
}



// Time Complexity: O(n),
// Space  : O(1)



// Logic:


/*





The goal is to find the maximum possible sum of a contiguous subarray in a circular array. This means the subarray can "wrap around" 
from the end of the array to the beginning.

The core idea is that the maximum circular subarray sum will be one of two things:

The maximum sum of a normal, non-wrapping subarray. (e.g., in [1, -2, 3, 4, -5], the max is 3+4=7).

The sum of a wrapping subarray. This is equivalent to (The total sum of the array) - (The minimum sum of a normal, non-wrapping subarray).

The code calculates both of these possibilities and returns the larger one.

Part 1: normalMaxSum - Finding the Maximum Subarray Sum (Kadane's Algorithm).
We have already seen kadens algorithm in program number 30, i guess.


int overallMaxSum(int arr[], int n)
{
    // Case 1: Calculate the max sum of a NORMAL subarray using Kadane's.
    int max_normal = normalMaxSum(arr, n);

    // This is a crucial edge case. If all numbers are negative, the max_normal
    // will be the largest (least negative) number. The circular sum calculation
    // below would give an incorrect result (0), so we return early.
    // Example: [-5, -2, -10]. max_normal is -2. That's the answer.
	// This base case is agian discussed at the end.
    if(max_normal < 0)
        return max_normal;

    // Now, we calculate the circular sum. The logic is:
    // Max Circular Sum = Total Array Sum - Minimum Normal Subarray Sum
    
    // Step A: Calculate the total array sum.
    int arr_sum = 0;
    for(int i = 0; i < n; i++)
    {
        arr_sum += arr[i];

        // Step B: Invert the sign of every element in the array.
        // This is a clever trick to find the minimum subarray sum.
        arr[i] = -arr[i];
    }

    // Step C: Find the maximum subarray sum of the INVERTED array.
    // The max sum of the inverted array is equal to the MINUS of the
    // minimum sum of the original array.
    // So, normalMaxSum(inverted_arr) = - (min_subarray_sum_of_original_arr)
    int min_subarray_sum = normalMaxSum(arr, n);

    // Step D: Calculate the max circular sum using our formula.
    // max_circular = arr_sum - (-normalMaxSum(inverted_arr))
    // max_circular = arr_sum + normalMaxSum(inverted_arr)
    int max_circular = arr_sum + min_subarray_sum;

    // The final answer is the maximum of the two cases.
    return max(max_circular, max_normal);
}


Why the Inversion Trick Works
Let's use an example to illustrate Max Circular Sum = Total Sum - Minimum Normal Sum.

Consider arr = [5, -3, -2, 5]

The wrapping subarray with the maximum sum is [5, ..., 5], which sums to 10.

The total sum of the array is 5 - 3 - 2 + 5 = 5.

The elements not part of the wrapping max sum are [-3, -2]. This is the minimum sum subarray. Its sum is -5.

Notice that: Total Sum - Minimum Sum = 5 - (-5) = 10. This matches our circular sum.

The code cleverly finds this minimum sum:

It calculates arr_sum = 5.

It inverts the array to [-5, 3, 2, -5].

It calls normalMaxSum on this inverted array. The max subarray is ``, and the sum is 5.

It calculates max_circular = arr_sum + 5 = 5 + 5 = 10.


if(max_normal < 0)
    return max_normal;

this condition will trigger if all the elements in the array are zero
Let's see what would happen without this check, using an example like arr = [-5, -2, -10].

Calculate max_normal: The normalMaxSum function (Kadane's algorithm) will correctly find the largest (least negative) subarray sum. 
In this case, the subarray is [-2], so max_normal will be -2. This is the correct final answer.

Proceed to the circular sum logic (without the edge case check):

The code calculates the total sum of the array: arr_sum = -5 + (-2) + (-10) = -17.

It then inverts every element in the array: arr becomes ``.

It calls normalMaxSum on this inverted array to find the "maximum" sum, which is a trick to find the minimum sum of the original array. 
The max subarray of `` is the entire array, so normalMaxSum returns 5 + 2 + 10 = 17.

It calculates the circular sum: max_circular = arr_sum + 17 which is -17 + 17 = 0.

Finally, it would return max(max_circular, max_normal), which is max(0, -2), giving an incorrect answer of 0.


*/
#include <bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n, int k)
{
    // Step 1: Create frequency array and initialize all values to 0.
    int frequency[k];
    for(int i = 0; i<k; i++)
    {
        frequency[i] = 0; 
    }

    // Step 2: Count the occurrences of each element in the input array.Each arr[i] is assumed to be in the range 0 to k-1
    // iterate through original array and count the frequency of each element. Write this frequency in frequency array
    for(int i = 0; i<n; i++)
    {
        frequency[arr[i]] ++; 
    }

    
    // Step 3: Compute the cumulative frequency so that frequency[i] contains the position of the last occurrence of element i in the sorted array.
    // now find the cumularive frequency and override the same frequency array. Try dry run to understand better
    for(int i = 1; i<k; i++)
    {
        frequency[i] = frequency[i-1] + frequency[i] ; 
    }

    //Step 4: Build the output array by placing elements at their correct positions.
    // Traverse input array from right to left to maintain stability.
    // create a output array and traverse from right side and put the element from arr by accessing the position from the frequency array.
    // do -1 from position because if position is 4 then index will be 3.
    int output[n];
    for(int i =n-1; i>=0; i--)
    {
        // / Place arr[i] in the correct position in output array
        output[frequency[arr[i]] - 1 ] = arr[i];

        // Decrement the cumulative frequency
        // If you missed updating the cumulative frequency after placing the element, Without frequency[arr[i]]--, repeated values will 
        // overwrite the same index.
        frequency[arr[i]]--;
    }

    // / Step 5: Copy the sorted result back into the original array.
    for(int i = 0; i<n; i++)
    {
        arr[i] = output[i]; 
    }
}



int main()
{
    int arr[] = {1, 4, 4, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    countSort(arr, n, k);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}



// time and space

// Time Complexity : O(n + k)
// Where:
// n is the number of elements in the input array
// k is the range of input values (max value + 1, if values start from 0)
// Breakdown of operations:
// Initializing the frequency/count array: O(k)
// Counting occurrences: O(n)
// Building cumulative frequency: O(k)
// Building the output array: O(n)
// Copying output back: O(n)
// Total = O(k) + O(n) + O(k) + O(n) + O(n) = O(n + k)
// Best Case:
// If k is much smaller than n (k ≪ n) → time complexity is nearly linear, O(n).
// Worst Case:
// If k is much larger than n (for example, n=10, k=1000000), the time is dominated by k (O(n + k)), so counting sort can become inefficient
//  when k is huge compared to n.

// Space Complexity : O(n + k)
// Why:
// Output array: O(n)
// Frequency array: O(k)
// Thus, total additional space needed = O(n + k)


// --------------------------------------------------------------------------------------

/*



// Some important points to understand better. In addition to above comments


void countSort(int arr[], int n, int k)
{
    
    int frequency[k];
    for(int i = 0; i<k; i++)
    {
        frequency[i] = 0; 
    }

    // here indices will act as a element
    for(int i = 0; i<n; i++)
    {
        frequency[arr[i]] ++; 
    }

    
    for(int i = 1; i<k; i++)
    {
        frequency[i] = frequency[i-1] + frequency[i] ; 
    }


    int output[n];
    // why we are traversing from last element because we have the position stroed in our cumulative array. like for example
    // {1,3,6,6,6,7,7} Now take this 3. 3 is at index 1. Means element 1 occurs at position 3 means index will be 3-1 = 2.
    // so if we traverse from right side we can easily put our element at index 2 or position 3 and then we decrement the frequency count.
    // Now if there are duplicate elements then next element will be placed at position 2 means index 1. Try dry run for better understanding.
    for(int i =n-1; i>=0; i--)
    {
        output[frequency[arr[i]] - 1 ] = arr[i];

        frequency[arr[i]]--;
    }

    for(int i = 0; i<n; i++)
    {
        arr[i] = output[i]; 
    }
}



*/




// --------------------------------------------------------------------------------------


// dry run 




/*




Input
Suppose arr[] = {2, 5, 3, 0, 2, 3, 0, 3}
Let n = 8 (number of elements)
Let k = 6 (range is 0 to 5 because max element is 5)

Step 1: Initialize frequency array
text
frequency = [0, 0, 0, 0, 0, 0]
Step 2: Count occurrences
Loop through arr:

arr=2 → frequency++

arr=5 → frequency++

arr=3 → frequency++

arr=0 → frequency++

arr=2 → frequency++

arr=3 → frequency++

arr=0 → frequency++

arr=3 → frequency++

Result:

text
frequency = [2, 0, 2, 3, 0, 1]
Step 3: Cumulative frequency
For i from 1 to 5:

i=1: frequency=frequency+frequency=0+2=2

i=2: frequency=frequency+frequency=2+2=4

i=3: frequency=frequency+frequency=3+4=7

i=4: frequency=frequency+frequency=0+7=7

i=5: frequency=frequency+frequency=1+7=8

Result:

text
frequency = [2, 2, 4, 7, 7, 8]
Step 4: Build output array (traverse from right to left)
Output array is size 8: output = [,,,,,,,]

Start from arr=3, go backwards:

arr=3: Place at index frequency-1=7-1=6 → output=3; frequency--

arr=0: Place at index frequency-1=2-1=1 → output=0; frequency--

arr=3: Place at index frequency-1=6-1=5 → output=3; frequency--

arr=2: Place at index frequency-1=4-1=3 → output=2; frequency--

arr=0: Place at index frequency-1=1-1=0 → output=0; frequency--

arr=3: Place at index frequency-1=5-1=4 → output=3; frequency--

arr=5: Place at index frequency-1=8-1=7 → output=5; frequency--

arr=2: Place at index frequency-1=3-1=2 → output=2; frequency--

Result:

text
output = [0, 0, 2, 2, 3, 3, 3, 5]
Step 5: Copy output to arr
After copying:
arr[] = [0, 0, 2, 2, 3, 3, 3, 5]

Result: The sorted output is [0, 0, 2, 2, 3, 3, 3, 5]





*/
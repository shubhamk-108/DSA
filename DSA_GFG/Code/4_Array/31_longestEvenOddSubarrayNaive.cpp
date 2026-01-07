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
    
    int result = 1;

    for(int i =0; i<n; i++)
    {

        int count = 1;
        for(int j = i+1; j<n; j++)
        {
            if( (arr[j] % 2 == 0 && arr[j-1] %2 != 0) || (arr[j] % 2 != 0 && arr[j-1] %2 == 0))
            {
                count++;
            }
            else
                break;
        }
        result = max(result, count);
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
// Time Complexity: O(n^2),
// Space  : O(1)


// Pair with given sum in unsorted array 

/*
Sample 1 (Pair Found)
Input Array: [8, 7, 2, 5, 3, 1]
Given Sum: 10
Reasoning: The pairs (8, 2) and (7, 3) both add up to 10. Since at least one pair exists, the condition is met.
Output: true

Sample 2 (Pair Not Found)
Input Array: [5, 2, 6, 8, 1, 9]
Given Sum: 12
Reasoning: No two numbers in this array add up to 12. For example, 5+2=7, 5+6=11, 9+2=11, 9+1=10, etc. After checking all
combinations, none equal 12.
Output: false

*/


#include <iostream>
using namespace std;

bool pairWithGivenSum(int arr[], int n, int sum)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n ; j++)
        {
            if(arr[i]+arr[j] == sum)
                return true;
        }
    }
    return false;
}

int main()
{
    int arr1[] = {1,6, 2, 7, 8, 15, 15};
    
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 15;

    cout<< pairWithGivenSum(arr1, n, sum);

    return 0;
}



// time and space
// Time Complexity: O(n²)
// Space Complexity: O(1)

// logic

/*


#include <iostream>
using namespace std;

// This function checks if there exists a pair of elements in an unsorted array
// whose sum is equal to a given value. It returns true if a pair is found, otherwise false.
// This is a brute-force approach using nested loops.
bool pairWithGivenSum(int arr[], int n, int sum)
{
    // The outer loop picks the first element of the potential pair.
    // It iterates from the beginning of the array.
    for (int i = 0; i < n; i++)
    {
        // The inner loop picks the second element of the potential pair.
        // It starts from 'i + 1' to ensure that:
        // 1. We don't pair an element with itself.
        // 2. We don't check the same pair twice (e.g., arr[1]+arr[3] and arr[3]+arr[1]).
        for (int j = i + 1; j < n; j++)
        {
            // Check if the sum of the current pair equals the target sum.
            if (arr[i] + arr[j] == sum)
            {
                // If a pair is found, we don't need to look any further.
                // We can immediately return true.
                return true;
            }
        }
    }

    // If the loops complete without finding any pair, it means no such pair exists.
    // We can then return false.
    return false;
}



*/
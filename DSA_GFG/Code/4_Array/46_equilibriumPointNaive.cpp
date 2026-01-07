// Our Task: Given a sequence arr[ ] of size n, Write a function int equilibrium(int[] arr, int n) that returns an equilibrium index 
// (if any) or -1 if no equilibrium index exists. 

// What is an Equilibrium Point?
// The equilibrium index of an array is an index such that the sum of elements at lower indexes (left side) is equal to the sum of 
// elements at higher indexes (right side). 

// Input: A[] = {-7, 1, 5, 2, -4, 3, 0} 
// Output: 3 //index of 2
// 3 is an equilibrium index, because: 
// A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

 

// Input: A[] = {1, 2, 3} 
// Output: -1 

// Input : {4, 2, -2}
// Output : 4
// Explanation: The left side of first index is considered as 0. That is we are considering there is 0 at the left of 4.
// so 4 is equilibrium because left of 4 is 0 and right of 4, sum is 0 ( 2 + (-2) ) 

#include <iostream>
#include <vector>

using namespace std;

int equilibriumPoint(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int left_sum = 0;

        for(int j = 0; j<i; j++)
        {
            left_sum += arr[j];
        }
        int right_sum = 0;

        for(int j = i+1; j<n; j++)
        {
            right_sum += arr[j];
        }

        if(left_sum == right_sum )
            return i;
    }

    return -1;
}

int main() {
    
    int arr[] = {-7, 1, 5, 2, -4, 3, 0} ;
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<equilibriumPoint(arr,n);

    return 0;
}




// Time Complexity: O(n2)
// Auxiliary Space: O(1) 


// The logic

// Iterate through every element of the array using an outer loop. Let's say the current index is i.

// For each i, treat it as a potential equilibrium point.

// Calculate the sum of all elements to the left of i (from index 0 to i-1).

// Calculate the sum of all elements to the right of i (from index i+1 to the end of the array).

// If the left sum equals the right sum, then i is an equilibrium point, and we can return it.

// If the outer loop finishes without finding any such point, it means no equilibrium point exists, and we can return -1.
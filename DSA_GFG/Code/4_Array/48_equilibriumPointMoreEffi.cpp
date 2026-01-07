// Our Task: Given a sequence arr[ ] of size n, Write a function int equilibrium(int[] arr, int n) that returns an equilibrium index 
// (if any) or -1 if no equilibrium index exists. 

// What is an Equilibrium Point?
// The equilibrium index of an array is an index such that the sum of elements at lower indexes(left side) is equal to the sum of elements at higher indexes(right side). 

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

using namespace std;    

int equilibriumPoint(int arr[], int n)
{
    if (n == 0)
        return -1;

    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }


    int left_sum = 0;
    int right_sum = total_sum;

    for (int j = 0; j < n; j++)
    {
        right_sum -= arr[j];

        if (right_sum == left_sum)
            return j;

        left_sum += arr[j];
    }

    return -1;
}

int main()
{

    int arr[] = {-7, 1, 5, 2, -4, 3, 0} ;
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<equilibriumPoint(arr,n);

    return 0;
}




// Time Complexity: O(n)
// Auxiliary Space: O(1) 



// Logic


/*



#include <iostream>

// Note: The <vector> header from the previous code is not needed here
// as we are not using std::vector.

// Use the standard namespace to avoid writing std:: before every standard function.
using namespace std;


int equilibriumPoint(int arr[], int n)
{
    // If the array is empty, there is no equilibrium point.
    if (n == 0)
        return -1;

    // --- Step 1: Calculate the sum of all elements in the array ---
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    // --- Step 2: Initialize sums for the iteration ---
    int left_sum = 0;      // This will store the sum of elements to the left of the current index.
    int right_sum = total_sum; // Initially, right_sum is the total sum of the array.

    // --- Step 3: Iterate through the array to find the equilibrium point ---
    // Loop through each element, considering it as a potential equilibrium point.
    for (int j = 0; j < n; j++)
    {
        // For the current index 'j', the sum of elements to its right is
        // the total_sum minus all elements up to and including 'j'.
        // We update right_sum by subtracting the current element.
        right_sum -= arr[j];

        // Check if the sum of elements on the left equals the sum on the right.
        // At this point, left_sum contains the sum of elements before 'j',
        // and right_sum contains the sum of elements after 'j'.
        if (right_sum == left_sum)
            return j; // If they are equal, 'j' is the equilibrium point.

        // IMPORTANT: Update left_sum for the *next* iteration.
        // The current element arr[j] will be part of the left_sum for the next index (j+1).
        left_sum += arr[j];
    }

    // If the loop completes without finding an equilibrium point, return -1.
    return -1;
}






*/
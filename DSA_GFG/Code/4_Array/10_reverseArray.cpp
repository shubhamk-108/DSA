#include<iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
    int low = 0;
    int high = n-1;
    int temp;

    while (low<high)
    {   
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        low++;
        high--;
    }
    
}

// using for loop

// void reverseArray(int arr[], int n)
// {
//     for(int i = 0; i < n / 2; i++)
//     {
//         int temp = arr[i];
//         arr[i] = arr[n - 1 - i];
//         arr[n - 1 - i] = temp;
//     }
// }


int main()
{
    int arr[]={4,2,66,34,90};
    int n = 5;
    reverseArray(arr,n);
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

// time: O(n)
// 2. Space Complexity
// Case 1: Reversing in-place (typical)
// No extra array or data structure used.
// Just a few variables (i, maybe temp for swapping).
// Space Complexity = O(1)

// Question:  here we are not passing array by reference then how it is reflecting in memory
// The answer:
// In C++, when you pass an array to a function, you're actually passing a pointer to its first element. That means:
// void reverseArray(int arr[], int n)
// is equivalent to:
// void reverseArray(int* arr, int n)
// So even though you're not using an explicit reference (&), you're still passing the address of the array, and any modification you make to the array elements affects the original array in memory.

// Question
// is it the same with vectors
// ans
// No, vectors are not the same as arrays in this regard.
// When you pass a std::vector<T> to a function by value, the entire vector is copied. Any changes you make will not affect the original vector.
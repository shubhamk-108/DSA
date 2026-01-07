#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int minn = i;

        for(int j = i+1; j<n;j++)
        {
            if(arr[j] < arr[minn])
                minn = j;
        }
        swap(arr[i], arr[minn]);
    }
}

int main()
{
    int a[] = {2, 1, 3, 4};
    selectionSort(a, 4);
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}   

// Time Complexity: O (n²)
// Space Complexity: O(1)

// logic



// The algorithm works as follows :
// Find the Minimum: The algorithm starts at the first element and scans the entire unsorted part of the array to find the smallest element.
// Swap: It then swaps this smallest element with the first element of the unsorted part. This action places the smallest element in its 
// correct final position

/*


// A standard function to swap two integer values.
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform selection sort on an array.
void selectionSort(int arr[], int n) {
    // The outer loop iterates from the first to the second-to-last element.
    // i represents the boundary between the sorted and unsorted parts of the array.
    for (int i = 0; i < n - 1; i++) {
        // Assume the first element of the unsorted part is the minimum.
        // min_index will hold the INDEX of the smallest element found.
        int min_index = i;

        // The inner loop iterates through the rest of the unsorted part of the array.
        for (int j = i + 1; j < n; j++) {
            // Compare the current element with the element at the current minimum index.
            // If we find a new smaller element, update the minimum index.
            if (arr[j] < arr[min_index]) {
                min_index = j; // This is the corrected line.
            }
        }

        // After the inner loop, min_index holds the position of the smallest element.
        // Swap it with the element at the beginning of the unsorted part (at index i).
        swap(arr[i], arr[min_index]);
    }
}




*/
#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int low, int high)
{
    int i = low -1 ;
    // we assumed that pivot is always the last element that is high
    int pivot = arr[high];

    for(int j = low ; j< high; j++)
    {
        if(arr[j] < pivot )
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}




int main()
{

    int arr[] = {10,80,30,90,40,50,70};

    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n-1;

    lomutoPartition(arr, low, high);

    for (int x : arr)
        cout << x << " ";
}


// time:
// space:

//time complexity of O(n) and a space complexity of O(1).



// logic


/*

TO understand code you should dry run it.

// there will be two windows. One for smaller elements and one for larger elements. i will cover the smaller elements' window. 
// initially i will point to -1 because there are no element in the window at the start.

 * @brief Partitions a subarray using the Lomuto partition scheme.
 * 
 * This function takes the last element as the pivot, places the pivot element at
 * its correct position in the sorted array, and puts all smaller elements to the
 * left of the pivot and all greater elements to the right.
 * 
 * @param arr The array to be partitioned.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 * @return The final index of the pivot element after partitioning.
 
int lomutoPartition(int arr[], int low, int high)
{
    // i is the index of the last element in the "smaller than pivot" window.
    // It starts at one less than the beginning of the array.
    int i = low - 1; 
    
    // The pivot element is the last element of the subarray.
    int pivot_value = arr[high]; // Storing the value is fine for comparison

    // Iterate through the array from the start up to the element before the pivot.
    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than the pivot...
        if (arr[j] < pivot_value)
        {
            // ...increment i to expand the window for smaller elements...
            i++;
            // ...and swap the current element into that window.
            swap(arr[i], arr[j]);
        }
    }

    // After the loop, the correct position for the pivot is i + 1.
    // Swap the pivot (which is still at arr[high]) into its correct place.
    // This is the corrected swap operation.
    swap(arr[i + 1], arr[high]);
    
    // Return the final index of the pivot. This is essential for Quicksort.
    return (i + 1);
}



*/
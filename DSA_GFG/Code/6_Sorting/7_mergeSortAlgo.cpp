#include <iostream>
#include <algorithm>
using namespace std;

void mergeTwoArrays(int arr[], int low, int mid, int high)
{
    
    int n1= mid-low + 1;
    int n2 = high - mid;

    int left_arr[n1];
    int right_arr[n2];


    for(int i =0; i<n1; i++)
    {
        left_arr[i] = arr[low + i];
    }
    for(int i =0; i<n2; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0; 
    int j = 0;
    int k = low;

    while(i<n1 && j < n2)
    {   
        if(left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else // if(right_arr[j] < left_arr[i])
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if(right > left)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        mergeTwoArrays(arr,left, mid, right);
    }
}

int main()
{

    int a[] = {10, 5, 30, 15, 7};
    int left = 0, right = 4;

    mergeSort(a, left, right);
    for (int x : a)
        cout << x << " ";
}


// Time Complexity: O(n log n)

// The algorithm consistently divides the array into halves, which results in log n levels of recursion.
// At each level of recursion, the mergeTwoArrays function processes every element of the array once, which takes O(n) time.
// The total time is the work at each level (O(n)) multiplied by the number of levels (O(log n)), giving a total time complexity 
// of O(n log n) in all cases (best, average, and worst).

// Space Complexity: O(n)

// The primary consumer of space is the mergeTwoArrays function, which creates temporary arrays (left_arr and right_arr) to hold 
// the subarrays being merged.
// Therefore, the space complexity is O(n) because it requires auxiliary space proportional to the size of the input array.



// logic:


// Merge Sort is a highly efficient, comparison-based sorting algorithm that operates on the divide-and-conquer principle. The process can be
// broken down into three main steps :

// Divide: The algorithm starts by splitting the input array into two equal halves. It then recursively calls itself on each of these halves, 
// continuing to split them until it has many small subarrays, each containing only a single element. By definition, an array with one element 
// is already sorted.

// Conquer: This is the "base case" of the recursion. Since the single-element arrays are already sorted, no further work is needed at this stage.

// Combine (Merge): The algorithm then begins to merge the smaller, sorted subarrays back together. It takes two adjacent sorted subarrays and 
// combines them into a single, larger sorted array. This merging process continues up the chain of recursion until the entire original array is 
// reassembled in a fully sorted order.

// The key to the algorithm's effectiveness lies in the merge step, which can efficiently combine two already-sorted lists in linear time.




/*



mergeTwoArrays() this function is already code and explained in previous file no 6.

 This function recursively divides the array into two halves, sorts them,

void mergeSort(int arr[], int left, int right)
{
    // Base case for recursion: if the segment has 1 or 0 elements, it's already sorted.
    if (right > left)
    {
        // Calculate the middle point to divide the array into two halves.
        // Using `left + (right - left) / 2` prevents potential overflow for very large arrays.
        int mid = left + (right - left) / 2;

        // --- Divide Step ---
        // Recursively call mergeSort for the first half.
        mergeSort(arr, left, mid);
        // Recursively call mergeSort for the second half.
        mergeSort(arr, mid + 1, right);

        // --- Conquer (Combine) Step ---
        // Merge the two sorted halves.
        mergeTwoArrays(arr, left, mid, right);
    }
}


*/
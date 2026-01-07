#include<iostream>
#include<algorithm>
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


int main()
{

    int a[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
    int low = 0, high = 8, mid = 3;

    mergeTwoArrays(a, low, mid, high);
    for (int x : a)
        cout << x << " ";
}


// time  : O(n)
// space : O(n)


// logic 


/*



 * @brief Merges two sorted subarrays of a single array.
 * 
 * This function assumes that the subarrays arr[low...mid] and arr[mid+1...high]
 * are already sorted. It merges them into a single sorted subarray arr[low...high].
 * This is a standard helper function used in the Merge Sort algorithm.
 * 
 * @param arr The array containing the subarrays to merge.
 * @param low The starting index of the first subarray.
 * @param mid The ending index of the first subarray.
 * @param high The ending index of the second subarray.
 

void mergeTwoArrays(int arr[], int low, int mid, int high)
{
    // Calculate the sizes of the two subarrays to be merged.
    int n1 = mid - low + 1; // Size of the left subarray: arr[low...mid]
    int n2 = high - mid;    // Size of the right subarray: arr[mid+1...high]

    // Create temporary arrays to hold the data of the two subarrays.
    // Note: Variable Length Arrays (VLAs) like this are a non-standard C++ extension.
    // In standard C++, it's better to use std::vector<int> left_arr(n1);
    int left_arr[n1];
    int right_arr[n2];

    // --- Step 1: Copy data to temporary arrays ---
    
    // Copy elements from the main array's left part into the temporary left_arr.
    for (int i = 0; i < n1; i++)
    {
        left_arr[i] = arr[low + i];
    }
    // Copy elements from the main array's right part into the temporary right_arr.
    for (int i = 0; i < n2; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    // --- Step 2: Merge the temporary arrays back into the main array ---

    // Initialize indices for the temporary arrays and the main array.
    int i = 0;      // Initial index for  the temporary left_arr
    int j = 0;      // Initial index for the temporary right_arr
    int k = low;    // Initial index for the merged subarray in the original arr
    The index k is initialized to low instead of 0 because the function is designed to merge a specific segment of a larger array, 
    not always the entire array starting from index 0.

    // Merge the elements back into arr[low...high] in sorted order.
    while (i < n1 && j < n2)
    {
        // Compare elements and place the smaller one into the main array.
        // Using <= instead of < would make the sort stable.
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else // right_arr[j] < left_arr[i]
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++; // Move to the next position in the main array.
    }

    // --- Step 3: Copy any remaining elements ---
    // If one of the temporary arrays is exhausted, copy the rest of the other array.
    // Only one of these two loops will execute.

    // Copy the remaining elements of left_arr, if there are any.
    while (i < n1)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }

    // Copy the remaining elements of right_arr, if there are any.
    while (j < n2)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
}


int main()
{
    // The test array is specifically set up to have two sorted halves:
    // First sorted half: {10, 15, 20, 40} -> from index 0 to 3 (mid)
    // Second sorted half: {8, 11, 15, 22, 25} -> from index 4 to 8 (high)
    int a[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
    int low = 0, high = 8, mid = 3;

    // Call the merge function on the array 'a'.
    mergeTwoArrays(a, low, mid, high);

    // Print the array to verify that it has been correctly merged.
    // Expected output: 8 10 11 15 15 20 22 25 40
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl; // Add a newline for clean output.
    
    return 0;
}




*/
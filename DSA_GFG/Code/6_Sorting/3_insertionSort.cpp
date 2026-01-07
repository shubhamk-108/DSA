#include<iostream>
using namespace std;


void insertionSort(int arr[], int n)
{
    for(int i = 1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {3,5,1,22,4};  
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

    for(auto x: arr)
        cout<<x<<" ";
    return 0;
}






// time: worst case : O(n^2)
// time : best case : O(n). When array is already sorted
// space : O(1)


// logic


// algorithm works by dividing the array into a sorted and an unsorted region. Initially, the sorted region contains only the first 
// element of the array. The algorithm then iterates through the unsorted region, taking one element at a time (the key) and inserting 
// it into its correct position within the sorted region .

// To insert the key, it is compared with the elements in the sorted region, moving from right to left. Elements in the sorted region 
// that are greater than the key are shifted one position to the right to make space. This process continues until an element smaller 
// than or equal to the key is found, or the beginning of the array is reached. The key is then placed in the newly created space .




/*



// Function to sort an array of integers using insertion sort
void insertionSort(int arr[], int n) 
{
    // Start from the second element (index 1) as the first element is already "sorted" by itself.
    for (int i = 1; i < n; i++) 
    {
        // Select the element to be inserted into the sorted portion of the array.
        // the reason that we dont directly compare with arr[i], we do it using key because 
        // the value at arr[i] itself can be overwritten during the shifting process before it is correctly placed.
        // this can be understand better when we dry run
        int key = arr[i];
        
        // Initialize j to the last index of the sorted portion.
        int j = i - 1;

        // Move elements of the sorted portion (arr[0..i-1]) that are greater than the key
        // to one position ahead of their current position.
        // This loop shifts elements to the right to make space for the key.
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j]; // Shift the element to the right.
            j--;                 // Move to the next element on the left.
        }
        
        // Place the key at its correct sorted position.
        // j is now at the index of the first element that is not greater than key,
        // so j+1 is the correct spot.
        arr[j + 1] = key;
    }
}



*/
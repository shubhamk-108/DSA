// This is not the actual cycle sort algo although it is a variation of cycle sort but this is very very simple appraoch and works
// under specific constraints only.
// The more general-purpose cycle sort algorithm that works on any array  is optimized to minimize the number of writes to memory. See the in 
// // next file
// Your Algorithm (Cyclic Sort): Is a specialized, fast, and intuitive method that works only when the input array contains a permutation of 
// numbers from 1 to n. 

// Constraint: The input array must contain a permutation of numbers from 1 to n. It will fail or cause errors if there are duplicates,
// negative numbers, or numbers greater than n.

#include<iostream>                        
#include<algorithm>
using namespace std;


void cycleSort(int arr[], int n)
{
    int i = 0;
    
    while(i<n)
    {
        int correct_idx_for_that_element = arr[i] - 1;

        // if the element is not at the correct index thens
        if(arr[i] != arr[correct_idx_for_that_element])
        {
            swap(arr[i], arr[correct_idx_for_that_element]);
            // after this we dont increment i because we dont know that newly swapped element is truely belongs to this index or not
        }
        else // element is already at correct index then increment i because we have to check for next element
            i++;
    }
}

int main()
{
    int arr[] = {3,5,1,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cycleSort(arr,n);

    for(auto x: arr)
        cout<<x<<" ";
    
    return 0;
}


// time : O(n)
// space : O(1)


// logic


/*




 * @brief Sorts an array containing a permutation of numbers from 1 to n.
 * 
 * This function implements the Cyclic Sort algorithm, which is an efficient,
 * in-place sorting method specifically for arrays where elements are in the
 * range [1, n] and there are no duplicates.
 * 
 * The main idea is to iterate through the array and place each element
 * at its correct index. The correct index for a number 'x' is 'x - 1'.
 * 
 * @param arr The integer array to be sorted.
 * @param n The size of the array.
 
void cycleSort(int arr[], int n)
{
    // Start an index 'i' to iterate through the array.
    int i = 0;
    
    // The loop continues until we have checked every position.
    while(i < n)
    {
        // For an array with numbers from 1 to n, the element 'x' should
        // be at index 'x - 1'. Calculate the correct index for the current element.
        int correct_idx_for_that_element = arr[i] - 1;

        // Check if the current element arr[i] is already at its correct position.
        // The condition `arr[i] != arr[correct_idx_for_that_element]` is a robust
        // way to check this. It's equivalent to `arr[i] != i + 1` but also
        // handles unsorted values at the destination index correctly.
        if(arr[i] != arr[correct_idx_for_that_element])
        {
            // If the element is not at its correct index, swap it with the
            // element at its correct destination.
            swap(arr[i], arr[correct_idx_for_that_element]);
            
            // IMPORTANT: We do NOT increment 'i' here. After the swap, a new
            // element is now at arr[i]. We must re-evaluate this new element
            // in the next iteration of the loop to see if it's in the right place.
        }
        else 
        {
            // If the element at arr[i] is already in its correct spot,
            // we can move on to check the next element in the array.
            i++;
        }
    }
}

int main()
{
    // Example array containing a permutation of numbers from 1 to 5.
    int arr[] = {3, 5, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the sorting function.
    cycleSort(arr, n);

    // Print the sorted array to verify the result.
    for(auto x: arr)
        cout << x << " "; // Expected output: 1 2 3 4 5
    
    return 0;
}




*/
// Length of Longest Consecutive Subsequence. Elements can appear in any order. And elements are scattered all over the arry meaning
// {5,77,4} here longest sequencef is 2 even though there are 77 placed in between 5 and 4.
// {1,9,3,4,2,20} op = 4. explanation: 1,3,4,2 They are consecutive. Order does not matter.

// {20,30,40} op = 1

#include <iostream>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(int arr[], int n)
{
    if (n == 0)
        return 0;

    sort(arr, arr + n);

    int longest = 1;
    int current = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            // Consecutive element found, extend the current sequence.
            current++;
        }
        else if (arr[i] != arr[i - 1])
        {
            // Sequence is broken, update longest and reset current.
            longest = max(longest, current);
            current = 1;
        }
        else if( arr[i] == arr[i-1] ) // (duplicate), do nothing.
            continue;
    }

    // Final check in case the longest sequence was at the end.
    return max(longest, current);
}

int main()
{
    int arr[] = {5, 6, 1, 2, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestConsecutiveSequence(arr, n);

    return 0;
}


/*
Time Complexity: O(n log n)
sorting: nlog(n) and one O(n) linear traversal

space : 
Space Complexity: O(1) or O(log n)
You are not using any auxiliary data structures like new arrays or maps that scale with the size of the input. You are only using a few integer 
variables (longest, current), which take up constant space.
Therefore, the space complexity is often considered O(1) (constant space).
Note: Purists might argue that the std::sort function itself can use a small amount of stack space for recursion (in the case of QuickSort 
or MergeSort), which can be up to O(log n). However, for most practical interview purposes, an in-place sort is treated as O(1) space.
*/



// logic


/*



 * @brief Finds the length of the longest consecutive sequence of elements in an array.
 * 
 * @param arr The input array of integers.
 * @param n The size of the array.
 * @return int The length of the longest consecutive sequence.
 * 
 * This approach works by first sorting the array. Sorting places elements
 * that could be part of a sequence next to each other, making them easy to count.
 * The time complexity is dominated by the sort, making it O(n log n).
 * The space complexity is O(1) as we modify the array in-place.
 
int longestConsecutiveSequence_alternative(int arr[], int n)
{
    // --- Step 1: Handle Edge Cases ---
    // If the array is empty, there are no elements to form a sequence.
    // So, the longest sequence length is 0.
    if (n == 0)
    {
        return 0;
    }

    // --- Step 2: Pre-processing ---
    // Sort the array in ascending order. This is the key to this approach.
    // Example: {100, 4, 200, 1, 3, 2} becomes {1, 2, 3, 4, 100, 200}
    // Now, we can just iterate through it once to find sequences.
    sort(arr, arr + n);

    // --- Step 3: Initialization ---
    // 'longest' will store our final answer. We initialize it to 1 because
    // any single element is itself a consecutive sequence of length 1.
    // This also handles the case of an array with one element, e.g., {10}.
    int longest = 1;

    // 'current' tracks the length of the sequence we are currently building.
    // It also starts at 1.
    int current = 1;

    // --- Step 4: The Main Logic ---
    // We loop from the second element (index 1) to the end of the array.
    // We do this because we need to compare each element `arr[i]` with the one before it `arr[i-1]`.
    for (int i = 1; i < n; i++)
    {
        // --- CASE A: We found the next number in our sequence ---
        // Example: We just saw a 3 (arr[i-1]) and now we see a 4 (arr[i]).
        if (arr[i] == arr[i - 1] + 1)
        {
            // Since this element extends our current sequence, we increment the 'current' counter.
            current++;
        }
        // --- CASE B: The sequence is broken ---
        // This condition triggers if `arr[i]` is NOT a duplicate of `arr[i-1]`.
        // Because the first 'if' failed, we also know it's NOT consecutive.
        // Example: We just saw a 4 (arr[i-1]) and now we see a 100 (arr[i]). The sequence {1,2,3,4} is over.
        else if (arr[i] != arr[i - 1])
        {
            // The sequence we were building has just ended. Before we move on,
            // we must check if it was the longest one we've seen so far.
            // We update 'longest' to be the maximum of its current value and the 'current' sequence length.
            longest = max(longest, current);

            // Now, we reset 'current' to 1. This is because the new element `arr[i]`
            // is the start of a brand new potential sequence of length 1.
            current = 1;
        }
        // --- CASE C (Implicit): The element is a duplicate ---
        // Example: We just saw a 3 (arr[i-1]) and now we see another 3 (arr[i]).
        // If the first 'if' is false and the 'else if' is false, it MUST mean that `arr[i] == arr[i-1]`.
        // In this case, we do nothing. The sequence is not broken, but it's not extended either.
        // We just ignore the duplicate and let the loop continue to the next element.
    }

    // --- Step 5: Final Check ---
    // The loop only updates 'longest' when a sequence *breaks*. But what if the
    // longest sequence is at the very end of the array?
    // Example: {1, 2, 5, 6, 7}. The loop finishes with `current` = 3 (for {5,6,7})
    // but `longest` is still 2 (from {1,2}). `longest` was never updated for the last sequence.
    // This final comparison ensures we capture the length of the last sequence as well.
    return max(longest, current);
}



*/


// Question and answer 

/*
Question:
how sorting is using log(n) space . we hava to store all elements . so shouldnt it ne O(n)


Answer:

You are correct that the array itself takes up O(n) space to store all the elements. However, when we analyze the space complexity of an 
algorithm, we are usually talking about the auxiliary space (or "extra space") that the algorithm needs in addition to the space taken by 
the input itself.

The "In-Place" Concept
The sorting approach is what we call an "in-place" algorithm. This means it rearranges the elements directly within the original array 
without creating a separate, new array of size O(n) to do its work.

Let's compare two types of sorting algorithms:

1. In-Place Sorts (like HeapSort, most QuickSorts)
How they work: They shuffle elements around within the original array. For example, they might swap arr[i] with arr[j].

Auxiliary Space: They only need a few extra variables to keep track of indices, pivots, or temporary values during swaps. This amount of 
extra space does not grow as the array gets bigger.

This is why we say they have O(1) space complexity. They don't need a whole new copy of the data.

2. Out-of-Place Sorts (like MergeSort)
How they work: MergeSort, for example, works by breaking the array into halves, sorting them, and then merging them back together. To do
the "merge" step efficiently, it needs to create temporary arrays to hold the sorted halves.

Auxiliary Space: These temporary arrays can be as large as the original input.

This is why MergeSort has O(n) space complexity. It needs extra space proportional to the input size.

*/
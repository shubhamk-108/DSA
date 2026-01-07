// Our Task: Given two arrays L[ ] and R[ ] of size N where L[i] and R[i] (0 ? L[i], R[i] < 106) denotes a range of numbers,
//  the task is to find the maximum occurred integer in all the ranges. If more than one such integer exists, print the smallest one. 

//  Input: L[ ] = {1, 4, 3, 1}, R[ ] = {15, 8, 5, 4}
// Output: 4

// Explanation: 
// L[0] is left index of range_1 and R[0] is right index of range_1. So we get numbers from 1 to 15. {1,2,3,4,5,6,7,8,9,10,11,12,13,14 15}
// L[1] is left index of range_2 and R[1] is right index of range_2. So we get numbers from 1 to 15. {4,5,6,7,8}
// Similarly we get other ranges:
// {3,4,5}, 
// {1,2,3,4}. 

// And 4 is the element which is appearing maximum times (because it is present in all the ranges)

#include<iostream>
#include<vector>
using namespace std;


int maxAppearingElement(int L[], int R[], int n)
{
    const int max_range = 1000000;
    // int freq[max_range] = {0};  // problem discussed below. Stack Overflow. Use heap. SO we used vector. Vector manage memory efficiently
     vector<int> freq(max_range, 0);

    for(int i = 0; i< n ; i++)
    {
        for(int j = L[i]; j<= R[i] ; j++)
        {
            freq[j]++;
        }
        
    }

    int max_element = -1;
    int max_element_index = -1;

    for(int i = 0; i< max_range ; i++)
    {
        if(freq[i] > max_element)
        {
            max_element = freq[i];
            max_element_index = i;
        }
    }

    return max_element_index; 

}


int main() {
    // Example Input from the problem description
    int L[] = {1, 4, 3, 1};
    int R[] = {15, 8, 5, 4};
    int N = sizeof(L) / sizeof(L[0]);

    // Call the function to get the result
    int result = maxAppearingElement(L, R, N);

    // Print the result
    // Expected output is 4
    std::cout << "The maximum appearing element is: " << result << std::endl;

    return 0;
}


// Time Complexity: O(N*M). Here N is the number of ranges and M is the maximum number of elements in any of the ranges.
// Auxiliary Space: O(M). For Hash table.



// Logic




/* 



int maxAppearingElement(int L[], int R[], int n)
{
    // Define the maximum possible value for an element in the ranges + 1.
    // Based on problem constraints (0 <= L[i], R[i] < 10^6).
    const int max_range = 1000000;

    // --- Step 1: Create a frequency array ---
    // We use std::vector instead of a C-style array `int freq[max_range]` to avoid a stack overflow.
    // std::vector allocates its memory on the heap, which is much larger than the stack.
    // This creates a vector of size 'max_range' with all elements initialized to 0.
    // `freq[i]` will store how many times the number `i` has appeared.
    vector<int> freq(max_range, 0);

    // --- Step 2: Populate the frequency array by iterating through all ranges ---
    // This is the core of the naive approach.
    // The outer loop processes one range at a time.
    for(int i = 0; i < n; i++)
    {
        // The inner loop iterates through every single number from the start (L[i])
        // to the end (R[i]) of the current range.
        for(int j = L[i]; j <= R[i]; j++)
        {
            // For each number 'j' found in the range, increment its corresponding counter.
            freq[j]++;
        }
    }

    // --- Step 3: Find the element with the highest frequency ---
    // Initialize variables to track the maximum frequency found and the element that has it.
    int max_element_freq = -1; // Stores the highest frequency count seen so far.
    int result_index = -1;     // Stores the element (index) that corresponds to that highest frequency.

    // Iterate through the entire frequency array from the beginning.
    for(int i = 0; i < max_range; i++)
    {
        // Check if the frequency of the current element 'i' is greater than the max we've found.
        if(freq[i] > max_element_freq)
        {
            // If it is, we have a new maximum. Update our tracking variables.
            max_element_freq = freq[i]; // Update the highest frequency.
            result_index = i;           // Store the current element 'i' as the new result.
        }
    }
    // NOTE on tie-breaking: By using `>` and not `>=`, we ensure that if two elements have the
    // same maximum frequency, the one with the smaller index (`i`) that was found first
    // will remain the result. This correctly handles the "print the smallest" rule.

    // --- Step 4: Return the result ---
    // After checking all elements, result_index will hold the smallest element
    // with the highest frequency.
    return result_index; 
}





Problem here: int freq[max_range] = {0}; 

The Calculation: Your array needs 1,000,000 * sizeof(int) bytes. Assuming an int is 4 bytes, that's 4,000,000 bytes, or 4 MB.

The Crash: Since 4 MB is larger than the default stack size on many systems, your program runs out of stack memory the moment it
 tries to create this array. This causes a stack overflow, and the program crashes immediately, before it ever has a chance to run
  the loops or print any output.

This is why you are "not getting any output"—the program terminates before the std::cout line in main is ever reached.

The Solution: Use the Heap
To fix this, you need to allocate the memory for this large array on the heap. The heap is a much larger pool of memory available to your 
program.

The modern C++ way to do this is to use std::vector, which manages heap memory for you automatically and safely





*/
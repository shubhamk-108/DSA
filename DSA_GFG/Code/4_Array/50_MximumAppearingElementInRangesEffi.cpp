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

#include <iostream>
#include <vector> // Required for using std::vector

using namespace std;

int maxAppearingElement(int L[], int R[], int n)
{
    // Define the maximum possible value for an element in the ranges + 1.
    // Based on problem constraints (0 <= L[i], R[i] < 10^6), so MAX_SIZE = 10^6 + 1.
    const int max_range = 1000001;
    
    // Create a frequency array (also known as a difference array in this context).
    // We use std::vector to safely allocate on the heap and initialize all elements to 0.
    // This avoids potential stack overflow issues with large static arrays.
    vector<int> freq(max_range, 0);

    // --- Step 1: Mark the start and end points of each range ---
    // This is the core of the difference array optimization. Instead of incrementing
    // all numbers within a range, we just mark the start and the point after the end.
    // The outer loop iterates through each of the 'n' given ranges.
    for (int i = 0; i < n; i++)
    {
        // Increment the count at the start of the current range (L[i]).
        // This signifies that a new range begins at this number.
        freq[L[i]]++;
        
        // Decrement the count at the element *after* the end of the current range (R[i] + 1).
        // This signifies that the current range ends at R[i], so its contribution
        // should be removed from numbers starting from R[i] + 1 onwards.
        // We must ensure R[i] + 1 does not exceed max_range.
        if (R[i] + 1 < max_range) { // Basic bounds check for R[i]+1
            freq[R[i] + 1]--;
        }
    }

    // --- Step 2: Calculate prefix sums and find the maximum frequency ---
    // The prefix sum at any index 'i' in the 'freq' array will give the actual count
    // of how many ranges cover the number 'i'.
    // Initialize max_freq with the count of the first element (0) and result to 0.
    int max_freq = freq[0];
    int result = 0; // The element (index) that has the maximum frequency.

    // Iterate through the 'freq' array starting from the second element (index 1).
    for(int i = 1; i < max_range; i++)
    {
        // Calculate the running sum (prefix sum).
        // The value at freq[i] now represents the number of active ranges covering 'i'.
        freq[i] = freq[i-1] + freq[i];

        // Check if the current element's frequency is greater than the maximum found so far.
        if(freq[i] > max_freq)
        {
            // If it is, update max_freq and store the current element 'i' as the result.
            max_freq = freq[i];
            result = i; // Store the index (the number itself).
        }
    }

    // If the loop completes and no valid maximum was found (e.g., all ranges were empty
    // or max_range was too small and no element had a positive count), result might remain 0.
    // If the problem guarantees at least one range and valid numbers, 0 is a possible answer.
    // In scenarios where no element appears, or max_freq remains its initial value and no element
    // is greater, you might want to return a sentinel like -1.
    // However, for typical equilibrium point-like problems where at least one element exists,
    // this logic correctly finds the smallest such element.
    return result; 
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


// Time Complexity: O(N + MAX)
// Auxiliary space: O(MAX)


// Logic

// The Core Idea of the Optimization
// Instead of simulating the count for every number, we can think of it like this:

// When a range (L, R) begins at L, the "count of active ranges" goes up by one.

// When the range ends at R, the "count of active ranges" should go down by one for all numbers after R.

// This can be achieved with just two operations per range:

// Mark the start of the range by adding 1 at index L.

// Mark the end of the range by subtracting 1 at index R + 1.

// After marking all the start and end points, a single pass over the array can reveal the actual counts. The count for
//  any number i is the sum of all the markers up to that point (a prefix sum).

//  How the Logic Works (Example Walkthrough)
// Let's trace the example L[] = {1, 4}, R[] = {5, 8}.

// Initialization: An array arr of size MAX_SIZE is created, filled with zeros.

// Marking Ranges:

// For (1, 5): arr becomes 1, and arr becomes -1.

// For (4, 8): arr becomes 1, and arr becomes -1.

// The arr now looks like: [... 0, 1, 0, 0, 1, 0, -1, 0, 0, -1, 0 ...].

// Prefix Sum Pass:

// i = 0: arr is 0. max_freq is 0, result is 0.

// i = 1: arr = arr + arr = 0 + 1 = 1. This is the new max. max_freq is 1, result is 1.

// i = 2: arr = arr + arr = 1 + 0 = 1.

// i = 3: arr = arr + arr = 1 + 0 = 1.

// i = 4: arr = arr + arr = 1 + 1 = 2. This is the new max. max_freq is 2, result is 4. (The number 4 is in both ranges).

// i = 5: arr = arr + arr = 2 + 0 = 2.

// i = 6: arr = arr + arr = 2 + (-1) = 1. (The first range has ended).

// ...and so on.

// The loop continues, but the maximum frequency found will be 2, and the first element to have it was 4. The function correctly returns 4
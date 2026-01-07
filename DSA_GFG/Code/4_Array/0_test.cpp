#include <iostream>
#include <vector>


int maxOccurringElementOptimized(int L[], int R[], int n) {
    // Define the maximum possible value for an element in the ranges + 1.
    // We need space for R[i] + 1, so the size needs to be slightly larger than the max value.
    const int MAX_SIZE = 1000001; 

    // Step 1: Create a difference array (or marker array).
    // Use std::vector to safely allocate on the heap. Initialize all values to 0.
    std::vector<int> arr(MAX_SIZE, 0);

    // Step 2: Mark the start and end points of each range.
    // This is the core of the optimization. We only perform two operations per range.
    for (int i = 0; i < n; i++) {
        // Increment the value at the start index L[i]. This signifies a new range begins here.
        arr[L[i]]++;
        
        // Decrement the value at the index *after* the end, R[i] + 1.
        // This marks that a range has concluded at R[i]. The effect of the increment
        // at L[i] will be "canceled out" from this point forward when we calculate prefix sums.
        arr[R[i] + 1]--;
    }

    // Step 3: Calculate prefix sums and find the maximum frequency.
    // The prefix sum at any index 'i' will give us the actual number of ranges covering 'i'.
    int max_freq = arr[0];
    int result = 0;

    // Iterate through the array starting from the second element.
    for (int i = 1; i < MAX_SIZE; i++) {
        // Calculate the prefix sum: the frequency of element 'i' is the
        // frequency of 'i-1' plus the marker value at 'i'.
        arr[i] += arr[i - 1];
        
        // Check if the frequency of the current element 'i' is the new maximum.
        if (arr[i] > max_freq) {
            max_freq = arr[i];
            result = i;
        }
    }
    // The tie-breaker rule (return smallest element) is handled automatically because
    // we iterate from left to right and only update on a strictly greater (>) condition.

    return result;
}

// The main function where the program execution begins.
int main() {
    // Example Input from the problem description
    int L[] = {1, 4, 3, 1};
    int R[] = {15, 8, 5, 4};
    int n = sizeof(L) / sizeof(L[0]);

    // Call the function to get the result
    int result = maxOccurringElementOptimized(L, R, n);

    // Print the result
    // Expected output is 4
    std::cout << "The maximum appearing element is: " << result << std::endl;

    return 0;
}

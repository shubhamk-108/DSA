// Our Task: Given an array arr[ ] of non-negative integers and an integer sum, find a subarray that adds to a given sum.

// Examples: 

// Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
// Output: Sum found between indexes 2 and 4
// Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

// Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
// Output: Sum found between indexes 1 and 4
// Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

// Input: arr[] = {1, 4}, sum = 0
// Output: No subarray found
// Explanation: There is no subarray with 0 sum

#include <iostream>
#include <vector>

// Function to find a subarray with a given sum using a naive approach
void findSubarrayWithSum(const std::vector<int>& arr, int target_sum) {
    int n = arr.size();

    // Pick a starting point for the subarray
    for (int i = 0; i < n; i++) {
        int current_sum = 0;

        // Try all subarrays starting with index 'i'
        for (int j = i; j < n; j++) {
            // Add the current element to the sum
            current_sum += arr[j];

            // Check if the current sum equals the target
            if (current_sum == target_sum) {
                std::cout << "Sum found between index " << i << " and " << j << std::endl;
                // Return after finding the first match
                return;
            }
        }
    }

    // If the loops complete, no subarray was found
    std::cout << "No subarray found with the given sum." << std::endl;
}

// Driver code to test the function
int main() {
    std::vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 23;
    findSubarrayWithSum(arr, sum); // Output: Sum found between index 1 and 4

    std::vector<int> arr2 = {1, 4, 20, 3, 10, 5};
    int sum2 = 33;
    findSubarrayWithSum(arr2, sum2); // Output: Sum found between index 2 and 4

    std::vector<int> arr3 = {10, 2, -2, -20, 10};
    int sum3 = -10;
    findSubarrayWithSum(arr3, sum3); // Output: Sum found between index 3 and 4

    std::vector<int> arr4 = {1, 4};
    int sum4 = 0;
    findSubarrayWithSum(arr4, sum4); // Output: No subarray found with the given sum.

    return 0;
}


// Time Complexity: O(n2), Trying all subarrays from every index, used nested loop for the same
// Auxiliary Space: O(1). 

// Logic:
// Try to dry run program
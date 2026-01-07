/*
Array: arr[] = {10, 20, 20, 10, 30, 40, 10}

Window Size (k): 4

Output:
2 3 4 3

Detailed Explanation
The goal is to slide a window of size k across the array from left to right and, for each window, count the number of unique elements within it.
First Window: {10, 20, 20, 10}
The elements in this window are 10, 20, 20, and 10.
The distinct (unique) elements are {10, 20}.
Count of distinct elements: 2
Second Window: {20, 20, 10, 30}
The elements are 20, 20, 10, and 30.
The distinct elements are {10, 20, 30}.
Count of distinct elements: 3
Third Window: {20, 10, 30, 40}
The elements are 20, 10, 30, and 40.
The distinct elements are {10, 20, 30, 40}.
Count of distinct elements: 4
Fourth Window: {10, 30, 40, 10}
The elements are 10, 30, 40, and 10.
The distinct elements are {10, 30, 40}.
Count of distinct elements: 3
Combining these counts gives the final output sequence: 2 3 4 3.


*/

#include <iostream>
#include <algorithm>
using namespace std;

void countDistinctElementInEveryWindow(int arr[], int n, int k)
{

    for (int i = 0; i < n - k + 1; i++)
    {
        int current = 0;

        for (int j = i; j < i + k; j++)
        {
            bool flag_hasSeenSoFar = false;

            for (int p = i; p < j; p++)
            {
                if (arr[p] == arr[j])
                {
                    flag_hasSeenSoFar = true;
                    break;
                }
            }
            if (flag_hasSeenSoFar == false)
                current++;
        }
        cout << current << " ";
    }
}

int main()
{
    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinctElementInEveryWindow(arr, n, 4);

    return 0;
}


// time 
/*

Time Complexity: O((n - k) * k²)
The time complexity is determined by the three nested loops.
Outer Loop: for (int i = 0; i < n - k + 1; i++)
This loop runs for each window. There are n - k + 1 windows. In big O notation, we can approximate this to O(n), as k is a constant for a 
given problem and n is the dominant factor.
Middle Loop: for (int j = i; j < i + k; j++)
This loop runs exactly k times for each iteration of the outer loop. Its complexity is O(k).
Inner Loop: for (int p = i; p < j; p++)
This loop checks for duplicates. In the worst-case scenario (for each element j in the window), it iterates up to k-1 times. On average, it 
runs about k/2 times. For complexity analysis, we consider the worst case, which is O(k).
To get the total time complexity, we multiply the complexities of these nested loops:
Total Time = (Outer Loop) × (Middle Loop) × (Inner Loop)
Total Time ≈ O(n) × O(k) × O(k) = O(n * k²)
Since the outer loop runs exactly n - k + 1 times, a more precise representation is O((n - k) * k²). This cubic-like complexity makes the 
brute-force approach very slow for large arrays.

Space Complexity: O(1)

*/
// Logic 


/*

#include <iostream>

// Use a clear and descriptive function name.
// Standard C++ style uses camelCase or snake_case for function names.
void countDistinctInWindow_BruteForce(int arr[], int n, int k)
{
    // The outer loop determines the starting point of each window.
    // It runs from the first element (index 0) up to the last possible
    // starting point, which is 'n - k'.
    // For example, with n=7 and k=4, the last window starts at index 3 (7-4).
    // So 'i' will go from 0, 1, 2, to 3. The loop condition i <= n-k is also valid.
    for (int i = 0; i < n - k + 1; i++)
    {
        // For each new window, reset the count of distinct elements to zero.
        int distinct_count = 0;

        // The second loop iterates through each element *within the current window*.
        // The window starts at index 'i' and has 'k' elements,
        // so it ends at index 'i + k - 1'.
        // 'j' will go from i, i+1, ..., up to i+k-1.
        // i is sliding 1 position further for every new window. so why j < i + k. It tells us that four(k) position from start of the window
        // i is start of window and k is k position ahead thereafter
        for (int j = i; j < i + k; j++)
        {
            // Assume the current element (arr[j]) is unique until proven otherwise.
            bool is_duplicate = false;

            // The third loop checks if arr[j] has already appeared *earlier*
            // in the *current window*.
            // It compares arr[j] with all preceding elements in the window,
            // which are located from index 'i' to 'j - 1'.
            // we need to check all elements within each window. i is the start of window that is why p = i . and from i we have to
            // check all elements in the current window prior to j
            for (int p = i; p < j; p++)
            {
                // If a match is found, we know arr[j] is a duplicate.
                if (arr[p] == arr[j])
                {
                    // Set the flag and exit this inner loop immediately since
                    // we don't need to check any further.
                    is_duplicate = true;
                    break;
                }
            }

            // After checking against all previous elements in the window,
            // if the flag is still false, it means arr[j] is unique.
            if (is_duplicate == false)
            {
                // Increment our count for this window.
                distinct_count++;
            }
        }

        // After the middle loop finishes, we have the final count for the window
        // starting at 'i'. Print it, followed by a space.
        std::cout << distinct_count << " ";
    }
}


*/
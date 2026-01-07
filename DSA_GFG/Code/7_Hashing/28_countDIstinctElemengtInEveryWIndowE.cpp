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
#include <unordered_map>
using namespace std;

void countDistinctElementInEveryWindow(int arr[], int n, int k)
{

    unordered_map<int, int> um;

    for (int i = 0; i < k; i++)
    {
        um[arr[i]]++;
    }

    cout << um.size() << " ";

    for (int i = k; i < n; i++)
    {
        auto it_key_to_decrement = um.find(arr[i - k]);
        if (it_key_to_decrement != um.end())
        {
            if (it_key_to_decrement->second == 1)
                um.erase(it_key_to_decrement);
            else
                it_key_to_decrement->second--;
        }

        um[arr[i]]++;

        cout << um.size() << " ";
    }
}

int main()
{
    int arr[] = {10, 20, 20, 10, 30, 40, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinctElementInEveryWindow(arr, n, 4);

    return 0;
}

// time space 
/*
Time Complexity

First loop (0 → k-1): Inserts k elements into the hash map → O(k).
Sliding window loop (k → n-1):
Remove outgoing element → O(1) average.
Insert incoming element → O(1) average.
Print size → O(1).
Runs for (n - k) iterations → O(n - k).
⚠️ Worst case = O(n * k) if hash collisions happen (very rare in practice).


💾 Space Complexity
The unordered_map stores at most k elements at any time (since window size = k).
Therefore, O(k) auxiliary space.



*/




// logic:


/*

// Function to count distinct elements in every window of size k in an array
void countDistinctElementInEveryWindow(int arr[], int n, int k)
{
    // Hash map to store the frequency of elements in the first window
    unordered_map<int, int> um;

    // Step 1: Process the first window of size k
    for (int i = 0; i < k; i++)
    {
        um[arr[i]]++; // increase frequency of each element
    }

    // Print the count of distinct elements in the first window
    cout << um.size() << " ";

    // Step 2: Process rest of the windows (sliding window approach)
    for (int i = k; i < n; i++)
    {
        // Remove the first element of the previous window
        auto it_key_to_decrement = um.find(arr[i - k]);
        if (it_key_to_decrement != um.end())
        {
            if (it_key_to_decrement->second == 1)
                // If frequency becomes 0, erase the element (no longer in the window)
                um.erase(it_key_to_decrement);
            else
                // Otherwise just reduce the frequency
                it_key_to_decrement->second--;
        }

        // Add the new element of the current window
        um[arr[i]]++;

        // Print distinct element count of the current window
        cout << um.size() << " ";
    }
}


*/
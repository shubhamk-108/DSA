// arr = {1, 4, 20, 3, 10, 5}
// target_sum = 33
// op = true
// expln: found from index 2 to 4

#include <iostream>
using namespace std;

bool subarrayWithGivenSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        int current_sum = arr[i];

        if(arr[i] == sum )
            return true;

        for (int j = i + 1; j < n; j++)
        {
            current_sum += arr[j];
            if (current_sum == sum)
                return true;
        }
    }
    return false;
}

int main()
{
    int arr1[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int sum = 33;

    cout << subarrayWithGivenSum(arr1, n, sum);

    return 0;
}




// Time Complexity: O(n²)
// Space Complexity: O(1)


// logic

/*


#include <iostream>
using namespace std;

// This function checks if a subarray with a given sum exists.
// It uses a brute-force approach by checking every possible subarray.
bool subarrayWithGivenSum(int arr[], int n, int sum)
{
    // The outer loop picks the starting index 'i' of a potential subarray.
    for (int i = 0; i < n; i++)
    {
        // 'current_sum' will act as the running sum for subarrays starting at index 'i'.
        int current_sum = arr[i];
        
        // --- THE FIX ---
        // Immediately check if the single-element subarray {arr[i]} itself
        // is equal to the target sum. This handles cases like arr=[1, 5, 2] and sum=5.
        if (current_sum == sum)
            return true;

        // The inner loop iterates from the next element (i + 1) to the end of the array.
        // This loop builds and checks subarrays of length 2 or more that start at 'i'.
        for (int j = i + 1; j < n; j++)
        {
            // Add the next element to our running sum.
            current_sum += arr[j];

            // Check if the sum of the subarray from index 'i' to 'j' equals the target.
            if (current_sum == sum)
            {
                // If a match is found, we can stop and return true immediately.
                return true;
            }
        }
    }

    // If both loops complete without finding any matching subarray,
    // we can conclude that none exists in the entire array.
    return false;
}


*/
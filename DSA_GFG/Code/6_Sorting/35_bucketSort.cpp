#include <bits/stdc++.h>
using namespace std;

void bucketSort(int arr[], int n, int k)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);

    max_val++;

    
    vector<vector<int>> bkt(k);

    for (int i = 0; i < n; i++)
    {
        int bi = (k * arr[i]) / max_val;
        bkt[bi].push_back(arr[i]);
    }

    for (int i = 0; i < k; i++)
        sort(bkt[i].begin(), bkt[i].end());

    int index = 0;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < bkt[i].size(); j++)
            arr[index++] = bkt[i][j];
}

int main()
{
    int arr[] = {30, 40, 10, 80, 5, 12, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    bucketSort(arr, n, k);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// time and space

/*

Time Complexity:

Best/Average Case: O(n + k). This occurs when elements are uniformly distributed.

O(n) to find the maximum element.

O(n) to place n elements into k buckets.

O(k) to iterate through buckets and sort them. If n elements are uniformly distributed into k buckets, each bucket has n/k elements. 
Sorting them takes a small, near-constant amount of time if n/k is small.

O(n) to concatenate the results.

Total: O(n + n + k + n) = O(3n + k) = O(n + k).

Worst Case: O(n log n). This happens when all elements fall into a single bucket (e.g., input is {1, 2, 3, 1000} with a small k). In this case,
 the std::sort function has to sort all n elements, which takes O(n log n) time.

Space Complexity: O(n + k).

O(k) for creating the array of bucket vectors.



O(n) for storing the n elements in the buckets collectively.

This

*/



// logic

/*


High-Level Concept
Bucket Sort works by distributing elements of an array into a number of "buckets." Each bucket is then sorted individually, either using a
different sorting algorithm or by recursively applying the bucket sort algorithm. Finally, the sorted buckets are concatenated to get the
 final sorted array.

This algorithm is most effective when the input data is uniformly distributed over a range.


*/

// code

/*


// Function to sort an array 'arr' of size 'n' using 'k' buckets.
void bucketSort(int arr[], int n, int k)
{
    // --- Step 1: Find the maximum value in the input array ---
    // Initialize max_val with the first element of the array.
    int max_val = arr[0];
    // Iterate through the rest of the array to find the true maximum element.
    for (int i = 1; i < n; i++)
        max_val = max(max_val, arr[i]);

    // Increment the maximum value by 1.
    // This is a crucial step to ensure that the largest element `arr[i]` when used in the
    // distribution formula `(k * arr[i]) / max_val` results in an index less than k.
    // For example, if max_val is 80 and arr[i] is 80, (k*80)/80 = k, which is an out-of-bounds index.
    // By using max_val+1, the index will always be in the range [0, k-1].
    // if we have 5 buckets then are this buckets 1,2,3,4 and not 0,1,2,3,4,5. So we we dont add max value + 1 then for ex.
    // max = 80 and buckets = 5 then 5*80 / 80 = 5. But 5th bucket is not available because they are from 0 to 4. That is 
    // why we add 1 to max value to bound bucket in 0 to k-1.
    max_val++;

    // --- Step 2: Create 'k' empty buckets ---
    // 'bkt' is an array of 'k' vectors. Each vector represents a bucket.
    // For example, if k=4, bkt[0], bkt[1], bkt[2], and bkt[3] are created as empty vectors.
    // vector<int> bkt[4] means there are 4 different arrays and each array can store multiple elements.
    // bkt[0] → {10, 15}
    // bkt[1] → {20}
    // bkt[2] → {33, 34, 35}
    // bkt[3] → {}
    //  if k=4, you create bkt1, bkt2, bkt3, and bkt4, each being an independent vector.
    vector<int> bkt[k];

    // --- Step 3: Distribute array elements into buckets ---
    // Iterate through each element of the original array.
    for (int i = 0; i < n; i++)
    {
        // Calculate the bucket index 'bi' for the current element arr[i].
        // This formula scales the element's value to the range of bucket indices [0, k-1].
        int bi = (k * arr[i]) / max_val;

        // Add the current element to the vector at the calculated bucket index.
        bkt[bi].push_back(arr[i]);
    }

    // --- Step 4: Sort individual buckets ---
    // Iterate through each of the 'k' buckets.
    for (int i = 0; i < k; i++)
        // Use the built-in sort function (std::sort) to sort the elements within each bucket.
        sort(bkt[i].begin(), bkt[i].end());

    // --- Step 5: Concatenate the sorted buckets back into the original array ---
    // Initialize an index 'index' to keep track of the current position in the original array 'arr'.
    int index = 0;
    // Iterate through the buckets in order (from bucket 0 to k-1).
    for (int i = 0; i < k; i++) {
        // Iterate through all elements in the current bucket.
        for (int j = 0; j < bkt[i].size(); j++) {
            // Place the sorted elements from the bucket back into the original array.
            arr[index++] = bkt[i][j];
        }
    }
}



*/


// Question 
/*

Bucket sort is a framework, not a single sorting algorithm
The main idea of bucket sort is:
Divide values into buckets
Sort within each bucket (so the concatenation produces a fully sorted array)
Concatenate buckets
Step 2 uses a helper sorting algorithm — it could be:
Insertion sort (classical textbook)
Merge sort / quicksort / built-in sort()
Even another bucket sort (for nested buckets in some implementations)
Bucket sort itself doesn’t define which sorting algorithm must be used in the bucket.

Bucket sort can use insertion sort to sort individual bukcets, though it is O(n^2) in worst case, it works faster for smaller size arrays.
*/
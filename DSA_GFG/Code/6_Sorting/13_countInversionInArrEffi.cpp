//  There are two conditions for the  elements to be inverse:
// arr[i] > arr[j]
// i < j
// basically there is a greater element occuring in array before current element

// int arr[]={2,4,1,3,5}; // (4, 1), (4, 3), (2, 1)
    // int arr[]={10,20,30,40};
//int arr[] = {50, 40, 30, 20, 10}; // if sorted in decreasing order then inversions are ( n*(n-1) )/2 because firse ekement will form 4 inversion that is// (n-1) and  second will form 3 inversions that is (n-2) and so on



// This program is totally based on mergge sort algorithm and merge function of merge sort.

// you can refer apna college shraddha video if you dont understand

#include <iostream>
using namespace std;

int countInversionWhileMergingTwoArray(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left_arr[n1];
    int right_arr[n2];

    for (int i = 0; i < n1; i++)
    {
        left_arr[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;
    int count = 0;

    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else // left_arr[i] > right_arr[j]
        {
            arr[k] = right_arr[j];
            j++;
            k++;
            count += n1 - i;
        }
    }
    while (i < n1)
        arr[k++] = left_arr[i++];

    while (j < n2)
        arr[k++] = right_arr[j++];


    return count;

}

int countInversion(int arr[], int left, int right)
{
    int count = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += countInversion(arr, left, mid);
        count += countInversion(arr, mid + 1, right);
        count += countInversionWhileMergingTwoArray(arr, left, mid, right);
    }
    return count;
}

int main()
{

    
    int arr[]={6,3,5,2,7};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = n-1;

    cout << countInversion(arr, left, right);
}

// Time Complexity: O(n log n)
// The algorithm's time complexity is described by the recurrence relation T(n) = 2T(n/2) + O(n).

// 2T(n/2) comes from the two recursive calls that each process half of the array.

// O(n) is the time taken by the countInversionWhileMergingTwoArray function to linearly scan through the n elements during the merge process.
// This is the same recurrence relation as Merge Sort, which solves to O(n log n). This is very efficient for a comparison-based sorting/counting algorithm.

// Space Complexity: O(n)
// The space complexity is determined by two factors:

// Temporary Arrays: The countInversionWhileMergingTwoArray function creates temporary arrays (left_arr and right_arr) whose combined size is equal to the size of the subarray being processed. 


// Logic:







/*


#include <iostream>
using namespace std;

// Function to count inversions while merging two sorted halves of array
int countInversionWhileMergingTwoArray(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;   // size of left subarray
    int n2 = high - mid;      // size of right subarray

    int left_arr[n1];         // temporary array for left half
    int right_arr[n2];        // temporary array for right half

    // Copy left half into left_arr
    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[low + i];

    // Copy right half into right_arr
    for (int i = 0; i < n2; i++)
        right_arr[i] = arr[mid + 1 + i];

    int i = 0;    // index for left_arr
    int j = 0;    // index for right_arr
    int k = low;  // index for merged array (original arr)
    int count = 0; // to count inversions

    // Merge two sorted halves while counting inversions
    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            // No inversion because left[i] <= right[j]
            arr[k++] = left_arr[i++];
        }
        else
        {
            // left[i] > right[j] → inversion found
            arr[k++] = right_arr[j++];
            
            // All remaining elements in left_arr[i ... n1-1]
            // will also be greater than right_arr[j-1]
            // suppose we have {6, 3, 5, 2, 7} array and we split it into {6,3,5} and {2,7}. While backtracking this array
            // will be sorted and we have {3,5,6} and {2,7}. Now if arr[i] > arr[j] means 3 is greater than 2 so because left
            // array is sorted so all the elements in the left array are anyways greater than 2. Like 3,6,5 all are greater than 2.
            // That is why we have count as n1 - i = 3 - 0 = 3. So we will have 3 pairs of inversion. {3,2}. {5,2}, {7,2}.
            count += n1 - i;
        }
    }

    // Copy any remaining elements of left_arr
    while (i < n1)
        arr[k++] = left_arr[i++];

    // Copy any remaining elements of right_arr
    while (j < n2)
        arr[k++] = right_arr[j++];

    return count; // return inversion count for this merge step
}


// Recursive function to count inversions in arr[left ... right]
int countInversion(int arr[], int left, int right)
{
    int count = 0;

    if (left < right)  // base case: single element → no inversion
    {
        int mid = left + (right - left) / 2;

        // Count inversions in left half
        count += countInversion(arr, left, mid);

        // Count inversions in right half
        count += countInversion(arr, mid + 1, right);

        // Count split inversions (across left & right halves)
        count += countInversionWhileMergingTwoArray(arr, left, mid, right);
    }
    return count;
}





dry-run your code with

int arr[]={6,3,5,2,7};


We’ll track recursive calls, merge steps, and which inversions are counted.

🔹 Step 1: Initial Call
countInversion(arr, 0, 4)   // full array {6,3,5,2,7}


mid = 2 → split into:

Left = {6,3,5} (0..2)

Right = {2,7} (3..4)

🔹 Step 2: Process Left Half {6,3,5}
countInversion(arr, 0, 2)


mid = 1 → split into:

Left = {6,3} (0..1)

Right = {5} (2..2)

Step 2.1: Left Half {6,3}
countInversion(arr, 0, 1)


mid = 0 → split into {6} and {3}

Left = {6} → no inversion

Right = {3} → no inversion

Merge {6} and {3} → call countInversionWhileMergingTwoArray(arr,0,0,1)

Compare 6 and 3 → 6 > 3 → inversion

Count = 1 ((6,3))

Array becomes {3,6,...} after merge.

Step 2.2: Merge {3,6} and {5}

Call countInversionWhileMergingTwoArray(arr,0,1,2)

Left = {3,6}

Right = {5}

Compare:

3 ≤ 5 → no inversion

6 > 5 → inversion

Count = 1 ((6,5))

Array becomes {3,5,6,...} after merge.

👉 Total inversions in left half = 2 ((6,3), (6,5))

🔹 Step 3: Process Right Half {2,7}
countInversion(arr, 3, 4)


mid = 3 → split into {2} and {7}

Left = {2} → no inversion

Right = {7} → no inversion

Merge {2} and {7} → 2 ≤ 7 → no inversion

👉 Total inversions in right half = 0

Array becomes {3,5,6,2,7} (only right half sorted).

🔹 Step 4: Merge Full Array

Merge {3,5,6} and {2,7}
Call countInversionWhileMergingTwoArray(arr,0,2,4)

Left = {3,5,6}

Right = {2,7}

Compare:

3 > 2 → inversion → add 3 (because n1 - i = 3 - 0 = 3)
Inversions: (3,2), (5,2), (6,2)

Then merge continues → 3 ≤ 7, 5 ≤ 7, 6 ≤ 7 → no more

Array becomes {2,3,5,6,7} fully sorted.

👉 Cross inversions = 3

🔹 Final Count

Left half inversions = 2 → (6,3), (6,5)

Right half inversions = 0

Cross inversions = 3 → (3,2), (5,2), (6,2)

Total = 5 inversions

✅ Answer: For arr[]={6,3,5,2,7}, inversion count = 5
Inversions are:

(6,3), (6,5), (6,2), (3,2), (5,2)





when this array is splitted {6,3,5,2,7} into {6,3,5} and {2,7}. It gets sorted after backtracking into {3,5,6} and {2,7}
So countInversionWhileMergingTwoArray this function is counting inversion in left half and right half both. One element of pair 
is in left half and another is in right hald.

But we also have inversions from the individual left half and individual right half like here {6,3,5} we have {6,3} , etc
so to see in left and right half as well we do this  count += countInversion(arr, left, mid); count += countInversion(arr, mid + 1, right);


*/
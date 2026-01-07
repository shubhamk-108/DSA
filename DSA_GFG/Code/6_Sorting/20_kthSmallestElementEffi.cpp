
// {10, 5, 30, 12} , k = 2. THen op will be 10

// This algo is also called as quick select algorithm
#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int low, int high)
{
    int i = low - 1;
    // we assumed that pivot is always the last element that is high
    int pivot = arr[high];

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int kthSmallestElement(int arr[], int n, int k)
{
    int left = 0;
    int right = n - 1;

    

    while (left <= right)
    {
        int pivot_index = lomutoPartition(arr, left, right);

        if (pivot_index == k - 1)
            return arr[pivot_index];

        else if (pivot_index > (k - 1))
            right = pivot_index -1;
        else
            left = pivot_index + 1;
    }

    return -1;
}

int main()
{

    int arr[] = {10, 5, 30, 12};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << kthSmallestElement(arr, n, k);
}

// Time 

// best and average : O(nlogn)

// Worst Case: O(n²)
// The worst case occurs when the pivot selection is consistently poor, leading to highly unbalanced partitions. For instance, 
// if the pivot is always the smallest or largest element in the current sub-array, the problem size is only reduced by one element 
// at each step. This can happen with a sorted or reverse-sorted array if the pivot is always the last element. It can also happen 
// with an array containing many duplicate values, as the Lomuto partition may not handle them efficiently. This leads to a recurrence
//  of T(n) = T(n-1) + O(n), which results in a quadratic, O(n²), time complexity.


// space c: 

// Your Iterative Code: O(1)
// Your implementation of kthSmallestElement uses a while loop instead of recursion. It only uses a few variables (left, right, pivot_index) 
// to keep track of the state. The amount of memory used does not depend on the size of the input array n. Therefore, the space complexity of 
// your specific code is O(1) (constant space), which is a significant advantage of the iterative approach.

// Recursive Version: O(log n) to O(n)
// If you were to implement this recursively, the space complexity would be determined by the depth of the recursion stack. In the average 
// case (balanced partitions), the depth would be O(log n). In the worst case (unbalanced partitions), the depth could be O(n)


// logic

// Lomuto partition is already explained in previous code files
// Explaining this function here kthSmallestElement

// if k is 3 then the element after sorting will be at 2nd index
// so we will continuously make the partition and get the pivot index
// If the pivot index is k-1 means the smallest element is at that 
// position and when we get pivot index as k-1 then that will be our answer
// if pivot_index is greater then we havae to move to the left side so
// right = pivot_index - 1
// and if pivot_index is smaller  then we have to move to the right side so
// left = pivot_index + 1
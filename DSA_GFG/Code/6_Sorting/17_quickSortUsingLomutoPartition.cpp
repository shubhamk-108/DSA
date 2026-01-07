#include <bits/stdc++.h>
using namespace std;

int lomutoPartition(int arr[], int low, int high)
{
    int i = low - 1;
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = lomutoPartition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

int main()
{

    int arr[] = {10, 80, 30, 90, 40, 50, 70};

    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    quickSort(arr, low, high);

    for (int x : arr)
        cout << x << " ";
}

// time:

// Best Case: O(n log n) This scenario occurs when the pivot element consistently divides the array into two nearly equal halves. Each 
// recursive step reduces the problem size by half, leading to a logarithmic number of levels in the recursion tree. At each level, the partitioning
// process takes linear time, O(n), resulting in an overall efficient time complexity of O(n log n).

// Average Case: O(n log n) On average,

// Worst Case: O(n²) 
// The worst-case scenario happens when the partitioning is extremely unbalanced. For instance, if the pivot is always the 
// smallest or largest element, the array is divided into one sub-array with n-1 elements and another with 0 elements. This can happen if 
// the array is already sorted and the last element is chosen as the pivot. In this situation, the recursion depth becomes n, and the total 
// time taken is O(n²). For example : {4,6,8,33,55}. Pivot element is 55 then partition will be {4,6,8,33,55} on left and {} nothing on right.
// THis took n-1 time. Again we will partition for this  {4,6,8,33} , and we will get {4,6,8,33} on left half and {} nothing on right.
// THat means it took (n-2) time and so on. So time will be (n-1)+(n-2)+(n-3).... = (n*(n+1)) / 2 that is n^2.


// space:

// Quick Sort is recursive, so space is needed for stack frames.
// Each recursive call uses O(1) space.
// Depth of recursion = depends on pivot choice.
// In-place partitioning
// Unlike Merge Sort, Quick Sort does not need extra arrays for merging.
// Partitioning rearranges elements within the array itself.
// So no O(n) temporary space.

// 🔹 Best & Average Case
// If pivot always splits array into roughly two halves (balanced recursion):
// Recursion depth = O(log n)
// Space = O(log n)

// 🔹 Worst Case
// If pivot is always the smallest or largest element (highly unbalanced split):
// Recursion depth = O(n)
// Space = O(n)


// logic


// Quick Sort is an efficient, comparison-based sorting algorithm that uses a divide-and-conquer strategy to sort an array or list of elements. 
// The fundamental idea is to pick an element from the array, called the pivot, and partition the other elements into two sub-arrays according to
//  whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

// The process involves three main steps:

// Pivot Selection: Choose a pivot element from the array. Common strategies include picking the first, last, middle, or a random element. The 
// provided code uses the last element as the pivot, which is a key characteristic of the Lomuto partition scheme.

// Partitioning: Rearrange the array so that all elements smaller than the pivot are placed before it, and all elements greater than the pivot 
// are placed after it. After this partitioning, the pivot is in its final sorted position.

// Recursion: Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with 
// greater values.



/*


// the lomuto partition is already explained in previous code files. Following is explanation of quicksort function.



// The main function that implements the Quick Sort algorithm.
// It takes an array, a low index, and a high index as input.
void quickSort(int arr[], int low, int high)
{
    // The base case for the recursion: if the low index is less than the high index,
    // it means there are at least two elements to be sorted.
    if (low < high)
    {
        // 'pivot_index' is the partitioning index. arr[pivot_index] is now at its correct sorted position.
        // we will continuously divide the array using pivot. Left side of pivot are smaller elements and right side of pivot is greater.
        // Now lets assume we divide all the way to the end and there are two elements remain in the array like {56, 22} then we will take
        // pivot as last element that is 22 and partition it accordingly and you can see that 22 will come ahead because it is smaller 
        // so array will become {22.56} and that we we will sort everything when we backtrack and join all our array that was splitted 
        // in the divide process. 
        // All the changes are in the original array so when the array gets split then for ex right half is {4,6,3,12}, then this is not 
        // from index 0 to 2. Because it is right half and the changes is in the original array itself then this array may range from 2 to 5
        // for example.

        int pivot_index = lomutoPartition(arr, low, high

        // Recursively sort the elements before the partition index. Further partition the left half
        quickSort(arr, low, pivot_index - 1);
        // Recursively sort the elements after the partition index. Further partition the right half.
        // Ans why there is no return statement here before recursion call that is because 
        // Because all operations happen on the original array, there is no need to return a new array.
        quickSort(arr, pivot_index + 1, high);
    }
}


*/


// if time limit exceed error occurs


/*'''



this choose random element as pivot
int random_pivot = (rand() % (high - low + 1)) + low;
swap(arr[random_pivot], arr[high]);
rand() % (high - low + 1) → gives a number in [0, high - low]
Adding low → shifts the range to [low, high]


Example:

Suppose low = 3, high = 7

high - low + 1 = 5

rand() % 5 → 0, 1, 2, 3, 4

Adding low = 3 → gives 3, 4, 5, 6, 7 ✅


*/
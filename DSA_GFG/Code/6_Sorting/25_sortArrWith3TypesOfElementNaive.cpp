// you need to segregate an array of elements containing three types of elements. The types are:

// Sort an array of 0s, 1s, 2s.
// Three-way partitioning when multiple occurrences of a pivot may exist.
// Partitioning around a range.

// Sort an array of 0s, 1s, 2s.
// ip: {0,1,0,2,1,2}
// op: {0,0,1,1,2,2}

// Three-way partitioning when multiple occurrences of a pivot may exist.
// ip: {2,1,2,20,10,20,1}, pivot : 2
// op: {1,1,2,2,20,10,20}

// Partitioning around a range.
// ip: {10,5,6,3,20,9,40}, range :[5,10]
// op: {3,5,6,9,10,20,40}: All the elements less than 5 should be on left side and then elements between 5 to 10 and all elements
// greater than 10 should be on the right side of 10.

#include <bits/stdc++.h>
using namespace std;

void sortArrOfZerosOnesTwos(int arr[], int n)
{
    int temp[n], i = 0;

    for (int j = 0; j < n; j++)
        if (arr[j] == 0)
            temp[i++] = arr[j];

    for (int j = 0; j < n; j++)
        if (arr[j] == 1)
            temp[i++] = arr[j];

    for (int k = 0; k < n; k++)
        if (arr[k] == 2)
            temp[i++] = arr[k];

    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
}

int main()
{

    int arr[] = {0, 1, 1, 2, 0, 1, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortArrOfZerosOnesTwos(arr, n);

    for (int x : arr)
        cout << x << " ";
}

// time : O(n)
// space : O(n)
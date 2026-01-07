#include <bits/stdc++.h>
using namespace std;

int hoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low -1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = hoarePartition(arr, low, high);
        quickSort(arr, low, pivot_index);
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


// to understand the code see 17_quickSortUsingLomutoPartition
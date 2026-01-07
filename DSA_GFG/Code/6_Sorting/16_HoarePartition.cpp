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



int main()
{

    int arr[] = {40, 80, 30, 90, 10, 50, 70, 15};

    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    hoarePartition(arr, low, high);

    for (int x : arr)
        cout << x << " ";
}

// we are givrn an array and a partition number. We have to put all the less than and equal to partition elements to the left side and
// greater elements to the right side. equal to size is to cover duplicate elements. if there are 8,8,8 and partition is also 8 then we
// have to print all 8. So not taking equal to size and insted printing 8 only once at the end of first half is not a good option.
// ex; {4,6,2,6,22,1, 10,12} and given partition is 6 then output will be {1,2,4,6,10, 12}

#include <bits/stdc++.h>
using namespace std;

void naivePartition(int arr[], int low, int high, int partition)
{
    int temp[high - low + 1];
    int idx = 0;

    for (int i = low; i <= high; i++)
    {
        if (arr[i] <= arr[partition] && i != partition)
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    temp[idx] = arr[partition];
    idx++;

    for (int i = low; i <= high; i++)
    {
        if (arr[i] > arr[partition])
        {
            temp[idx] = arr[i];
            idx++;
        }
    }

    for (int i = low; i <= high; i++)
    {

        arr[i] = temp[i - low];
    }

}

int main()
{

    int arr[] = {5, 13, 6, 9, 12, 11, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int partition_idx = 3;
    naivePartition(arr, 0, n - 1, partition_idx);

    for (int x : arr)
        cout << x << " ";
}

// Time Complexity: O(n),
// Space Complexity: O(n)
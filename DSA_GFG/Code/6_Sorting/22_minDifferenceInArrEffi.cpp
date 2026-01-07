// {1,8,12,5,18} op = 8-5 = 3
// {8,15 } op = 7
// {8,-1,0,3} op = 0-(-1)  = 1

// You must calculate the absolute difference to ensure you are comparing the magnitudes of the differences, not their signed values.

#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int getMinDifference(int arr[], int n)
{
    if (n < 2)
        return 0;
    sort(arr, arr + n);

    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        // minimm difference must be between any two adjecent pair.
        // since array is sorted there is no need to use abs
        res = min(res, std::abs(arr[i] - arr[i - 1]));
    }
    return res;
}

int main()
{

    // int arr[] = {1,8,12,5,18,8}; // 0
    int arr[] = {1, 8, 12, 5, 18}; // 3
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getMinDifference(arr, n);
    return 0;
}


// time: O(nlogn)
//space : O(1). Sorting may take space as discussed in merge sort and quick sort
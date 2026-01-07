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

    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Skip comparing an element with itself
            if (i == j)
                continue;

            int current_difference = std::abs(arr[i] - arr[j]);
            res = min(res, current_difference);
        }
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

// time : O(n^2)
// space O(1)
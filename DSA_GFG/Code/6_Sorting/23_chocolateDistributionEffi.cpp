// Given array. pick m number of chocolates such that their difference is minimum
// {7, 3, 2, 4, 9, 12, 56} k = 3. so op = 2 because we picked 2, 3, 4. And diff betn maximum chocolate and  minimum chocolate smaller. so  4-2 = 2

#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(int arr[], int n, int k)
{
    if (n < k || k == 0)
        return -1;
    sort(arr, arr + n);

    int res = INT_MAX;

    for (int i = k - 1; i < n; i++)
    {

        res = min(res, arr[i] - arr[i - k + 1]);
    }
    return res;
}

int main()
{

    // int arr[] =  {7, 3, 2, 4, 9, 12, 56} ; 
    // int k = 3;

    int arr[] =  {3, 4, 1, 9 ,56 , 7, 9 ,12} ; 
    int k = 5;

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << chocolateDistribution(arr, n, k);
    return 0;
}




// time: O(nlogn)
//space : O(1). Sorting may take space as discussed in merge sort and quick sort

// logic

/*



#include <climits>   // Required for INT_MAX

int chocolateDistribution(int arr[], int n, int k) {
    // 1. Handle edge cases: Impossible to distribute if there are fewer
    // chocolates than students (n < k) or if no students are considered (k == 0).
    if (n < k || k == 0) {
        return -1; // Indicates an error or impossible scenario
    }

    // 2. Sort the array to easily find min/max in a subarray.
    std::sort(arr, arr + n);

    // 3. Initialize the minimum difference to the largest possible value.
    int min_difference = INT_MAX;

    // 4. Use a sliding window to find the minimum difference.
    // The window is of size 'k'. 'i' represents the end of the window.
    for (int i = k - 1; i < n; i++) {
        // The start of the current window is at index (i - k + 1).
        int current_difference = arr[i] - arr[i - k + 1];
        
        // Update the minimum difference found so far.
        min_difference = std::min(min_difference, current_difference);
    }

    return min_difference;
}


*/
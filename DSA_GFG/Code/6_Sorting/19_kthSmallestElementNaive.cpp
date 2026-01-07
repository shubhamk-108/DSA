
// {10, 5, 30, 12} , k = 2. THen op will be 10

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    // sort it and return k-1 element
    sort(arr, arr + n);
    return arr[k - 1];
}

int main()
{

    int arr[] = {10, 5, 30, 12};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << kthSmallest(arr, n, k);
}

// time  : O(nlogn)
// space : it doesnt take any space as such but if we consider it is using merge sort then it will take O(N) space and for 
// quick sort it will take O(log n) for recursion call stack
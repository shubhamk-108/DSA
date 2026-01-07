// A element is a peak element if the element after that current_element and before that current_element is smaller.
// for 0th element and last element there is no need to check left and right side element resp.
// examples:
// {5,10,20,15,7}
// op = 20

// {10,20,15,23,90,67} op = 20 or 90
// {80,70,60} op = 80

#include <iostream>
using namespace std;

int peakElement(int arr[], int n)
{
    if (n == 0)
        return -1;
    if (n == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
    return -1;
}


int main()
{

    int arr[] = {5, 10, 7, 8, 20, 12}, n = 6;

    cout << peakElement(arr, n);

    return 0;
}

// Time : O(n)
// space : O(1)


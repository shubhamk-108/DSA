#include <iostream>
using namespace std;

void intersectionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
            

        if (arr1[i] > arr2[j])
            j++;

        else if (arr1[i] < arr2[j])
            i++;

        else // arr1[i] == arr2[j]
        {
            cout << arr1[i]<<" ";
            i++;
            j++;
        }
    }
}

int main()
{

    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    intersectionOfTwoSortedArrays(a, b, m, n);
}

// time : O(m+n)
// space : O(1)


// logic:

// this code is inspired from file no 6 6_mergeFunOfMergeSort
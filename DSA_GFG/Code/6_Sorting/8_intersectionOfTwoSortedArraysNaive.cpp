#include <iostream>
using namespace std;

void intersectionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
            continue;

        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
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


// time : O(n*m)
// space : O(1)
#include <bits/stdc++.h>
using namespace std;

void intersection(int arr1[], int arr2[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                flag = true;
                break;
            }
        }

        if(flag == false)
        {
            for(int k = 0; k < n; k++)
            {
                if(arr1[i] == arr2[k])
                {
                    cout<<arr1[i] <<" ";
                    break;
                }
            }
        }
    }
}

int main()
{
    int arr1[] = {15, 16, 27, 27, 28, 15, 15, 15};
    int arr2[] = {28, 15, 40, 50, 15};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    

    intersection(arr1, arr2, m, n);

    return 0;
}


// Complexity
// Outer loop: O(m)
// Duplicate check: up to O(m)
// Inner loop over arr2: up to O(n)
// 👉 Worst case = O(m * (m + n))

//space : O(1)

// logic


/*

// Function to print intersection of two arrays
// arr1[] -> first array, size m
// arr2[] -> second array, size n
void intersection(int arr1[], int arr2[], int m, int n)
{
    // Traverse each element of arr1
    for (int i = 0; i < m; i++)
    {
        bool flag = false;  // to check if arr1[i] appeared before in arr1

        // Check if arr1[i] is a duplicate in arr1
        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                flag = true; // arr1[i] already seen
                break;
            }
        }

        // If arr1[i] is unique so far
        if (flag == false)
        {
            // Check if arr1[i] is present in arr2
            for (int k = 0; k < n; k++)
            {
                if (arr1[i] == arr2[k])
                {
                    cout << arr1[i] << " ";  // print intersection element
                    break; // no need to check further in arr2
                }
            }
        }
    }
}


*/
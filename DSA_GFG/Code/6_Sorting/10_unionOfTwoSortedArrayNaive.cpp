#include <iostream>
#include <algorithm>
using namespace std;

void unionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
{
    int temp[m + n];

    for (int i = 0; i < m; i++)
    {
        temp[i] = arr1[i];
    }
    for (int j = 0; j < n; j++)
    {
        temp[m + j] = arr2[j];
    }

    sort(temp, temp + m + n);

    for (int i = 0; i < m + n; i++)
    {
        if (i == 0 || temp[i] != temp[i-1])
        {
            cout << temp[i]<<" ";
        }
    }
}

int main()
{

    int a[] = {3, 8, 10};
    int b[] = {2, 8, 9, 10, 15};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    unionOfTwoSortedArrays(a, b, m, n);
}

// time and space : O(n)

// logic:


/*




 * @brief Finds and prints the union of two sorted arrays.
 * 
 * This function takes two sorted integer arrays and their sizes, merges them
 * into a temporary array, sorts the merged array, and then prints the unique
 * elements, which represent the union of the two input arrays.
 * 


void unionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
{
    // Create a temporary array to hold all elements from both arrays.
    // Its size is the sum of the sizes of the two input arrays.
    int temp[m + n];

    // Copy all elements from the first array (arr1) into the temporary array.
    for (int i = 0; i < m; i++)
    {
        temp[i] = arr1[i];
    }
    
    // Copy all elements from the second array (arr2) into the temporary array,
    // starting after the elements of the first array.
    for (int j = 0; j < n; j++)
    {
        temp[m + j] = arr2[j];
    }

    // Sort the combined temporary array. This brings all identical elements together.
    sort(temp, temp + m + n);

    // Iterate through the sorted temporary array to find and print unique elements.
    for (int i = 0; i < m + n; i++)
    {
        // Print the element if it is the first one, or if it is different
        // from the previous element. This effectively removes duplicates.
        if (i == 0 || temp[i] != temp[i - 1])
        {
            cout << temp[i] << " ";
        }
    }
}



*/
#include <iostream>
#include <algorithm>
using namespace std;

void unionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
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
        if (j > 0 && arr2[j] == arr2[j - 1])
        {
            j++;
            continue;
        }
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else // (arr2[j] == arr1[i])
        {
            cout << arr2[j] << " ";
            j++;
            i++;
        }
    }
    while (i < m)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
        }
    }
    while (i < m)
    {
        if (i == 0 || arr1[i] != arr1[i - 1])
            cout << arr1[i] << " ";
        i++;
    }
    while (j < n)
    {
        if (j == 0 || arr2[j] != arr2[j - 1])
            cout << arr2[j] << " ";
        j++;
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


// time: O(m+n)
// space : O(1)


// logic


/*






 * @brief Finds and prints the union of two sorted arrays efficiently.
 * 
 * This function uses a two-pointer approach to find the union of two sorted
 * arrays without using extra space. It iterates through both arrays simultaneously,
 * printing the smaller element and advancing the corresponding pointer. It also
 * handles duplicates to ensure each number from the union is printed only once.
 * 
 * @param arr1 The first sorted integer array.
 * @param arr2 The second sorted integer array.
 * @param m The number of elements in arr1.
 * @param n The number of elements in arr2.
 
void unionOfTwoSortedArrays(int arr1[], int arr2[], int m, int n)
{
    int i = 0; // Pointer for arr1
    int j = 0; // Pointer for arr2

    // Iterate while there are elements in both arrays
    while (i < m && j < n)
    {
        // Skip consecutive duplicates in the first array
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        // Skip consecutive duplicates in the second array
        if (j > 0 && arr2[j] == arr2[j - 1])
        {
            j++;
            continue;
        }

        // Compare elements at the current pointers
        if (arr1[i] < arr2[j])
        {
            // If element in arr1 is smaller, print it and move its pointer
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            // If element in arr2 is smaller, print it and move its pointer
            cout << arr2[j] << " ";
            j++;
        }
        else // Elements are equal (arr1[i] == arr2[j])
        {
            // Print the common element once and move both pointers
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    // After the main loop, one array may still have elements left.
    // This loop prints the remaining elements of arr1, if any.
    while (i < m)
    {
        // Skip duplicates before printing
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }
        // Print the unique element and advance the pointer
        cout << arr1[i] << " ";
        i++;
    }

    // This loop prints the remaining elements of arr2, if any.
    while (j < n)
    {
        // Skip duplicates before printing
        if (j > 0 && arr2[j] == arr2[j - 1])
        {
            j++;
            continue;
        }
        // Print the unique element and advance the pointer
        cout << arr2[j] << " ";
        j++;
    }
}


*/

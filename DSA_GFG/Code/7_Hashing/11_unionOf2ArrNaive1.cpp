#include <bits/stdc++.h>
using namespace std;

void printDistinctElements(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << arr[i] << " ";
    }
}

void unionOf2Array(int arr1[], int arr2[], int m, int n)
{
    // int together[m + n]; This is called a Variable Length Array (VLA). You are trying to create a standard C-style array on the stack, but its
    // size (m + n) is determined at runtime, not at compile time. Standard C++: VLAs are not part of the official C++ standard. So use vectors insted

    vector<int> together;
    together.reserve(m + n); // Optional: pre-allocate memory to avoid reallocations.

    for (int i = 0; i < m; i++)
    {
        together.push_back(arr1[i]);
    }
    for (int j = 0; j < n; j++)
    {
        together.push_back(arr2[j]);
    }

    // --- Stage 2: Print the distinct elements of the combined array. To pass a vector to a function expecting a C-style array,
    // you use the .data() method, which returns a pointer to the underlying array.
    printDistinctElements(together.data() , together.size());
}

int main()
{
    int arr1[] = {15, 16, 27, 27, 28, 15, 15, 15};
    int arr2[] = {28, 15, 40, 50, 15};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    unionOf2Array(arr1, arr2, m, n);

    return 0;
}

// Overall Time Complexity: O((m + n)²)
// Overall Space Complexity: O(m + n)
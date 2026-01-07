// ip:{3,6,3,12}
// op : 3. explanation : 3,6,12

// {10,10,10}
// op: 1 . explanation 1

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int countDistinctElements(int arr[], int n)
{
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        us.insert(arr[i]);
    }
    return us.size();
}

// alternative representation
int countDistinctElements(int arr[], int n)
{
    unordered_set<int> us(arr, arr + n);
    return us.size();
}

int main()
{
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countDistinctElements(arr, n);

    return 0;
}


// Time Complexity: O(n)

// Space Complexity: O(n)

// logic 


/*


#include <iostream>
#include <unordered_set> // You need to include this header to use unordered_set
using namespace std;

// This function counts the number of distinct elements in an array
// using an efficient, modern C++ approach with an unordered_set.
int countDistinctElements(int arr[], int n)
{
    // Create an unordered_set. An unordered_set is a hash-based container
    // that only stores unique elements. It automatically handles duplicates.
    unordered_set<int> us;

    // Iterate through each element of the input array.
    for (int i = 0; i < n; i++)
    {
        // Insert the current array element into the unordered_set.
        // If the element is already present in the set, the insert operation
        // does nothing. This is the key property we are using.
        us.insert(arr[i]);
    }

    // The final number of distinct elements is simply the size of the set,
    // as it has automatically filtered out all duplicates.
    return us.size();
}


*/
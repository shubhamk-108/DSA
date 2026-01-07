#include <bits/stdc++.h>
using namespace std;
#include<unordered_set>

void intersection(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> us;

    for(int i = 0; i<m; i++)
    {
        us.insert(arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if( us.find(arr2[i] ) != us.end())
        {
            cout<<arr2[i]<<" ";
            us.erase(arr2[i]);
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


// time and space

/*

Time and Space Complexity
Time Complexity: O(m + n)

Step 1 (Building the set): You iterate through the m elements of arr1. Each insert operation takes O(1) on average. Total time for this 
step is O(m).
Step 2 (Finding the intersection): You iterate through the n elements of arr2. Each find and erase operation takes O(1) on average. 
Total time for this step is O(n).
Overall: The total time complexity is O(m) + O(n), which is simplified to O(m + n). This is linear time and is considered highly efficient.

Space Complexity: O(k), where k is the number of unique elements in arr1 (or simply O(m) in the worst case).

*/


// some imp info  about set

/*

unordered_set

Stores unique elements only ( no duplicates).
Elements are stored in no specific order (hash-based).
Lookup/insert/erase → O(1) average.

set (ordered set)
Stores unique elements only ( no duplicates).
Elements are stored in sorted order (tree-based, usually Red-Black Tree).
Lookup/insert/erase → O(log n).

*/


// logic:


/*

#include <iostream>
#include <unordered_set>
using namespace std;

// This function correctly and efficiently prints the unique intersection of two arrays.
void intersection(int arr1[], int arr2[], int m, int n)
{
    // Create an unordered_set to store the unique elements of the first array.
    // This provides O(1) average time complexity for lookups.
    unordered_set<int> us;

    // --- Step 1: Populate the set with unique elements from arr1 ---
    // This loop runs 'm' times. Each insert is O(1) on average.
    for (int i = 0; i < m; i++)
    {
        us.insert(arr1[i]);
    }

    // --- Step 2: Iterate through arr2 to find common elements ---
    // This loop runs 'n' times.
    for (int i = 0; i < n; i++)
    {
        // Check if the current element from arr2 exists in our set.
        // The find operation is O(1) on average.
        if (us.find(arr2[i]) != us.end())
        {
            // If it exists, we have found an element in the intersection.
            cout << arr2[i] << " ";
            
            // --- THE CRITICAL FIX ---
            // Immediately erase the element from the set.
            // This ensures that if the same number appears again in arr2,
            // the `find` operation will fail, preventing a duplicate print.
            us.erase(arr2[i]);
        }
    }
}



code would have worked without erase operation if we would have searched unique elements from set into arr2. That way we would have printed only
 unique elements but unordered_set elements are not ordered. So we access elements in unordered set like this 
 for(auto it = us.begin(); it != us.end(); i++) and inside loop we would have gotten out value using deferencing operator like *it but 
 that way we would not have abled to compare it with array elements like arr2[i] because inside loop we only have iterator and not array's access.

*/

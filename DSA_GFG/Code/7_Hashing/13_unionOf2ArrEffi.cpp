#include <bits/stdc++.h>
using namespace std;
#include<unordered_set>

void unionOf2Array(int arr1[], int arr2[], int m, int n){
    unordered_set<int> us1;

    for (int i = 0; i < m; i++)
    {
        us1.insert(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        us1.insert(arr2[i]);
    }

    for(auto x : us1)
    {
        cout<< x<<" ";
    }
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

// time and space 

/*

Time Complexity: O(m + n)

Inserting from arr1: You iterate through m elements. Each insert operation into an unordered_set takes O(1) time on average. Total for 
this step: O(m).
Inserting from arr2: You iterate through n elements. Each insert is also O(1) on average. Total for this step: O(n).
Printing the set: You iterate through the k unique elements in the final set. Total for this step: O(k).
The overall time complexity is O(m) + O(n) + O(k). Since k (the number of unique elements) is at most m + n, the complexity simplifies to O(m + n).
This is a linear time solution, which is highly efficient.

Space Complexity: O(m + n)
The extra space is used by the unordered_set.
In the worst-case scenario, if all elements in both arr1 and arr2 are unique, the set will store m + n distinct elements.
Therefore, the space complexity is O(m + n).

*/

// logic


/*

#include <iostream>
#include <unordered_set> // You must include this header
using namespace std;

// This function correctly and efficiently finds and prints the union of two arrays.
void unionOf2Array(int arr1[], int arr2[], int m, int n)
{
    // --- Step 1: Create a single unordered_set to store the union ---
    // An unordered_set is a hash-based container that only stores unique elements.
    // This is the key property that makes this algorithm work.
    // us2 is not needed, so it has been removed.
    unordered_set<int> us1;

    // --- Step 2: Insert all elements from the first array (arr1) into the set ---
    // This loop runs 'm' times. If an element is already in the set, the insert
    // operation does nothing.
    for (int i = 0; i < m; i++)
    {
        us1.insert(arr1[i]);
    }
    
    // --- Step 3: Insert all elements from the second array (arr2) into the same set ---
    // This loop runs 'n' times. Again, duplicates (either from arr2 itself or
    // elements that were already in arr1) will be ignored automatically.
    for (int i = 0; i < n; i++)
    {
        us1.insert(arr2[i]);
    }

    // --- Step 4: Print all elements in the final set ---
    // At this point, 'us1' contains every unique element from both arr1 and arr2, which is the definition of a union.
    // We can use a range-based for loop for a clean way to print them.
    // Note: The order of printing is not guaranteed because it's an UNORDERED set.
    cout << "The union of the two arrays is: ";
    for (auto x : us1)
    {
        cout << x << " ";
    }
}



*/
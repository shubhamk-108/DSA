// ip:{3,6,3,12}
// op : 3. explanation : 3,6,12

// {10,10,10}
// op: 1 . explanation 1

#include <bits/stdc++.h>
using namespace std;

int countDistinctElements(int arr[], int n)
{
    int count = 0;
    for(int i = 0; i<n ; i++)
    {
        bool flag = false;

        for(int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;

            }
        }
        if(flag == false)
            count++;
    }   
      
    return count;
}

int main()
{
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << countDistinctElements(arr, n);
    
    return 0;
}

// Time Complexity: O(n²)

// Space Complexity: O(1)


// logic

/*

#include <iostream>
using namespace std;

// This function counts the number of distinct (unique) elements in an array.
// It uses a naive, brute-force approach with nested loops.
int countDistinctElements(int arr[], int n)
{
    // 'count' will store the final number of unique elements.
    int count = 0;

    // The outer loop iterates through each element of the array.
    for (int i = 0; i < n; i++)
    {
        // 'flag' is used to track if the current element arr[i] has been seen before.
        // It is reset to false for each new element we check.
        bool flag = false;

        // The inner loop checks if the current element arr[i] has appeared
        // in the portion of the array that comes *before* it (from index 0 to i-1).
        for (int j = 0; j < i; j++)
        {
            // If a match is found, it means arr[i] is a duplicate.
            if (arr[i] == arr[j])
            {
                // Set the flag to true to indicate a duplicate has been found.
                flag = true;
                // Since we found a duplicate, we can stop checking and break the inner loop.
                break;
            }
        }

        // After the inner loop, if the 'flag' is still false, it means
        // no duplicates were found in the preceding part of the array.
        // Therefore, this is the first occurrence of this element, and it is distinct.
        if (flag == false)
        {
            // Increment the distinct element count.
            count++;
        }
    }

    // Return the total count of distinct elements.
    return count;
}



*/
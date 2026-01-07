#include <bits/stdc++.h>
using namespace std;

void countFrequencyOfEachElement(int arr[], int n)
{

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

        if(flag == true)
        {
            continue;
        } 

        int freq = 1;
        for(int k = i + 1; k<n; k++)
        {
            if(arr[i] == arr[k])
                freq++;
        }
        cout<<arr[i] <<" : " <<freq <<endl;
    }   
      
}

int main()
{
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    countFrequencyOfEachElement(arr, n);
    
    return 0;
}



// Time Complexity: O(n²)

// Space Complexity: O(1)


// logic

/*

#include <iostream>
using namespace std;

// This function counts and prints the frequency of each element in an array.
// It uses a more optimized brute-force approach with nested loops.
void countFrequencyOfEachElement(int arr[], int n)
{
    // The outer loop iterates through each element of the array.
    // 'i' acts as a candidate for a distinct element.
    for (int i = 0; i < n; i++)
    {
        // --- Step 1: Check if arr[i] is the *first* occurrence ---
        // 'flag' is used to track if arr[i] has already been seen in the part of the array to its left.
        bool flag = false;

        // Inner loop checks the portion of the array *before* the current index 'i'.
        for (int j = 0; j < i; j++)
        {
            // If a match is found, it means we have already processed this element.
            if (arr[i] == arr[j])
            {
                flag = true; // Mark that this is a duplicate of a previously seen element.
                break;       // No need to check further.
            }
        }

        // If the flag is true, it means arr[i] is not the first occurrence of this number.
        // We have already counted its frequency when we encountered it the first time.
        // So, we use 'continue' to skip the rest of the outer loop and move to the next element.
        if (flag == true)
        {
            continue;
        }

        // --- Step 2: If it is the first occurrence, count its total frequency ---
        // If we reach this point, arr[i] is a distinct element we haven't processed yet.
        // Initialize its frequency to 1 (for itself).
        int freq = 1;

        // This loop now counts all other occurrences of arr[i] in the part of the array to its *right*.
        for (int k = i + 1; k < n; k++)
        {
            if (arr[i] == arr[k])
            {
                freq++;
            }
        }
        
        // Print the distinct element and its calculated frequency.
        cout << arr[i] << " : " << freq << endl;
    }
}


*/
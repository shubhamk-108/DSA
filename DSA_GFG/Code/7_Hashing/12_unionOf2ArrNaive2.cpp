#include <bits/stdc++.h>
using namespace std;

void unionOf2Array(int arr1[], int arr2[], int m, int n)
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
        if (flag == false)
        {
            cout << arr1[i] << " ";
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = 0; j < i; j++)
        {
            if (arr2[i] == arr2[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            bool flag_already_exist_in_arr1 = false;

            for (int k = 0; k < m; k++)
            {
                if (arr2[i] == arr1[k])
                {
                    flag_already_exist_in_arr1 = true;
                    break;
                }
            }

            if(flag_already_exist_in_arr1 == false)
                cout << arr2[i] << " ";
        }
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

Time Complexity:O(m² + n²)
To determine the overall time complexity, we need to analyze the two main stages of your function.
Stage 1: Printing unique elements from arr1
This involves a nested loop structure.
The outer loop runs m times.
The inner loop (for checking duplicates) runs 0, 1, 2, ..., m-1 times.
This is a classic O(m²) operation, as the number of comparisons is proportional to m * (m-1) / 2.
Stage 2: Printing unique elements from arr2 that are not in arr1
The main outer loop runs n times.
Inside this loop, for each of the n elements, you do two things:
Check for duplicates in arr2: This involves a loop that runs up to n times. This part is O(n²).
Check if the element exists in arr1: This involves a loop that runs m times. This check is performed for each of the n
elements, contributing O(m*n) to the complexity.
The total work in this stage is approximately O(n² + m*n).
Overall Complexity
Combining both stages, the total time complexity is O(m²) + O(n² + m*n).
When combining complexities, we keep the dominant terms. Therefore, the most accurate representation of the time 
complexity is O(m² + n²)

Space Complexity: O(1)

*/

// logic

/*


// Function to print the union of two arrays (arr1 and arr2)
void unionOf2Array(int arr1[], int arr2[], int m, int n)
{
    // ---- Step 1: Print unique elements from arr1 ----
    for (int i = 0; i < m; i++)
    {
        bool flag = false;  // to check if arr1[i] already appeared in arr1 before

        // Check for duplicates of arr1[i] in the part before index i
        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                flag = true;  // duplicate found
                break;
            }
        }

        // If arr1[i] is unique, print it
        if (flag == false)
        {
            cout << arr1[i] << " ";
        }
    }

    // ---- Step 2: Print unique elements from arr2 that are not in arr1 ----
    for (int i = 0; i < n; i++)
    {
        bool flag = false;  // to check if arr2[i] already appeared in arr2 before

        // Check for duplicates of arr2[i] in the part before index i
        for (int j = 0; j < i; j++)
        {
            if (arr2[i] == arr2[j])
            {
                flag = true;  // duplicate found
                break;
            }
        }

        // If arr2[i] is unique so far
        if (flag == false)
        {
            bool flag_already_exist_in_arr1 = false;  // check if arr2[i] already exists in arr1

            for (int k = 0; k < m; k++)
            {
                if (arr2[i] == arr1[k])
                {
                    flag_already_exist_in_arr1 = true; // element already in arr1
                    break;
                }
            }

            // If arr2[i] is unique in arr2 and not present in arr1, print it
            if(flag_already_exist_in_arr1 == false)
                cout << arr2[i] << " ";
        }
    }
}




*/
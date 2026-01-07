// In this particular problem, we are provided with a sorted array of integers. Our objective is to determine whether 
// there exists a triplet (pair of 3 elements equal to given sum. )

// array must be sorted



#include <iostream>
using namespace std;



bool getripletOfGivenSum(int arr[], int n, int x)
{   
    if(n<3)
        return false;
    for(int i =0; i<n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                    return true;
            }   
        }
    }
    return false;
}


int main()
{
    int arr[] = {2,5,8,12,30};
    int n = 5;
    int x = 25;

    cout<<getripletOfGivenSum(arr, n, x);

    return 0;

}


// time: O(n^3)
// space  O(1)

// Logic


/*

 * @brief Checks if a triplet of elements with a given sum 'x' exists in an array.
 * 
 * NOTE: This function uses a brute-force approach with three nested loops.
 * It works correctly on unsorted arrays but is inefficient for large inputs,
 * with a time complexity of O(n^3).
 *
 * @param arr The input integer array (does not need to be sorted).
 * @param n The total number of elements in the array.
 * @param x The target sum for the triplet.
 * @return `true` if a triplet with the sum 'x' is found, otherwise `false`.

bool getTripletOfGivenSum(int arr[], int n, int x) // Renamed for clarity
{   
    // A triplet requires at least three numbers. If the array is smaller,
    // it's impossible to form one, so we can exit early.
    if(n < 3)
        return false;
    
    // The first loop fixes the first element of the potential triplet.
    // It runs up to `n-2` because we need at least two more elements (j and k) after it.
    for(int i = 0; i < n - 2; i++)
    {
        // The second loop fixes the second element.
        // It starts from `i+1` to ensure we don't reuse the same element and that
        // we are only considering unique combinations.
        for(int j = i + 1; j < n - 1; j++)
        {
            // The third loop checks for the third element.
            // It starts from `j+1` for the same reason as above.
            for(int k = j + 1; k < n; k++)
            {
                // This is the core logic: check if the sum of the three chosen elements
                // equals the target sum 'x'.
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    // If a match is found, we don't need to look any further.
                    // Return true immediately.
                    return true;
                }
            }   
        }
    }

    // If the function has gone through all possible unique triplets and has not
    // returned true, it means no such triplet exists.
    return false;
}



*/
// ind out the maximum difference between any two elements
// nput : arr = {2, 3, 10, 6, 4, 8, 1}
// Output : 8
// Explanation : The maximum difference is between 10 and 2. 10-2 = 9. check for 10-2 and not 2-10

// Input : arr = {7, 9, 5, 6, 3, 2}
// Output : 2
// Explanation : The maximum difference is between 9 and 7.

// To find the maximum difference arr[j] - arr[i] such that j > i.
// That means: Find the largest profit if you buy at i and sell at j later.



#include <iostream>
#include <cmath>
using namespace std;

int maxDifference(int arr[], int n)
{
    int max_diff = arr[1] - arr[0];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] - arr[i] > max_diff)
                max_diff = arr[j] - arr[i];
        }
    }
    return max_diff;
}

int main()
{
    int arr[] =  {7, 9, 5, 6, 3, 2}; 
    int n = 6;

    cout<<maxDifference(arr, n);
}

// time : O(n^2)
// space : O(1)
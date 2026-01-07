// Our Task: Given an array of N non-negative integers arr[ ] representing an elevation map where the width of 
// each bar is 1, compute how much water it is able to trap after rain.

// Note: The array elements represent the height of the bars.
// Examples:  
// Input: arr[]   = {3, 0, 2, 0, 4}
// Output: 7
// Explanation: Structure is like below.
// We can trap “3 units” of water between 3 and 2,
// “1 unit” on top of bar 2 and “3 units” between 2 and 4.




#include<iostream>
#include<cmath>
using namespace std;

int trapWater(int arr[], int n)
{
    int lmax, rmax, trappedWater = 0;

    for(int i = 1; i<n-1; i++)
    {
        lmax = arr[i];

        for(int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }

        rmax = arr[i];

        for(int k = i+1; k < n; k++)
        {
            rmax = max(rmax, arr[k]);
        }

        trappedWater = trappedWater + min(lmax, rmax) - arr[i];
    }
    return trappedWater;
}

int main ()
{
    int arr[] =  {3, 0, 1, 2, 5} ;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Trapped Water : "<<trapWater(arr, n);
    return 0;
}



// Time Complexity: O(n2). There are two nested loops traversing the array.
// Space Complexity: O(1). No extra space is required.

// -------------------------------------------------------------------------

// Logic

/*


// Imagine a diagram of this problem from internet
int trapWater(int arr[], int n)
{
    int lmax, rmax, trappedWater = 0;

    // first and last building will not store any water that is why i = 1 and i<n-1 that is till second last element 
    for(int i = 1; i<n-1; i++)
    {
        // we have to find what is the maximum building of the current building so that we can give the support to hold the water
        lmax = arr[i];
        // this is left side so j<i
        for(int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }

        rmax = arr[i];
        // do same for finding max building on right side. Due to this is right side we have k<n
        for(int k = i+1; k < n; k++)
        {
            rmax = max(rmax, arr[k]);
        }
        // whatever is minimum we have to take that because if we take maximub building then we will not get support to hold water from one side
        // we are substracting arr[i] because we have to subtract height of current building
        trappedWater = trappedWater + min(lmax, rmax) - arr[i];

    }
    return trappedWater;
}



*/
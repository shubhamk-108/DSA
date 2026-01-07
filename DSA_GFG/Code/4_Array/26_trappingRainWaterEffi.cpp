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

int trappedWater(int arr[], int n)
{
    int lmax[n];
    int rmax[n];
    int trappedWaterCount = 0;

    lmax[0] = arr[0];

    for(int i = 1; i<n; i++)
    {   
        lmax[i] = max(arr[i], lmax[i-1]);
    }

    rmax[n-1] = arr[n-1];
    for(int j = n-2; j>=0; j--)
    {
        rmax[j] = max(arr[j], rmax[j+1]);
    }

    for(int k = 1; k< n-1; k ++)
    {
        trappedWaterCount = trappedWaterCount + (min(lmax[k], rmax[k]) - arr[k]);
    }
    return trappedWaterCount; 
}

int main ()
{
    int arr[] =  {3, 0, 1, 2, 5} ;
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Trapped Water : "<<trappedWater(arr, n);
    return 0;
}


// Time Complexity: O(N). Only one traversal of the array is needed, So time Complexity is O(N).
// Space Complexity: O(N). Two extra arrays are needed, each of size N.


// -------------------------------------------------------------------------

// Logic



/*


The Core Idea
Imagine the input array arr as a series of vertical bars. Water can be trapped between two taller bars. The amount of water that 
can be held above any single bar is determined by the height of the "walls" on its left and right. Specifically, the water level 
can only rise to the height of the shorter of the two walls.

The amount of water trapped directly above a bar arr[i] is:
Water on bar[i] = (Height of water level) - (Height of bar[i])

And the height of the water level is:
Height of water level = min(tallest bar to the left of i, tallest bar to the right of i)

So, the formula for water trapped at a specific index i is:
trapped_water[i] = min(max_left_height, max_right_height) - arr[i]

The total trapped water is the sum of trapped_water[i] for all i.

The Algorithm's Logic
A naive approach would be to iterate through each bar and, for each one, find the maximum height to its left and right. This would be 
inefficient (O(n²)). The provided code optimizes this by pre-calculating all the left and right maximums in two separate passes.

1. Pre-computation: Calculating Left Maximums (lmax)
The first loop creates an array lmax where lmax[i] stores the maximum height of a bar from the beginning of the array up to and 
including index i.

text
lmax[0] = arr[0];
for(int i = 1; i < n; i++)
{   
    // The max height at 'i' is either the current bar's height
    // or the max height we've seen so far (lmax[i-1]).
    lmax[i] = max(arr[i], lmax[i - 1]);
}
lmax is initialized with arr because there are no bars to its left.

The loop then moves from left to right. At each step i, lmax[i] is the greater of the current bar's height arr[i] and the maximum 
height found just before it, lmax[i-1].

2. Pre-computation: Calculating Right Maximums (rmax)
Similarly, the second loop creates an array rmax where rmax[j] stores the maximum height of a bar from the end of the array down to 
and including index j.

text
rmax[n - 1] = arr[n - 1];
for(int j = n - 2; j >= 0; j--)
{
    // The max height at 'j' is either the current bar's height
    // or the max height we've seen so far from the right (rmax[j+1]).
    rmax[j] = max(arr[j], rmax[j + 1]);
}
rmax[n-1] is initialized with the last bar's height arr[n-1].

The loop moves from right to left. rmax[j] is the greater of the current bar's height arr[j] and the maximum found to its right, rmax[j+1].

3. Calculating the Total Trapped Water
The final loop iterates through the bars to calculate the trapped water for each one and sums it up.

text
for(int k = 1; k < n - 1; k++)
{
    // Water level is limited by the shorter of the two walls.
    int waterLevel = min(lmax[k], rmax[k]);
    
    // Water trapped above the current bar is the difference
    // between the water level and the bar's own height.
    trappedWaterCount += waterLevel - arr[k];
}
The loop runs from k = 1 to k < n - 1 because the first and last bars cannot trap any water (they don't have walls on both sides).

For each bar k, it takes the pre-computed lmax[k] (the tallest wall to its left) and rmax[k] (the tallest wall to its right).

The actual water level is the minimum of these two values.

The amount of water stored above arr[k] is min(lmax[k], rmax[k]) - arr[k]. This value is added to trappedWaterCount.

Example Walkthrough
Let's use arr = {3, 0, 2, 0, 4}. n = 5.

Calculate lmax:

lmax = 3

lmax = max(arr, lmax) = max(0, 3) = 3

lmax = max(arr, lmax) = max(2, 3) = 3

lmax = max(arr, lmax) = max(0, 3) = 3

lmax = max(arr, lmax) = max(4, 3) = 4

lmax array is: {3, 3, 3, 3, 4}

Calculate rmax:

rmax = 4

rmax = max(arr, rmax) = max(0, 4) = 4

rmax = max(arr, rmax) = max(2, 4) = 4

rmax = max(arr, rmax) = max(0, 4) = 4

rmax = max(arr, rmax) = max(3, 4) = 4

rmax array is: {4, 4, 4, 4, 4}

Calculate trappedWaterCount (loop from k=1 to 3):

k = 1 (bar height arr = 0):

waterLevel = min(lmax, rmax) = min(3, 4) = 3

water = waterLevel - arr = 3 - 0 = 3

trappedWaterCount = 3

k = 2 (bar height arr = 2):

waterLevel = min(lmax, rmax) = min(3, 4) = 3

water = waterLevel - arr = 3 - 2 = 1

trappedWaterCount = 3 + 1 = 4

k = 3 (bar height arr = 0):

waterLevel = min(lmax, rmax) = min(3, 4) = 3

water = waterLevel - arr = 3 - 0 = 3

trappedWaterCount = 4 + 3 = 7

The function returns 7.

*/
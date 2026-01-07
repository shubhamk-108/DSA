/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1


*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else if (arr[mid] > arr[mid + 1])
                high = mid;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 10, 5, 2};
    cout << sol.peakIndexInMountainArray(v);
    return 0;
}
//___________________________________________________________________________________________________________________________________________
// My explanation
//___________________________________________________________________________________________________________________________________________
/*

if (arr[mid] < arr[mid + 1])

This condition is like increasing slope, imagine.

      mid+1 = 10
         /
        /
      mid = 5

now see our mid means 5 can not be the top of the mountaion because the condition if (arr[mid] < arr[mid + 1])  itself says that
there is a greater element ahead. Thus we can safely move to right doing low = mid + 1.

Now consider this condn. Both diagramatic xample are seperate. Dont confuse that they are same.
else  if (arr[mid] > arr[mid + 1])

 
        mid  = 10
            \
             \
           mid + 1 = 5

Now here if this condition satisfies then we are like something like above diagram. See we are at decreasing slope and 
there is a possibility that mid is correctly positioned itself representing descending slope of mountain after a pick.
So, we do not do high = mid - 1. We do high = mid. And rest of the work that is coming towards the peak is being done by low.


Next why low is our answer. 
Because low will bring up to the element which is equaal to target(if any) and all the lesser elements. And this lesser elements
shown by low will surely take us to pick because the slope in increasing on left side of mountaion that is those numbers
are sorted in order. So the low will surely take us to the pick. Imagine that array is sorted on that left side so as if low 
is walking towards pick.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*


| Metric               | Complexity                      |
| -------------------- | ------------------------------- |
| **Time Complexity**  | **O(log n)** — binary search    |
| **Space Complexity** | **O(1)** — constant extra space |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We use binary search to find the peak of a mountain array.
A mountain array has two parts:
Strictly increasing portion
Strictly decreasing portion
Key idea:
If arr[mid] < arr[mid+1], we are on the left (ascending) slope → the peak is to the right, so move low = mid + 1
If arr[mid] > arr[mid+1], we are on the right (descending) slope → the peak is at mid or on the left, so move high = mid
Eventually, low == high, and that index is the peak index.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        // Binary search to find the peak
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If mid is part of increasing slope,
            // the peak must be to the right
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;

            // If mid is part of decreasing slope,
            // the peak is mid or somewhere to the left
            else
                high = mid;
        }

        // low == high → peak index
        return low;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Binary Search on Answer
✔️ Peak Finding Pattern
✔️ Binary Search on Mountain 



*/

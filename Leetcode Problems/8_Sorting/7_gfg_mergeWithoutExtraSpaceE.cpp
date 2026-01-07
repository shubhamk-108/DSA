/*
Problem link : https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space.
Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output: a[] = [1, 2, 3, 5, 8, 9], b[] = [10, 13, 15, 20]
Explanation: After merging two sorted arrays we get [1, 2, 3, 5, 8, 9, 10, 13, 15, 20].

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
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();

        int i = n - 1;
        int j = 0;

        while (i >= 0 && j < m)
        {
            if (a[i] > b[j])
            {
                swap(a[i], b[j]);
            }
            i--;
            j++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 5, 9, 10, 15, 20};
    vector<int> v2 = {2, 3, 8, 13};
    sol.mergeArrays(v1, v2);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Total Time Complexity
✔ O(min(n, m)) + O(n log n) + O(m log m)
Simplified Big-O:

Since min(n,m) is much smaller than the sorting cost,

👉 O(n log n + m log m)

space : O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal
Given two sorted arrays a[] and b[], rearrange them so that:
a[] contains the smallest n elements
b[] contains the largest m elements
All without using extra space.

Steps
Start with:
i = n - 1 → last element of a
j = 0 → first element of b
If the largest element in a (a[i]) is bigger than the smallest in b (b[j]):
Swap them → they belong in opposite arrays.
Move both pointers inward:
i--
j++
After the swapping phase, arrays may not be fully sorted → so sort both a and b.
This ensures:
a holds the smallest n elements
b holds the largest m elements


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();

        // i = last index of a
        int i = n - 1;
        // j = first index of b
        int j = 0;

        // Compare largest of a with smallest of b
        while (i >= 0 && j < m)
        {
            // If a[i] is bigger, it's out of place -> swap it with b[j]
            if (a[i] > b[j])
            {
                swap(a[i], b[j]);
            }

            // Move both pointers
            i--;
            j++;
        }

        // After swapping, individually sort both arrays
        // so that overall merged order is correct
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Two-pointer Technique + Sorting

*/

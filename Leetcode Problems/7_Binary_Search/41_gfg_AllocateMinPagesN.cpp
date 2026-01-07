/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
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
    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();

        if (k > n)
            return -1;

        int lowestPagespossible = *max_element(arr.begin(), arr.end());

        int sum = 0;
        for (auto x : arr)
            sum += x;

        int largestPagesPossible = sum;
        int res = -1;

        for (int pages = lowestPagespossible; pages <= largestPagesPossible; pages++)
        {
            int studentsWhoGotPagesAlloted = 1;
            int currSum = 0;
            bool possible = true;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] > pages)
                {
                    possible = false;
                    break;
                }

                currSum += arr[i];
                if (currSum > pages)
                {
                    studentsWhoGotPagesAlloted++;
                    currSum = arr[i];
                }

                if (studentsWhoGotPagesAlloted > k)
                {
                    possible = false;
                    break;
                }
            }
            if (possible && studentsWhoGotPagesAlloted <= k)
                return pages;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {12, 34, 67, 90};
    cout << sol.findPages(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O((sum(arr) − max(arr)) × n)
Because:
We try roughly (sum − max) different values for pages
For each value, we scan the array once → O(n)

Space Complexity
O(1)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We try every possible answer for "maximum pages a student can get".
Key idea:
A student can receive at most pages pages.
Try pages = max(arr) (minimum possible max load)
up to pages = sum(arr) (maximum possible load).
For each pages, simulate allocation:
Assign books sequentially.
If current student exceeds pages, give books to next student.
If students used ≤ k, then this pages is a valid distribution → return it.
Brute force returns the first valid value because pages increases from smallest to largest.
This ensures the smallest possible maximum pages is returned.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

using namespace std;

class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();

        // If more students than books → impossible
        if (k > n)
            return -1;

        // Minimum possible value of max pages = largest single book
        int lowestPagesPossible = *max_element(arr.begin(), arr.end());

        // Maximum possible value = sum of all pages
        int sum = 0;
        for (auto x : arr)
            sum += x;

        int largestPagesPossible = sum;

        // Try every possible maximum pages value from lowest to highest
        for (int pages = lowestPagesPossible; pages <= largestPagesPossible; pages++)
        {
            int studentsWhoGotPagesAlloted = 1;   // start with 1 student
            int currSum = 0;                      // pages for current student
            bool possible = true;                 // to check if allocation works

            // Try to allocate books to students
            for (int i = 0; i < n; i++)
            {
                // If a book exceeds allowed pages → impossible
                if (arr[i] > pages)
                {
                    possible = false;
                    break;
                }

                currSum += arr[i];

                // If current student exceeds pages → new student needed
                if (currSum > pages)
                {
                    studentsWhoGotPagesAlloted++;
                    currSum = arr[i];  // new student gets this book
                }

                // If more than k students needed → invalid
                if (studentsWhoGotPagesAlloted > k)
                {
                    possible = false;
                    break;
                }
            }

            // If allocation possible with ≤ k students → answer found
            if (possible && studentsWhoGotPagesAlloted <= k)
                return pages;
        }

        return -1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force + Feasibility Check
This is the naive version of the famous pattern:
“Binary Search on Answer” / “Search Space Reduction”


*/

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

        if(k>n)
            return -1;

        int low = *max_element(arr.begin(), arr.end());

        int sum = 0;
        for (auto x : arr)
            sum += x;

        int high = sum;
        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int studentsWhoGotPagesAlloted = 1;
            int j = 0;

            int currPages = 0;
            while (j < n)
            {
                currPages += arr[j];
                if (currPages > mid)
                {
                    studentsWhoGotPagesAlloted++;
                    currPages = arr[j];
                }
                j++;
            }

            if (studentsWhoGotPagesAlloted > k)
                low = mid + 1;

            else if (studentsWhoGotPagesAlloted <= k)
            {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
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
// Key things
//___________________________________________________________________________________________________________________________________________

/*
1. we can have less than k students. We have to distribute books in at most k students. problem does not explicitely states this.
2. What is mid:

What is mid in Book Allocation?

mid is not an index.
mid is not a book.
mid is a guess.

Specifically:

mid is our current guess for the minimum possible value of
the maximum pages any student will get.
This problem’s goal is:
Minimize the maximum number of pages assigned to any student.
So we binary-search on that maximum value.
💡 Why do we guess a maximum instead of splitting directly?
Because splitting books in all possible ways is impossible (too many ways).
So instead of finding the perfect split directly, we ask:
“Suppose the maximum pages allowed per student is mid.
Can we distribute books among ≤ k students without exceeding mid for any student?”

If YES → This mid is possible, try a smaller one
If NO → This mid is too small, try bigger one

🚀 How is mid computed?
mid = low + (high - low) / 2;

Where:

low = max(arr)
(minimum possible max pages — because someone must take the largest book)

high = sum(arr)
(maximum possible max pages — if one student takes everything)
So mid is a number between these two.

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(N log S)
Where:
N = number of books
S = sum(arr) − max(arr)
Reason:
Binary search takes log S
For each mid, you scan array once → O(N)

✅ 4. Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal:
Allocate books to ≤ k students (each gets contiguous books),
such that the maximum pages any student gets is minimized.

🔥 Key Insight
Instead of deciding how to split,
we decide:“Can we allocate books so that no student gets more than mid pages?”
This is done using Binary Search on Answer.
Steps:
Search space (minimum & maximum possible answer):
Minimum = largest book (because one student must take that book)
Maximum = sum of all books (one student takes all)
Binary search mid = a possible maximum pages per student
Check feasibility (can we allocate using ≤ k students?):
Keep adding books to current student
If pages exceed mid → allocate to new student
Count students used
If more than k students needed → mid too small → increase low
If <= k students → mid is valid → store result and try to reduce max load
Finally, return stored result.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Minimum possible max pages is the largest single book
        int low = *max_element(arr.begin(), arr.end());

        // Maximum possible max pages = sum of all pages
        int sum = 0;
        for (auto x : arr)
            sum += x;

        int high = sum;
        int res = -1;

        // Binary search on the answer
        while (low <= high)
        {
            int mid = low + (high - low) / 2;   // assume mid is max pages any student gets

            int studentsWhoGotPagesAlloted = 1; // start with 1 student
            int currPages = 0;                  // pages for current student

            // Try to allocate books greedily
            for (int j = 0; j < n; j++)
            {
                currPages += arr[j];

                // If adding this book exceeds mid, allocate to a new student
                if (currPages > mid)
                {
                    studentsWhoGotPagesAlloted++;
                    currPages = arr[j]; // new student starts with this book
                }
            }

            // If more than k students needed → mid too small
            if (studentsWhoGotPagesAlloted > k)
                low = mid + 1;

            // If <= k students used → mid is valid → try minimizing it
            else
            {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Binary Search on Answer / Search Space Binary Search
*/

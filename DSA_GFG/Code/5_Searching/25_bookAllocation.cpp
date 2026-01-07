// Problem statement:
// The program you've written solves the classic Book Allocation Problem. The goal is to distribute a set of books (given by an array of their
//  page counts) among a specific number of students. The distribution must follow two rules:
// Each student gets a contiguous block of books.
// The distribution should be done in such a way that the maximum number of pages assigned to any single student is minimized.
// Your code finds this "minimum possible maximum" value. It does this using a very clever and efficient algorithm: Binary Search on the Answer.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(const vector<int> &arr_no_of_pages, int n_no_of_books, int no_of_students, int max_allowed_pages)
{
    int students = 1;
    int pages_for_current_student  = 0;

    for(int i = 0; i<n_no_of_books; i++)
    {
        if(arr_no_of_pages[i] > max_allowed_pages)
        {
            return false;
        }
        if(pages_for_current_student  + arr_no_of_pages[i] <= max_allowed_pages)
        {
            pages_for_current_student  +=arr_no_of_pages[i];
        }
        else
        {
            students++;
            pages_for_current_student  = arr_no_of_pages[i];
        }
    }

    return students > no_of_students ? false : true;
}

int allocateMinPages(const vector<int> &arr_no_of_pages, int no_of_students)
{
    int n_no_of_books = arr_no_of_pages.size();

    if(no_of_students > n_no_of_books)
        return -1;
    
    int sum = 0;

    for(int i= 0; i<n_no_of_books; i++)  // this is O(n)
    {
        sum += arr_no_of_pages[i];
    }

    int start = *max_element(arr_no_of_pages.begin(), arr_no_of_pages.end());
    int end = sum;
    int ans = -1;

    while(start<=end)  //  time  c: this is O(log(sum)). Overall O(n⋅log(sum of pages)) see nested function
    {
        // int mid = (start + (end - start))/2; // wrong
        int mid = start + (end - start) / 2;


        if(isPossible(arr_no_of_pages, n_no_of_books, no_of_students, mid))  // time  c: this is O(n)
        {
            ans = mid;
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> pages = {2, 1, 3, 4};
    int students = 2;
    cout << allocateMinPages(pages, students) << "\n"; 
    return 0;
}


// time 
// binary search takes about O(log(sum)).
// For each mid, we run isPossible() which scans all n books → O(n).
// overall : O(n⋅log(sum of pages))
// space. O(1)

// logic



/*


// Instead of trying to figure out the allocations directly, your code searches for the answer itself. It knows the answer (the minimum 
possible maximum pages for a student) must be somewhere between:

Lower Bound: The number of pages in the largest single book.

Upper Bound: The total number of pages in all books combined.

Your allocateMinPages function performs a binary search within this range. For each potential answer (mid) it checks, it asks a
 simple question: "Is it possible to allocate the books so that no student has more than mid pages?" The isPossible function is 
 responsible for answering this question.

 
 Function 1: allocateMinPages
This is the main function that drives the logic.

int allocateMinPages(const vector<int> &arr_no_of_pages, int no_of_students)
{
    // Get the number of books.
    int n_no_of_books = arr_no_of_pages.size();

    // A crucial edge case: if you have more students than books, it's impossible
    // to give each student at least one book.
    if(no_of_students > n_no_of_books)
        return -1;
    
    // Calculate the search space for the binary search.
    long long sum = 0; // Use long long to be safe from overflow
    for(int i= 0; i<n_no_of_books; i++)
    {
        sum += arr_no_of_pages[i];
    }

    // 'start' is the lower bound of our search space. The answer can't be
    // smaller than the biggest book.
    long long start = *max_element(arr_no_of_pages.begin(), arr_no_of_pages.end());
    // 'end' is the upper bound. The worst case is one student gets all books.
    long long end = sum;
    int ans = -1; // Stores the best possible answer found so far.

    // Standard binary search loop.
    while(start <= end)
    {
        // Correctly calculate the midpoint of the current search range.
        long long mid = start + (end - start) / 2;

        // Ask the helper function: Can we achieve this 'mid' value?
        if(isPossible(arr_no_of_pages, n_no_of_books, no_of_students, mid))
        {
            // check if there is more worthy minimum value
            // If it's possible, this 'mid' is a potential answer.
            // We store it and try to find an even BETTER (smaller) one.
            // So, we shrink the search space to the lower half.
            ans = mid;
            end = mid - 1;
        }
        else
        {
            // If it's not possible, 'mid' is too small. We need to allow
            // more pages. So, we shrink the search space to the upper half.
            start = mid + 1;
        }
    }
    return ans;
}


Function 2: isPossible
This is the helper function, often called a "feasibility checker." Its only job is to answer one question: given a hard limit on pages 
(max_allowed_pages), can we fit all the books into the given number of students?

It does this using a greedy approach.



bool isPossible(const vector<int>& arr_no_of_pages, int n_no_of_books, int no_of_students, long long max_allowed_pages)
{
    int students_required = 1; // Start with the first student.
    long long pages_for_current_student = 0; // This student has 0 pages so far.

    for(int i = 0; i < n_no_of_books; i++)
    {
        // First check: If any single book is bigger than our limit, it's impossible.
        // Because we have to allot pages to every student
        if(arr_no_of_pages[i] > max_allowed_pages)
        {
            return false;
        }

        // Greedily add the current book to the current student if it fits.
        if(pages_for_current_student + arr_no_of_pages[i] <= max_allowed_pages)
        {
            pages_for_current_student += arr_no_of_pages[i];
        }
        else
        {
            // If the book doesn't fit, the current student is full.
            // We need to bring in a new student.
            students_required++;
            // This new student starts with the current book.
            pages_for_current_student = arr_no_of_pages[i];
        }
    }

    // After checking all books, did we use more students than we have?
    return students_required <= no_of_students;
}





How It Works with Your main Example
Let's trace pages = {2, 1, 3, 4} and students = 2.

allocateMinPages starts.

Search space is set: start = 4 (largest book), end = 10 (sum of all pages).

Iteration 1:

mid = 4 + (10 - 4) / 2 = 7.

Call isPossible with a limit of 7 pages.

Student 1 gets book 1 (2 pages). Current total: 2.

Student 1 gets book 2 (1 page). Current total: 3.

Student 1 gets book 3 (3 pages). Current total: 6.

Can Student 1 take book 4 (4 pages)? No, 6 + 4 > 7.

Need a new student. Student 2 gets book 4.

Total students used: 2. This is <= no_of_students. So isPossible returns true.

Since it was possible, we know 7 is a potential answer. Let's try for better. ans becomes 7, end becomes 6.

Iteration 2:

Search space is now ``.

mid = 4 + (6 - 4) / 2 = 5.

Call isPossible with a limit of 5. It will fail because you'd need 3 students: {2, 1}, {3}, {4}. isPossible returns false.

Since it failed, 5 is too small. start becomes 6.

Iteration 3:

Search space is now ``.

mid = 6 + (6 - 6) / 2 = 6.

Call isPossible with a limit of 6.

Student 1: gets books 1, 2, 3 (total 6 pages).

Student 2: gets book 4 (total 4 pages).

Works with 2 students. isPossible returns true.

ans becomes 6, end becomes 5.

The loop terminates because start (6) is now greater than end (5).

The last valid answer found, ans = 6, is returned.



QUEStion

for {2,1,3,4}
s1 = 2, s2 = 8,
s1 = 3, s2 = 7,
s1 = 6 , s2 =4
isnt minimum no of pages are 2. so ans is 6

Ans:

The goal is to choose the split that is the fairest. "Fairest" means we want to minimize the maximum load. We want to make the life of the most overworked student as easy as possible.

Let's look at the "maximum load" from each of your splits:

From Split 1, the maximum load is 8.

From Split 2, the maximum load is 7.

From Split 3, the maximum load is 6.

The problem asks for the minimum of these maximums.

What is min(8, 7, 6)?

It's 6.

Answering Your Specific Question
"isnt minimum no of pages are 2. so ans is 6"

You are noticing that in Split 1, one student gets only 2 pages. That is indeed the smallest pile a student gets across all scenarios. 
But the problem isn't asking for the "minimum pages any single student ever gets." It's a "minimax" problem: Minimize the Maximum.

Think of it like this: You are the teacher. You have three plans for assigning the books.

Plan A: One student gets 8 pages, the other gets 2. The student with 8 pages complains.

Plan B: One student gets 7 pages, the other gets 3. The student with 7 pages complains.

Plan C: One student gets 6 pages, the other gets 4. The student with 6 pages complains, but they are complaining about the lightest 
"heavy load" possible.

Plan C is the fairest distribution because the highest burden (6 pages) is lower than the highest burden in any other plan.

Therefore, the answer is 6. 






*/
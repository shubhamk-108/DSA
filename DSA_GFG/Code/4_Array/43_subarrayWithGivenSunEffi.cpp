//Solved through sliding window approach

// Our Task: Given an array arr[ ] of non-negative integers and an integer sum, find a subarray that adds to a given sum.

// Examples: 

// Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
// Output: Sum found between indexes 2 and 4
// Explanation: Sum of elements between indices 2 and 4 is 20 + 3 + 10 = 33

// Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
// Output: Sum found between indexes 1 and 4
// Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

// Input: arr[] = {1, 4}, sum = 0
// Output: No subarray found
// Explanation: There is no subarray with 0 sum



#include <stdio.h>
#include <iostream>
using namespace std;
/* Returns true if the there is a subarray of arr[] with a sum equal to 'sum'
otherwise returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
	int current_sum = arr[0];
	int start_of_window = 0;

	for (int i = 1; i <= n; i++)
	{
		while (current_sum > sum && start_of_window < i - 1)
		{
			current_sum = current_sum - arr[start_of_window];
			start_of_window++;
		}

		if (current_sum == sum)
		{
			cout << "Sum found between index " << start_of_window << " to " << i - 1;
			return 1;
		}

		if (i < n)
		{
			current_sum += arr[i];
		}
	}

	// If we reach here, then no subarray
	cout << "No subarray found";
	return -1;
}

// Driver program to test above function
int main()
{
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}






// Time Complexity: O(n)
// Auxiliary Space: O(1). Since no extra space has been taken.




// Logic: 


/*


The Core Idea: The Variable-Size Sliding Window
Think of a "window" that slides over the array. This window represents the current subarray we are examining.

The window has a start (the left edge) and an end (the right edge).

The start pointer is the variable start.

The end pointer is managed by the loop counter i.

curr_sum always holds the sum of the elements currently inside the window.

The algorithm's strategy is to intelligently adjust this window:

Expand: If the curr_sum is less than the target sum, it expands the window to the right to include more elements.

Shrink: If the curr_sum is greater than the target sum, it shrinks the window from the left to decrease the sum.

Match: If the curr_sum is exactly equal to the target sum, we've found our answer.

This is much more efficient because we never re-add all the elements. We just add one new element or subtract one old element at each step.

Step-by-Step Breakdown of the Code
Let's trace the code with an example to see how it works.
Array: arr = {1, 4, 20, 3, 10, 5}
Target Sum: sum = 33

1. Initialization

int curr_sum = arr[0], start = 0, i;
curr_sum starts with the value of the first element. curr_sum = 1.

start is the left edge of our window, initialized to index 0.

Our initial window is just {1}.

2. The Main Loop

for (i = 1; i <= n; i++) 
The loop starts at i = 1 and will be our "right edge" pointer. It systematically expands the window.

Iteration 1: i = 1

Window is {1}, curr_sum = 1, start = 0.

Shrink Check (while): Is 1 > 33? No.

Match Check (if): Is 1 == 33? No.

Expand (if (i < n)): Add arr (which is 4) to curr_sum.

curr_sum becomes 1 + 4 = 5.

The window is now effectively {1, 4}.

Iteration 2: i = 2

Window is {1, 4}, curr_sum = 5, start = 0.

Shrink Check (while): Is 5 > 33? No.

Match Check (if): Is 5 == 33? No.

Expand (if (i < n)): Add arr (which is 20) to curr_sum.

curr_sum becomes 5 + 20 = 25.

The window is now {1, 4, 20}.

Iteration 3: i = 3

Window is {1, 4, 20}, curr_sum = 25, start = 0.

Shrink Check (while): Is 25 > 33? No.

Match Check (if): Is 25 == 33? No.

Expand (if (i < n)): Add arr (which is 3) to curr_sum.

curr_sum becomes 25 + 3 = 28.

The window is now {1, 4, 20, 3}.

Iteration 4: i = 4

Window is {1, 4, 20, 3}, curr_sum = 28, start = 0.

Shrink Check (while): Is 28 > 33? No.

Match Check (if): Is 28 == 33? No.

Expand (if (i < n)): Add arr (which is 10) to curr_sum.

curr_sum becomes 28 + 10 = 38.

The window is now {1, 4, 20, 3, 10}.

Iteration 5: i = 5

Window is {1, 4, 20, 3, 10}, curr_sum = 38, start = 0.

Shrink Check (while): Is 38 > 33? Yes. The while loop starts.

Remove arr[start] (which is arr, value 1). curr_sum becomes 38 - 1 = 37.

Increment start. start is now 1.

The window is now {4, 20, 3, 10}.

Check the while condition again: Is 37 > 33? Yes.

Remove arr[start] (which is arr, value 4). curr_sum becomes 37 - 4 = 33.

Increment start. start is now 2.

The window is now {20, 3, 10}.

Check the while condition again: Is 33 > 33? No. The loop stops.

Match Check (if): Is curr_sum == 33? Yes!

printf is called with start (which is 2) and i-1 (which is 5-1 = 4).

Output: "Sum found between indexes 2 and 4".

The function returns 1 and exits.




A Subtle but Important Detail
Why does the loop run up to i <= n?

This is a clever way to handle the case where the subarray that matches the sum ends at the very last element of the array.

In our trace, the match was found when i was 5. If the match had not been found then, the code would have added arr and continued to i=6. 
When i=6 (i == n), the loop runs one last time:

It performs the while (shrink) and if (match) checks on the final window state.

This is also the reason that at the end we have to check if (i < n) because loop is taking one extra iteration so we have
to check it while doing sum otherwise it will add garbage value at the end and give wrong output.





why this conditon && start_of_window < i - 1
This is because at any point we have to keep at least one element in the window. So if we try to shrink then i whould already have
gone for next iteration so i would jhave been incremented and now we are trying to shrink then suppose we have {10,20,30,40}
then if in window we have {10,20,30} and i will be pointing to next iteration that is 3rd index. i-1 = 3-1 = 2. So if we take
start_of_window < 2 then we have to substract / delete 0th and 1st element and that way we will have at least one element in the 
window which is correct. If we would have taken start_of_window < i then i = 3 and  less than 3 means condition is valid for 
0th, 1st and 2nd index. SO that way we will delete everything from the window and we will be having no element in the window
which is wrong. 




*/



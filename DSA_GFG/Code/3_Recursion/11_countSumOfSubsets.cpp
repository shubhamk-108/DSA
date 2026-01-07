// This function counts the number of subsets of an array whose elements sum is equal to given value (sum).
// Suppose you have {10, 20, 15, 25, 24, 1} and you want subsets that sum to 25.
//  subset is {25}, {10, 15}, {24, 1}.
//  so output is 3 subsets of having sum = sum

#include <iostream>
#include <limits.h>
using namespace std;
#include<vector>

int countSubsets(int arr[], int n, int sum)
{
	if(n==0)
		return sum==0? 1 : 0;

	return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);
}



int main() {
    
    	int n = 6, arr[]= {10, 20, 15, 25, 24, 1}, sum = 25;

    	cout<<countSubsets(arr, n, sum);
		
    	
    	return 0;
}

// time and space

// The time complexity of the recursive function is O(2^n), and the space complexity is O(n).

// Time complexity:
// For each element, you have two choices: include it or not. This creates a binary tree of all possibilities, resulting in 2^n
//   function calls in the worst case, making the time complexity exponential, O(2^n)

//   Space complexity:
// The recursion stack can go as deep as n (since at each step you reduce n by 1 until it reaches 0), 
// so the auxiliary space is O(n) due to the call stack
// -----------------------------------------------------------------------------------------------

// Logic:

// How does it work?
// Base Case:
// if(n==0)

// When no elements left (n == 0), check if the required sum is also 0 (sum == 0).

// If yes, we've found a valid subset; return 1.

// If not, return 0.

// Recursive Case:
// We consider two possibilities for each element:

// Exclude the last element:
// Don't include arr[n-1] in the subset. So, call for n-1 elements with the same sum.

// Include the last element:
// Include arr[n-1] in the subset. Now, reduce the sum by arr[n-1] and call for n-1 elements.

// Sum of both:
// The total number of subsets for the current (n, sum) is the sum of both cases above.

// // My question to chatgpt:
// but when we were printing subsets at that time we have run two recursive function seperately something like this .
// 			// exclude
//             solve(nums, output, index+1, ans);
//             // include
//             solve(nums, output, index+1, ans);
// so why here in count sum we are calling both function in same call and adding them

// Answer:
// 1. Printing subsets:
// When you want to print all subsets (or store them), you "branch out" your recursion in two ways:

// Exclude the current element and move ahead.

// Include the current element (add it to your current output), and move ahead.

// You separately make two recursive calls.

// 2. Counting subsets (countSum example):
// When you care only about the number of subsets (not what they are), you still have the same two choices at each step (include/exclude), but:

// You combine the results: Each path returns a count.

// You don't need to remember the subset itself, just count how many lead to the target sum.

// Each function returns a count of valid subsets for its branch, and we add them. We're not collecting or printing each subset, just tallying the total.

// Why the difference?
// Printing/storing subsets: You must execute both branches in full and do something with the results (like add to ans vector).

// Counting: You're only interested in how many, so you just return numbers and add them up.

// Both use two recursive calls, but:
// Print/store: Side effect is important (what you collect/print).

// Count: Only the number returned matters; combine them via summation.
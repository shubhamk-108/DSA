// You are given a rope of length n. You want to cut it into pieces such that each piece length is either a, b, or c, and you 
// want to maximize the number of pieces you get.
// The function maxCuts(n, a, b, c) returns the maximum number of pieces you can cut the rope into.

#include <iostream>
using namespace std;

int maxCuts(int n, int a, int b, int c)
{
	if(n==0)
		return 0;
	if (n<0)
		return -1;
	
	int res = max(maxCuts(n-a, a,b,c), max(maxCuts(n-b, a,b,c), maxCuts(n-c,a,b,c)));

	if(n == -1)
		return -1;
	
	return res = res + 1;
}


int main() {
	
	int n = 5, a = 2, b = 1, c = 5;
	
	cout<<maxCuts(n, a, b, c);
	
	return 0;  
}

// Time complexity :
// This is a brute-force recursion that tries 3 recursive calls per level, so:
// Time Complexity = O(3ⁿ) (Exponential)
// 🧠 Why?
// Every call branches into 3 new calls (for each cut length), up to depth n.

// space complexity:
// Each recursive call uses space on the call stack.
// Your function makes up to 3 recursive calls at each level:
// One with n - a
// One with n - b
// One with n - c
// This forms a recursive tree, with many branching paths.
// But what matters for space complexity is the maximum depth of the recursion stack, not total calls.
// 🧮 What’s the Maximum Depth?
// The worst-case depth is when:
// Each recursive call subtracts the smallest of (a, b, c) from n
// Let’s say minVal = min(a, b, c)
// So maximum depth of recursion is approximately n / minVal
// So:
// Space Complexity = O(n / min(a, b, c))

// Logic

// Given:
// A rope of length n
// You can cut it into pieces of length a, b, or c
// Goal: Maximize the number of pieces after cuts such that total length used is exactly n.
// Output for n = 5, a = 2, b = 1, c = 5
// It tries all combinations of cuts:
// 2+1+2
// 1+1+1+1+1
// 5
// And returns the maximum number of cuts.
// Answer = 5 (cut 1 five times)

// if(n == 0)
//     return 0;
// Rope is completely used — this is a valid cutting pattern.
// We return 0 because no further cuts needed.

// if(n <= -1)
//     return -1;
// This means you made an invalid cut (cut too much).
// So we return -1 to indicate this path is not allowed.


// 🔄 Recursive Step
// You are trying all three possibilities:
// Cut a piece of size a, and solve for remaining n - a
// Cut a piece of size b, and solve for n - b
// Cut a piece of size c, and solve for n - c
// Each of these returns the maximum number of pieces possible from that path.
// Then, you take the maximum of all three paths.


// Handle Failure Case	
//  if(res == -1)
//     return -1;
// All 3 paths failed (e.g., couldn't make any cut that led to exact solution).
// So we return -1 to indicate no valid cuts possible from this n.


// Add 1 for the current cut
// return res + 1;
// If at least one path returned a valid result (res != -1), that means:
// You made a successful cut at this level
// And res is the number of pieces from the rest of the rope
// So you add 1 to count this cut.
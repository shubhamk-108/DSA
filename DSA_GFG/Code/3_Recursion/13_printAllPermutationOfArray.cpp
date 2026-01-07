// Java program to print all permutations of a
// given string.
// for example for ip [ 1,2,3], output should be 
// 1 2 3 , 1 3 2 , 2 1 3 , 2 3 1 , 3 1 2 , 3 2 1


// ---------------------------------------------------------------------------------
//  This code is explained in my notebook dsa (dsa -1). Problem No : 2
// ---------------------------------------------------------------------------------


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

class Permutation
{
private:
void recurPermute(vector<int> &nums, vector<int>& ds, int freq[], vector<vector<int>> &ans)
	{
		if (ds.size() == nums.size())
			{
			    ans.push_back(ds);
			    return;
			}
		else
		{
			for(int i = 0; i<nums.size(); i++)
			{
				if(!freq[i])
				{
					ds.push_back(nums[i]);
					freq[i] = 1;
					recurPermute(nums, ds, freq, ans);
					freq[i] = 0;
					ds.pop_back();
				}
			}
		}
	}

	public :
		vector<vector<int>> permute(vector<int> &nums)
		{
			vector<vector<int>> ans;
			vector<int>ds;
			int freq[nums.size()] ;
			for(int i = 0 ; i< nums.size(); i++)
				freq[i] = 0;
			recurPermute(nums, ds, freq, ans);
			return ans;
		}


};



int main()
{
	
	Permutation p;
	vector<int> nums = {1,2,3};
	vector<vector<int>> final_ans = p.permute(nums);

	for(auto outerVector : final_ans)
	{	
		// cout<<", ";
		for(auto innerVector : outerVector)
		{
			cout<<innerVector<<" ";
		}
		cout<<", ";
	}
	return 0;
}







// Logic:

// Start with an empty temporary vector ds (short for "data structure") to store the current permutation we're building.

// Create a freq[] array (same length as input array) to track which elements have been used so far in the current permutation:

// freq[i] == 0 → element at index i is not used yet.

// freq[i] == 1 → element at index i is already used.

// Now, begin a recursive process:

// At each recursive level, loop through every index i of the input array.

// If freq[i] == 0, then:

// Add nums[i] to ds → this is your choice at this level.

// Set freq[i] = 1 → mark as used.

// Recurse to the next level (to make the next choice).

// After the recursive call returns:

// Reset freq[i] = 0 → unmark (so others can use it later).

// Remove the last element from ds (undo your choice → backtrack).

// Base case of recursion:

// If the size of ds becomes equal to nums (input array), it means you have a complete permutation.

// Store it in your ans list.

// At the end, ans will contain all permutations.

// Input: nums = [1, 2, 3]
// We’ll trace the recursive calls and how the ds, freq, and ans evolve.

// 📦 Initial Setup:
// ds = []

// freq = [0, 0, 0]

// ans = []

// 🔁 Level 0 (Start): ds = []
// We loop over i = 0 to 2

// i = 0 → Pick 1
// ds = [1]

// freq = [1, 0, 0]

// Call recursively...

// 🔁 Level 1: ds = [1]
// Loop again i = 0 to 2

// i = 0 → already used (skip)

// i = 1 → pick 2

// ds = [1, 2]

// freq = [1, 1, 0]

// Call recursively...

// 🔁 Level 2: ds = [1, 2]
// Loop again:

// i = 0 → used

// i = 1 → used

// i = 2 → pick 3

// ds = [1, 2, 3]

// freq = [1, 1, 1]

// ✅ Base case: ds.size() == nums.size(), so:

// Add [1, 2, 3] to ans.

// ⬅️ Backtrack from Level 2:
// Pop 3: ds = [1, 2]

// Unmark freq[2] = 0

// Back to Level 1

// Continue Level 1 (i = 2):
// i = 2 → pick 3

// ds = [1, 3]

// freq = [1, 0, 1]

// Recurse...

// 🔁 Level 2: ds = [1, 3]
// Loop:

// i = 0 → used

// i = 1 → pick 2

// ds = [1, 3, 2]

// freq = [1, 1, 1]

// ✅ Add [1, 3, 2] to ans

// Backtrack: pop 2, unmark freq[1] = 0 → ds = [1, 3]

// Pop 3, unmark freq[2] = 0 → ds = [1]

// Back to Level 0

// Level 0 (i = 1): Pick 2
// ds = [2]

// freq = [0, 1, 0]

// Recurse...

// 🔁 Level 1: ds = [2]
// i = 0 → pick 1 → ds = [2, 1]

// Recurse → pick 3 → ds = [2, 1, 3]

// ✅ Add to ans, then backtrack

// Try i = 2 → pick 3 → ds = [2, 3], then 1 → [2, 3, 1]

// ✅ Add to ans, backtrack

// Back to Level 0

// Level 0 (i = 2): Pick 3
// Same steps give us:

// [3, 1, 2]

// [3, 2, 1]

// ✅ Final ans
// ans = {
//   {1, 2, 3},
//   {1, 3, 2},
//   {2, 1, 3},
//   {2, 3, 1},
//   {3, 1, 2},
//   {3, 2, 1}
// }






// ---------------------------------------------------------------------------------------------------------------------

// TIME COMPLEXITY
// We are generating all permutations of the input array.
// 🔸 Number of permutations = n!
// Because every element has to appear in every position once → total unique permutations of n elements is n!
// 🔸 Work done per permutation:
// At each recursive call, we:
// •	Loop through all n elements.
// •	For each valid choice (i.e., not used), we:
// o	push element to ds
// o	mark freq[i] = 1
// o	call recursively
// o	backtrack: unmark, pop
// Each complete path (from root to leaf) does O(n) work per permutation (due to push/pop/mark/unmark).
// ________________________________________
// ✅ Final Time Complexity:
// O(n!⋅n)
// 	n! for all permutations
// •	n time for constructing and copying each permutation into ans
// ________________________________________
// 🧠 SPACE COMPLEXITY
// 🔹 Auxiliaries:
// •	ds → stores current permutation → max size n
// •	freq[] → size n
// •	Recursion stack → depth n (one for each element placed)
// So auxiliary space is:
// O(n)+O(n)+O(n)=O(n) 
// 🔹 Output space:
// •	ans will contain n! permutations
// •	Each permutation is of size n
// So output space is:
// O(n!⋅n) 
// ________________________________________
// ✅ Final Space Complexity:
// O(n!⋅n)  (auxiliary)

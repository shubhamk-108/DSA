#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

class Solution
{	
	private:
		void solve(vector<int>nums, vector <int>output, int index, vector<vector<int>> &ans)
		{
			if(index >= nums.size())
			{
				ans.push_back(output);
				return;

			}

			// exclude
			solve(nums, output, index+1, ans);

			// include
			int element = nums[index];
			output.push_back(element);
			solve(nums, output, index+1, ans);
		}

	public:
		vector<vector<int>> subsets(vector <int> & nums)
		{
			vector<vector<int>> ans;
			vector<int>output;
			int index = 0;

			solve(nums, output, index ,ans);
			sort(ans.begin(), ans.end());
			return ans;
		}

		

};


	
int main() {
	
	Solution s;
	vector<int> v = {1,2,3};

	vector<vector<int>> result =  s.subsets(v);

	for (auto x : result)
	{
		cout<< "[ ";
		for (int o : x)
		{
			cout<<o<<" ";
		}
		cout<< "] , ";
	}
	
	return 0;
}


//  Logic Explanation:
// Let's go step-by-step:

// ✅ subsets function:
// It initializes the variables needed:

// ans: to store all subsets.

// output: to build subsets during recursion.

// index: to track the current index in the input vector nums.

// It then calls the helper function solve.

// ✅ solve(nums, output, index, ans):
// This is the recursive function that does the actual work.

// At each step (each index of nums), we have two choices:

// Exclude the current element → go to next index without adding it to output.

// Include the current element → add it to output, then go to the next index.

// This leads to a binary tree of decisions:

// Left branch: excludes the element

// Right branch: includes the element

// 🔁 Base case:

// When index >= nums.size(), we’ve processed all elements.

// So, we push the current output subset into ans.

// 📌 The use of copying output in recursive calls is important:

// Since vector<int> is passed by value, any changes to output in one call won’t affect other branches of the recursion tree.

// 🧠 Example Trace (for input [1, 2]):

// solve([1,2], [], 0)
// ├── solve([1,2], [], 1)
// │   ├── solve([1,2], [], 2) → add []
// │   └── solve([1,2], [2], 2) → add [2]
// └── solve([1,2], [1], 1)
//     ├── solve([1,2], [1], 2) → add [1]
//     └── solve([1,2], [1,2], 2) → add [1,2]


// Final ans

// [
//  [], 
//  [2], 
//  [1], 
//  [1,2]
// ]
// Time Complexity:
// At each element, we make 2 choices: include or exclude.

// So for n elements → 2^n subsets

// Each subset can be up to size n, so copying into ans takes O(n) per subset in worst case.

// 🔹 Total time complexity:
// O(2^n × n)

// 🧠 Space Complexity:
// Recursive stack depth: O(n) (due to recursive calls)

// Output vector is copied in each call, but it's passed by value (so not modifying original).

// ans stores 2^n subsets, each of size up to n.

// 🔹 Total space complexity:
// O(2^n × n) (for storing subsets in ans)

// 🧪 Plus O(n) for recursion stack (auxiliary space)

// | Aspect            | Value                               |
// | ----------------- | ----------------------------------- |
// | Problem Solved    | Generating all subsets (power set)  |
// | Technique         | Backtracking (with include/exclude) |
// | Time Complexity   | O(2^n × n)                          |
// | Space Complexity  | O(2^n × n)                          |
// | Extra Stack Space | O(n)                                |

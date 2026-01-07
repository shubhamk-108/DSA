//------------------------------------------------------------------------------
// This problem is solved in notebook (dsa-1) Problem No - 3
// --------------------------------------------------------------------------------
// this is optimised code compared to previous code. because here we are not using extra ds or that extra space

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {

private:
    void solve(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, index+1, ans);
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};





int main()
{
	
	Solution s;
	vector<int> nums = {1,2,3};
	vector<vector<int>> final_ans = s.permute(nums);

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


// logic


// Time Complexity
// How many permutations are there?
// For n elements, the total permutations possible are:

// n!(factorial of n)

// Recursive calls:
// At index = 0: loop runs n times.

// At index = 1: loop runs n-1 times.

// ...

// At index = k: loop runs n-k times.

// Total number of recursive calls and paths explored corresponds to generating all permutations, which is 
// n!.

// Work done per permutation:
// Each complete permutation is stored via ans.push_back(nums), which copies a vector of length n.

// Copying costs 
// O(n) time.

// Total time complexity:
// O(n!)×O(n)=O(n×n!)
// n!permutations.

// Each permutation requires copying 
// O(n) elements into the answer vector.

// Space Complexity
// 1. Recursion stack:
// Maximum depth of recursion is 
// n because index increases by 1 until it reaches n.

// So, recursion stack space is:

// O(n)

// 2. Space for storing permutations (ans):
// There are 
// n! permutations.

// Each permutation is a vector of length 
// n.

// Total space for storing all permutations is:

// O(n×n!)
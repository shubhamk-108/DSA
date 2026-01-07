// this code is same as its previsous code file no 13.  I just implemented it in main function insted of class

// Java program to print all permutations of a
// given string.
// for example for ip [ 1,2,3], output should be 
// 1 2 3 , 1 3 2 , 2 1 3 , 2 3 1 , 3 1 2 , 3 2 1
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
		vector<vector<int>> permuteHelperFunction(vector<int> &nums, vector<int>& ds, int freq[], vector<vector<int>> &ans)
		{
			recurPermute(nums, ds, freq, ans);
			return ans;
		}


};



int main()
{
	
	Permutation p;
	vector<int> nums = {1,2,3};
	// vector<vector<int>> final_ans = p.permute(nums);

	vector<vector<int>> ans;
	vector<int>ds;
	int freq[nums.size()] ;
	for(int i = 0 ; i< nums.size(); i++)
		freq[i] = 0;
	
	vector<vector<int>> final_ans = p.permuteHelperFunction(nums, ds, freq, ans);

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

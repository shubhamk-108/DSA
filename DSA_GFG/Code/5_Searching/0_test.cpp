#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;
#include <vector>
#include <algorithm>

bool isPossible(vector<int> pages, int m, int maxAllowedPages)
{
	int n = pages.size();

	

	int students = 1;
	int current_Student_pages = 0;

	for (int i = 0; i < n; i++)
	{
		if (pages[i] > maxAllowedPages)
		return false;

		if (current_Student_pages <= maxAllowedPages)
		{
			current_Student_pages += pages[i];
		}
		else
		{
			students++;
			current_Student_pages = pages[i];
		}
	}
	return students <= m ? true : false;
}

int bookAllocation(vector<int> pages, int m)
{
	int n = pages.size();

	if (m > n)
		return -1;

	int sum = 0;
	for (auto x : pages)
		sum += x;
	int low = *max_element(pages.begin(), pages.end());
	int high = sum;
	int ans = -1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (isPossible(pages, m, mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

int main()
{
	vector<int> pages = {2, 1, 3, 4};
	int students = 2;
	cout << bookAllocation(pages, students) << "\n";
	return 0;
}

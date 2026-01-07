/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number
of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep
answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Explanation:
Day 0 → 73 → Next warmer temp is 74 (after 1 day)
Day 1 → 74 → Next warmer temp is 75 (after 1 day)
Day 2 → 75 → Next warmer temp is 76 (after 4 days)
Day 3 → 71 → Next warmer temp is 72 (after 2 days)
Day 4 → 69 → Next warmer temp is 72 (after 1 day)
Day 5 → 72 → Next warmer temp is 76 (after 1 day)
Day 6 → 76 → No warmer temp → 0
Day 7 → 73 → No warmer temp → 0

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        if(temperatures.empty())
            return {};
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int j;
            bool flag = false;
            for (j = i+1; j < n; j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                res.push_back(j - i);
            else
                res.push_back(0);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {73,74,75,71,69,72,76,73};
    vector<int> res = sol.dailyTemperatures(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

if correTime Complexity: O(n²) — For every day, you may look ahead to all future days.
Space Complexity: O(1) 

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop through each temperature i from 0 to n-1.
For every i, start another loop j = i + 1 to n-1 and check all future days.
If you find any day j where temperatures[j] > temperatures[i],
you have found the next warmer day,
record j - i as the number of days to wait,
and stop searching further for this i.
If the inner loop finishes without finding a warmer day, push 0 for that day.
Continue until all days are processed.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        if (temperatures.empty())
            return {};  // ✅ Return empty result for empty input

        vector<int> res;  // Stores days to wait for a warmer temperature

        // Outer loop: check for each day's temperature
        for (int i = 0; i < n; i++)
        {
            bool flag = false;  // Marks if a warmer day was found

            // Inner loop: look for the next warmer day
            for (int j = i + 1; j < n; j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    flag = true;                // Found warmer temperature
                    res.push_back(j - i);       // Store number of days waited
                    break;                      // Stop searching for this day
                }
            }

            // If no warmer day found, push 0
            if (!flag)
                res.push_back(0);
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

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
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();

        // Minimum capacity must be at least the heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum capacity is the sum of all weights
        int sum = 0;
        for (auto x : weights)
            sum += x;
        int high = sum;

        // Binary search for the minimum valid capacity
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int currWeightSum = 0; // Current day's load
            int currDays = 1;      // Start counting from day 1

            // Simulate packing the packages in order
            for (int j = 0; j < n; j++)
            {
                if (currWeightSum + weights[j] > mid)
                {
                    // Start a new day
                    currDays++;
                    currWeightSum = 0;
                }
                currWeightSum += weights[j];
            }

            // Adjust binary search based on number of days used
            if (currDays <= days)
                high = mid;       // Capacity works, try smaller
            else
                low = mid + 1;    // Capacity too small, increase it
        }

        // low == high is the minimum valid capacity
        return high;
    }
};

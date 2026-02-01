
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes,
                      vector<int> &runningCosts,
                      long long budget)
    {
        int n = chargeTimes.size();
        int left = 0;
        deque<int> maxDq;
        int len = 0;

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + runningCosts[i];

        for (int right = 0; right < n; right++)
        {
            while (!maxDq.empty() &&
                   chargeTimes[maxDq.back()] < chargeTimes[right])
                maxDq.pop_back();

            maxDq.push_back(right);

            while (left <= right)
            {
                long long windowSum =
                    prefixSum[right + 1] - prefixSum[left];

                int k = right - left + 1;

                long long cost =
                    chargeTimes[maxDq.front()] +
                    (long long)k * windowSum;

                if (cost <= budget)
                    break;

                if (maxDq.front() == left)
                    maxDq.pop_front();

                left++;
            }

            if (left <= right)
                len = max(len, right - left + 1);
        }

        return len;
    }
};

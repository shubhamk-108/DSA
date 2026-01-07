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
    int numRescueBoats(vector<int> &people, int limit)
    {

        int n = people.size();
        vector<bool> used(n, false);
        int boats = 0;

        for (int i = 0; i < n; i++)
        {

            if (used[i])
                continue;

            used[i] = true;
            int bestIdx = -1;

            for (int j = 0; j < n; j++)
            {

                if (used[j])
                    continue;
                if (i == j)
                    continue;

                if (people[i] + people[j] <= limit)
                {
                    if (bestIdx == -1 || people[j] > people[bestIdx])
                    {
                        bestIdx = j;
                    }
                }
            }

            if (bestIdx != -1)
                used[bestIdx] = true;

            boats++;
        }
        return boats;
    }
};

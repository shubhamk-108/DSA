#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;

    void solve(int idx, int aLeft, int bLeft,
               vector<vector<int>>& costs, int currCost) {

        // If cost already exceeds best answer, prune
        if (currCost >= ans) return;

        // All people processed
        if (idx == costs.size()) {
            if (aLeft == 0 && bLeft == 0)
                ans = min(ans, currCost);
            return;
        }

        // Send current person to City A
        if (aLeft > 0) {
            solve(idx + 1, aLeft - 1, bLeft,
                  costs, currCost + costs[idx][0]);
        }

        // Send current person to City B
        if (bLeft > 0) {
            solve(idx + 1, aLeft, bLeft - 1,
                  costs, currCost + costs[idx][1]);
        }
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        solve(0, n, n, costs, 0);
        return ans;
    }
};

// int main()
// {
//     Solution sol;
//     vector<int> p = {10, 8, 0, 5, 3};
//     vector<int> s = {2, 4, 1, 1, 3};
//     cout << sol.carFleet(12, p, s);
//     return 0;
// }
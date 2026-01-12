/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int height = heights[i];

            // expand left
            int left = i;
            while (left >= 0 && heights[left] >= height)
                left--;

            // expand right
            int right = i;
            while (right < n && heights[right] >= height)
                right++;

            int width = right - left - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(v);
    return 0;
}



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Worst case: O(N²)
Example: [1,1,1,1,1]
Each bar scans left and right fully

🧠 Space Complexity
O(1) (no extra data structures)
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*




*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*




*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*
"Fix minimum height and expand"
This brute is the mental foundation of the stack solution.



*/


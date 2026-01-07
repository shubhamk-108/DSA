/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 Diagram

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

LC gives the general Euclidean distance formula:
√ (x1​−x2​)^2 + (y1​−y2​)^2​

This formula is for the distance between two arbitrary points
(x 1 ​ ,y 1 ​ ) and ( 𝑥 2 , 𝑦 2 )

In LC 973, the distance is always from the origin.

Origin = (0,0)

So substitute:

𝑥2 = 0 and y2 = 0

and then the formula becomes under root x^2 + y^2

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

// This is heap problem so wE will do it in heap playlist
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> v = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> res = sol.kClosest(v, 2);

    for (auto &x : res)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Formula
//___________________________________________________________________________________________________________________________________________

/*


LC gives the general Euclidean distance formula:
√ (x1​−x2​)^2 + (y1​−y2​)^2​

This formula is for the distance between two arbitrary points
(x 1 ​ ,y 1 ​ ) and ( 𝑥 2 , 𝑦 2 )

In LC 973, the distance is always from the origin.

Origin = (0,0)

So substitute:

𝑥2 = 0 and y2 = 0

and then the formula becomes under root x^2 + y^2

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*


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




*/

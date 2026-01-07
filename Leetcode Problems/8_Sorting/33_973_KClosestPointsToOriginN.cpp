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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        
        int n = points.size();
        vector<pair<long long, vector<int>>> distances;

        for (auto &v : points)
        {
            long long d = (1LL * v[0] * v[0]) + (1LL * v[1] * v[1]);

            distances.push_back({d,v});

        }

        sort(distances.begin(), distances.end());

        vector<vector<int>> res;

        for (int i = 0 ; i < k; i++)
        {
            res.push_back(distances[i].second);
        }
        return res;
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

Let n = number of points.
Computing distances: O(n)
Sorting: O(n log n)
Extracting k points: O(k)
Total Time Complexity:
O(nlogn)

Space Complexity
Extra vector distances stores all points → O(n)
Result vector stores k points → O(k)
Total Space Complexity: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Find the k points closest to the origin (0,0).
Steps:
For every point (x, y), compute its distance from the origin using
x^2 + y^2
(square root not needed because we only compare distances).
Store each point along with its computed distance.
Sort all points based on their distance.
Take the first k points from the sorted list.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        // This vector will store:
        // (distance_from_origin, point)
        vector<pair<long long, vector<int>>> distances;

        // Step 1: Compute distance for each point
        for (auto &v : points)
        {
            // x^2 + y^2 (no sqrt needed)
            long long d = (1LL * v[0] * v[0]) + (1LL * v[1] * v[1]);

            // Store distance along with the point
            distances.push_back({d, v});
        }

        // Step 2: Sort points by distance (pair sorts by .first automatically)
        sort(distances.begin(), distances.end());

        // Step 3: Collect the first k closest points
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(distances[i].second);
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Decorate → Sort → Undecorate
Also known as:
Schwartz Transform
Sort by key pattern
How it applies here:
Decorate: attach distance to each point
Sort: by distance
Undecorate: return only the points



*/

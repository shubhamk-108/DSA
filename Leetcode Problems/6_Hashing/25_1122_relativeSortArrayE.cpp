/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in
arr2 should be placed at the end of arr1 in ascending order.

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]

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
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        unordered_map<int, int> ump2;
        for (int i = 0; i < n2; i++)    
        {
            if (!ump2.count(arr2[i]))
                ump2[arr2[i]] = i;
        }

        for (int i = 0; i < n1; i++)
        {
            if (!ump2.count(arr1[i]))
                ump2[arr1[i]] = INT_MAX;
        }

        auto myComparator = [&](int &a, int &b)
        {
            if (ump2[a] != ump2[b])
                return ump2[a] < ump2[b];
            else // (ump2[a] == ump2[b])
                return a < b;
        };

        sort(arr1.begin(), arr1.end(), myComparator);

        return arr1;
    }
};
int main()
{
    Solution sol;
    vector<int> v1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> v2 = {2, 1, 4, 3, 9, 6};
    vector<int> res = sol.relativeSortArray(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time:
Building map → O(n1 + n2)
Sorting → O(n1 log n1)
Comparator is O(1)
Final: O(n1 log n1)

Space:
Hash map → O(n1 + n2)
Final: O(n1 + n2)
 
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Map each value of arr2 → its index
This tells you the priority order
arr2[i] should come before arr2[j] if i < j.
Assign all arr1 elements NOT in arr2 an index of INT_MAX
Meaning: they should come after all arr2 values.
Custom Comparator
First compare by mapped index (order defined by arr2).
If mapped index is equal → sort by natural increasing value.
Sort arr1 using this comparator.


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


Store the order in a hash map
Sort arr1 with a comparator that uses the map to enforce priority

*/

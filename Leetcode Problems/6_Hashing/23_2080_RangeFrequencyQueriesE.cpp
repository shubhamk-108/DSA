/*
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).



Example 1:

Input
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
Output
[null, 1, 2]

Breaks down like this:
"RangeFreqQuery" → call constructor with [[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]]
That means the array arr = [12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]
Constructor does not return anything, so the output for this is always null
"query" → call query(1, 2, 4)
That means count how many times 4 occurs from index 1 to 2.
arr[1..2] = [33,4] → 4 occurs once → returns 1
"query" → call query(0, 11, 33)
arr[0..11] = entire array → 33 occurs twice → returns 2

Explanation
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.

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

class RangeFreqQuery
{
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value)
    {
        if (!mp.count(value))
            return 0;

        vector<int> & indicesOfValue = mp[value];
        int i = lower_bound(indicesOfValue.begin(), indicesOfValue.end(), left) - indicesOfValue.begin();
        int j = upper_bound(indicesOfValue.begin(), indicesOfValue.end(), right) - indicesOfValue.begin();

        int length = j - i;
        int numberOfOccurancesBetweenLeftAndRight = length;

        return numberOfOccurancesBetweenLeftAndRight;
    }
};

int main()
{
    vector<int> v = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery sol(v);
    // vector<int> v = {0, 1, 0, 3, 12};

    cout << sol.query(0, 11, 33);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// My explanation
//___________________________________________________________________________________________________________________________________________


/*

take ex: {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56}; and query (0, 11, 33) where left is 0, right is 11 and toFindValue is 33.
1.store all the occurances of value in the map. Store key value pair as nums[i] and there indices where they have occured.
2.Now we got like this:

value   indices
12:     0, 9
33:     1, 7
4:      2
56:     3
22:     4, 8
2:      5
34:     6, 10
56:     11

3. Now we know that all the indices are in sorted order.

4. What are lower_bound and upper_bound?
They are binary search functions from <algorithm> in C++.
So we can app;y here binary search.
Binary search is already implemented in lower_bound and upper_bound.

LOWER_BOUND
Definition:
Returns an iterator to the first element that is ≥ target. 
If target exists → returns its first occurrence
If target does not exist → returns the place where it should be inserted to maintain sorting
(= first element greater than target)

Definition:
Returns an iterator to the first element that is > target.
Meaning:
If target exists → returns the position after its last occurrence
If target does not exist → returns first element greater than target

Both functions return an iterator, NOT an index.
To convert to index:
int idx = iterator - vec.begin();

Syntax
lower_bound:
auto it = lower_bound(vec.begin(), vec.end(), x);

upper_bound:
auto it = upper_bound(vec.begin(), vec.end(), x);

vec.begin() → starting iterator
vec.end() → ending iterator
x → value to search

Examples (Crystal Clear)

Let’s use this sorted vector:

vec = {1, 2, 4, 4, 4, 7, 9}
   index: 0  1  2  3  4  5  6

🔵 Example 1 — lower_bound
lower_bound(vec, 4)

Return first element ≥ 4
Indices of 4 are {2,3,4}
So return index 2

int i = lower_bound(vec.begin(), vec.end(), 4) - vec.begin();
// i = 2

🔵 Example 2 — lower_bound for missing value
lower_bound(vec, 5)

Find first element ≥ 5
5 is not present
But 7 ≥ 5
So return index 5

🔵 Example 3 — lower_bound for smaller value
lower_bound(vec, 0)

First element ≥ 0 → index 0

🔵 Example 4 — lower_bound > last element
lower_bound(vec, 10)

No element ≥ 10
So returns vec.end() → index 7 (past last element)

🔥 UPPER_BOUND EXAMPLES
upper_bound(vec, 4)

Return first element > 4

Vec:
4’s end at index 4
Next element > 4 is 7 at index 5

upper_bound(vec, 5)

Return first element > 5 → 7
So index 5

upper_bound(vec, 9)

Return first element > 9 → doesn’t exist
→ return end() → index 7


Coming to our query (0, 11, 33) where left is 0, right is 11 and toFindValue is 33.
Now i know 33 is at index 1 and 7.
So we have to find in the range 0 to 11.
We applied lower bound and upper bound on the indices of 33 that is 1,7
Now left is 0. So we are searching for index 0 or index greater that 0. and 1 is greater than 0. So we will store the index of 1.
And on right we have 11. So we will find in 1,7 for 11. Upper bound finds immediate greater element. 11 is not there so it will
point element after 7, and its index will be 2. Because 1,7,upperBoundPointHere. 
Now how many elements are there in this range for this we just have to do r - l same as we find length when we use two different loops
like j - i.

*/



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n)
We scan the array once and store indices.
Per Query
lower_bound → O(log k)
upper_bound → O(log k)
Where k = number of occurrences of the value.
Worst case:
O(log n) per query.

Total Space
O(n)
Because we store the index of each element exactly once.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


For each query (left, right, value), quickly count how many times value appears in arr[left..right].
Key Observations
The array does not change, so we can preprocess it once.
For each value in the array, we store all indices at which it appears.
These indices are automatically stored in sorted order because we push them in order during preprocessing.
Now the problem reduces to:
Count how many numbers in a sorted list fall between [left, right].
This can be solved using:
lower_bound → first index ≥ left
upper_bound → first index > right
Difference → count of valid indices

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


unordered_map<int, vector<int>> mp;
✔ Stores positions of each number efficiently.


for (int i = 0; i < arr.size(); i++)
    mp[arr[i]].push_back(i);
✔ Preprocess
 all positions — vectors stay sorted automatically.


if (!mp.count(value))
    return 0;
✔ If value never appears, frequency is 0.


vector<int> & indicesOfValue = mp[value];
✔ Correct: using reference to avoid copying the vector.


int i = lower_bound(indicesOfValue.begin(), indicesOfValue.end(), left) 
        - indicesOfValue.begin();
✔ Finds first index where value appears ≥ left.


int j = upper_bound(indicesOfValue.begin(), indicesOfValue.end(), right) 
        - indicesOfValue.begin();
✔ Finds first index where value appears > right.


return j - i;
✔ Correct frequency in range.

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Use this pattern when:
Array is static (not changing).
You have many offline queries.
You need to count frequency in a subarray.
Using a map of value → sorted positions makes queries very fast.

This pattern appears in:
Range frequency queries
Count occurrences in interval
Count events inside a timeline
Binary searching on pre-stored index lists
Prefix problems where prefix sums don't help because queries are value-specific


*/

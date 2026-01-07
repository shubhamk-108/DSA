/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character
y in order,
then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "bcafg", s = "abcd"
Output: "bcad"
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
    string customSortString(string order, string s)
    {

        int n = order.length();
        int m = s.length();

        vector<int> um_order(26, INT_MAX);

        for (int i = 0; i < n; i++)
        {

            um_order[order[i] - 'a'] = i;
        }

        auto myComparator = [&](char ch1, char ch2)
        {
            return um_order[ch1 - 'a'] < um_order[ch2 - 'a'];
        };

        sort(s.begin(), s.end(), myComparator);

        return s;
    }
};

int main()
{
    Solution sol; 
    string order = "cba";
    string s = "abcddd";
    cout << sol.customSortString(order, s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Building rank array → O(n)
Sorting string s → O(m log m)
Total: O(n + m log m)
(where n = order.length() and m = s.length())

Space Complexity
Rank array of 26 characters → O(1) (constant space)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We are given two strings — order and s.
order defines a custom order of characters.
We must rearrange the characters of s so that they follow this custom order.
To achieve this efficiently:
Assign each character in order a rank (index) — lower index = higher priority.
Characters not in order get the largest rank (INT_MAX) so they appear last.
Sort string s using a custom comparator based on these ranks.
The sort() function uses our comparator to decide which character should come first.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    string customSortString(string order, string s)
    {
        // Step 1: Create an array to store order/rank of each character
        // Initialize all to INT_MAX (so chars not in 'order' go to the end)
        vector<int> um_order(26, INT_MAX);

        // Step 2: Assign rank based on position in 'order'
        for (int i = 0; i < order.length(); i++)
        {
            um_order[order[i] - 'a'] = i;
        }

        // Step 3: Define comparator that sorts based on rank from 'order'
        auto myComparator = [&](char ch1, char ch2)
        {
            return um_order[ch1 - 'a'] < um_order[ch2 - 'a'];
        };

        // Step 4: Sort 's' using custom comparator
        sort(s.begin(), s.end(), myComparator);

        // Step 5: Return the sorted string
        return s;
    }
};



*/

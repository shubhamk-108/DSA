
/*

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:
Input: strs = [""]
Output: [[""]]
Example 3:
Input: strs = ["a"]
Output: [["a"]]

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool checkAnagram(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 != n2)
            return false;

        int freq_arr[26] = {0};

        for (int i = 0; i < n1; i++)
        {
            freq_arr[s1[i] - 'a']++;
            freq_arr[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq_arr[i] != 0)
                return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string> &str)
    {
        int n = str.size();

        unordered_set<int> us_alreadyProcessedIndices;
        vector<vector<string>> res;

        for (int i = 0; i < n; i++)
        {
            if (us_alreadyProcessedIndices.find(i) == us_alreadyProcessedIndices.end())
            {
                vector<string> inner_vector;
                inner_vector.push_back(str[i]);
                for (int j = i + 1; j < n; j++)
                {
                    if (checkAnagram(str[i], str[j]))
                    {
                        inner_vector.push_back(str[j]);
                        us_alreadyProcessedIndices.insert(j);
                    }
                }
                res.push_back(inner_vector);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> s1 = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> res = sol.groupAnagrams(s1);
    for (auto outer_vector : res)
    {
        for (auto inner_vector : outer_vector)
        {
            cout << inner_vector << ", ";
        }
        cout << endl;
    }

    return 0;
}


// timespace


/*

Complexity Analysis
Time Complexity: O(N² * K)
N is the number of strings in the strs vector.
K is the maximum length of a string in strs.
The outer loop runs N times, and the inner loop runs up to N times, leading to roughly O(N²) comparisons.
Each checkAnagram call takes O(K) time.
This makes the total complexity O(N * N * K), which is too slow for large inputs on LeetCode and will result in a "Time Limit Exceeded" (TLE) error.

Space Complexity: O(N * K)
The us_alreadyProcessedIndices set stores at most N integers.
The space required for the output res is the dominant factor. In the worst case (no anagrams), it stores all N strings of average length K.
O(n*k) + O(n) = O(n*k)
*/



// code


/*



class Solution
{
public:
    // Helper function to check if two strings are anagrams.
    bool checkAnagram(string s1, string s2)
    {
        // Anagrams must have the same length.
        if (s1.length() != s2.length())
            return false;

        // Create a frequency array for all 26 lowercase English letters.
        int freq_arr[26] = {0};

        // Increment count for chars in s1, decrement for chars in s2.
        for (int i = 0; i < s1.length(); i++)
        {
            freq_arr[s1[i] - 'a']++;
            freq_arr[s2[i] - 'a']--;
        }

        // Check if all character counts are zero.
        // If any count is non-zero, they are not anagrams.
        for (int i = 0; i < 26; i++)
        {
            if (freq_arr[i] != 0)
                return false;
        }
        return true;
    }

    // Main function to group anagrams using a brute-force approach.
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> res; // The final result vector of groups.

        // A set to keep track of indices of strings that have already been grouped.
        unordered_set<int> us_alreadyProcessedIndices;

        // Iterate through each string in the input vector.
        for (int i = 0; i < n; i++)
        {
            // If the string at index 'i' has not been processed yet...
            if (us_alreadyProcessedIndices.find(i) == us_alreadyProcessedIndices.end())
            {
                // Create a new temporary group for this set of anagrams.
                vector<string> current_group;
                // Add the current string to its new group.
                current_group.push_back(strs[i]);
                // Mark this index as processed.
                us_alreadyProcessedIndices.insert(i);

                // Now, compare this string with all subsequent strings.
                for (int j = i + 1; j < n; j++)
                {
                    // If the string at index 'j' is an anagram of the string at 'i'...
                    if (checkAnagram(strs[i], strs[j]))
                    {
                        // Add the anagram to the current group.
                        current_group.push_back(strs[j]);
                        // Mark this anagram's index as processed so we don't start a new group with it.
                        us_alreadyProcessedIndices.insert(j);
                    }
                }
                // Once all subsequent strings are checked, add the completed group to the result.
                res.push_back(current_group);
            }
        }
        return res;
    }
};



*/

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
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();

        vector<vector<string>> res;
        unordered_map<string, vector<string>> grouped_anagrams;

        for (int i = 0; i < n; i++)
        {
            string word = strs[i];
            sort(word.begin(), word.end());

            grouped_anagrams[word].push_back(strs[i]);
        }

        for(auto pair : grouped_anagrams)
        {
            res.push_back(pair.second);
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

Time Complexity
We process each of the n words. Suppose the average word length is k.
Sorting each word
Sorting takes O(k log k) time.
Doing this for all n words → O(n * k log k).
Inserting into unordered_map
Hashing the sorted word (length k) takes O(k) on average.
Total for all words → O(n * k).
Building result vector
Iterating over hashmap entries and pushing into res takes overall O(n) (since all words are pushed once).
✅ Total time = O(n * k log k + n * k) ≈ O(n * k log k)

🔹 Space Complexity
Hashmap storage
Each of the n words is stored once inside the hashmap buckets.
Keys are sorted words of length k → O(n * k) space.
Values store original words, total across all keys → O(n) strings.
Result vector
Holds all words again in grouped form → O(n) extra.
✅ Total space = O(n * k)

*/


// code


/*

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();

        vector<vector<string>> res;
        unordered_map<string, vector<string>> grouped_anagrams;

        // iterate through string 
        for (int i = 0; i < n; i++)
        {
            // take one by one word and sort it. Atter you sort it all the anagrams will have same key. 
            // Ex: eat, tea, ate are anagrams. But when we sort them each of them become aet.
            // That means we just have to take unordered map where its key will be sorted word and its value will be vector<String>
            // after sorting word, push that original non sorted word to the map. Now all three above example will get 
            // pushed to the same place because there key will be same that is aet. It it is not present already then it will
            // create that key and pushed original word and it it was already there then it will just push back.
            string word = strs[i];
            sort(word.begin(), word.end());

            grouped_anagrams[word].push_back(strs[i]);
        }

        // here pair is the object which will be pointing to key and values of map both. We take pair.second then it 
        // will point to the values of map. And remember that we have taken vector<String> as a data type of map for values.
        // so we are directly pushing a complete vector to the res. And because res is vector of vector so it is a valid push.
        for(auto pair : grouped_anagrams)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};


*/
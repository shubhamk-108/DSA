/*
Given an array of strings arr[]. Return the longest common prefix among each and every strings present in the array. If there's no prefix common in all the strings, return "".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: "gee"
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: ""
Explanation: There's no common prefix in the given strings.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    // this is efficient solution. But is is debatable because it has time complexity larger than naive solution
public:
    string longestCommonPrefix(vector<string> arr_str)
    {
        int n = arr_str.size();

        sort(arr_str.begin(), arr_str.end());

        int min_len = min(arr_str[0].length(), arr_str[n-1].length());

        string ans = "";

        for (int i = 0; i < min_len; i++)
        {
            if(arr_str[0][i] == arr_str[n-1][i])
                ans+=arr_str[0][i];
            else
                break;
        }

        // i am thinking of something like this. return arr_str[0].substr(0, word_len); but even if you don’t create a variable and 
        // store and then returned substring in a variable, the operation itself still creates a temporary std::string object under the hood.
        // so it take O(n) space.
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> arr_str = {"geeksforgeeks", "geeks", "geek", "geezer"};

    cout << sol.longestCommonPrefix(arr_str);
    return 0;
}



// timespace
// this is intresting. read all time and space
/*

Time and Space Complexity
Let's define the variables for the analysis:
N = the number of strings in the list.
M = the average length of the strings.
K = the length of the final longest common prefix.
Time Complexity: O(N * M * log(N))
The most expensive operation in your code is sort(arr_str.begin(), arr_str.end()).
Sorting a list of N items takes O(N * log(N)) comparisons.
However, comparing two strings is not a single operation; in the worst case, it requires checking each character. So, each comparison 
takes up to O(M) time.
Therefore, the total time complexity is dominated by the sort, making it approximately O(N * M * log(N)).
You are thinking of the complexity as:
Time to sort + Time to compare = O(N log N) + O(M)
This would be correct if comparing two items during the sort was an O(1) operation (like comparing two integers). However, we are not sorting 
integers; we are sorting strings.
The Hidden Cost of Sorting Strings
When the sort function decides to compare two strings, say "flower" and "flight", it can't just know which one comes first in a single step. 
It has to perform a character-by-character comparison:
Compare f and f. They are the same.
Compare l and l. They are the same.
Compare o and i. They are different. i comes before o, so "flight" comes before "flower".
This comparison took 3 steps. In the worst case, if you compare "applepie" and "applepen", you have to check almost the entire length of the 
strings. This comparison operation takes O(M) time, where M is the length of the strings.
Putting it Together
The sort algorithm performs roughly O(N log N) comparisons.
Each of those comparisons costs up to O(M) time.
Therefore, the total time complexity for the sorting part alone is the number of comparisons multiplied by the cost of each comparison:
O(N log N) * O(M) = O(N * M * log N)
After this, the final loop to compare the first and last strings takes only O(M) time.
The total time complexity is O(N * M * log N) + O(M). In Big O notation, we drop the lower-order term, so the final complexity is dominated 
by the sort.
Final Time Complexity = O(N * M * log N).

Question: if there were only one word for sorting then would time complexity  be nlogn where n is length of word
t if string word = "shubham" and i want to sort it like abhhmsu
Answer: Yes


Space Complexity: O(log N) to O(M)
Sort Space: The std::sort algorithm itself requires some auxiliary space, which is typically O(log N). In some implementations, it could be
higher for strings.
Answer Space: The ans string you create will store the result. In the worst case, its length will be K. So, it takes O(K) space. Since K 
can be at most M, we can say this is O(M).



*/

// logic

/*
Logic Steps (The Sorting Approach)
Here is the flow of the algorithm, broken down into simple steps:
Handle the Edge Case: First, check if the input list of strings is empty. If so, return an empty string "" immediately.
Sort the List: Arrange all the strings in the list in alphabetical (lexicographical) order.
Identify the Extremes: After sorting, the problem is simplified. The longest common prefix for the entire list will be whatever prefix 
is shared by just the first string and the last string.
Compare Character by Character: Loop through the first and last strings simultaneously, comparing the characters at each position (index 0, 
then 1, then 2, and so on).
Build the Prefix: For every position where the characters match, add that character to your result string.
Stop and Return: The moment you find a position where the characters do not match, stop the process. The result string you have built up to that 
point is your final answer.

*/


// code 

/*


class Solution
{
public:
    string longestCommonPrefix(vector<string>& arr_str)
    {
        int n = arr_str.size();

        // Edge Case: If the input array is empty, there can be no common prefix.
        if (n == 0) {
            return "";
        }

        // --- Step 1: Sort the array of strings lexicographically ---
        // This is the key insight. After sorting, the longest common prefix for the
        // whole array will be the common prefix between the very first and very last string.
        sort(arr_str.begin(), arr_str.end());

        // --- Step 2: Identify the strings to compare ---
        // Take the first string (now the lexicographically smallest).
        string first = arr_str[0];
        // Take the last string (now the lexicographically largest).
        string last = arr_str[n - 1];

        // This variable will store our result.
        string ans = "";

        // --- Step 3: Compare the two strings character by character ---
        // We only need to check up to the length of the shorter of the two strings.
        for (int i = 0; i < first.length(); i++)
        {
            // If the characters don't match, we've found the end of the common prefix.
            if (first[i] != last[i])
            {
                break;
            }
            // If they match, append the character to our answer.
            ans += first[i];
        }

        // --- Step 4: Return the result ---
        // Your thought process here is correct. Both building a string like 'ans' and
        // using substr() will result in a new string being created, so the space
        // complexity for the result itself is unavoidable. This is a clean way to do it.
        return ans;
    }
};


*/


// Question

/*

The naive solution has smaller time complexity than efficient solution. SO it is debatable which is efficient. Both naive and this 
solution can be considered efficient solution


When Vertical Scanning (naive solution) is better: If you have a huge number of strings (N is very large), that extra log N factor in the 
sorting approach will make it slower.

When Sorting might be better in practice: The analysis above is for the worst-case. In many real-world scenarios, string comparisons 
during a sort are very fast (they stop at the first different character). If the strings are very different from each other, sorting 
can be surprisingly quick.

*/
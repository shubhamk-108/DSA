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
#include<climits>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr_str)
    {
        int n = arr_str.size();

        int smallest_word_length = INT_MAX;

        for (int i = 0; i < arr_str.size(); i++)
        {
            int len = arr_str[i].length();
            smallest_word_length = min(smallest_word_length, len);
        }

        string ans = "";
        for (int j = 0; j < smallest_word_length; j++)
        {
            char curr_char = arr_str[0][j];
            bool flag = true;
            
            for (int i = 0; i < arr_str.size(); i++)
            {
                if (curr_char != arr_str[i][j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                ans += curr_char;
            }
            else
            {
                break;
            }
        }
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

/*

N = the number of strings in the input array (arr_str).

M = the length of the shortest string in the array.

Time Complexity: O(N * M)
The first loop to find the smallest_word_length runs N times. This is O(N).

The main part is the nested loop. The outer loop (for j...) runs M times in the worst case (if the common prefix is the entire shortest string).
The inner loop (for i...) runs N times for each character being checked.
The work done inside the loops (character comparison) is a constant time operation, O(1).
Therefore, the total time complexity is dominated by the nested loops, giving us O(N * M). This is a very good and widely accepted 
time complexity for this problem.

Space Complexity: O(M)
You use the ans string to build your result. In the worst case, the length of this string can be up to M.
All other variables (n, smallest_word_length, len, j, i, curr_char, flag) use a constant amount of extra space, which is O(1).
So, the space complexity is determined by the space required for the output string, which is O(M).

*/


// logic

/*

]

The Logical Flow
Step 1: Handle Edge Cases
First, check if the input list of strings is empty. If it is, there's no possible prefix, so you're done. Return an empty string "".

Step 2: Find the Search Limit (An Optimization)
The common prefix can't be longer than the shortest word in the list. For example, in ["apple", "ape"], the common prefix can't be longer than 
"ape" (length 3).
Go through the entire list of strings once just to find the length of the shortest string. Let's call this minLength.

Step 3: Scan Vertically, Column by Column
Now, start a loop that will go through the character positions (columns). This loop will run from the first character (index 0) up to minLength - 1.
Inside this loop, for each column j:
a. Pick a Reference Character: Take the character from the very first word at the current column j. For example, at column 0, you pick 'f' from 
"flower".
b. Compare with All Other Words: Start another loop that goes through every other word in the list. For each word, look at the character at the 
same column j.
c. Check for a Mismatch: Compare the reference character with the character from the other word. If they are different (e.g., comparing 'o' from
 "flow" with 'i' from "flight" at column 2), you have found the end of the common prefix.
d. If a Mismatch Occurs: The common prefix is everything you've successfully checked before this point. Immediately stop everything and return 
the prefix you have built so far.

Step 4: Build the Answer
If your inner loop (Step 3b) completes without finding any mismatches for the current column j, it means that character is common to all words.
Append this common character to your answer string.
Then, let the outer loop continue to the next column (e.g., from 'f' to 'l').

Step 5: Finish
The process ends in one of two ways:
You find a mismatch and return the answer string immediately (as in Step 3d).
Your outer loop finishes completely, meaning all characters up to minLength were common. In this case, you just return the ans string you have built.

*/

// code

/*

string longestCommonPrefix(vector<string> arr_str)
{
    int n = arr_str.size();

    // Edge Case: If the input array is empty, there is no common prefix.
    if (n == 0) {
        return "";
    }

    // This is an unused variable from your previous draft and can be removed.
    // string prefix = ""; 
    
    // This is also unused.
    // int max_len = 0; 

    // --- Step 1: Find the length of the shortest word ---
    // This is a great optimization, as the common prefix cannot be longer than the shortest word.
    int smallest_word_length = INT_MAX;

    for (int i = 0; i < arr_str.size(); i++)
    {
        int len = arr_str[i].length();
        smallest_word_length = min(smallest_word_length, len);
    }

    string ans = ""; // This will store our final answer.

    // --- Step 2: Perform Vertical Scanning ---
    // Loop through each character index from 0 up to the smallest_word_length.
    for (int j = 0; j < smallest_word_length; j++)
    {
        // Get the character at the current column 'j' from the first word.
        char curr_char = arr_str[0][j];
        
        // This flag is not strictly necessary as we can return directly, but it works well.
        bool flag = true; 
        
        // Loop through all the words in the array to check the character at column 'j'.
        for (int i = 1; i < arr_str.size(); i++)
        {
            // If we find a character that does not match...
            if (curr_char != arr_str[i][j])
            {
                // ... we set the flag and break, because the common prefix ends here.
                flag = false;
                break;
            }
        }
        
        // If the flag is still true, it means all words had the same character at this column.
        if (flag == true)
        {
            // So, we add this character to our answer.
            ans += curr_char;
        }
        // If the flag is false, a mismatch was found.
        else
        {
            // We break the outer loop because no further characters can be part of the prefix.
            break;
        }
    }
    
    // Return the final result.
    return ans;
}


*/
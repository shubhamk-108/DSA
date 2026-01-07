/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

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
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        if (m > n)
            return "";

        int minWinLen = INT_MAX;
        unordered_map<char, int> ump;

        for (auto c : t)
            ump[c]++;

        int left = 0;
        int right = 0;
        int countReq = m;
        int startOfWin = 0;

        while (right < n)
        {
            if (ump[s[right]] > 0)
                countReq--;

            ump[s[right]]--;

            while (countReq == 0)
            {
                int currWindSize = right - left + 1;
                if (currWindSize < minWinLen)
                {
                    minWinLen = currWindSize;
                    startOfWin = left;
                }

                ump[s[left]]++;
                if (ump[s[left]] > 0)
                    countReq++;

                left++;
            }

            right++;
        }
        return minWinLen == INT_MAX ? "" : s.substr(startOfWin, minWinLen);
    }
};

int main()
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// my explanation
//___________________________________________________________________________________________________________________________________________

/*

string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        if (m > n)
            return "";

        int minWinLen = INT_MAX;
        unordered_map<char, int> ump;

        // we will increment all chars from string t so that they are now greater than 0.
        // Those char will be greater than 0, we will need those chars.
        for (auto c : t)
            ump[c]++;


        //left to shrink window from left when we get valid win. And right to expand window unless we get valid window.
        int left = 0;
        int right = 0;

        // couunt required means those many chars we required.
        int countReq = m;

        // we need to return substring so it is imp to know from where does window start.
        int startOfWin = 0;

        // exand window
        while (right < n)
        {
            // if char's count is greater than 0 means we need this char. So consider this char is in window now so we get one char 
            // hench now reduce the count required.
            if (ump[s[right]] > 0)
                countReq--;

            // now that we used that char we need to reduce its count from the map. Those char that were present in string t will
            //anyway be greater than 0 so we dont have problem here but those char which were not present in the string t and present
            // in string s will have negative count. ex . we got v 3 times but if that wasnt in string t then it was unnecessary so v's couut
            // will be in negative. in simple word ignore these negative because we dont need it.
            ump[s[right]]--;

            // this loop run only when we get valid window. And valid win meane reqcount will be 0. So unless and until this count is 0
            // , shrink that win from left.
            while (countReq == 0)
            {
                // everytime note curent window size and start of win to return substring later
                int currWindSize = right - left + 1;
                if (currWindSize < minWinLen)
                {
                    minWinLen = currWindSize;
                    startOfWin = left;
                }

                // we are shrinking win means we are not considering that letter in our current window so increment that char's count
                //signifying  that this letter is no longer in our window.
                ump[s[left]]++;

                // While shrinking if we notice that any char's couunt was greater than 0 means we wanted that char but we discarded it
                // while shrinking so increment count req and now our window will not be valid so till loop will terminate and we will
                // again expand our right pointer in order to find next valid window.
                if (ump[s[left]] > 0)
                    countReq++;

                // shrink window
                left++;
            }
            // expand window
            right++;
        }
        return minWinLen == INT_MAX ? "" : s.substr(startOfWin, minWinLen);


*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity — O(n + m)
We scan string s once using right pointer → O(n)
Each character is removed from window at most once by left pointer → O(n)
Creating t’s frequency map → O(m)
Total: O(n + m)
This is optimal.

💾 Space Complexity — O(k)

We use a hashmap storing at most k distinct characters from t
(where k ≤ 128 for ASCII)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Step 1 — Build frequency map of t

Count how many times each character appears in t.

Example: t = "AABC"

A:2  
B:1  
C:1

We also keep a variable countReq = t.length() to track how many characters are still needed.
Step 2 — Expand window using right pointer
Move right pointer forward through s:
If s[right] is needed (map[s[right]] > 0), reduce countReq
Decrease map count: map[s[right]]--
(because this character is added into the window)
When countReq becomes 0 → window is valid (contains all chars of t)
Step 3 — Shrink window from left
Now try to make the window as small as possible:
While window is valid:
Update minimum window length
Add back s[left] to map (map[s[left]]++)
If map count becomes positive → we NEED this char → window is invalid
→ increase countReq
Move left++ to shrink
Step 4 — Continue scanning
Repeat until right reaches the end.
Step 5 — Return smallest window found
🎯 WHY THIS WORKS?
Right pointer grows the window to include necessary characters
Left pointer shrinks unnecessary characters
Hashmap keeps track of how many characters are still needed
We always track the minimum valid window


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        // If t is bigger than s → no possible window
        if (m > n)
            return "";

        int minWinLen = INT_MAX;       // smallest window found
        unordered_map<char, int> ump;  // char frequency map for t

        // Build frequency map for t
        for (auto c : t)
            ump[c]++;

        int left = 0;
        int right = 0;
        int countReq = m;              // how many chars still needed
        int startOfWin = 0;            // starting index of best window

        // Expand window using right pointer
        while (right < n)
        {
            // If s[right] is needed, reduce required count
            if (ump[s[right]] > 0)
                countReq--;

            // Use this char in window
            ump[s[right]]--;

            // If window is valid (we got all chars of t)
            while (countReq == 0)
            {
                int currWindSize = right - left + 1;

                // Update minimum window
                if (currWindSize < minWinLen)
                {
                    minWinLen = currWindSize;
                    startOfWin = left;
                }

                // Try removing s[left] to shrink window
                ump[s[left]]++;

                // If after removal, window becomes invalid
                if (ump[s[left]] > 0)
                    countReq++;

                left++; // shrink from left
            }

            right++; // expand from right
        }

        // If no valid window found
        return minWinLen == INT_MAX ? "" : s.substr(startOfWin, minWinLen);
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Sliding Window (Variable Size)

✔ Expand right pointer until requirement is met
✔ Shrink left pointer to minimize window
✔ Maintain count of required characters

This is the classic:

Sliding Window + Two Pointers + Hashmap (Character Frequency Tracking)

*/

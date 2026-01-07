// abcdabc
// op : 4 , expln: cdab
// aaa
// op : 1 , expln : a
// ""
// op : 0
// substring means contiguous characters and subsequences means
// substring: A contiguous sequence of characters within a string. For s = "abcde": "abc", "bcd" are substrings. "ace" is not a substring.
// Subsequence: A sequence of characters that appears in the same order in a string, but not necessarily contiguous. For s = "abcde": "ace", "bd",
// are subsequences. Contiguity not required. Only order should be preserved

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int LongestSubstringWithDistinctCharactersN(std::string str)
{
    
}


int main()
{
    string str = "abcdabc";
    cout << LongestSubstringWithDistinctCharactersN(str);
    return 0;
}



// time and space
// Time Complexity: O(n²)
// Space Complexity: O(1)


// ____________________________________________________________________________________________________________________________
// logic:
// ____________________________________________________________________________________________________________________________



/*

Imagine you have two pointers, start and end, on your string. These two pointers define a "window" or a substring. The main idea is to always maintain a window that contains only distinct characters.

Expand: We try to make this window as large as possible by moving the end pointer to the right.

Shrink: If moving the end pointer introduces a duplicate character into the window, we must "shrink" the window from the left by moving the start pointer to the right until the duplicate is removed.

We use a hash map (like unordered_map) to keep track of the characters currently in our window and their most recent positions. This allows us to check for duplicates in constant O(1) time.

The Key Components in the Code
start: The left-side boundary of our window. It's the starting index of our current substring.

end: The right-side boundary of our window. It moves from left to right across the string, character by character.

last_seen (an unordered_map): This is our memory. For any character, it tells us the last index where we saw it. This is the key to knowing if a character is a duplicate within our current window.

max_len: A variable to store the maximum length we've found so far.

1. The Loop and Window Expansion
The for loop drives the whole process. The end pointer automatically moves one step to the right with each iteration, effectively trying to expand our window by one character (current_char).

2. The Duplicate Check
This is the most important line of code:
if (last_seen.count(current_char) && last_seen[current_char] >= start)

Let's break it down:

last_seen.count(current_char): First, have we ever seen this character before? If not, it can't possibly be a duplicate, so we can skip the rest.

last_seen[current_char] >= start: This is the brilliant part. Even if we've seen the character before, we only care if its last appearance was inside our current window. The window is defined by the range [start, end]. If the character's last seen index is less than start, it's a "stale" duplicate that is no longer in our window, so we can safely ignore it.

3. Handling a Duplicate (Shrinking the Window)
If the if condition is true, we have found a duplicate character inside our current window.

cpp
start = last_seen[current_char] + 1;
To fix this, we must shrink the window from the left. We move our start pointer to the index right after the previous occurrence of that character. This effectively discards the old duplicate and all characters before it, ensuring our new, smaller window is once again free of duplicates.

4. Updating Our State (Always Happens)
These two lines run in every iteration of the loop, whether a duplicate was found or not.

cpp
last_seen[current_char] = end;
max_len = std::max(max_len, end - start + 1);
last_seen[current_char] = end;: We must update our map to record that the current_char has now been seen at the end index. This is vital for future duplicate checks.

max_len = std::max(max_len, end - start + 1);: After potentially shrinking the window, the substring from start to end is guaranteed to have distinct characters. We calculate its length (end - start + 1) and update max_len if this window is the longest one we've seen yet.

*/


// ____________________________________________________________________________________________________________________________
// code
// ____________________________________________________________________________________________________________________________




/*

int LongestSubstringWithDistinctCharactersN(std::string str)
{
    int n = str.length();
    int max_len = 0;
    std::unordered_map<char, int> last_seen;
    int start = 0;

    // The 'end' pointer automatically moves from 0 to n-1
    for (int end = 0; end < n; ++end)
    {
        char current_char = str[end];

        // Check if the current character creates a duplicate in the window. That is it check does this char occured before. And even if it
        // occured, check if it occur in our current window in which we are now standing.
        if (last_seen.count(current_char) && last_seen[current_char] >= start)
        {
            // Shrink the window by moving the start pointer
            start = last_seen[current_char] + 1;
        }

        // Update the last seen position of the character
        last_seen[current_char] = end;

        // The window [start...end] is now valid, calculate its length
        max_len = std::max(max_len, end - start + 1);
    }

    return max_len;
}


*/


// ____________________________________________________________________________________________________________________________
// dry run for 
// ____________________________________________________________________________________________________________________________




/*

start → start of current window
end → end of current window (iterates through string)
last_seen → map storing the last index each character was seen
max_len → maximum length found so far



| end | current\_char | last\_seen                      | start | window   | max\_len | Explanation                                                |
| --- | ------------- | ------------------------------- | ----- | -------- | -------- | ---------------------------------------------------------- |
| 0   | 'c'           | {}                              | 0     | "c"      | 1        | 'c' not seen before, add to last\_seen                     |
| 1   | 'a'           | {'c':0}                         | 0     | "ca"     | 2        | 'a' not seen, extend window                                |
| 2   | 'd'           | {'c':0,'a':1}                   | 0     | "cad"    | 3        | 'd' not seen, extend window                                |
| 3   | 'b'           | {'c':0,'a':1,'d':2}             | 0     | "cadb"   | 4        | 'b' not seen, extend window                                |
| 4   | 'z'           | {'c':0,'a':1,'d':2,'b':3}       | 0     | "cadbz"  | 5        | 'z' not seen, extend window                                |
| 5   | 'a'           | {'c':0,'a':1,'d':2,'b':3,'z':4} | 0     | "cadbza" | 5        | 'a' seen at 1, which is ≥ start (0), so move start = 1+1=2 |
| 5   | 'a' update    | {'c':0,'a':5,'d':2,'b':3,'z':4} | 2     | "dbza"   | 5        | Update last\_seen for 'a'                                  |
| 6   | 'b'           | {'c':0,'a':5,'d':2,'b':3,'z':4} | 2     | "dbzab"  | 5        | 'b' seen at 3 ≥ start(2), move start = 3+1=4               |
| 6   | 'b' update    | {'c':0,'a':5,'d':2,'b':6,'z':4} | 4     | "zab"    | 5        | Update last\_seen for 'b'                                  |
| 7   | 'c'           | {'c':0,'a':5,'d':2,'b':6,'z':4} | 4     | "zabc"   | 5        | 'c' seen at 0 < start(4), no change in start               |
| 7   | 'c' update    | {'c':7,'a':5,'d':2,'b':6,'z':4} | 4     | "zabc"   | 5        | Update last\_seen for 'c'                                  |
| 8   | 'd'           | {'c':7,'a':5,'d':2,'b':6,'z':4} | 4     | "zabcd"  | 5        | 'd' seen at 2 < start(4), no change in start               |
| 8   | 'd' update    | {'c':7,'a':5,'d':8,'b':6,'z':4} | 4     | "zabcd"  | 5        | Update last\_seen for 'd'                                  |


*/
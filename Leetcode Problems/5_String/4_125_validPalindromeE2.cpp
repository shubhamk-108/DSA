/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// This is optimised solution but more cleaner solution is written in next file.
class Solution
{
public:

    bool isPalindrome(string &s)
    {
        int n = s.length();
        int i = 0; 
        int j = n-1;

        while (i<j)
        {
            while (i <j && !isalnum(s[i]))
            {
                i++;
            }
            while (j > i  && !isalnum(s[j]))
            {
                j--;
            }

            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
            
        }
        return true;
        
    }
};

int main()
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout<<sol.isPalindrome(s);
    return 0;
}


// time space/*

/*

Time Complexity

Each character is visited at most once → O(n), where n = s.length()

Space Complexity

No extra string or array used → O(1) auxiliary space

*/


//logic:



/*

''How it works

Two pointers i (start) and j (end)

Skip non-alphanumeric characters using isalnum

Compare lowercase versions of characters using tolower

If mismatch → return false

Otherwise → move pointers inward until they meet


*/
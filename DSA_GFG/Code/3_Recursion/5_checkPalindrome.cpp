#include <iostream>
using namespace std;


bool isPalindrome(string str, int start , int end)
{
    if(start >= end)
        return true;
    return ( (str[start] == str[end]) && (isPalindrome(str, start+1, end-1)));
}
int main() {
	
	string str = "abcba";
    int start = 0;
    int end = str.length()-1;
	
	cout<<(isPalindrome(str, start, end) ? "Palindrome" : "Not Palindrome" );
	
	return 0;
}

// time : T(n-2) + theta(1)
// that is time is O(n)

// space  : This function will have (n/2) calls. so space complexity is O(n/2). Ignore constant and we get O(n)

// Logic 
// str: The string to check

// start: The current left index

// end: The current right index

// The function compares characters from both ends and keeps moving toward the center.

// Once start meets or crosses end, the string is fully checked.

// If we haven’t found any mismatch until now, then it's a palindrome ✅.
// for even string start crosses end and for odd string start and end both come at the same pointer(happens at the middile char of string)

// start+1 moves one step forward from the start.

// end-1 moves one step backward from the end.

// Example:
// For the string "racecar":

// Compare r (start=0) and r (end=6) → equal

// Recursive call: isPalindrome("racecar", 1, 5) → compare a and a

// Recursive call: isPalindrome("racecar", 2, 4) → compare c and c

// Recursive call: isPalindrome("racecar", 3, 3) → start == end, return true

// All return true → original call returns true → "racecar" is a palindrome.
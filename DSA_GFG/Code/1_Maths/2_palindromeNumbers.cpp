// Purpose:
// To check whether a given integer num is a palindrome number, i.e., it reads the
//  same forward and backward (like 121, 3223, etc.)

#include <iostream>
using namespace std;


bool isPalindrome(int num) {
    // num = abs(num);  // handle negative input
    if(num<0){return false;}
    int original_number = num;
    int reverse_sequence = 0;

    while (num > 0) {
        int last_digit = num % 10;
        reverse_sequence = reverse_sequence * 10 + last_digit;
        num = num / 10;
    }

    return reverse_sequence == original_number;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (isPalindrome(num))
        cout << "Number is a Palindrome\n";
    else
        cout << "Number is Not a Palindrome\n";

    return 0;
}




// Time Complexity = O(log₁₀(n))
// This simplifies to O(log n) in base 10.

// The loop does run d times — once per digit.
// → Loop runs O(d) times
// But Why Do We Say O(log n)?
// Because in asymptotic analysis, we often express complexity
//  in terms of the input size n, not its digit count.


// ======================================================
// =====================================================

// Space Complexity

// int reverse_sequence

// int original_number

// int last_digit

// All of these are just integer variables, not arrays or recursion stacks.

// Space Complexity = O(1)


// ======================================================
// =====================================================

// Logic 

// 1. 
// Make Number Positive (Handle Negative Input)
// num = abs(num);
// We only care about the digits, not the sign.
// Example: -121 → 121

// 2.
// Store Original Number for Comparison Later
// int original_number = num;

// 3. 
// Initialize Reverse Variable
// int reverse_sequence = 0;
// This will store the reversed number.


// 4.
// while(num > 0) {
//     int last_digit = num % 10;
//     reverse_sequence = reverse_sequence * 10 + last_digit;
//     num = num / 10;
// }
// Extract last digit using % 10.
// Add it to reverse_sequence by shifting previous digits to the left.
// Remove last digit from num using / 10.
// This loop repeats until all digits are reversed.


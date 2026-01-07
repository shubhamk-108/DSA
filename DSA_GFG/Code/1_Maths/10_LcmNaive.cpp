// LCM stands for Least Common Multiple.

//Definition:
// The LCM of two integers a and b is the smallest positive integer that is divisible by both a and b.

// Examples:
// LCM of 4 and 6 = 12
// Multiples of 4: 4, 8, 12, 16, ...
// Multiples of 6: 6, 12, 18, ...
// Smallest common multiple = 12

// LCM of 3 and 7 = 21
// Multiples of 3: 3, 6, 9, 12, 15, 18, 21, ...
// Multiples of 7: 7, 14, 21, ...
// LCM = 21

// for 2, 8 lcm is 8


#include <iostream>
#include <limits.h>
using namespace std;

int lcm(int a, int b)
{
    int multiple = max(a, b); // Start from the largest of a and b

    while (true)
    {
        if ((multiple % a == 0) && (multiple % b == 0))
        {
            return multiple; // Return as soon as LCM is found
        }
        multiple++;
    }
}


int main() {
    
    	int a = 24, b = 12;
    	
    	cout<<lcm(a, b);
        cout<<"\n Control Ends \n";
    	
    	return 0;
}

// Time c:
// O(a*b)). (if a and b are co-prime, you may go up to a*b).


// Logic: 
// Why start from max(a, b)?
// Because the LCM cannot be less than the larger of the two numbers.
// Example: LCM of 4 and 6 can't be less than 6
// Loop infinitely (while (true)):
// Keep checking next multiple values one-by-one.
// Check if current multiple is divisible by both a and b:
// If yes, then it's the first (least) number divisible by both.
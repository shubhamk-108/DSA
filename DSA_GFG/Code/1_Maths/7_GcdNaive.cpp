// Naive approach

// The GCD of two integers is the largest number that divides both of them without leaving a remainder.
// GCD(12, 18)

// Divisors of 12 = 1, 2, 3, 4, 6, 12  
// Divisors of 18 = 1, 2, 3, 6, 9, 18

// Common divisors = 1, 2, 3, 6  
// Greatest = 6

// So, GCD(12, 18) = 6

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int small_number = min(a,b);
    while(small_number > 0){
        if(a % small_number == 0 && b % small_number == 0){
            return small_number;
        }
        small_number--;
    }
    return 1;

}

int main()
{

    cout<<gcd(12,24);
    cout<<"\n Control ends\n";
    return 0;
}


// Time : O(min(a,b))

// Logic: 
// int small_number = min(a,b);
// You're starting from the smaller number — smart, because the GCD cannot be more than min(a, b).
// suppose for (100,200) gcd can not be more than 100. So we take 100 and check modulo with both numbers
// to check if they are completely divisible. And if not we decrement smaller number one by one like 99,98,97,96....
// and check everytime
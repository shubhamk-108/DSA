#include<iostream>
using namespace std;
 
int sumOfDigits(int n)
{
    if(n<=0)
        return 0;
    return ((n % 10) + sumOfDigits(n / 10)); 
}

int main()
{
    cout<<sumOfDigits(3538);
    cout << " control ends " << " ";
    return 0;
}

//  Time Complexity
// Let’s say the number n has d digits.
// Each recursive call processes 1 digit.
// Total recursive calls = number of digits = d
// In terms of n, the number of digits is ≈ log₁₀(n)
// So:
// Time Complexity = O(log n) (base 10)


//  Space Complexity
// Each recursive call uses stack space.
// Number of recursive calls = log₁₀(n)
// So:
// 🔹 Space Complexity = O(log n)
// Time Complexity: Θ(d)
// Space Complexity: Θ(d)
// Where d is the number of digits in the number n.
// O(log n) gives an upper bound in terms of the numeric value of n
// But d = floor(log₁₀(n)) + 1, which is the actual number of digits

// 
// logic :

// How does it work?
// n % 10 extracts the last digit. and then we add such last digit and then we do n/10 to remove that last digit so that 
// it doesnt count again in the addition process

// n / 10 removes the last digit.
// It keeps doing this recursively until n <= 0.
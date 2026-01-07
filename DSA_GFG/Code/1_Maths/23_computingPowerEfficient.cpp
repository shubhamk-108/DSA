// Problem Description: We are given two numbers. The task is to compute Power(x,n)  which means x to the power y.
// Input: x = 2, n = 3
// Output: 8      2*2*2
// Input: x = 7, n = 2
// Output: 49    7*7

#include <iostream>
#include <limits.h>
using namespace std;

 double power(double x, int n)
{
	long long N = n;
	if(N == 0)
		return 1;
	
	// to handle negative values
	if(N < 0)
	{
		return 1 / power(x, -n);
		// x^-2 = 1/x^2. 
		// so negative value becomes positive when we take it to denominator. 
		// so 2^-2 will become 1/2^2. So denominator la jo race to la two aahe to positive aala pahije.
		// pn aapan x^n kartoy ani n ha -2 aahe. Mhanje ha x^-2 ch rahila asta jari aapan tyala denominator la gheun gelo tri
		// mhann  1 / power(x, -n) as kel. Karan 1/(x^-n) that is 1/(x^-2) will become  1/(x^-(-2)). And this -(-) become plus +.
		// and this is how we get positive number to race to  ^ in denominator
		// In short, n value hi already negative aahe for negative powers like -2, -5, etc. So  we take -n which is -(-2) = 2 or 
		// -(-5) = 5. So this is (-n)
	}

	double temp = power(x, N/2);

	temp = temp * temp; // x^n = (x^(n/2)) * (x^(n/2)) = (x^(n/2))^2

	if(N % 2 == 0)
		return temp;
	else
		return temp * x; 
}
int main() {
    
    // double x = 2, n = 3;
    double x = 2, n = -2;

	cout<<power(x, n);
    cout<<endl<<"control ends";
}


// Time Complexity: Theta(logn)
// Auxiliary Space: Theta(logn)  Since uses recursion and height of tree goes upto logn height

//  Logic Behind It (Divide and Conquer):
// If n is even:
// x^n = (x^(n/2)) * (x^(n/2)) = (x^(n/2))^2
// If n is odd:
// x^n = x * (x^(n/2)) * (x^(n/2)) = x * (x^(n/2))^2
// You're dividing the problem into smaller subproblems, solving power(x, n/2), and combinin
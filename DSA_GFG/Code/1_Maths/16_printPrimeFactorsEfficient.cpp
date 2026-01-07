#include <iostream>
#include <limits.h>
using namespace std;

 void printPrimeFactors(int n)
{
	if(n <= 1)
		return;

	for(int i=2; i*i<=n; i++)
	{
		while(n % i == 0)
		{
			cout<<i<<" ";

			n = n / i;
		}
	}

	if(n > 1)
		cout<<n<<" ";

	cout<<endl;
}

int main() {
    
    	int n = 450;
    	
    	printPrimeFactors(n);
    	
    	return 0;
}

// Time Complexity: O(sqrt(n))
// Auxiliary space: O(1)

// Logic 
// because it is prime factor loop will be like this i*i<=n as explained and learned in previous code
// now take number 45. 45/3 = 15. But 15 can also be divided by 3. 15/3 = 5. 
// for understanding purpost take 6 insted of above 5. So 6 can also be divided by 3.
// So i want to say that we keep on dividing because there can be multiple 2 and 3, etc as a prime factor.

// The corner case if(n > 1) this is to check that if there remains prime factor at the end then we have to print that also.
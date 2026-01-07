#include<iostream>
using namespace std;


 bool isPrime(int n)
{
	if(n==1)
		return false;

	if(n==2 || n==3)
		return true;

	if(n%2==0 || n%3==0)
		return false;

	for(int i=5; i*i<=n; i=i+6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false; 
	}

	return true;
}
void printPrimeFactors(int n )
{
    for (int i = 2; i <n ; i++)
    {
        if(isPrime(i))
        {
            int x = i;
            while (n % x == 0)
            {
                cout<<i<<endl;
                x = x * i;
            }
        }
    }
}



int main()
{

    printPrimeFactors(12);
    cout<<"\n control ends \n";
    return 0;
}

// Time Complexity: O(n*sqrt(n)*log(n))
// O(sqrt(n) for isPrine and n*log(n) for printPrimeFactors

// Auxiliary Space: O(1)


// Logic:

//  Example: n = 18
// Loop:

// i = 2 → isPrime(2) 

// x = 2, 18 % 2 == 0 → print 2

// x = 4, 18 % 4 != 0 → stop

// i = 3 → isPrime(3) 

// x = 3, 18 % 3 == 0 → print 3

// x = 9, 18 % 9 == 0 → print 3

// x = 27, 18 % 27 != 0 → stop

// Output: 2 3 3 

// we have in mind that is 12 is divisible by 2 then it is also divisible by 4. 
// So we will check for 4,8 ,16, 32, etc and we stop when this number is goes beyond our number (in this case 12)
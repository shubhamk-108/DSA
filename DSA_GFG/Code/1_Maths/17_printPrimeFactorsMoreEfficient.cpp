#include<iostream>
using namespace std;

void printPrimeFactors(int n)
{
    if( n <2)
    {
        return;
    }
    while (n % 2 == 0)
    {
        cout<<2<<" ";
        n = n / 2;
    }
    while (n % 3 ==0)
    {
        cout<<3<<" ";
        n = n / 3;
    }
    for(int i = 5; i * i <= n; i +=6)
    {
        while(n % i == 0)
        {
            cout<<i<<" ";
            n = n / i;
        }
        while(n % (i+2) == 0)
        {
            cout<<i<<" ";
            n = n / (i+2);
        }
    }
    if(n > 3)
		cout<<n<<" ";

	cout<<endl;

}

int main()
{

    int n = 90;
    printPrimeFactors(n);
    cout<<endl<<"control ends\n";
    return 0;
}



// In while loop we are continuously checking number n even after we got 2 or 3 as our factor that is because
// if 90 can be divided by 3 then (90/3 = 30) 30 can again divided by 3. So there can be multiple similar factors like 2,2,3,3,3
// so we need to find that also. that is why we are doing  n = n / 2; n = n / 3; n = n / i; n = n / (i+2);
// 

//  Example Walkthrough
// Let’s say n = 60
// Prime factorization: 60 = 2 × 2 × 3 × 5

// Loop steps:

// i = 2
// 60 % 2 == 0 → print 2, n = 30
// 30 % 2 == 0 → print 2, n = 15
// 15 % 2 != 0 → move on

// i = 3
// 15 % 3 == 0 → print 3, n = 5
// 5 % 3 != 0 → move on

// i = 4 → skip (not prime, and 5 % 4 != 0)

// i = 5 → loop ends before 5 because 5×5 = 25 > 5

// After loop: n = 5 → print 5

// Time Complexity: O(sqrt(n))

// Auxiliary space: O(1)
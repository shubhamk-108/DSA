// Check Previous file for what is lcm. And what ip and op for lcm should be

#include <iostream>
#include <limits.h>
using namespace std;

 bool checkPrimeNum(int n)
{
    if  (n == 1){return false;}

	for(int i = 2; i<n ; i++)
    {
        if((n % i) ==0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    
    	cout<<checkPrimeNum(29);
    	cout<<"\n Control Ends \n";
    	return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)
// Logic 

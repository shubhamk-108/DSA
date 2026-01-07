// Check Previous file for what is lcm. And what ip and op for lcm should be

#include <iostream>
#include <limits.h>
using namespace std;

 int gcd(int a, int b)
{
	if(b==0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main() {
    
    	int a = 4, b = 6;
    	
    	cout<<lcm(a, b);
    	
    	return 0;
}

// Time 
// O(log(min(a,b))

// Logic 
// gcd(a,b) * lcm(a,b) = (a*b)
// Therefore lcm(a,b) = (a*b) / gcd(a,b)
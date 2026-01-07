// Problem Description: We are given two numbers. The task is to compute Power(x,n)  which means x to the power y.
// Input: x = 2, n = 3
// Output: 8      2*2*2
// Input: x = 7, n = 2
// Output: 49    7*7

#include <iostream>
using namespace std;


 int computePower(int x, int y)
{
    int res = 1;
	
	for (int i = 0; i< y ; i ++)
	{
		res = x * res;
	}
	return res;
}
int main() {
    
    	int x = 5;
    	int y = 3;

		cout<<computePower(x, y);
		cout<<endl<<"control ends";
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)
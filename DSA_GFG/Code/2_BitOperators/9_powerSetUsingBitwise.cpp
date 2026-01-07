// Problem: Power set P(S) of a set S is the set of all subsets of S. For example S = {a, b, c} 
// then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
// If S has n elements in it then P(s) will have 2n elements

#include <iostream>
#include <cmath>
using namespace std;

void printPowerSet(string str)
{
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                cout<<str[j];
		}
		
		cout<<endl;
	}
}
    

    
int main() {
	
	string s = "abc";

    printPowerSet(s);  
    
}
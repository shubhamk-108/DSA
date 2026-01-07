#include<iostream>
using namespace std;
 
bool checkIfPowerOfTwo(int n)
{
    if(n <= 0)
        return false;
    return ((n & (n-1)) == 0);
}

int main()
{
 
    cout<<checkIfPowerOfTwo(32);
    cout << " control ends " << " ";
    return 0;
}

// time complexity : O(1)
// Why?
// This code uses:
// One comparison: n <= 0
// One subtraction: n - 1
// One bitwise AND: n & (n - 1)
// One comparison with 0
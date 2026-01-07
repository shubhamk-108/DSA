// problem : whether a given number is power of two or not
// Input : n = 4
// Output : Yes
// Explanation: 22 = 4

// Input : n = 32
// Output : Yes
// Explanation: 25 = 32

#include<iostream>
using namespace std;
 
bool checkIfPowerOfTwo(int n)
{
    if (n <1)
        return false;
    while(n!=1)
    {
        if(n%2 ==0)
            n = n / 2;
        else
            return false;
    }
    return true;
}


int main()
{
 
    int n = 32;
    cout << "Before function call " << " \n ";
    cout<< (checkIfPowerOfTwo(n) ? "true" : "false  ");
    cout << " \ncontrol ends " << " ";
    return 0;
}

// Time c : O(logn)

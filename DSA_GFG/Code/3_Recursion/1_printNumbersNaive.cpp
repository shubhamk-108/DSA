// problem 
// if n = 5 then print 5 4 3 2 1

#include<iostream>
using namespace std;
 
void printNumbers(int n)
{
    if (n < 1)
        return;
    cout<<n<<" ";
    printNumbers(n-1);
}


int main()
{
 
    printNumbers(12);
    cout << " \ncontrol ends " << " ";
    return 0;
}


// Time: because T(n) = T(n-1) + theta(1). That means when you call for n, it calls for n-1 and does theta(1) means constant work.
// Therefore total time complexity is: // TIME : theta(n) or O(n)
// Function calls itself with n-1, until n == 0

// So total n recursive calls
// Each call does O(1) work: addition
// Time Complexity: O(n)

// space complexity : O(n)

// Logic:
// first we are printing n and then we are calling function for (n-1)
// and remember the last called function will finishes first.
// for n = 5
// we are printing 5 and then we are calling for n -1 = 4
// we are printing 4 and then we are calling for 4 -1 = 3
// we are printing 3 and then we are calling for 3 -1 = 2
// we are printing 2 and then we are calling for 2 -1 = 1
// we are printing 1 and then we are calling for 1 -1 = 0 so we returns 
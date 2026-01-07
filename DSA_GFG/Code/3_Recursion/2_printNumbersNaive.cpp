// problem 
// if n = 5 then print 1 2 3 4 5

#include<iostream>
using namespace std;
 
void printNumbers(int n)
{
    if (n < 1)
        return;
    printNumbers(n-1);
    cout<<n<<" ";
}


int main()
{
 
    printNumbers(12);
    cout << " \ncontrol ends " << " ";
    return 0;
}

// TIME : O(n)
// space : O(n)


// TIME : O(n)
// space : O(n)

// Logic:
// first we are calling the function and then we are printing n 
//for n = 5, so function will call for 5 and then it will not print 5 because we are first calling function and then printing it
// so function will call for 5 and then it will again call for 4 then for 3 then for 2 and then for 1.
// and now we have these much functions in our function call stack.
// last function call will finish first
// so last was for n = 1 so it will resume its execution from this line cout<<n<<" ";.
// so it will print 1. Then (n-1)'s previous function which was for n = 2 get called and it will resume its execution from this line 
// line cout<<n<<" ";. and then it will print 5 
// similarly other function calls will resume execution from line cout<<n<<" ";. this lien and print 3 then 4 and then 5 
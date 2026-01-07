#include<iostream>
using namespace std;
 
int printSum(int n)
{
    if(n<1)
        return 0;
    return (n + printSum(n-1));
}

int main()
{
 
    cout<<printSum(10);
    cout << " control ends " << " ";
    return 0;
}
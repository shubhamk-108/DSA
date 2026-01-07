// Problem : count the number of digit in a number. If number is 4532 then number of digits are 4

#include <iostream>
using namespace std;

int main()
{
    int num;
    int result = 0;
    cout<<"Enter Number\n";
    cin>>num;
    num = abs(num);


    while(num>0)
    {
        num = num/10;
        result++;
        
    }
    cout<<"Given number is "<<result << " digit number"; 

    return 0;
}

// Logic: 
// Everytime we will divide number by 10 until number is greater than 0. 
// And we will take absolute value of num so that it can work for negative values also

// Time complexity: theta (d) where d is number of digits
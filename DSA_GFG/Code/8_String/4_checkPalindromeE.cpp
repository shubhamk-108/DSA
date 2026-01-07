
#include<iostream>
using namespace std;
 

bool checkPalindrome(string str)
{
    
    int i = 0;
    int j = str.length()-1;

    while(i<=j)
    {
        if(str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    return true;
    
}

int main()
{
 
    string str = "ABCCBA";

    cout<< checkPalindrome(str);
    cout << " \ncontrol ends " << " ";
    return 0;
}

// time : O(n)
// The while loop runs, at most, N/2 times because the two pointers (left and right) start at opposite ends and move towards the center,
// meeting in the middle.
// In Big O notation, constant factors like 1/2 are ignored. Therefore, O(N/2) is simplified to O(N).


//space : O(1)


//logic:

// This is two pointer approach
#include<iostream>
using namespace std;
 
bool checkPalindrome(string str)
{
    string reversed_str;
    for (int i = str.length()-1 ; i >= 0 ; i--)
    {
        reversed_str = reversed_str + str[i];
    }
    return (str == reversed_str);
    
}

int main()
{
 
    string str = "ABCCBA";

    cout<< checkPalindrome(str);
    cout << " \ncontrol ends " << " ";
    return 0;
}


// time: O(n)
// Space: 
// Because the memory required by reversed_str scales linearly with the input size N, its contribution to the space complexity is O(N).




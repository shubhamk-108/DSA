// Efficient solution using Brian Kernighan’s Algorithm:  


#include<iostream>
using namespace std;
 
unsigned int countSetBits(  int n)
{
    int res = 0;
    while (n>0)
    {
        n = n & (n-1);
        res ++;
    }
    return res;
}

int main()
{
    unsigned int n = 15;
    cout<<countSetBits(n);
    cout << " control ends " << " ";
    return 0;
}



// Time Complexity: O(log n)
// Auxiliary Space: O(1)

// So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit.
// If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 
// The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer. 

// n =  9 (1001)
//    count = 0

//    Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
//    n = 9&8  (1001 & 1000)
//    n = 8
//    count  = 1

//    Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
//    n = 8&7  (1000 & 0111)
//    n = 0
//    count = 2

//    Since n = 0, return count which is 2 now.

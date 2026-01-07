// Given an array of positive integers. All numbers occur an even number of times except one number which 
// occurs an odd number of times.

// nput : arr = {1, 2, 3, 2, 3, 1, 3}
// Output : 3

#include <iostream>
using namespace std;

int findOddOccuring(int arr[], int n)
{
    int res = 0;
    for(int i = 0; i<n; i++)
    {
        res = arr[i] ^ res;
    }
    return res;
}

int main() {
	
	int arr[]= {4, 3, 4, 4, 4, 5, 5, 3, 3}, n = 9;
	
    cout<<findOddOccuring(arr, n);
    
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)

// Logic:

// The Best Solution is to do bitwise XOR of all the elements. XOR of all elements gives us odd occurring elements. 

// Here ^ is the XOR operators;
// Note :
// x^0 = x
// x^y=y^x (Commutative property holds)
// (x^y)^z = x^(y^z) (Associative property holds)
// x^x=0

// so same same number cha xor 0 yeil. that is even number cha xor 0 yeil.
// so at the end we will remain with odd numbers xor 0
// for example : 4 ^ 4 ^ 4 ^ 3 ^ 3 ^ 8 ^ 5 ^ 5 ^ 8 // commutative and associative property satistied. so pudhe mage jari zale number tri
// kahi farak padat nahi
// = 4 ^ 4 ^ 4 ^ 3 ^ 3 ^ 5 ^ 5 ^ 8 ^ 8
//  =  4 ^ 4 ^ 4 ^ 0 ^ 0 ^ 0
//  = 0 ^ 4 ^ 0
//  = 4 ^ 0
// = 4

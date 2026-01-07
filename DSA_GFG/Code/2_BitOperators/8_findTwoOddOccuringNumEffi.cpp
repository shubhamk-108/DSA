// problem: 
// Given an unsorted array that contains even number of occurrences for all numbers except two 
// numbers. Find the two numbers which have odd occurrences 

// Input: {12, 23, 34, 12, 12, 23, 12, 45}
// Output: 34 and 45

// Input: {4, 4, 100, 5000, 4, 4, 4, 4, 100, 100}
// Output: 100 and 5000



#include <iostream>
using namespace std;

void oddAppearing(int arr[], int n)
{
    
        int xors = 0, res1 = 0, res2 = 0; 
        
        for (int i = 0; i < n; i++) 
        xors = xors ^ arr[i]; 
  
   
        int sn = xors & (~(xors - 1)); 
  
    
        for (int i = 0; i < n; i++) 
        { 
            if ((arr[i] & sn) != 0) 
                res1 = res1 ^ arr[i]; 
            else
                res2 = res2 ^ arr[i]; 
        } 
        
        
        cout <<  res1 << " " << res2;
}
    
    
int main() {
	
	int arr[]= {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
	
    oddAppearing(arr, n);
    
}


// Time Complexity: O(n)
// Auxiliary Space: O(1)

// All numbers occur even number of times, except two numbers, say a and b, which occur odd number of times.

// Your job is to find those two numbers.

// we already saw in previous code that due to properties of xor even occurances cancel each other 
// and n xor with 0 give that same n.
// now we we do the same code like previous. Here all the even occurances will cancel each other and 
// at the end we will remain with that two odd occurances.

// Now a and b are not equal
// So they differ in at least one bit
// We want to find any bit where a and b differ.
// So two numbers a and b and they differ in at least one bit and that bit which is differing can be find using this formula 
// xors & (~(xors - 1));
// so suppose that two odd occurances are 7 and 5. so we have to do xor of 7 and 5 and then we have to find this xors & (~(xors - 1));
// and this expression will give us the  rightmost set bit, i.e., first differing bit between a and b

// This bit tells us where a and b differ.
// So now we can split the entire array into two groups:

// Group 1: All numbers where that bit is set

// Group 2: All numbers where that bit is not set

// Because a and b differ on that bit, they will end up in different groups.
// And all even-count elements will pair up and cancel out in both groups, leaving only a and b.
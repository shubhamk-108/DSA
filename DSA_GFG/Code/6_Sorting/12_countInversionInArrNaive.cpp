//  There are two conditions for the  elements to be inverse:
// arr[i] > arr[j]
// i < j
// basically there is a greater element occuring in array before current element

#include<iostream>
using namespace std;

int countInversion(int arr[], int n)
{
    int res = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
                res++;
        }
    }
    return res;
}


int main() {
	
    // int arr[]={2,4,1,3,5}; // (4, 1), (4, 3), (2, 1)
    // int arr[]={10,20,30,40};
    int arr[]={50,40,30,20,10}; // if sorted in decreasing order then inversions are ( n*(n-1) )/2 because firse ekement will form 4 inversion that is
    // (n-1) and  second will form 3 inversions that is (n-2) and so on

	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	cout<<countInversion(arr,n);
}

// time : O(n^2)
// space : O(1)
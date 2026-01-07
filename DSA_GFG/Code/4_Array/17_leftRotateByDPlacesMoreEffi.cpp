#include <iostream>
#include <cmath>
using namespace std;


void reverse(int arr[], int low, int high)
{
	while(low < high)
	{
		swap(arr[high], arr[low]);

		low++;
		high--;
	}
}   

void dTimesLeftRotate(int arr[], int n, int d)
{
	reverse(arr, 0, d - 1);

	reverse(arr, d, n - 1);

	reverse(arr, 0, n - 1);
}




int main()
{
    int arr[] = {10, 20, 30, 21, 0}, // {21,0,10,20,30}
    n = 5;      
    int d = 3;
    
    dTimesLeftRotate(arr, n, d);
    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
    
        cout << " control ends " << " ";
    return 0;
}

// time O(n)
// space O(1)

// Logic:
// To understand the program do a dry run
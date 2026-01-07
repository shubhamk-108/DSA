//  Given a sorted array, arr[] consisting of N integers, the task is to find the frequencies of each array element.
// Input: arr[] = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10} 
// Output:       Frequency of 1 is: 3
//               Frequency of 2 is: 1
//               Frequency of 3 is: 2
//               Frequency of 5 is: 2
//               Frequency of 8 is: 3
//               Frequency of 9 is: 2
//               Frequency of 10 is: 1

#include <iostream>
#include <cmath>
using namespace std;


void printFreq(int arr[], int n)
{
	int freq = 1;
	int i = 1;

	while(i<n)
	{
		while(i<n && (arr[i] == arr[i-1]))
		{
			freq++;
			i++;		
		}
		cout<<arr[i-1]<<" "<<freq<<endl;
		freq=1;
		i++;
	}
	if((n==1) || arr[n-1] != arr[n-2] )
		cout<<arr[n-1]<<" "<<freq<<endl;
}
int main() {
	
    //   int arr[] = {10}, n = 1;
      int arr[] = {10, 10, 20, 30, 30, 30}, n = 6;

      printFreq(arr, n);
    
}

// Important
// time complexity : O(n)
// space: O(1)

// Everytime nested loop doesnt mean that time complexity is O(n^2). Look carefully here though loop is nested but it is
//  running n times only. Both loops are utilising same i.

// Logic
// if((n==1) || arr[n-1] != arr[n-2] ) 
// This  condition is necessary because when you dry run program then you will see that when last and second last element is 
// not same then it is not getting printed. That is why we are printing it seperately.
// other progarm you will understand just by reading.

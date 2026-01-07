// Our Task: Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s.  
// We need to do it using the minimum number of group flips. 

// Input : arr[] = {1, 1, 0, 0, 0, 1}
// Output :  From 2 to 4

// Explanation: If we had flipped 1's then we need two flips. From 0 to 1 and from 5 to 5, {0,0,0,0,0,0}. 
// But if we flipped from 2 to 4 then we need only one flip. {1,1,1,1,1,1}. And we want minimum number of flips so our op is from 2 to 4 or 1 flip

// Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
// Output :  
// From 1 to 3
// From 5 to 6
// From 8 to 8
 

// Input : arr[] = {0, 0, 0}
// Output :  
// Explanation : Output is empty, we need not to make any change
 

#include <iostream>
#include <cmath>
using namespace std;

void printGroups(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i] != arr[0])
				cout << "From " << i << " to ";
			else 
				cout << i - 1 << endl;
		}
	}

	if (arr[n - 1] != arr[0])
		cout << n - 1 << endl;
}

int main()
{

	int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0}, n = 9;

	printGroups(arr, n);
}


// time :O(n)
// space : O(1)



// logic :


// see bwlow examples:
// 1, 0, 1, 1, 1 0,0, 1 : If first and last element are same then the groups will be forming has difference of 1.
// Like there are 3 groups of ones and 2 groups of zeros. So difference is 3-2 = 1.

// 1, 0, 1, 1, 1 0,0, 1, 0 : If first and last element is not same then same number of groups of one and zero. So 
// we have group of ones is 3 and zeros is 3. So difference is 3-3 = 0.

// So the difference between group of one and group of zero is either 0 or 1.

// That is if first and last element is same then whatever that first element is, it will always have 1 more number of groups.
// So we will filp intermediate groups only.

// for (int i = 1; i < n; i++)
// We will start with index 1 because we are never gonna change starting group because that will always be one more group

// if (arr[i] != arr[i - 1])
// Then if current element and previous element is not same then this is the starting of new group. So we will start flipping from here.			

// if (arr[i] != arr[0])                                      
// 	cout << "From " << i << " to ";
// But here is the catch. We need to flip intermediate bits and not the bits which are similar to first bit or first group of bit. 
// So we will check every element with first element. If it is not similar to first element that means it is different group. So we will
//  print that index 
// as start index of new group

// else 
// 	cout << i - 1 << endl;
// Else part means the element is similar to first element which we dont want to flip so that means element prior to this element 
// is the end of our previous group. So we will print that index as end index.

// if (arr[n - 1] != arr[0])
// 	cout << n - 1 << endl;
// and we are printing last element because if last element is not similar to second last element that means that is the starting of new group.
// so loop will print starting index of that last group but then the loop will go index out pg bound. So we need to explicitely print 
// last element if last element belong to different group and we will check it by checking that element to first element that way 
// we will get to know that whether is it belonging to different group of first elenent's group.
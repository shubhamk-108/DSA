// An element is a leader if it is greater than all the elements to its right side. And the last element is always a leader. 
// Input: arr[] = {16, 17, 4, 3, 5, 2}, 
// Output: 17, 5, 2
 
// Input: arr[] = {1, 2, 3, 4, 5, 2}, 
// Output: 5, 2

// This program print leaders from right to left. If you want to print from left to right then make a temp array and store the
// leaders in it and apply reverse array function on it. In that type the space complexity will increase to O(n) due to temp array

#include <iostream>
#include <cmath>
using namespace std;

void leaders(int arr[], int n)
{
    int current_leader =  arr[n-1];
    cout<<current_leader<<" ";
	for(int i = n-2; i >=0 ; i--)
    {
        if(arr[i] > current_leader )
        {
            current_leader = arr[i];
            cout<<current_leader<<" ";
        }
    }
}


int main() {
	
    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int n = 7;

    leaders(arr, n);
    
}

// time : O(n)
// space : O(1)

// --------------------------------------------------------------------------------

// Logic

/*

void leaders(int arr[], int n)
{
    // last element is always leader
    int current_leader =  arr[n-1];
    cout<<current_leader<<" ";

    // traversing from right side
	for(int i = n-2; i >=0 ; i--)
    {
        // arr[i] means jr pathimagacha element larger aahe pudhachya element peksha then to arr[i] ha leader aahe
        if(arr[i] > current_leader )
        {
            // so current leader change karayacha mhanje pudhe compare karata yeil
            current_leader = arr[i];
            cout<<current_leader<<" ";
        }
    }
}

*/
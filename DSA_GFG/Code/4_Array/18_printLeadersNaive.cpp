// An element is a leader if it is greater than all the elements to its right side. And the last element is always a leader. 
// Input: arr[] = {16, 17, 4, 3, 5, 2}, 
// Output: 17, 5, 2
 
// Input: arr[] = {1, 2, 3, 4, 5, 2}, 
// Output: 5, 2

#include <iostream>
#include <cmath>
using namespace std;

void leaders(int arr[], int n)
{
	for(int i = 0; i < n; i++)
    {
        bool flag = false;
        // j = j + 1 means i jithe pn asel tithun pudhachya saglya index
        for(int j = i+1; j<n; j++)
        {
            // je pathimagacha element ha smaller aahe pudhachya element peksha means pudhe greater element aahe so ith element can not be a leader
            if(arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
                
        }
        if(flag==false)
            cout<<arr[i]<<" ";
    }
}



int main() {
	
    int arr[] = {7, 10, 4, 10, 6, 5, 2}; //10 6 5 2 
    int n = 7;

    leaders(arr, n);
    
}
// time : O(n^2)
// space : O(1)
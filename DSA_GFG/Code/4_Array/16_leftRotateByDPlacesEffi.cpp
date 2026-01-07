// ip = {1,2,3,4,5}
// op = {2,3,4,5,1}
// Anticlockwise direction madhe rotate karayache aahe element by D position. Above example is for 1 position. D = 1

#include<iostream>
using namespace std;
#include<algorithm>

void dTimesLeftRotate(int arr[], int n, int d)
{
    int temp[d];
    for(int i = 0 ; i< d; i++)
    {
        temp[i] = arr[i];
    }
    for(int i = d ; i< n; i++)
    {
        arr[i-d] = arr[i];
    }
    for(int i = 0 ; i< d; i++)
    {
        arr[n-d+i] = temp[i];
    }
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
// space O(n)

// Logic:
// To understand the program do a dry run
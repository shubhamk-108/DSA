// segregatePositiveNegative

#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void segregatePositivAndNegative(int arr[], int n)
{
    int temp[n];
    int idx = 0;

    // copy negative elements into temp array
    for(int i =0; i<n; i++)
    {
        if(arr[i] < 0)
        {
            temp[idx] = arr[i];
            idx++;
        }
    }
    // copy positive elements into temp array
    for(int i =0; i<n; i++)
    {
        if(arr[i] >=0)
        {
            temp[idx] = arr[i];
            idx++;
        }
    }
    // copy temp arr into original arr
    for(int i =0; i<n; i++)
    {
        arr[i] = temp[i];
    }

}

int main()
{

    // int arr[] =  {7, 3, 2, 4, 9, 12, 56} ; 
    // int k = 3;

    int arr[] =  {3, 4, -1, -9 ,-56 , 7, 9 ,12} ; 


    int n = sizeof(arr) / sizeof(arr[0]);

    segregatePositivAndNegative(arr, n);

    for(auto x: arr)
        cout<<x<<" ";
        
    return 0;
}


// TIME and space both: O(n)
#include<iostream>
using namespace std;
 
bool searchArr(int arr[], int n, int x)
{
    for(int i = 0; i < n ; i++)
    {
        if(arr[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {2,33,63,1,40};
    int n = 5;
    int x = 323;
    cout<< (searchArr(arr,n,x) ? "Found" : "Not found");
    cout << " \ncontrol ends " << " ";
    return 0;
}

// TIme complexity this search operation in unsorted array is O(n)
// spacecomplexity : O(1)
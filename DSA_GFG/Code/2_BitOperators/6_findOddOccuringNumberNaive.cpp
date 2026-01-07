#include<iostream>
using namespace std;
 
int findOddOccuringNum(int arr[], int n)
{
    for(int i = 0; i< n; i++)
    {
        int res = 0;
        for(int j = 0; j<n; j++)  
        {
            if(arr[i] == arr[j])
                res = res + 1;
        }
        if(res % 2 != 0)
            return arr[i];
    }
    return 0;
}

int main()
{
    int arr[] = {4, 5 ,6, 2, 4, 4, 5,6,2};
    int n = 9;
    cout<<findOddOccuringNum(arr, n);
    cout << " control ends " << " ";
    return 0;
}

// time O(n^2)

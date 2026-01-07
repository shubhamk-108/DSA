

#include <bits/stdc++.h>
using namespace std;

using namespace std;

int getlargest(int arr[],int n)
{
    if(n==0)
        return -1;
    int largest = arr[0]; // Assume first element is largest
    for (int i = 0 ; i < n ; i++)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}
int main()
{
    int arr[]={5,8,20,15};
    cout<<getlargest(arr,4);
    return 0;
}
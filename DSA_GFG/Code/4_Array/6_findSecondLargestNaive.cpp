

#include <bits/stdc++.h>
using namespace std;

using namespace std;

int getLargest(int arr[], int n)
{
    if(n==0)
        return -1;
    int largest = 0; // Assume first element is largest
    for (int i = 0 ; i < n ; i++)
    {
        if(arr[i] > arr[largest])
            largest = i;
    }
    return largest;
}

int getSecondLargest(int arr[],int n)
{
    
    int largest = getLargest(arr, n);
    
    // because there may be a possibility that there is no 2nd largest
    int second_largest =-1;

    for (int i = 0 ; i < n ; i++)
    {
        if(arr[i] != arr[largest] )
        {
            // largest no sodun jo pn pahila no milel tyala aapan assume kel ka to 2nd largest aahe
            if(second_largest == -1)
                second_largest = i;
            else if (arr[i] > arr[second_largest])
                second_largest = i;
            
        }
        
    }
    return second_largest;
}
int main()
{
    int arr[]={5,8,20,14};
    cout<<getSecondLargest(arr,4);
    return 0;
}

// time : O(n)
// space  O(1 )
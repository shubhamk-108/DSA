#include<iostream>
using namespace std;
 
int findSecondLargest(int arr[], int n)
{
    int largest = 0;
    int secondLargest = -1;

    for(int i = 1 ; i < n ; i ++ )
    {
        if(arr[i] > arr[largest])
        {
            secondLargest = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (secondLargest == -1 || arr[i] > arr[secondLargest])
                secondLargest = i;
        }
    }
    return secondLargest;
}

int main()
{
    int arr[]={5,19,20,14};
    cout<<findSecondLargest(arr,4);
    return 0;
}

// time : O(n)
// space  O(1)
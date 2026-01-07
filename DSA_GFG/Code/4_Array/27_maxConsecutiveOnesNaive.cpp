// // Our Task: Given a binary array, find the count of the maximum number of consecutive 1's present in the array.
// xamples : 

// Input: arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
// Output: 4

// Input: arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
// Output: 1


#include<iostream>
#include<cmath>
using namespace std;
using namespace std;

int maxConsecutiveOnes(int arr[], int n)
{
    
    int res = 0;
    for(int i = 0; i<n; i++)
    {   
        int count = 0;
        for(int j = i; j<n; j++)
        {
            if(arr[j] == 1)
            
                count++;
            else
                break;
        }
        res = max(res, count);
    }
    return res;
}


int main()
{
 
    int arr[] =  {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<maxConsecutiveOnes(arr, n);

    cout << " control ends " << " ";
    return 0;
}




// Time Complexity : O(n2) 
// Auxiliary Space : O(1)

// Logic:


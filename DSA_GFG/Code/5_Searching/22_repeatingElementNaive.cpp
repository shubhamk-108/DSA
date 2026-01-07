// In this problem, we have an array where each element appears only once except for a single element that has
// multiple occurrences. Additionally, the array always contains the number 0, and if the maximum element in the array
// is x, then all elements from 0 to x are guaranteed to be present in the array
// we are not allow to modify array


// we werent allow to modify array but this is one of the solution if that was not the constraint


#include <iostream>
#include <algorithm>
using namespace std;

bool repeatingElement(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 1 ; i++)
    {

        if (arr[i] == arr[i+1])
            return true;
    }
    return false;
}

int main()
{

    int arr[] = {0, 2, 1, 3, 2, 2}, n = 6;

    cout << repeatingElement(arr, n);

    return 0;
}

// time: O(n*logn)
// space :O(1)


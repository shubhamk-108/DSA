// Input  : arr[] = {10, 20, 10, 5, 15}
// Output : prefixSum[] = {10, 30, 40, 45, 60}
// Explanation : While traversing the array, update the element by adding it with its previous element.
// prefixSum[0] = 10,
// prefixSum[1] = prefixSum[0] + arr[1] = 30,
// prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on.

// we have a function like this getSum(arr,1,3) where 1 is left index and 3 is right index and we need to find
// the sum from left index to right index

#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int getSum(int arr[], int l, int r)
{
    int res = 0;
    for (int i = l; i <= r; i++)
        res += arr[i];
    return res;
}

int main()
{
    int arr[] = {2, 8, 3, 9, 6, 5};
    cout << getSum(arr, 1, 3);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(1)


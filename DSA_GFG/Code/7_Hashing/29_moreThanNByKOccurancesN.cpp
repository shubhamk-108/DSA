// { 30, 10, 20, 20, 10, 20, 30, 30}, n = 8 , k = 4 , n/k = 2 That is we have to find the number which is occuring 3 or more than 3 times
// Therefore op = 20 30

#include <iostream>
#include <algorithm>
using namespace std;

void printMoreThanNByKOccurances(int arr[], int n, int k)
{
    

    sort(arr, arr + n);

    int count = 1;
    for (int i = 1; i < n; i++)
    {

        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {   
            if(count > (n/k))
                cout<<arr[i-1]<< " ";
            count = 1;
        }
    }

    if (count > (n/k))
        cout<< arr[n-1];
}

int main()
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printMoreThanNByKOccurances(arr, n, k);

    return 0;
}



// time space

/*
Time Complexity
Sorting the array → O(n log n).
Single traversal of array → O(n).
✅ Total: O(n log n)

💾 Space Complexity
Space: O(1) auxiliary (or O(log n) if you count recursion stack of sort).

*/


//logic


/*

// Function to print all elements that appear more than n/k times in the array
void printMoreThanNByKOccurances(int arr[], int n, int k)
{
    // Step 1: Sort the array → groups equal elements together
    sort(arr, arr + n);

    int count = 1; // count occurrences of current element

    // Step 2: Traverse the array from 1 to n-1
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])  
        {
            // If current element is same as previous → increase count
            count++;
        }
        else
        {
            // When new element starts, check if previous element qualifies
            if (count > (n / k))
                cout << arr[i - 1] << " ";

            // Reset count for new element
            count = 1;
        }
    }

    // Step 3: Handle the last element group
    if (count > (n / k))
        cout << arr[n - 1];
}


*/
// In this problem, we have an array where each element appears only once except for a single element that has
// multiple occurrences. Additionally, the array always contains the number 0, and if the maximum element in the array
// is x, then all elements from 0 to x are guaranteed to be present in the array
// we are not allow to modify array

// we have assume that elements in array are positive integers

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

bool repeat(int arr[], int n, int max_element)
{
    if (n <= 1)
    {
        return false;
    }
    bool repeat_found = false;

    bool *visited = new bool[max_element];

    std::fill(visited, visited + max_element, false);

    for (int i = 0; i < n; i++)
    {
        if(arr[i] >= max_element || arr[i] < 0)
            continue;

        if (visited[arr[i]])
        {
            repeat_found = true;
            break;
        }
        else
        {
            visited[arr[i]] = true;
        }
    }

    delete[] visited;
    return repeat_found;
}

int main()
{

    // int arr[] = {0, 2, 1, 3, 2, 2}, n = 6;
    int arr[] = {0, 2, 1, 3, 543, 221}, n = 6;
    int max_element = 543 + 1;

    cout << repeat(arr, n, max_element);

    return 0;
}


// Time Complexity: O(N)
// space:
// Space Complexity: O(M)
// The space complexity is linear with respect to the maximum possible value in the array (M), which is max_element_plus_one.

// we are creating a look up table and we initialise it with zeors. We run loop and if we found that element
// occuring again then we make our arr[i] element in bool array as true and we return
// we are doing visited[arr[i]] because arr[i] is the element and it will act as a index. suppose arr[i] is 5
// then when it comes first time at that time we mark index 5 as true and if it comes second time then we 
// see it index 5 again and we see that it is already true means it is coming second time so we return as true.

// why max-element+ 1.
// because in loopup table (our visited bool array) we are marking true and false the arr[i] index in visited bool array.
// suppose there are only 5 elements in the array but the largest element is 543. at some point arr[i] will be 543
// so we will mark 543 as true in bool array so that when it comes again we will again see that index 543 is already marked 
//  and it means that 543 is the repeating number.
// and +1 is because bool* visited = new bool[max_element] This creates a boolean array named visited with indices ranging from 0 to 542.
// so when we will access visited[543] it will say index out of bound so that is why we are creating 543+1 size visited array
// so that it will create index from 0 to 543.
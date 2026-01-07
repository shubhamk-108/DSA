// { 30, 10, 20, 20, 10, 20, 30, 30}, n = 8 , k = 4 , n/k = 2 That is we have to find the number which is occuring 3 or more than 3 times
// Therefore op = 20 30

#include <iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

void printMoreThanNByKOccurances(int arr[], int n, int k)
{
    
    unordered_map <int,int> um;

    for (int i = 0; i < n; i++)
    {
        um[arr[i]] ++;
    }

    for(auto &p : um)
    {
        if(p.second > (n/k) )
            cout<<p.first<<" ";
    }
    
}

int main()  
{
    int arr[] = {30, 10, 20, 20, 10, 20, 30, 30};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    printMoreThanNByKOccurances(arr, n, k);

    return 0;
}

// time sapce 

/*

Time Complexity

Building frequency map:
Loop over n elements → O(n) average case (since unordered_map insert/find is O(1) average).
Traversing the map:
At most n distinct elements → O(n).
✅ Total Average Time: O(n)

Space = O(n) in worst case.

*/


// logic

/*

// Function to print all elements that appear more than n/k times in the array
void printMoreThanNByKOccurances(int arr[], int n, int k)
{
    // Step 1: Count frequencies of each element using unordered_map
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;  // increment frequency of arr[i]
    }

    // Step 2: Traverse the map and print elements whose count > n/k
    for (auto &p : um)
    {
        if (p.second > (n / k))
            cout << p.first << " ";
    }
}


*/
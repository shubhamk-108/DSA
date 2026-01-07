// problem:
// This function computes the sums of all possible subsets of a given array and stores them in the sumSubset vector.
// ip n = 2
// arr = [2,3]
// op [0 , 2, 3,5 ]
// when none taken = 0
// when only 2 is taken = 2
// when only 3 is taken = 3
// when both 2 and 3 are taken = 5

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void sumOfSubset(vector <int> arr, int n, int sum, int i,  vector<int> &sumSubset)
{
    if(i == n)
    {
        sumSubset.push_back(sum);
        return;
    }


    // Exclude element
    sumOfSubset(arr, n, sum, i+1, sumSubset);

    // include
    sumOfSubset(arr, n, sum+arr[i], i+1,  sumSubset);
}

int main()
{
    vector<int>arr = {1,2,3};
    int n = 3;
    int sum = 0;
    int i = 0;
    vector<int>sumSubset;

    sumOfSubset(arr, n, sum, i , sumSubset);

    sort(sumSubset.begin(), sumSubset.end());
    for(auto x : sumSubset)
    {
        cout<<x<<", ";
    }
    return 0;
}


// Logic:

Base condition (if (i == n)):

// Once we have considered every element (i.e., reached past the end of the array), we store the sum collected for this "path" (i.e., one subset).

// Recursive calls:

// Branch 1: Exclude arr[i] from the subset (keep sum unchanged, move to next index)

// Branch 2: Include arr[i] in the subset (add arr[i] to sum, move to next index)

// This covers all possibilities for each element (include/exclude).

// Result:

// In the end, sumSubset will contain the sums of all 2^n possible subsets of the input array.

// Time Complexity
// For every element, you make two recursive calls (include or exclude).

// So, the total number of recursive calls is O(2^n).

// For each call, the work done is O(1) except at the leaf, where you execute sumSubset.push_back(sum), which is O(1) (since sumSubset is passed by reference and adding to a vector is O(1) amortized).

// **Total Time Complexity: **
// O(2^n)

// Space Complexity
// Auxiliary (Recursion stack):
// The maximum depth of recursion is n (since for each element you go deeper by 1), so stack space is O(n).

// Output space (sumSubset):
// You're storing the sum for every subset, and there are 2^n subsets. So the vector will contain 2^n elements.

// Total Space Complexity:
// O(n + 2^n)
// Where:

// O(n) is for the recursion stack.

// O(2^n) is for the output vector storing all subset sums.
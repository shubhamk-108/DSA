#include<iostream>
#include<algorithm>
using namespace std;


void mergeTwoArrays(int arr1[], int arr2[], int m, int n)
{
    int mergeArr[m+n]; 
    for(int i = 0; i<m; i++)
    {
        mergeArr[i] = arr1[i];
    }
    for(int i = 0; i<n; i++)
    {
        mergeArr[m+i] = arr2[i];
    }

    sort(mergeArr, mergeArr+m+n);

    for(auto x: mergeArr)
        cout<<x<<" ";

}

int main()
{
    int arr1[] = {3,5,1,22,44};  
    int arr2[] = {14, 33, 17, 2};  
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    mergeTwoArrays(arr1, arr2, m, n);

    
    return 0;
}


// Time Complexity: O((m+n) log(m+n))
// Space Complexity: O(m+n)

// logic

/*



// Using namespace for cout and sort for brevity in this example
using namespace std;

// Function to merge two arrays, arr1 of size m and arr2 of size n
void mergeTwoArrays(int arr1[], int arr2[], int m, int n)
{
    // 1. Create a new array to hold the elements of both arrays.
    // In C++, variable-length arrays (VLAs) like this are a non-standard extension.
    // A std::vector<int> mergeArr(m + n); would be the standard C++ way.
    int mergeArr[m + n]; 

    // 2. Copy all elements from the first array (arr1) into the new array.
    for (int i = 0; i < m; i++)
    {
        mergeArr[i] = arr1[i];
    }

    // 3. Copy all elements from the second array (arr2) into the new array,
    // placing them after the elements from the first array.
    for (int i = 0; i < n; i++)
    {
        mergeArr[m + i] = arr2[i];
    }

    // 4. Sort the entire merged array.
    // std::sort is a highly efficient sorting algorithm (typically IntroSort).
    // It has an average time complexity of O(N log N), where N is the number of elements.
    sort(mergeArr, mergeArr + m + n);

    // 5. Print the elements of the sorted merged array.
    for (auto x : mergeArr)
    {
        cout << x << " ";
    }
    cout << endl; // Add a newline for better formatting
}



*/
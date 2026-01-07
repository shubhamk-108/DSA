#include<iostream>
using namespace std;
 
int insertArr(int arr[], int n, int cap, int x, int pos)
{
    if(cap == n)
    {
        return n;
        // If capacity is same as array size then there is no space to insert
    }

    int idx_to_insert = pos - 1;

    // reverse yayach jya insex la insert karayach aahe tith paryant aani jithe insert karayache aahe tithun pudhache element
    // ek-ek position ne pudhe shift karayache
    for(int i = n-1; i<= idx_to_insert; i --)
    {   
        // ek place ne pudhe shift karayach aahe tr pudhacya element la magacha element assign karayacha
        arr[i + 1] = arr[i];
    }
    // aata ti index empty zali aahe tr tya index la to element assign kr
    arr[idx_to_insert] = x;
    return n + 1;
}

int main()
{
    // code to check if array is not full then is it working fine or not
    int arr[] = {2,33,63};
    int n = 3;
    int cap = 5;
    int x = 9;
    int pos = 2;
    
    cout<<"Before insertion\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    

    n = insertArr(arr,n,cap, x, pos);


    cout<<"\nAfter insertion\n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    // code to check if array is full then is it working fine or not
    // int arr[] = {2,33,63, 6};
    // int n = 4;
    // int cap = 4;
    // int x = 9;
    // int pos = 2;
    
    // cout<<"Before insertion\n";
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    

    // n = insertArr(arr,n,cap, x, pos);


    // cout<<"\nAfter insertion\n";
    // for(int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";


    cout << " \ncontrol ends " << " ";
    return 0;
}

// TIme complexity this search operation in unsorted array is O(n)
// spacecomplexity : O(1)
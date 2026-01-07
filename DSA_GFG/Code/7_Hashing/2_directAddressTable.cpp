

#include <bits/stdc++.h>
using namespace std;

// Use PascalCase for the struct name for better readability
struct DirectAccessTable
{
    // Using bool is clearer and more memory-efficient
    bool isPresent[1000] = {false}; // {0} works, but {false} is more explicit

    // Use standard naming for functions
    void insert(int key)
    {
        isPresent[key] = true;
    }

    // Renamed to avoid using the 'delete' keyword
    void remove(int key)
    {
        isPresent[key] = false;
    }

    // Simplified the search function and corrected its return type
    bool search(int key)
    {
        return isPresent[key];
    }
};


int main()
{
    DirectAccessTable  dat;
    dat.insert(10);
    dat.insert(20);
    dat.insert(119);
    cout<<dat.search(10)<<endl;
    cout<<dat.search(20)<<endl;
    dat.remove(119);
    cout<<dat.search(119)<<endl;
    
    return 0; 
}


// Logic

// What is a Direct Access Table?
// A Direct Access Table is a simple data structure that uses an array to store and access data, where the key of the data is 
// used directly as the index of the array. It's one of the most basic forms of a hash table, but it doesn't use a hash function.

// Here are its key characteristics:

// Direct Mapping: A key k is stored at array[k]. There is a one-to-one relationship between the key and its location.

// O(1) Operations: Because arrays offer random access, the main operations—insert, delete, and search—all take constant time,
//  or O(1). You can jump directly to the correct index without iterating through other elements.

// Limited Key Range: It works well only when the universe of possible keys is relatively small and manageable. For example, if
//  your keys are integers from 0 to 999, you can use an array of size 1000. It becomes impractical if keys are very large
//   numbers (like phone numbers) because you would need an enormous array, wasting a lot of memory



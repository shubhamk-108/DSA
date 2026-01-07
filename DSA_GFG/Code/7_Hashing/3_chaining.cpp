#include <bits/stdc++.h>
using namespace std;

struct Chaining
{
    // This must be here only and not in constructor because
    // A constructor's job is to initialize member variables, not to declare them. The declaration of all member variables must happen \
    // in the main body of the struct or class
    int TOTAL_BUCKETS;
    list<int> *table;

    Chaining(int b)
    {
        // This is initialisation
        TOTAL_BUCKETS = b;

        // create one single array that holds bucket number of different lists. For ex: list<int>arr[4]; creates an array arr 
        // which holds 4 lists. Basically similar to array of array but here we have array of lists. Array aahe jyacha 
        // data type list aahe ani lists cha data type int aahe.
        table = new list<int>[TOTAL_BUCKETS];
    }

    // destructor
    ~Chaining()
    {
        delete[] table;
    }

    void insert(int x)
    {
        int BUCKET_no = x % TOTAL_BUCKETS;
        table[BUCKET_no].push_back(x);
    }

    bool search(int x)
    {
        int BUCKET_no = x % TOTAL_BUCKETS;
        for (auto y : table[BUCKET_no])
        {
            if (x == y)

                return true;
        }
        return false;
    }

    // this remove method will not create ambiguity becauase when we are invoking outer remove method then it is 
    // invoked using Myhash object or struct object and inside remove method is being invoked using list object
    // because inner remove belongs to the c++ stl lists
    void remove(int x)
    {
        int BUCKET_no = x % TOTAL_BUCKETS;
        // table[BUCKET_no] this will return us a list and then we are applying remove function on that list
        table[BUCKET_no].remove(x);
    }
};

int main()
{
    Chaining chain(7);
    chain.insert(10);
    chain.insert(20);
    chain.insert(15);
    chain.insert(7);
    cout << chain.search(10) << endl;
    chain.remove(15);
    cout << chain.search(15);
}



//

/*


#include <list>      // Required to use std::list
#include <algorithm> // Required for std::find in some search implementations
#include <iostream>  // Useful for testing and printing

// A struct to implement a Hash Table using the chaining method for collision resolution.
struct Chaining
{
    // --- Member Variables ---

    // The total number of buckets in the hash table. This determines the size of the array.
    int TOTAL_BUCKETS;

    // A pointer to a dynamic array of lists. Each element in the array is a bucket,
    // and each bucket is a list that will store keys that hash to the same index.
    std::list<int> *table;

    // --- Constructor ---
    // This function is automatically called when a Chaining object is created.
    // It initializes the hash table with a specific number of buckets.
    Chaining(int b)
    {
        // Set the number of buckets based on the user-provided size 'b'.
        TOTAL_BUCKETS = b;

        // Dynamically allocate memory on the heap for the array of lists.
        // The size of the array is determined by TOTAL_BUCKETS.
        table = new std::list<int>[TOTAL_BUCKETS];
    }
    
    // --- Destructor ---
    // This function is automatically called when a Chaining object goes out of scope or is deleted.
    // Its purpose is to clean up dynamically allocated memory to prevent memory leaks.
    ~Chaining()
    {
        // Free the memory that was allocated for the array of lists.
        delete[] table;
    }


    // --- Member Functions ---

    // Inserts a new key 'x' into the hash table.
    void insert(int x)
    {
        // Calculate the bucket index for the key 'x' using the modulo operator.
        // This is a simple hash function.
        int BUCKET_no = x % TOTAL_BUCKETS;

        // Access the list at the calculated bucket index and add 'x' to the end of it.
        // If other keys have the same hash, 'x' will be chained in the same list.
        table[BUCKET_no].push_back(x);
    }

    // Searches for a key 'x' in the hash table.
    // Returns true if the key is found, false otherwise.
    bool search(int x)
    {
        // Calculate the bucket index where the key 'x' should be located.
        int BUCKET_no = x % TOTAL_BUCKETS;

        // Iterate through every element 'y' in the list at the calculated bucket index.
        for (auto y : table[BUCKET_no])
        {
            // If the current element 'y' matches the key 'x' we are searching for...
            if (x == y)
            {
                // ...the key is found, so we can stop searching and return true immediately.
                return true;
            }
        }

        // If the loop completes without finding the key, it means 'x' is not in the list.
        return false;
    }

    // Removes a key 'x' from the hash table.
    void remove(int x)
    {
        // Calculate the bucket index where the key 'x' should be located.
        int BUCKET_no = x % TOTAL_BUCKETS;

        // Access the list at the calculated index (`table[BUCKET_no]`).
        // Then, call the built-in `remove()` method of the `std::list` class.
        // This method will find and remove all occurrences of 'x' from that specific list.
        table[BUCKET_no].remove(x);
    }
};



*/
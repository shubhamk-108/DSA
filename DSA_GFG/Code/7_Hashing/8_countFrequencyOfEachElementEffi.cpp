// Read this before reading the code 
// Question : if we have 5 elements in the array and one of elements is 481 then how we access index 481 in the array as we have only 
// 5 elements as we are doing  freqMap[arr[i]]++;

// answer:

/*

You are correct that if freqMap were an array, the line freqMap[arr[i]]++ would be a disaster. If arr[i] was 481, you would 
be trying to access index 481 of an array, which would be an out-of-bounds error.

However, freqMap is not an array. It is a std::unordered_map, which is a hash map.
The Magic of the [] Operator in unordered_map
When you use the square bracket operator [] on an unordered_map, it does something very different from an array:
It does not use the value as an index. Instead, it treats the value inside the brackets (e.g., 481) as a key.
The map takes this key (481) and passes it through its internal hash function.
The hash function converts the key (481) into a valid index that fits within the map's internal storage (e.g., hash(481) -> 7).
It then goes to that calculated index (e.g., index 7) to find or store the data.
Let's Trace Your Example:
arr has 5 elements. One of them is 481.
freqMap is an empty unordered_map.
The line freqMap++; performs the following steps:
Lookup: The map asks, "Does the key 481 already exist in me?"
Hash: To find out, it calculates hash(481) which might return, for example, the index 7.
Check Slot: It checks its internal array at index 7.
Key Not Found (First Time): The map sees that the key 481 is not there. Because you used the [] operator, it performs two actions:
It creates a new entry: It stores the key 481 in its internal structure.
It default-initializes the value: For an int, the value is initialized to 0. So now the map contains the pair {key: 481, value: 0}.
Increment: Finally, the ++ operator is applied to the value, changing it from 0 to 1. The map now contains {key: 481, value: 1}.
If the code later encounters another 481 in the array and runs freqMap++ again:
Lookup: The map asks, "Does the key 481 exist?"
Hash: It calculates hash(481) -> 7.
Check Slot: It goes to index 7 and finds the entry for key 481.
Key Found: It retrieves the current value, which is 1.
Increment: The ++ operator increments the value from 1 to 2. The map now contains {key: 481, value: 2}.


*/


// code: 


#include <iostream>
#include <unordered_map>
using namespace std;


void countFrequencyOfEachElement(int arr[], int n)
{
    
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++)
    {
        freqMap[arr[i]]++;
    }

    cout << "Element Frequencies:" << endl;
    for (const auto& pair : freqMap)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}
int main()
{
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    countFrequencyOfEachElement(arr, n);
    
    return 0;
}




// ______________________________________________________________________________________________________________
// Questions and answers 
// ______________________________________________________________________________________________________________


/*
// ----------------------------------------------------------------------------------------------------------

Question 1:
so this part freqMap[arr[i]] returns me value of a key and not a key itself
Answer 1:
You are absolutely correct. 

// -----------------------------------------------------------------------------------------------------

Question 2:
and if after doing this freqMap[arr[i]] , if key is not present it will add the key and add the by default value as 0 
and if the key is present freqMap[arr[i]] ++ this will increment value by 1 in the same key

Answer 2:
arr[i] is the key remember.
Your understanding is now 100% correct.

// ---------------------------------------------------------------------------

Question 3:
freqMap[arr[i]] if this return us the value then how to get key

Answer 3:
You are correct that freqMap[arr[i]] gives you the value. A hash map is designed for fast key-to-value lookup. It is not 
designed to do the reverse (value-to-key lookup).
So, how do you get the key?
You don't "get" the key from the value. You get both the key and the value at the same time by iterating over the map.

// -----------------------------------------------------------------------------------------
Question 4:
what if i have to set the value manually for ex set value as 16 then how would this freqMap[arr[i]]++ be

Answer 4:
freqMap[arr[i]] = 16;

// ---------------------------------------------------------------------------

Question 5:
so is it equivalent freqMap[arr[i]] += 1; and freqMap[arr[i]]++

Answer 5:
Yes but with subtle difference 
freqMap[arr[i]]++ (Post-increment): This operator first returns the original value of freqMap[arr[i]] before it was incremented.
Then, it increments the value in the map.
And freqMap[arr[i]] += 1 (Compound Assignment): This operator first adds 1 to the value of freqMap[arr[i]] and then returns the new, 
updated value.
But this difference does not affect our code

*/


// ______________________________________________________________________________________________________________
// Time and space 
// ______________________________________________________________________________________________________________

/*

Time Complexity: O(n) - Correct
You are absolutely correct. The process involves two main steps:
Building the Map: You iterate through the n elements of the array once. Each insertion into the unordered_map takes O(1) time 
on average. This step is O(n).
Printing the Map: You iterate through the k unique elements stored in the map. This step is O(k).
The total time complexity is O(n) + O(k). Since the number of unique elements k can be at most n, this simplifies to O(n).

Space Complexity: O(k) or O(n) - Correct
You are also correct here.
The extra space used is for the unordered_map.
The map stores one key-value pair for each unique element in the array.
If there are k unique elements, the space complexity is O(k).

*/




// ______________________________________________________________________________________________________________
// logic::
// ______________________________________________________________________________________________________________


/*



#include <iostream>
#include <unordered_map>
using namespace std;

// This function counts and prints the frequency of each element in an array
// using an optimized approach with a hash map (unordered_map).
void countFrequencyOfEachElement(int arr[], int n)
{
    // Create an unordered_map to store the frequency of each element.
    // The 'key' of the map will be the element from the array.
    // The 'value' will be the count of how many times that element has appeared.
    unordered_map<int, int> freqMap;

    // --- Step 1: Build the Frequency Map in a Single Pass ---
    // Iterate through the input array exactly once.
    for (int i = 0; i < n; i++)
    {
        // For each element arr[i], use it as a key in the map and increment its associated value (count).
        // If the key arr[i] does not exist in the map yet, C++ automatically creates it
        // and initializes its value to 0 before the increment operation.
        freqMap[arr[i]]++;
    }

    // --- Step 2: Print the Results ---
    // After the loop, freqMap contains every unique element and its total frequency.
    // Now, iterate through the map to print the results.
    // 'const auto&' is an efficient way to loop through map pairs without making copies.
    cout << "Element Frequencies:" << endl;
    for (const auto& pair : freqMap)
    {
        // pair.first is the element (the key).
        // pair.second is its frequency (the value).
        cout << pair.first << " : " << pair.second << endl;
    }
}


*/
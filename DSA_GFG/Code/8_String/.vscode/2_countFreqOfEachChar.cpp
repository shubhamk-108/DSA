// This code will also show us how we can do arithmetic operations with string

#include<iostream>
using namespace std;

 int main()
 {
    string str = "geeksforgeeks";

    int count[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if(count[i]>0)
        {
            cout<< char(i + 'a') <<" " << count[i] <<endl;
        }
    }
    
    
 }


//  Time Complexity: O(N)
// The first loop iterates through the input string of length N once. This takes O(N) time, where N is the length of the string str.
// The second loop iterates 26 times, which is a constant number. This takes O(26) or O(1) time


// Space Complexity: O(1)

 //logic

 /*
 
 #include <iostream>
#include <string>

// The 'using namespace std;' directive is often used for convenience,
// but in larger projects, it's better to qualify names with 'std::' 
// to avoid potential naming conflicts. For this small example, it's fine.
using namespace std;

int main()
{
    // 1. Initialize the input string.
    string str = "geeksforgeeks";

    // 2. Create a frequency array for lowercase English letters.
    // An array of size 26 is used, where each index corresponds to a letter.
    // index 0 -> 'a', index 1 -> 'b', ..., index 25 -> 'z'.
    // It's initialized to all zeros.
    int count[26] = {0};

    // 3. Populate the frequency array.
    // Loop through each character of the input string.
    for (int i = 0; i < str.length(); i++)
    {
        // This is the core logic. It maps a character to an array index.
        // `str[i] - 'a'` uses ASCII arithmetic. For example, if str[i] is 'c',
        // the ASCII value of 'c' minus the ASCII value of 'a' gives 2.
        // This result (2) is used as the index for the character 'c'.
        // We then increment the value at that index to count the character's occurrence.
        count[str[i] - 'a']++;
    }

    // 4. Print the characters and their frequencies.
    // Loop through the frequency array from index 0 to 25.
    for (int i = 0; i < 26; i++)
    {
        // Check if the character corresponding to the current index appeared
        // in the string. If count[i] is greater than 0, it means it did.
        if (count[i] > 0)
        {
            // If the character was found, print it and its frequency.
            // `char(i + 'a')` reverses the mapping. It converts the index
            // back to its corresponding character. For example, if i is 2,
            // char(2 + 'a') results in 'c'.
            cout << char(i + 'a') << " " << count[i] << endl;
        }
    }
    
    return 0; // Indicate successful execution.
}

 
 */
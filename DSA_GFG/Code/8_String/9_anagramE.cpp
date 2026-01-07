// An anagram is a word or phrase formed by rearranging the letters of another word or phrase, using all the original letters exactly once. 
// ex listen , silent
// triangle , integral


#include <iostream>
#include <string>

using namespace std;

// code 1 


bool anagram(const string & s1, const string & s2)
{
    if(s1.length() != s2.length())
        return false;

    int freq_s1[26] = {0};
    int freq_s2[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        freq_s1[s1[i] - 'a']++;
        freq_s2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if(freq_s1[i] != freq_s2[i])
            return false;
        
    }
    return true;
    
    
}


// same code can be optimised for only one temp array
// code 2



bool anagram(const string & s1, const string & s2)
{
    if(s1.length() != s2.length())
        return false;

    int freq[26] = {0};;

    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        freq[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
            return false;
        
    }
    return true;
    
    
}

int main()
{
    string s1 = "listen";
    string s2 = "silent";    

    cout<<anagram(s1,s2);

    return 0;
}

// code 1 time and space

// Time Complexity: O(N)
// Let N be the length of the strings s1 and s2
// Space Complexity: O(1)
// You have allocated two arrays, freq_s1 and freq_s2. Each array has a fixed size of 26.


// code 1 logic

/*

bool anagram(const string & s1, const string & s2)
{
    // A fundamental property of anagrams is that they must have the same length.
    // This is the quickest way to rule out non-anagrams.
    if(s1.length() != s2.length())
        return false;

    // Create two frequency arrays to store the character counts for each string.
    // The size is 26, one for each letter of the English alphabet.
    // Initialize all counts to zero.
    int freq_s1[26] = {0};
    int freq_s2[26] = {0};

    // Iterate through both strings simultaneously to build the frequency maps.
    // This is efficient as it uses a single loop.
    for (int i = 0; i < s1.length(); i++)
    {
        // Calculate the index (0-25) for the character by subtracting the ASCII
        // value of 'a'. For example, 'a' - 'a' = 0, 'b' - 'a' = 1, etc.
        freq_s1[s1[i] - 'a']++;
        freq_s2[s2[i] - 'a']++;
    }

    // Now, compare the two frequency maps.
    // If the strings are anagrams, every character count must be identical.
    for (int i = 0; i < 26; i++)
    {
        // If we find any character with a different count, we can immediately
        // conclude they are not anagrams.
        if(freq_s1[i] != freq_s2[i])
            return false;
    }
    
    // If the loop completes without finding any mismatches, it confirms
    // that both strings have the same character frequencies.
    return true;
}


*/


// code 2  time and space
// same as above


// code 2 logic 

/*




 * @brief Checks if two strings are anagrams using a single frequency array.
 * 
 * This optimized approach first populates a frequency map using the first
 * string and then decrements the counts using the second string. If the
 * strings are anagrams, all character counts in the array will be zero
 * at the end. Assumes input strings are lowercase English letters.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return true if the strings are anagrams, false otherwise.
 
bool anagram(const string & s1, const string & s2)
{
    // First, check if the lengths are different. If so, they cannot be anagrams.
    if(s1.length() != s2.length())
        return false;

    // A single frequency array of size 26 is used to track character counts.
    int freq[26] = {0};

    // First loop: Increment the count for each character in the first string.
    for (int i = 0; i < s1.length(); i++)
    {
        // The index is calculated by subtracting the ASCII value of 'a'.
        freq[s1[i] - 'a']++;
    }
    
    // Second loop: Decrement the count for each character in the second string.
    for (int i = 0; i < s2.length(); i++)
    {
        // If the strings are anagrams, this will exactly cancel out the counts
        // from the first string.
        freq[s2[i] - 'a']--;
    }

    // Final check: If all counts in the frequency array are zero, the strings are anagrams.
    for (int i = 0; i < 26; i++)
    {
        // If any character count is non-zero, it means the frequencies
        // did not match, so they are not anagrams.
        if(freq[i] != 0)
            return false;
    }
    
    // If the loop completes, it means all character counts are zero.
    return true;
}




*/
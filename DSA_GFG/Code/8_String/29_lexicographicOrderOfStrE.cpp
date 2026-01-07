/*
The lexicographic rank of a string is the position of the string in the sorted list of all its permutations (dictionary order).
Example 1
👉 Input: "STRING"
All permutations of "STRING" (there are 6! = 720) arranged in dictionary order.
The rank of "STRING" is 598.
Example 2
👉 Input: "ABC"
All permutations sorted:
ABC
ACB
BAC
BCA
CAB
CBA
Here, "ABC" is 1st, "ACB" is 2nd, "BAC" is 3rd, etc.
*/

#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }

    long long res = 1; 

    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }

    return res;
}


int lexicographicOrderOfString(string str)
{
    int n = str.length();
    const int total_ascii_chars = 256;
    int freq[256] = {0};
    int fact = factorial(n);
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        freq[str[i]]++;
    }

    for (int i = 1; i < total_ascii_chars; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }

    for (int i = 0; i < n-1; i++)
    {
        fact = fact / (n - i); 

        int how_many_chars_smaller = freq[str[i] -1];

        res = res + how_many_chars_smaller * fact  ;

        for (int j = str[i]; j < total_ascii_chars; j++)
        {
            freq[j] -- ;
        }
    }

    return res;
    
}

int main()
{
    string str = "rank";
    cout << "Lexiographic rank is: " << lexicographicOrderOfString(str);
    return 0;
}


// time and space


/*
Time Complexity: O(n)
The time complexity is linear with respect to the length of the string, n. Here's a breakdown of why:

factorial(n): The recursive factorial calculation takes O(n) time.

Frequency Count Loop: for (int i = 0; i < n; i++) runs n times. This is O(n).

Cumulative Frequency Loop: for (int i = 1; i < total_ascii_chars; i++) runs a fixed 255 times, regardless of the input string's length. 
This is a constant time operation, O(1).
Main Calculation Loop: for (int i = 0; i < n-1; i++) runs n-1 times, which is O(n).
Inside this loop, the inner loop for (int j = str[i]; j < total_ascii_chars; j++) runs at most 256 times. Since this is a constant number, 
the work inside the main loop is considered O(1).
Overall: The total time is the sum of these parts: O(n) + O(n) + O(1) + O(n) = O(n). The algorithm's runtime grows linearly as the 
string gets longer.



Space Complexity:

factorial_iterative Space: This function now only uses a few local variables (n, res, i). The memory required for these does not grow 
with the input n. This is O(1) space.
lexicographicOrderOfString Space:
freq: This is a fixed-size array, so it's O(1) space.
fact, res, n, and loop counters: These are all single variables, taking up O(1) space.

*/


// logic


/*


// A standard recursive function to calculate the factorial of a number.
// This is used to determine the number of permutations for the remaining characters.
int factorial(int n)
{
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}


int lexicographicOrderOfString(string str)
{
    int n = str.length();
    const int total_ascii_chars = 256;

    // freq array will store the count of characters. Its size is 256 to handle all possible ASCII values.
    int freq[total_ascii_chars] = {0};

    // Pre-calculate the factorial of the string length. This will be used to determine
    // the number of permutations for the remaining characters at each step.
    int fact = factorial(n);

    // Initialize rank to 1, as lexicographical rank is 1-based.
    int res = 1;

    // Step 1: Populate the frequency array with counts of each character in the string.
    // This provides a quick way to know which characters are present.
    for (int i = 0; i < n; i++)
    {
        freq[str[i]]++;
    }

    // Step 2: Convert the frequency array into a cumulative frequency array.
    // After this, freq[c] will store the number of characters in the string that
    // are less than or equal to character c. This is key for efficient lookups.
    // this will tell how many characters are smaller than current str[i]
    for (int i = 1; i < total_ascii_chars; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }

    // Step 3: Iterate through the string to calculate the rank.
    for (int i = 0; i < n - 1; i++)
    {
        // because we need here (n-1)! for 1st iteration then (n-2)! for next iteration because that much slots are 
        // vacant to fill so that much permutations will be there. 
        // formula : n! / n = (n-1)! ex: 7! / 7 = 6!
        // for length of 4 letter word - for first char there are n-1 positions are vacant to be filled on the right.
        // for second char there are n -2 positions are vacant and (n-2)! we needed there.
        // that is if word is of length 6 then see iteration and its factorial needed. 1st: 5!, 2nd: 4!, 3rd : 3!, 4th : 2! and so on
        fact = fact / (n - i);

        // freq[str[i] - 1] gives the count of characters in the remaining set that are
        // strictly smaller than the current character str[i].
        // consider example rank. here for a is the very first index so if you think [str[i] - 1] will give 0-1 index that is 
        // invalid index then this is wrong. Because we have taken array of ascii char length that is 256. Ascii value of a is 97.
        // and prior to 97 there are all 0 values in array as we initialised. So it is valid index for 'a' and this freq[str[i] - 1] 
        // is freq[96] which is 0 and it is correct that for 'a' we have no small char to the right of it because 'a' is very 1st char.
        int how_many_chars_smaller = freq[str[i] - 1];

        // Add to the result: For each smaller character, there are `fact` possible
        // permutations. We add this count to our total rank.
        // adding 1 because if we are calculating for rank word then if we not add 1 then it will give count of all the permutations
        // that are before word rank and rank is in the very next position to it.
        res = res + how_many_chars_smaller * fact;

        // "Remove" the current character str[i] from future consideration by
        // decrementing the count for it and all subsequent characters in the
        // cumulative frequency array.
        // In cumulative frequency array if we take 'r' char then till 'r' we have added all the counts of its previous char if that 
        // char was present. So if we have calculated r then imagine that 'r' does not exist. So we need to decrement count from
        // r to all the onwards char from 'r' for ex if 'rst' is string and so cumulative array is 1,2,3 and if we are done with 'r' 
        // then r does not exist for char s and char t. So rst is now 0,1,2.
        for (int j = str[i]; j < total_ascii_chars; j++)
        {
            freq[j]--;
        }
    }

    return res;
}




*/


// dry run for rank


/*


We want lexicographic rank of "rank".

Step 0: Initialize

str = "rank"

n = 4

res = 1

mul = fact(4) = 24

count[CHAR] is initialized to 0.

Step 1: Count frequency of each character

Loop over string:

'r' → count['r']++

'a' → count['a']++

'n' → count['n']++

'k' → count['k']++

So count for our letters:

count['a'] = 1
count['k'] = 1
count['n'] = 1
count['r'] = 1


All other count[i] = 0.

Step 2: Cumulative count
for (int i = 1; i < CHAR; i++)
    count[i] += count[i - 1];


count[i] now contains number of characters less than or equal to i

For our letters:

count['a'] = 1
count['k'] = 2  (since 'a'=1)
count['n'] = 3  (since 'k'=2)
count['r'] = 4  (since 'n'=3)

Step 3: Loop through string

We loop i = 0 to n-2 = 2

Iteration 0 (i=0, str[i]='r')

mul = mul / (n-i) = 24 / (4-0) = 6

count[str[i]-1] = count['r'-1] → 'r'-1 = 'q' → count['q'] = 3 (all letters < 'r')

res = res + count['r'-1] * mul = 1 + 3*6 = 19

Update count array:

for (int j = str[i]; j < CHAR; j++)
    count[j]--;


Decrement all counts from 'r' to end by 1. Now count['r'] = 3.

Iteration 1 (i=1, str[i]='a')

mul = mul / (n-i) = 6 / (4-1) = 2

count[str[i]-1] = count['a'-1] = count[''] = 0` (characters < 'a')

res = res + 0*2 = 19 (no change)

Update count array: decrement count['a'] and above by 1. count['a'] = 0.

Iteration 2 (i=2, str[i]='n')

mul = mul / (n-i) = 2 / (4-2) = 1

count[str[i]-1] = count['n'-1] = count['m']

Only letters less than 'n' that are still available are 'k' → count['m'] = 1

res = res + 1*1 = 20

Update count array: decrement count['n'] and above by 1.

Step 4: Return result
return res;


res = 20

✅ So the lexicographic rank of "rank" is 20


*/
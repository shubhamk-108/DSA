// Function to compute the Longest Proper Prefix Suffix (LPS) array.
// This array is a core component of the KMP pattern searching algorithm.

#include <bits/stdc++.h>
using namespace std;

void longProperPrefixSuffix(string str, int lps[])
{
    int n = str.length();

    // length will work as length of current longest prefix-suffix
    int length = 0;

    // i will work as pointer traversing the string
    int i = 1;

    lps[0] = 0;

    while (i < n)
    {
        if (str[length] == str[i])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}



int main()
{
    // string txt = "abacabad";
    string txt = "abcabdabcabdabdab";
    int lps[txt.length()];
    longProperPrefixSuffix(txt, lps);
    for(int i = 0; i< txt.length(); i++)
    {
        cout<<txt[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i< txt.length(); i++)
    {
        cout<<lps[i]<<" ";
    }
    return 0;
}


//time space

// Time Complexity: O(n)
// Space Complexity: O(n)

/*


// logic


#include <string>
#include <vector>

void computeLPSArray(std::string str, int lps[]) {
    int n = str.length();
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;   // Start from the second character

    while (i < n) {
        // Case 1: Characters match
        // The current character extends the existing prefix-suffix match.
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else { // Characters do not match
            if (len != 0) {
                // Case 2: Mismatch after a match
                // Fall back to the LPS value of the previous prefix.
                // We do not increment i here; we re-evaluate str[i] against the new, shorter prefix.
                // if mismatch happens then possibly previous char must be matched. Like abcd and abce we are checking for.
                // see here if mismatch happens at d == e then previous char of d that is c must be matched to string ahead.
                // that is why we come to previous index of len and ask that did you see this char(for which we are currently checking str[i])
                // before you. and that c char says yes, i have seen this before. so we take that lps[len-1] value and take our len pointer to 
                // that index. why we are going back if mismatch happens because if previous char matches here in somewhere backword side then 
                // there is a chance that next char of previous char is exactly same as for which we are currently checking that is str[i].
                // and if it is same then we just add 1 to the whatever value of that length. For example we went backward and len was 3 up to 
                // that point and now our str[i] matches to that char after going back then just add 1 to it. like we were checking for 
                // str[i] = e backward. And after taking our len pointer backward if we found that char as e then there must me abc prior to
                // that e. So abc's value was already written there in lps array till that point and if we wfound this str[i] means e equal 
                // to that char so add one to it.
                // Remember below line is just for taking len pointer to the back where there is possibility of that char appear again.
                // and we are checking whether that char mathces or not in the next while loop iteration in above if block.if (str[i] == str[len])
                len = lps[len - 1];
            } 
            else { // len == 0
                // Case 3: Mismatch with no existing prefix-suffix
                // No prefix matched, so lps[i] is 0.
                // when mismatch happens we were taking our poiter back-back-back but doing so at some point the len pointer will be at 0th
                // index  and lps[0] is always 0. Now this line len = lps[len - 1]; will make that pointer come to index 0. Then in next
                // iteration  if (str[i] == str[len]) this line will check that if the char matches or not. That means if we have managed to 
                // reach in this else block means everything is checked already and nothing matched so we just have to put lps[i] = 0 and 
                // move i pointer by 1 ahead.
                lps[i] = 0;
                i++;
            }
        }
    }
}


*/
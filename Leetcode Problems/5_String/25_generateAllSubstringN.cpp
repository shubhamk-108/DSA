/*

A substring is a continuous sequence of characters taken from a string.
It must be contiguous (characters must be next to each other, without gaps).
Order is preserved.
Every string is a substring of itself.
The empty string is also considered a substring.
s = "abcde"
Substrings of "abcde":
Length 1: "a", "b", "c", "d", "e"
Length 2: "ab", "bc", "cd", "de"
Length 3: "abc", "bcd", "cde"
Length 4: "abcd", "bcde"
Length 5: "abcde"
Total substrings = n * (n + 1) / 2 = 5 * 6 / 2 = 15


*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string>  generateAllSubstring(string s)
    {
        vector<string> allSubstring;

        int n = s.length();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n-i; j++)
            {
                allSubstring.push_back(s.substr(j,i));
            }
            
        }
        return allSubstring;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcde";

    vector<string> ss = sol.generateAllSubstring(s1);
    for(auto x:ss)
        cout<<x<<", ";
    return 0;
}

// timespace

/*

Time Complexity: O(N³)
This is often a point of confusion. While there are two nested loops, which typically suggests O(N²), the operation inside the loop is not 
constant time.
Outer Loop: Iterates N times (for substring lengths 1 to N).
Inner Loop: Iterates roughly N times on average. Together, these two loops result in O(N²) iterations of the inner-most code block.
The substr Operation: This is the crucial part. The function s.substr(j, i) creates a new string by copying i characters from the original string s. 
This copy operation is not free; it takes time proportional to the length of the substring being created, which is i. In the worst case, i can be as 
large as N.
Therefore, the total time is the number of times you call substr multiplied by the average cost of that call.
Number of calls: O(N²)
Average cost of each substr call: The lengths vary from 1 to N, so the average length is proportional to N, making the average cost O(N).
Combining these gives you the total time complexity: **O(N²) * O(N) = O(N³) **.


Space Complexity: O(N³)
The space complexity is determined by the total number of characters you store in the allSubstring vector, as this is what the function returns.
Number of Substrings: As established, a string of length N has N * (N+1) / 2 substrings. This is O(N²) separate string objects.
Size of Stored Substrings: You are not just storing pointers; you are storing the full content of each of these O(N²) substrings. The lengths of 
these substrings range from 1 to N. The total number of characters stored across all these substrings is the sum of their lengths, which calculates 
to (N * (N+1) * (N+2)) / 6.
This formula shows that the total storage grows with the cube of N.
Therefore, the total space complexity is O(N³).

Space complexity

The vector<string> allSubstring stores all substrings.
Number of substrings = O(n²)
Average substring length ≈ O(n/2)
So total storage = O(n³).

Each substring copy takes O(length) .
Total characters across all substrings = O(n^2).
So total substring * thire length (consider O(n)) = O(n^3)
✅ Space Complexity: O(n³)

Example
For "abc" (n=3):
substrings = "a","b","c","ab","bc","abc" (6 substrings = n(n+1)/2)
Storage grows quadratically in count and linearly in length → cubic overall.
✅ Final Answer:
Time Complexity: O(n³)
Space Complexity: O(n³)

*/

// code

/*

for (int i = 1; i <= n; i++) THis loop will be considered for length. Like first all substring of length 1, then lenght 2 and so on.      
for (int j = 0; j <= n-i; j++) This loop is for all possible combinations of length 1 substring. Then all length 2 substring then all 
length 3 substring and so on.
            
allSubstring.push_back(s.substr(j,i));
when i = 2 and j = 0,1,2,3, for string abcde then substrings will be             
 2, 0, = ab
 2, 1 = bc
 2, 2, = cd
 2, 3  = de
 
            
 

*/
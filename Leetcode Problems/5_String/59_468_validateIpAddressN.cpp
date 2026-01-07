/*

Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct
IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and
"192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

1 <= xi.length <= 4
xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
Leading zeros are allowed in xi.
For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses,
while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

Example 1:

Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:

Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:

Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.


*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
private:
    bool checkIpV4(string s)
    {
        int n = s.length();
        int i = 0;
        int dot_count = 0;

        while (i < n)
        {
            if (dot_count == 4)
                return false;

            string dotSepetaedValue = "";

            while (i < n && s[i] != '.')
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
                dotSepetaedValue += s[i];
                i++;
            }

            if (dotSepetaedValue.empty() || dotSepetaedValue.size() > 3)
                return false;

            if (dotSepetaedValue.size() > 1 && dotSepetaedValue[0] == '0')
                return false;

            int num = stoi(dotSepetaedValue);
            if (num < 0 || num > 255)
                return false;

            dot_count++;
            i++;
        }

        return dot_count == 4 && s.back() != '.';
    }

    bool
    checkIpV6(string s)
    {

        int n = s.length();
        int i = 0;
        int colon_count = 0;

        while (i < n)
        {
            if (colon_count == 8)
                return false;

            string colonSeperated = "";

            while (i < n && s[i] != ':')
            {
                if (!isdigit(s[i]) && !(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'))
                    return false;
                colonSeperated += s[i];
                i++;
            }
        
            if (colonSeperated.size() > 4 || colonSeperated.empty())
                return false;

            colon_count++;
            i++;
        }
        return colon_count == 8 && s.back() != ':';
    }

public:
    string validIPAddress(string queryIP)
    {
        if (checkIpV4(queryIP))
            return "IPv4";
        else if (checkIpV6(queryIP))
            return "IPv6";
        else
            return "Neither";
    }
};

int main()
{
    Solution sol;
    string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    cout << sol.validIPAddress(queryIP);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Let n = length of the input string.
Each character is visited once in both checks.
Time Complexity = O(n) ✅
💾 Space Complexity
We store a few strings for segments (max size 4 or 3).
No extra data structure proportional to n.
Space Complexity = O(1) ✅

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

1️⃣ Split and Validate IPv4
Split the string using . as delimiter.
There must be exactly 4 parts.
Each part:
Contains only digits.
Has length 1–3.
Has no leading zero unless it’s "0".
Integer value must be in 0–255 range.
2️⃣ Split and Validate IPv6
Split the string using : as delimiter.
There must be exactly 8 parts.
Each part:
Contains only digits or letters a–f / A–F.
Has length 1–4.
No leading zero rule here.

3️⃣ Final Decision
If IPv4 passes → return "IPv4".
Else if IPv6 passes → return "IPv6".
Else → return "Neither".


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
private:
    bool checkIpV4(string s)
    {
        int n = s.length();
        int i = 0;
        int dot_count = 0;

        while (i < n)
        {
            if (dot_count == 4) // IPv4 must have exactly 4 parts
                return false;

            string dotSeparatedValue = "";

            // Build each part until '.' or end of string
            while (i < n && s[i] != '.')
            {
                if (!isdigit(s[i]))
                    return false;
                dotSeparatedValue += s[i];
                i++;
            }

            // Empty part or part longer than 3 digits → invalid
            if (dotSeparatedValue.empty() || dotSeparatedValue.size() > 3)
                return false;

            // Leading zeros not allowed (except "0" itself)
            if (dotSeparatedValue.size() > 1 && dotSeparatedValue[0] == '0')
                return false;

            // Convert to number and check range
            int num = stoi(dotSeparatedValue);
            if (num < 0 || num > 255)
                return false;

            dot_count++;
            i++; // skip the '.' character
        }

        // ✅ Must have exactly 4 parts.
        // at the start this dot_count == 4 condition is false and here is true. how. because in running loop when the loop is 
        // not finished completely then we can check that does dot_cound exceed that what we need (3). That is why at the start it is false.
        // But when the loop is ending and that is very last cycle of creating  dotSeparatedValue then at the end dot_count will increment to 
        // 4 and that is correct. But it will not get checked because i and at that time n-1 so the loop will end there and the 
        // condition we applied at the top, that will not get checked that iteration was last itetation. 
        // And this is same with IPV6 code.
        return dot_count == 4 && s.back() != '.';
    }

    bool checkIpV6(string s)
    {
        int n = s.length();
        int i = 0;
        int colon_count = 0;

        while (i < n)
        {
            if (colon_count == 8) // IPv6 must have exactly 8 groups
                return false;

            string colonSeparated = "";

            // Build each group until ':' or end
            while (i < n && s[i] != ':')
            {
                // Valid characters: 0-9 or a-f/A-F
                if (!isdigit(s[i]) && !(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'))
                    return false;
                colonSeparated += s[i];
                i++;
            }

            // Each group: 1–4 hex digits
            if (colonSeparated.empty() || colonSeparated.size() > 4)
                return false;

            colon_count++;
            i++; // skip ':'
        }

        // ✅ Must have exactly 8 groups
        return colon_count == 8 && s.back() != ':';
    }

public:
    string validIPAddress(string queryIP)
    {
        if (checkIpV4(queryIP))
            return "IPv4";
        else if (checkIpV6(queryIP))
            return "IPv6";
        else
            return "Neither";
    }
};



*/

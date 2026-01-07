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
#include <sstream>
using namespace std;

class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        if (isIPv4(queryIP))
            return "IPv4";
        if (isIPv6(queryIP))
            return "IPv6";
        return "Neither";
    }

private:
    bool isIPv4(string s)
    {
        stringstream ss(s);
        string token;
        int count = 0;
        while (getline(ss, token, '.'))
        {
            if (++count > 4)
                return false;
            if (token.empty() || token.size() > 3)
                return false;
            if (token[0] == '0' && token.size() > 1)
                return false;
            for (char c : token)
                if (!isdigit(c))
                    return false;
            int num = stoi(token);
            if (num < 0 || num > 255)
                return false;
        }
        return count == 4 && s.back() != '.';
    }

    bool isIPv6(string s)
    {
        stringstream ss(s);
        string token;
        int count = 0;
        while (getline(ss, token, ':'))
        {
            if (++count > 8)
                return false;
            if (token.empty() || token.size() > 4)
                return false;
            for (char c : token)
                if (!isdigit(c) && !(tolower(c) >= 'a' && tolower(c) <= 'f'))
                    return false;
        }
        return count == 8 && s.back() != ':' ;
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

 Both naive and brutefroce are O(n) and O(1) but Naive solution works by manually parsing the string to check the IPv4 and IPv6 formats.
 This efficient solution is  improved for readability, efficiency, and edge-case handling using STL functions such as stringstream,
 regular expressions, or direct splitting with std::getline.

 | Function         | Time Complexity | Space Complexity | Explanation                                                                                                                                                   |
| ---------------- | --------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `isIPv4`         | **O(n)**        | **O(1)**         | Each character in the input string `s` is processed once. Stringstream tokenization is linear. Uses only constant extra memory for small tokens and counters. |
| `isIPv6`         | **O(n)**        | **O(1)**         | Same reasoning as IPv4 — linear scan, constant auxiliary space.                                                                                               |
| `validIPAddress` | **O(n)**        | **O(1)**         | Calls either IPv4 or IPv6 validation once. Total complexity remains linear.                                                                                   |



*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Check format type:
If the string contains '.', try validating as IPv4.
If it contains ':', try validating as IPv6.
Otherwise, return "Neither"

IPv4 validation:
Split the string by '.' → must have exactly 4 parts.
Each part must
Be non-empty and ≤ 3 digits.
Contain only digits.
Have no leading zero unless the number is 0.
Represent a value in [0, 255].

IPv6 validation:
Split the string by ':' → must have exactly 8 parts.
Each part must:
Be non-empty and ≤ 4 characters.
Contain only hexadecimal digits (0-9, a-f, A-F).

Return:
"IPv4" if valid IPv4,
"IPv6" if valid IPv6,
"Neither" otherwise.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Main function to validate the given IP address string.
    // Returns "IPv4" if it's a valid IPv4 address,
    // "IPv6" if it's a valid IPv6 address, and "Neither" otherwise.
    string validIPAddress(string queryIP)
    {
        if (isIPv4(queryIP))
            return "IPv4";
        if (isIPv6(queryIP))
            return "IPv6";
        return "Neither";
    }

private:
    // ------------------------------
    // Helper function to check IPv4 validity
    // ------------------------------
    bool isIPv4(string s)
    {
        stringstream ss(s); // Split the string using '.' as a delimiter
        string token;
        int count = 0;

        while (getline(ss, token, '.'))
        {
            if (++count > 4) // More than 4 segments -> invalid
                return false;

            // Segment must not be empty and must have at most 3 digits
            if (token.empty() || token.size() > 3)
                return false;

            // Leading zeros are not allowed (e.g., "01", "001")
            if (token[0] == '0' && token.size() > 1)
                return false;

            // Check if all characters are digits
            for (char c : token)
                if (!isdigit(c))
                    return false;

            // Convert to integer and validate range [0, 255]
            int num = stoi(token);
            if (num < 0 || num > 255)
                return false;
        }

        // Valid IPv4 should have exactly 4 parts and not end with a '.'
        return count == 4 && s.back() != '.';
    }

    // ------------------------------
    // Helper function to check IPv6 validity
    // ------------------------------
    bool isIPv6(string s)
    {
        stringstream ss(s); // Split the string using ':' as a delimiter
        string token;
        int count = 0;

        while (getline(ss, token, ':'))
        {
            if (++count > 8) // IPv6 has exactly 8 segments
                return false;

            // Each segment must have 1 to 4 hex digits
            if (token.empty() || token.size() > 4)
                return false;

            // Check that each character is a valid hexadecimal digit [0-9a-fA-F]
            for (char c : token)
                if (!isdigit(c) && !(tolower(c) >= 'a' && tolower(c) <= 'f'))
                    return false;
        }

        // Valid IPv6 should have exactly 8 parts and not end with a ':'
        return count == 8 && s.back() != ':';
    }
};


*/

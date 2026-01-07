#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        int n1 = s.length();
        int n2 = t.length();

        if (n1 != n2)
            return false;

        unordered_map<char, char> um;
        unordered_set<char> us;

        for (int i = 0; i < n1; i++)
        {
            if (um.find(s[i]) != um.end())
            {
                char value = um[s[i]];
                if (t[i] != value)
                    return false;
            }
            else
            {
                if (us.find(t[i]) == us.end())
                {
                    um[s[i]] = t[i];
                    us.insert(t[i]);
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s1 = "egg";

    string s2 = "add";

    cout << sol.isIsomorphic(s1, s2);
    return 0;
}

// ___________________________________________________________
// timespace
// ___________________________________________________________

/*
Time Complexity: O(N)
You iterate through the strings exactly once.
Inside the loop, all operations on the unordered_map and unordered_set (find, insert, []) take, on average, constant time, or O(1).

Space Complexity: O(k)
The unordered_map will store at most k key-value pairs.
The unordered_set will store at most k unique characters

*/


// ___________________________________________________________
// code
// ___________________________________________________________

/*

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();

        // If lengths differ, they can't be isomorphic
        if (n1 != n2)
            return false;

        unordered_map<char, char> um; // stores mapping from s[i] -> t[i]
        unordered_set<char> us;       // stores which characters from 't' are already used

        for (int i = 0; i < n1; i++)
        {
            // Case 1: s[i] already mapped before
            if (um.find(s[i]) != um.end())
            {
                char value = um[s[i]]; // get mapped value. we see to what value it has already mapped.
                if (t[i] != value)     // if current mapping doesn't match, not isomorphic
                    return false;
            }
            else
            {
                // Case 2: s[i] not mapped yet.
                // now this is new character and it is not mapped. now we will map it but before mapping we see that 
                // the char we are going to map, whether or not it is already mapped to some other key.
                If it is already mapped then we can not map two same values to two different keys. so we return false in else part of it.
                // Check if t[i] is already mapped by some other character
                if (us.find(t[i]) == us.end()) // we dont find that before
                {
                    // Safe to create a new mapping s[i] -> t[i]
                    um[s[i]] = t[i];

                    // after we map it, we have to put this in set so that we can check for further chars that wherther or not is is 
                    // mapped to something else.
                    us.insert(t[i]);
                }
                else
                {
                    // t[i] already used by another s[j], so invalid
                    return false;
                }
            }
        }
        // If no conflicts found, strings are isomorphic
        return true;
    }
};


*/

// ___________________________________________________________
// my earlier wrong code: this is improtant. please look.
// ___________________________________________________________

/*


unordered_map<char, char>um;

        for (int i = 0; i < n1; i++)
        {
            if(um.find(s[i]) != um.end() )
            {
                char value = um[s[i]];
                if(t[i] != value)
                    return false;
            }
            else
            {
                if(um.find(t[i]) == um.end())
                    um[s[i]] = t[i];
                else
                    return false;
            }
        }
        return true;

Here the thought process was correct in this line if(um.find(t[i]) == um.end()) that if we have a new character then before putting that in map
we have to ensure that its key is not used before. SO i was seraching for key that whether or not it is used before. So i used
if(um.find(t[i]) == um.end()). My intention was finding key, but the thing is you can not find keys in map using um.find() function
unless you explicitely use loos and do something like for (auto &p : um) {if (p.second == targetValue). ok. we can not do this loop here.
So the new approach was using set here and putting all keys in the set as well after we put our newly found char in the map with its key.
*/
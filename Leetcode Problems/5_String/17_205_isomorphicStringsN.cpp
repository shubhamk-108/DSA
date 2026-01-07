/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map
to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

*/

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

        for (int i = 0; i < n1; i++)
        {
            char value = s[i];
            char itsMapping = t[i];

            for (int j = i + 1; j < n2; j++)
            {
                if(s[j] == value)
                {
                    if(t[j] != itsMapping)
                        return false;
                }
                if(t[j] == itsMapping)
                {
                    if(s[j] != value)
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s1 = "title";

    string s2 = "paper";

    cout << sol.isIsomorphic(s1, s2);
    return 0;
}

// ___________________________________________________________
// timespace
// ___________________________________________________________

/*
Time Complexity: O(N²)

The nested loops mean that for N elements, you are performing roughly N*N checks, which is quadratic time.

Space Complexity: O(1)

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

        if (n1 != n2)
            return false;

        // For every character s[i]...
        for (int i = 0; i < n1; i++)
        {
            char value = s[i]; // this is current character
            char itsMapping = t[i]; // amd this is its mapping

            // aata aapan jithe aahe tithun pudhachya element madhe khalil goshti baghayachya ahe.
            for (int j = i + 1; j < n2; j++)
            {
               // aapan check karto ki jo current char aahe jyachi mapping aapan magashi keli. toch char ithun pudhe parat aalela aahe
            //    ka nahi he check karayach. Ani jr to char pudhe pn aalela asel tr tya pudhachya char chi mapping pn aapan saglya varti
            // top la aadhi ji mapping keli aahe tich asli pahije. Jr nasel tr false return kr.
            // s[j] mhanje ithe traverse kelelya value astil. == value mhanje check krto ki vari mapping keleli value aazun parat pudhe  pn aahe ka.
                if(s[j] == value)
                {
                    // t[j] mhanje jr ti value prt pudhe bhetli tr tithe tyachi mapped zaleli value. Aata ti map zaleli value hi same pahikje aapan
                    // saglyat top la ji map keleli value aahe ti. khali example cum dry run madhe bagh. clear houn jail.
                    if(t[j] != itsMapping)
                        return false;
                }

                // varti je kel tech ithe pn karayach . varti aapn baghital key parat repeat hotey ka ani mhanun tyachi mapping check keli.
                // ithe aapn baghu mapping prt repeat hotiy ka. ani jr hot asel tr tyachi value hi same pahije aadhi saglyat top la ji mapping
                // zali aahe tya sobat. please example cum dry run bagh khali clear hoil.
                // yacha aarth aahe ki aapan jya goshti la map kel, ti gosht parat pudhe pn aaleli aahe ka. Ani jr aaleli asel tr jyachya
                // sobat map zaleli aahe hi value hi same aahe ka varachya value sobat
                if(t[j] == itsMapping)
                {
                    // ...but s[j] is DIFFERENT from our original s[i], it's a violation.
                    if(s[j] != value)
                        return false;
                }
            }
        }
        
        // If no violations are found after checking all pairs, the strings are isomorphic.
        return true;
    }
};



*/


// ___________________________________________
// example cum dry run. In short
// ___________________________________________

/*
string s = "paper";
string t = "title"

consider karayach ki p chi mapping t sobat hoil. Tr aapan check kr p pasun pudhachya chars madhe ki pudhe pn parat p aalela aahe ka.
ani pr p pudhe pn aalela asel tr tyachi pn mapped zaleli value hi t ch pahije. Jr as nasel tr false return kara.

then aata t string madhe bagh
jo title cha t aahe to p la map kela. pn aata t pasun pudhe saglya char madhe check kara ki t ha parat pudhe pn aalela aahe ka. 
aani jr to aalela asel tr check kara ki tyachi value hi same aahe ka ji value hi pahilya t la match karatana hoti. mhanje check kara
ki tya t chi value mhanje reverse mapping hi pn p ch aahe ka. Jr nasel tr return false
*/
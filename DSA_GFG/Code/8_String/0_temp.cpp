#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{

    // reverse the whole string
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    for (int l = 0; l < n; ++l)
    {
        if (s[l] != '.')
        {

            // go to the beginning of the word
            if (i != 0)
                s[i++] = '.';

            // go to the end of the word
            int r = l;
            while (r < n && s[r] != '.')
                s[i++] = s[r++];

            // reverse the word
            reverse(s.begin() + i - (r - l), s.begin() + i);

            // move to the next word
            l = r;
        }
    }
    s.erase(s.begin() + i, s.end());
    return s;
}

int main()
{
    string s = "..geeks..for.geeks.";
    cout << reverseWords(s) << endl;
    return 0;
}
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};

int main()
{
    Solution sol;
    vector<char> str = {'H', 'E', 'L', 'L', 'O'};
    sol.reverseString(str);

    for (char c : str)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}


// time and space

/*
Time Complexity

reverse(s.begin(), s.end()) internally swaps elements from both ends.
Each element is swapped once → O(n/2) operations.
That simplifies to O(n), where n = number of characters in s.
Space Complexity

reverse works in-place (it just swaps elements inside the same vector).
No extra data structures are created.
So O(1) auxiliary space.
*/
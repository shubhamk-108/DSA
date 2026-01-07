/*

std::next_permutation is a built-in function in C++ from the <algorithm> header.
next_permutation(begin, end) rearranges the elements in the given range into the next lexicographically greater permutation.
If the current sequence is already the largest possible permutation, it rearranges it into the smallest one (sorted ascending order) and returns false.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abc";
    sort(s.begin(), s.end());  // make sure it starts from smallest order

    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}

Output:

abc
acb
bac
bca
cab
cba

So it automatically cycles through all permutations in sorted order — no need to write your own permutation generator.

When you call:
next_permutation(s1.begin(), s1.end());
it modifies s1 in place — it rearranges the string to form the next permutation (in lexicographic order).
When there are no more permutations left,
next_permutation() returns false.
That’s why we write the loop as:

do {
    // use s1 here
} while (next_permutation(s1.begin(), s1.end()));


Here’s what happens:
The first iteration runs with the initial s1.
The loop continues while a new permutation exists.
When all permutations are exhausted, next_permutation() returns false, and the loop exits.
*/


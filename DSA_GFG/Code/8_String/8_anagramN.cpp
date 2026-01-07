// An anagram is a word or phrase formed by rearranging the letters of another word or phrase, using all the original letters exactly once. 
// ex listen , silent
// triangle , integral


#include <iostream>
#include <string>
#include<algorithm>

using namespace std;


bool anagram( string & s1, string & s2)
{
    if(s1.length() != s2.length())
        return false;

    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1==s2;
    
    
}


int main()
{
    string s1 = "listen";
    string s2 = "silent";    

    cout<<anagram(s1,s2);

    return 0;
}


// time and space

/*

Sorting: The std::sort function in C++ is highly optimized. For general-purpose sorting, it's typically an introsort (a hybrid of 
quicksort, heapsort, and insertion sort). Its average and worst-case time complexity is O(N log N),
Total Time = O(N log N) + O(N log N) + O(N) = O(N log N).
That extra O(N) comes from the final comparison step in your code:
return s1 == s2;
To check if two strings are equal, the computer must, in the worst case, compare them character by character from beginning to end.



space:

Space Complexity: O(log N) or O(N)
The space complexity of std::sort can be a bit nuanced.
Introsort: The quicksort part of introsort requires a recursion stack. The depth of this stack is typically O(log N) on average. If it degrades, 
it switches to heapsort, which can be done in-place (O(1) extra space).
Merge Sort: Some std::sort implementations might use merge sort for certain data types, which would require O(N) auxiliary space.
*/


// Extra info

/*
The three algorithms it uses are:

Quicksort

Heapsort

Insertion Sort

How Introsort Works
Introsort starts with Quicksort because it is extremely fast on average. However, it also "introspects" or monitors its own performance to 
avoid Quicksort's major weakness: a terrible O(N²) worst-case performance, which can happen with poorly chosen pivots.
Here is the strategy it follows:
Start with Quicksort: The algorithm begins by partitioning the data using Quicksort, as it's typically the fastest.
Switch to Heapsort (The "Safety Net"): It keeps track of the recursion depth. If the recursion gets too deep (a sign that Quicksort might be
 heading towards its O(N²) worst case), Introsort immediately switches to Heapsort. Heapsort guarantees an O(N log N) worst-case time complexity, 
 acting as a safety net to prevent a performance disaster.
Switch to Insertion Sort (The "Finisher"): When the partition size becomes very small (typically around 16 elements), the algorithm switches 
to Insertion Sort. While Insertion Sort is slow for large arrays (O(N²)), it is extremely fast for small, nearly-sorted arrays and has very
little overhead, making it more efficient than Quicksort or Heapsort in these tiny cases.

*/
/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.
string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.


Example:

Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]

Explanation:
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BrowserHistory
{
private:
    vector<string> history;
    int current;

public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        current = 0;
    }

    void visit(string url)
    {
        history.erase(history.begin() + current + 1, history.end());
        history.push_back(url);
        current++;
    }

    string back(int steps)
    {
        current = max(0, current - steps);
        return history[current];
    }

    string forward(int steps)
    {
        current = min((int)history.size() - 1, current + steps);
        return history[current];
    }
};

//___________________________________________________________________________________________________________________________________________
// why typecasting here current = min((int)history.size() - 1, current + steps);
//___________________________________________________________________________________________________________________________________________
/*
history.size() does NOT return int.
It returns:
size_t
And size_t is:
Unsigned
Usually 64-bit on modern systems

🔹 The Problem Without Cast
Look at this:
min(history.size() - 1, current + steps);
Now types are:
history.size() - 1 → unsigned (size_t)
current + steps → signed int
std::min() requires both arguments to be same type.
Since one is unsigned and one is signed,
compiler gets confused.
You may see error like:
no matching function for call to ‘min(size_t, int)’


Question:
but when we were solving array sometimes ago, then i have used vec.size() without int with no issues

Answer:
You're absolutely right — sometimes you use vec.size() without casting and it works fine.

So why did we need cast here?

Let’s break it clearly.

🔹 Key Rule
vector.size() returns:
size_t   // unsigned
Problems only happen when you mix:
size_t (unsigned)
int (signed)

🔹 Case 1: When It Works Without Cast ✅
Example:
for (int i = 0; i < vec.size(); i++)
Why no issue?
Because:
i is int
vec.size() is size_t
In comparison (i < vec.size()), C++ silently converts i to size_t.
Compiler allows it.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Complexity
visit
Worst case: O(n) (due to erase)
back
O(1)
forward
O(1)
Space
O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We maintain:
history → stores visited URLs
current → index of current page
Operations:
visit(url)
Remove all elements after current
Push new URL
Move current forward
back(steps)
Move current = max(0, current - steps)
Return history[current]
forward(steps)
Move current = min(size-1, current + steps)
Return history[current]

Browser behavior is linear.
We only need:
Move backward → decrease index
Move forward → increase index
Visit new page → erase forward history + push new page

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class BrowserHistory
{
private:
    // Stores all visited URLs in order
    vector<string> history;

    // Index of the current page in history
    int current;

public:
    // Constructor initializes browser with homepage
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);  // Add homepage to history
        current = 0;                  // We start at index 0
    }

    // Visit a new URL
    void visit(string url)
    {
        // Remove all forward history after current page
        // (because visiting new page clears forward stack)
        history.erase(history.begin() + current + 1, history.end());

        // Add new URL to history
        history.push_back(url);

        // Move current pointer to newly added page
        current++;
    }

    // Move back by at most 'steps'
    string back(int steps)
    {
        // Ensure we don't go below index 0
        current = max(0, current - steps);

        // Return the current page
        return history[current];
    }

    // Move forward by at most 'steps'
    string forward(int steps)
    {
        // Ensure we don't go beyond last index
        current = min((int)history.size() - 1, current + steps);

        // Return the current page
        return history[current];
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Simulation
Dynamic Array + Index Tracking



*/

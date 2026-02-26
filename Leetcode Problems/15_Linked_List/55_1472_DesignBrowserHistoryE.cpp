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
using namespace std;

class BrowserHistory
{
private:
    struct ListNode
    {
        string val;
        ListNode *next;
        ListNode *prev;
        ListNode(string x) : val(x), next(nullptr), prev(nullptr) {}
    };

public:
    ListNode *head;
    ListNode *current;

    BrowserHistory(string homepage)
    {
        head = new ListNode(homepage);
        current = head;
    }

    void visit(string url)
    {
        ListNode *temp = current->next;
        while (temp)
        {
            ListNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        current->next = nullptr;

        ListNode *newNode = new ListNode(url);
        current->next = newNode;
        newNode->prev = current;
        current=newNode;
    }

    string back(int steps)
    {
        ListNode *temp = current;
        while (steps > 0 && temp->prev)
        {
            temp = temp->prev;
            steps--;
        }
        current = temp;
        return temp->val;
    }

    string forward(int steps)
    {
        ListNode *temp = current;
        while (steps > 0 && temp->next)
        {
            temp = temp->next;
            steps--;
        }
        current = temp;
        return temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Worst case: O(n)
(If we delete many forward nodes)
back
O(steps)
forward
O(steps)

Space
O(n)
We store every visited page.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We use a Doubly Linked List to simulate browser navigation.
We maintain:
A pointer current → the page we are currently on.
Operations:
visit(url)
Delete all forward history (nodes after current).
Create new node.
Connect it to current.
Move current to new node.
back(steps)
Move current = current->prev while possible and steps > 0.
Return current page.
forward(steps)
Move current = current->next while possible and steps > 0.
Return current page.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class BrowserHistory
{
private:
    struct ListNode
    {
        string val;
        ListNode *next;
        ListNode *prev;

        ListNode(string x) : val(x), next(nullptr), prev(nullptr) {}
    };

public:
    ListNode *head;     // Not really needed
    ListNode *current;  // Pointer to current page

    BrowserHistory(string homepage)
    {
        head = new ListNode(homepage);
        current = head;
    }

    void visit(string url)
    {
        // Delete all forward history
        ListNode *temp = current->next;
        while (temp)
        {
            ListNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        current->next = nullptr;  // Disconnect forward chain
        
        // Create new node
        ListNode *newNode = new ListNode(url);
        newNode->prev = current;
        current->next = newNode;

        current = newNode;   // Move current forward
    }

    string back(int steps)
    {
        while (steps > 0 && current->prev)
        {
            current = current->prev;
            steps--;
        }
        return current->val;
    }

    string forward(int steps)
    {
        while (steps > 0 && current->next)
        {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



This problem uses:
🔹 Doubly Linked List

🔹 Design Data Structure
🔹 Maintain Current Pointer
🔹 Delete Forward Branch
This is a classic state navigation simulation problem.
*/

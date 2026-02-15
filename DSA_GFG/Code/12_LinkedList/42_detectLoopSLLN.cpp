#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node *head)
{
    unordered_set<Node *> us;
    while (head != NULL)
    {
        if (us.find(head) != us.end())
            return true;

        us.insert(head);
        head = head->next;
    }
    return false;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

⏱ Time Complexity
O(n)
Each node is visited once (average case).

📦 Space Complexity
O(n)
Extra space for the hash set.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the linked list from the head.
Store addresses of visited nodes in a hash set.
Before visiting a node:
Check if it already exists in the set.
If yes → loop detected.
If traversal reaches NULL → no loop.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

bool detectLoop(Node *head)
{
    unordered_set<Node *> us;

    while (head != NULL)
    {
        // If node already visited → loop exists
        if (us.find(head) != us.end())
            return true;

        us.insert(head);        // mark node as visited
        head = head->next;      // move forward
    }
    return false;               // reached NULL → no loop
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Hashing / Visited Set Pattern
*/

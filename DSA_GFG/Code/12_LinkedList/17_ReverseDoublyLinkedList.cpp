#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *reverseList(Node *head)
{

    Node *curr = head;
    if (head == NULL || head->next == NULL)
        return head;

    Node *nextNode = NULL;
    Node *prevNode = NULL;
    Node *possibleHead = NULL;

    while (curr != NULL)
    {
        possibleHead = curr;
        nextNode = curr->next;
        prevNode = curr->prev;

        curr->next = prevNode;
        curr->prev = nextNode;

        curr = nextNode;
    }
    return possibleHead;
}
int main()
{
    Node *head = new Node(10);

    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    printList(head);
    head = reverseList(head);
    printList(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time & Space Complexity
⏱ Time Complexity
O(n) where n is number of nodes

🧠 Space Complexity
O(1) (in-place reversal)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Reverse a doubly linked list in-place.
Key observations
Each node has two pointers: next and prev
Reversing the list means:
next should point to the previous node
prev should point to the next node
Strategy
Traverse the list from head to tail.
For every node:
Save the original next node (so traversal is not lost).
Swap next and prev pointers.
Keep track of the last processed node — this becomes the new head.
Return the new head after traversal ends


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node *reverseList(Node *head)
{
    // Start traversal from the head
    Node *curr = head;

    // Edge cases: empty list or single node
    if (head == NULL || head->next == NULL)
        return head;

    Node *nextNode = NULL;     // stores original next node
    Node *prevNode = NULL;     // stores original previous node (not strictly needed)
    Node *possibleHead = NULL; // will become new head after reversal

    // Traverse the list
    while (curr != NULL)
    {
        // Keep updating possibleHead to the current node
        // The last node processed will be the new head
        possibleHead = curr;

        // Save original links
        nextNode = curr->next;
        prevNode = curr->prev;

        // Swap next and prev pointers
        curr->next = curr->prev;
        curr->prev = nextNode;

        // Move to the next node in original list
        curr = nextNode;
    }

    // possibleHead now points to the new head
    return possibleHead;
}

// Note:
// prevNode is stored for understanding, but not required for logic.
// Keeping it is perfectly fine for learning.

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
In-place pointer reversal pattern


*/

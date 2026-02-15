#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int findMiddlle(Node *head)
{
    if (head == NULL)
        return -1;
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}

// for 2 middle in even case print 2nd middle
// For even number of nodes, return the first middle. The while condition will change.
// while (fast->next != NULL && fast->next->next != NULL)

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printlist(head);
    cout << "Middle of Linked List: ";
    cout << findMiddlle(head);
    return 0;
}





//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Single traversal of list
👉 O(n)

💾 Space Complexity
Only two pointers used
👉 O(1)
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

Initialize two pointers
slow and fast both start at head.
Move pointers at different speeds
slow moves one node at a time
fast moves two nodes at a time

Stopping condition
When fast reaches the end of the list (or becomes NULL),
slow will be at the middle node.

Why this works
Since fast moves twice as fast as slow,
when fast has traversed the entire list,
slow has traversed half of it.

Result
slow points to the middle node
Return slow->data


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

int findMiddlle(Node *head)
{
    // If the linked list is empty, no middle exists
    if (head == NULL)
        return -1;

    // Slow pointer moves one step at a time
    Node *slow = head;

    // Fast pointer moves two steps at a time
    Node *fast = head;

    // Traverse the list until fast reaches the end
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // move slow by 1 node
        fast = fast->next->next;    // move fast by 2 nodes
    }

    // When loop ends, slow points to the middle node
    return slow->data;
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

Two Pointer Technique
Also called Tortoise and Hare Algorithm


*/


#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int x)
    {
        data = x;
        next = NULL;
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

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Each node is visited exactly once
n = number of nodes in the linked list

4️⃣ Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We reverse a singly linked list iteratively by changing the direction of links.
Idea:
Traverse the list once
For every node, reverse its next pointer so it points to the previous node instead of the next one
Move forward until the list ends
The last processed node becomes the new head
To do this safely, we maintain three pointers:
curr → current node being processed
prevNode → previous node (already reversed part)
nextNode → temporarily stores next node (so it’s not lost)


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node *reverseList(Node *head)
{
    // curr will traverse the list starting from head
    Node *curr = head;

    // Base case: if there is only one node, no reversal needed
    if (curr->next == NULL)
        return head;

    // prevNode will point to the previous node (initially NULL)
    Node *prevNode = NULL;

    // nextNode is used to store the next node before breaking the link
    Node *nextNode = NULL;

    // Traverse the entire linked list
    while (curr != NULL)
    {
        // Store the next node
        nextNode = curr->next;

        // Reverse the current node's link
        curr->next = prevNode;

        // Move prevNode one step forward
        prevNode = curr;

        // Move curr one step forward
        curr = nextNode;
    }

    // prevNode will be the new head of the reversed list
    return prevNode;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

This problem uses the Iterative Pointer Manipulation Pattern, specifically:
🔹 Three-Pointer Technique
prev
curr
next


*/

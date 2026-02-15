#include <bits/stdc++.h>
using namespace std;

// A node of the singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *segregateEvenOdd(Node *head)
{
    if (head == nullptr)
        return head;

    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = nullptr;

        if (curr->data % 2 == 0)
        {
            if (evenStart == nullptr)
            {
                evenStart = curr;
                evenEnd = curr;
            }
            else
            {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        }
        else
        {
            if (oddStart == NULL)
            {
                oddStart = curr;
                oddEnd = curr;
            }
            else
            {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = nextNode;
    }

    if (evenStart == nullptr)
        return oddStart;
    else if (oddStart == nullptr)
        return evenStart;
    else
    {
        evenEnd->next = oddStart;
        oddEnd->next = nullptr;
        return evenStart;
    }
}

// Function to print nodes in a
// given linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    // Let us create a sample linked list as following
    // 0->1->4->6->9->10->11
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(11);

    cout << "Original Linked list: ";
    printList(head);

    head = segregateEvenOdd(head);

    cout << "\nModified Linked list: ";
    printList(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n
Each node is processed exactly once.

📦 Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the original linked list once.
Detach each node and place it into:
an even list (nodes with even data)
an odd list (nodes with odd data)
Preserve the relative order of even and odd nodes (stable segregation).
After traversal:
If only one list exists, return it.
Otherwise, append the odd list after the even list.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node* segregateEvenOdd(Node* head)
{
    // Edge case: empty list
    if (head == nullptr)
        return head;

    // Pointers for even and odd sublists
    Node *evenStart = NULL, *evenEnd = NULL;
    Node *oddStart = NULL, *oddEnd = NULL;

    Node *curr = head;

    // Traverse the list once
    while (curr != nullptr)
    {
        Node *nextNode = curr->next; // Save next node
        curr->next = nullptr;        // Detach current node

        // Place node in even or odd list
        if (curr->data % 2 == 0)
        {
            if (evenStart == nullptr)
                evenStart = evenEnd = curr;
            else
            {
                evenEnd->next = curr;
                evenEnd = curr;
            }
        }
        else
        {
            if (oddStart == nullptr)
                oddStart = oddEnd = curr;
            else
            {
                oddEnd->next = curr;
                oddEnd = curr;
            }
        }
        curr = nextNode;
    }

    // If no even nodes, return odd list
    if (evenStart == nullptr)
        return oddStart;

    // If no odd nodes, return even list
    else if (oddStart == nullptr)
        return evenStart;

    // Attach odd list after even list
    else
    {
        evenEnd->next = oddStart;
        oddEnd->next = nullptr;  // safety termination
        return evenStart;
    }
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-List Partitioning
Stable Segregation


*/

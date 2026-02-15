#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printCll(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;

    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;

    else if (head->next == head)
    {
        delete (head);
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;

        Node *newHead = curr->next->next;
        curr->next = newHead;
        delete (head);
        return newHead;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    printCll(head);
    head = deleteHead(head);
    printCll(head);

    return 0;
}


// Approach

// Handle empty list
// If head == NULL, nothing to delete → return NULL
// Handle single-node list
// If head->next == head, delete the node and return NULL
// For multiple nodes
// Traverse to the last node (node whose next points to head)
// Store the node after head as newHead
// Make last node point to newHead
// Delete the old head
// Return newHead as the updated head

// Time Complexity
// O(n)
// (Traversal to the last node)
// 📦 Space Complexity
// O(1)
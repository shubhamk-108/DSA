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

    vector<int> even;
    vector<int> odd;
    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->data % 2 == 0)
            even.push_back(curr->data);
        else
            odd.push_back(curr->data);

        curr = curr->next;
    }

    curr = head;

    for (int x : even)
    {
        curr->data = x;
        curr = curr->next;
    }

    for (int x : odd)
    {
        curr->data = x;
        curr = curr->next;
    }
    return head;
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
O(n)
Two traversals of the linked list.

📦 Space Complexity
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the linked list and separate values into two arrays:
one for even values
one for odd values
Traverse the list again:
first overwrite nodes with even values
then overwrite nodes with odd values
Node structure remains the same; only data is rearranged


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

    // Arrays to store values
    vector<int> even;
    vector<int> odd;

    Node* curr = head;

    // First traversal: collect data
    while (curr != nullptr)
    {
        if (curr->data % 2 == 0)
            even.push_back(curr->data);
        else
            odd.push_back(curr->data);

        curr = curr->next;
    }

    // Second traversal: overwrite data
    curr = head;

    for (int x : even)
    {
        curr->data = x;
        curr = curr->next;
    }

    for (int x : odd)
    {
        curr->data = x;
        curr = curr->next;
    }

    return head;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

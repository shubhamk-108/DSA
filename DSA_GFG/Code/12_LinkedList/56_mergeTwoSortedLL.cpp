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

Node *sortedMerge(Node *a, Node *b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;
    Node *head = nullptr;
    Node *tail = nullptr;

    if (a->data <= b->data)
    {
        head = a;
        tail = a;
        a = a->next;
    }
    else
    {
        head = b;
        tail = b;
        b = b->next;
    }

    while (a != nullptr && b != nullptr)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == nullptr)
        tail->next = b;
    else
        tail->next = a;
    return head;
}

int main()
{
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    Node *b = new Node(5);
    b->next = new Node(35);
    printlist(sortedMerge(a, b));
    return 0;
}



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n + m)
n = length of list a
m = length of list b
Each node is visited exactly once

🧠 Space Complexity
O(1) auxiliary space

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Goal
Merge two already sorted linked lists a and b into one sorted linked list without creating new nodes.
High-level idea:
Decide the first node (head) of the merged list by comparing a->data and b->data
Maintain a tail pointer that always points to the last node of the merged list
Repeatedly:
Compare current nodes of a and b
Attach the smaller node to tail
Move forward in the list from which the node was taken
When one list becomes empty, attach the remaining part of the other list
This is exactly how merge step of merge sort works

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

Node *sortedMerge(Node *a, Node *b)
{
    // If one list is empty, return the other
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    Node *head = nullptr; // Head of merged list
    Node *tail = nullptr; // Tail of merged list

    // Initialize head and tail
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    // Merge while both lists have nodes
    while (a != nullptr && b != nullptr)
    {
        if (a->data <= b->data)
        {
            tail->next = a; // attach smaller node
            tail = a;       // move tail
            a = a->next;    // move list a
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    // Attach remaining nodes
    if (a == nullptr)
        tail->next = b;
    else
        tail->next = a;

    return head;
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/


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
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr!= head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    printCll(head);

    return 0;
}

// Time: O(n)
// Space: O(1)

// approach
/*
Approach (short and clear):
Handle empty list
If head == NULL, nothing to print → return
Start from head
Use a pointer curr = head
Use do–while loop
Print the current node first
Move to curr->next
Continue until you reach head again
Stop when cycle completes
Condition curr != head ensures each node is printed exactly once
👉 A do–while loop is used because, in a Circular Linked List, the head must be printed before checking the stopping condition.

*/
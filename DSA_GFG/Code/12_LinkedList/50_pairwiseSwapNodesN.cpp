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

void pairwiseSwap(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    pairwiseSwap(head);
    printlist(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:

O(n)

4️⃣ Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Problem:
Pairwise swap elements of a singly linked list.

Example:

Input :  10 → 20 → 30 → 40 → 50
Output:  20 → 10 → 40 → 30 → 50

Idea:
Traverse the linked list two nodes at a time.
Swap the data of the current node with the next node.
Move the pointer ahead by two nodes.
Stop when fewer than two nodes remain.
This avoids pointer manipulation and keeps the logic simple.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


void pairwiseSwap(Node *head)
{
    // Start from the head of the linked list
    Node *curr = head;

    // Traverse while at least two nodes are available
    while (curr != NULL && curr->next != NULL)
    {
        // Swap data of current node and next node
        swap(curr->data, curr->next->data);

        // Move pointer two nodes ahead
        curr = curr->next->next;
    }
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

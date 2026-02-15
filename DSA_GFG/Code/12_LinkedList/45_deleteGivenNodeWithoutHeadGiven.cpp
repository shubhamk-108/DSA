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

// this code is not for deleting the last node
void deleteNode(Node *ptr)
{
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete(temp);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    Node *ptr = new Node(30);
    head->next->next = ptr;
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(25);
    printlist(head);
    deleteNode(ptr);
    printlist(head);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(1)
No traversal required.

📦 Space Complexity
O(1)
No extra memory used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Since we do not have access to the head, we cannot traverse the list or update the previous node.
So instead of deleting the given node directly, we:
Copy the data of the next node into the current node.
Bypass the next node by changing pointers.
Delete the next node.

⚠️ Important Constraint (must know)
🚨 This method works only if the given node is NOT the last node.
Why?
The last node has no next node to copy data from.
If ptr->next == NULL, this approach is impossible.

Before deletion:

A → B → C → D
      ↑
     ptr


After copying data:

A → C → C → D
      ↑
     ptr


After bypass & delete:

A → C → D
      ↑
     ptr

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

void deleteNode(Node *ptr)
{
    // Store the next node
    Node *temp = ptr->next;

    // Copy data from next node into current node
    ptr->data = temp->data;

    // Bypass the next node
    ptr->next = temp->next;

    // Delete the duplicate node
    delete(temp);
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Data Replacement Technique
Pointer Manipulation

*/

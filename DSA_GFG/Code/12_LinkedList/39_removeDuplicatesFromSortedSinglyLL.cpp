
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

// This solution works only for sorted linked lists.
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    if (head == NULL)
        return head;

    while (curr != NULL && curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            Node *duplicate = curr->next;
            curr->next = curr->next->next;
            delete (duplicate);
        }
        else
            curr = curr->next;
    }
    return head;
}

Node *push(Node *head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    head = new_node;
    return head;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *llist = NULL;
    llist = push(llist, 20);
    llist = push(llist, 13);
    llist = push(llist, 13);
    llist = push(llist, 11);
    llist = push(llist, 11);
    llist = push(llist, 11);
    cout << ("List before removal of duplicates\n");
    printList(llist);
    cout << ("List after removal of elements\n");
    llist = removeDuplicates(llist);
    printList(llist);
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n)
Each node is visited at most once.

📦 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Assumption: The linked list is sorted
Start from the head of the list
Compare the current node with the next node
If both values are equal:
Remove the next node (duplicate)
Do not move the current pointer
If values are different:
Move to the next node
Continue until the end of the list

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node* removeDuplicates(Node* head)
{
    // If list is empty, nothing to remove
    if (head == NULL)
        return head;

    Node* curr = head;

    // Traverse the list
    while (curr != NULL && curr->next != NULL)
    {
        // If duplicate is found
        if (curr->data == curr->next->data)
        {
            Node* duplicate = curr->next;   // store duplicate node
            curr->next = curr->next->next;  // remove duplicate from list
            delete duplicate;               // free memory
        }
        else
        {
            // Move forward only if no duplicate
            curr = curr->next;
        }
    }
    return head;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

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
    if (head->next == head)
    {
        delete (head);
        return nullptr;
    }

    Node *temp2 = head;
    while (temp2->next != head)
        temp2 = temp2->next;
    temp2->next = head->next;
    delete (head);
    return (temp2->next);
}

Node *deleteKthNode(Node *head, int k)
{
    if (head == NULL || k < 0)
        return NULL;

    int count = 1;
    Node *temp3 = head;
    while (temp3->next != head)
    {
        count++;
        temp3 = temp3->next;
    }

    if (k > count)
        return head;

    if (k == 1)
        return deleteHead(head);

    Node *curr = head;
    for (int i = 1; i < k - 1; i++)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;

    curr->next = temp->next;
    delete (temp);
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    printCll(head);
    head = deleteKthNode(head, 2);
    printCll(head);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n) time
O((1) space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Handle edge cases
If the list is empty or k is invalid, return immediately.
Count nodes in the circular linked list
Traverse once until the pointer comes back to head.
This helps validate whether k is within range.
If k is greater than the number of nodes
No deletion is performed.
If k == 1
If the list has only one node, delete it and return NULL.
Otherwise:
Find the last node.
Make it point to head->next.
Delete the old head and return the new head.
If k > 1
Traverse to the (k−1)th node.
Adjust links to skip the kth node.
Delete the kth node.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node *deleteKthNode(Node *head, int k)
{
    // If list is empty or k is invalid
    if (head == NULL || k < 0)
        return NULL;

    // Step 1: Count number of nodes in circular linked list
    int count = 1;
    Node *temp3 = head;
    while (temp3->next != head)
    {
        count++;
        temp3 = temp3->next;
    }

    // If k is greater than number of nodes, no deletion
    if (k > count)
        return head;

    // Step 2: If first node is to be deleted
    if (k == 1)
    {
        // If only one node exists
        if (head->next == head)
        {
            delete (head);
            return nullptr;
        }

        // Find last node to maintain circular link
        Node *temp2 = head;
        while (temp2->next != head)
            temp2 = temp2->next;

        // Make last node point to second node
        temp2->next = head->next;

        // Delete old head
        delete (head);

        // Return new head
        return (temp2->next);
    }

    // Step 3: Traverse to (k-1)th node
    Node *curr = head;
    for (int i = 1; i < k - 1; i++)
    {
        curr = curr->next;
    }

    // Step 4: Delete k-th node
    Node *temp = curr->next;
    curr->next = temp->next;
    delete (temp);

    // Head remains unchanged
    return head;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

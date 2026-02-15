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

Node* reverseList(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;

    
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
O(n) due to recursion stack)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Base case
If the list is empty or has only one node, it is already reversed.
Return head.
Recursive call
Recursively reverse the sublist starting from head->next.
This returns the head of the reversed sublist (newHead).
Fix the current node’s links (while returning)
Make the next node point back to the current node:
head->next->next = head;
Break the original forward link to avoid a cycle:
head->next = NULL;

Return the final head
The head of the reversed list (newHead) is returned unchanged through all recursive calls.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

Node* reverseList(Node* head)
{
    // Base case:
    // If the list is empty or has only one node,
    // it is already reversed, so return head.
    if (head == NULL || head->next == NULL)
        return head;

    // Recursively reverse the rest of the list starting from head->next.
    // newHead will store the head of the reversed list
    // (this will be the last node of the original list).
    Node* newHead = reverseList(head->next);

    // At this point, head->next is the last node of the reversed sublist.
    // Make that node point back to the current head.
    head->next->next = head;

    // Break the original forward link to avoid a cycle.
    // After this, current head becomes the last node.
    head->next = NULL;

    // Return the head of the reversed list.
    // This value remains the same for all recursive calls.
    return newHead;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

// find Nth Node From End Of Singly LinkedList

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

int findNthNodeFromEndOfSinglyLinkedList(Node *head, int n)
{
    Node *curr = head;
    int len = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }

    if(n > len)
        return-1;

    curr = head;
    for (int i = 1; i < len - n + 1; i++)
    {
        curr = curr->next;
    }
    return curr->data;    
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    printlist(head);
    cout<<findNthNodeFromEndOfSinglyLinkedList(head, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
First traversal → O(n)
Second traversal → O(n)
Total: O(n)

Space Complexity
O(1) (constant extra space)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Pass 1: Find length of linked list
Traverse the list once
Count how many nodes are present (len)

Pass 2: Move to the required node
The n-th node from the end is:
(len − n + 1)-th node from the beginning
Start from head
Move len − n steps forward
Return the data of that node


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

int findNthNodeFromEndOfSinglyLinkedList(Node *head, int n)
{
    // Pointer to traverse the list
    Node *curr = head;

    // Variable to store length of linked list
    int len = 0;

    // First traversal to calculate length
    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }

    // If n is greater than length, nth node from end doesn't exist
    if (n > len)
        return -1;

    // Reset pointer to head for second traversal
    curr = head;

    // Move to (len - n + 1)th node from beginning
    // i starts from 1, so loop runs (len - n) times
    for (int i = 1; i < len - n + 1; i++)
    {
        curr = curr->next;
    }

    // curr now points to nth node from end
    return curr->data;    
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

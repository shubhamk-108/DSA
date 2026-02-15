/*
Reverse singly linked list
*/

// Reverse Singly Singly LinkedList

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

Node *reverseSinglyLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseSinglyLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
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
    reverseSinglyLinkedList(head);
    printlist(head);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// What we are returning to the parent. final head or newly created head in each call.
//___________________________________________________________________________________________________________________________________________

/*

is it like this we are calling a function and assigning it in newHead but what the head in each seperate case is just a parameter we 
passed to the function but it wont get returned to the parent. What gets return to the parent is what its child have passed in the call. 
In case of 10-20-30-40 here the last call passes 40 when base condition triggers so subsequent all calls will pass 40 because we are 
passing what child has received to the parent and not what was new haed we we passed to the function and assigned to the newHead.

the final call will return last node and all subsequent call will return that same last node only because that is what it has received
from its parent.

In part 2 I tackled this proble. There you will understand that if we want some variable but that variable is refefining itself in 
every recursive call then we should pass such variable as a parameter through the recursive call itself.  
*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n)
Space: O(n) (recursive call stack)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Base case
If list is empty or has only one node → already reversed

Recursive call
Reverse the list from head->next onward
Assume recursion correctly reverses the smaller list

Fix current node
Make head->next point back to head
Break the old forward link

Return new head
The last node becomes the new head

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Recursive Linked List Reversal (Post-order recursion)

*/

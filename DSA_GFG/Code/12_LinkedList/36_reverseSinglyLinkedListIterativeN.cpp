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

void reverseSinglyLinkedList(Node *head)
{
    if(head==NULL)
        return ;
    Node *curr = head;
    vector<int>vec;
    while(curr!=NULL)
    {
        vec.push_back(curr->data);
        curr = curr->next;
    }
    curr = head;
    while(curr!=NULL)
    {
        curr->data = vec.back();
        vec.pop_back();
        curr = curr->next;
    }   
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
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
First traversal → O(n)
Second traversal → O(n)
Total: O(n)

Space Complexity
Vector stores n elements
O(n) extra space

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*
Step 1: Copy data into a container
Traverse the linked list
Store each node’s data in a vector
Step 2: Write data back in reverse order
Traverse the list again from the head
Take elements from the back of the vector
Overwrite each node’s data
✔ The structure of the linked list remains unchanged
✔ Only the values are reversed




*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


void reverseSinglyLinkedList(Node *head)
{
    // If list is empty, nothing to reverse
    if (head == NULL)
        return;

    // Pointer to traverse the list
    Node *curr = head;

    // Vector to store node values
    vector<int> vec;

    // First traversal: store all node data
    while (curr != NULL)
    {
        vec.push_back(curr->data);
        curr = curr->next;
    }

    // Reset pointer to head
    curr = head;

    // Second traversal: replace data in reverse order
    while (curr != NULL)
    {
        curr->data = vec.back();  // get last element
        vec.pop_back();           // remove last element
        curr = curr->next;
    }
}


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/


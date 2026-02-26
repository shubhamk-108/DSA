/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

*/

#include <iostream>
using namespace std;

class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}
    };
    Node *head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;

        Node *curr = head;

        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val)
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        size++;
        head = newHead;
    }

    void addAtTail(int val)
    {
        Node *newTail = new Node(val);
        if (head == nullptr)
        {
            head = newTail;
        }
        else
        {
            Node *curr = head;

            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = newTail;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *curr = head;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *curr = head;
            for (int i = 0; i < index - 1; i++)
                curr = curr->next;
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time:
| Operation       | Time |
| --------------- | ---- |
| `get`           | O(n) |
| `addAtHead`     | O(1) |
| `addAtTail`     | O(n) |
| `addAtIndex`    | O(n) |
| `deleteAtIndex` | O(n) |

Space Complexity
Auxiliary space: O(1)
Total space: O(n) (for storing nodes)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Core idea

Encapsulate a singly linked list inside a class
Use a private Node structure
Maintain:
head pointer → start of list
size → number of nodes
Why this works
head gives access to the list
size allows:
fast index validation
avoids traversing for length
Each operation modifies pointers safely



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class MyLinkedList
{
private:
    // Internal node structure (hidden from outside)
    struct Node
    {
        int val;
        Node *next;

        // Node constructor
        Node(int x) : val(x), next(nullptr) {}
    };

    Node *head;  // pointer to first node
    int size;    // current size of linked list

public:
    // Constructor: initialize empty list
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    // Get value at given index
    int get(int index)
    {
        // Index validation
        if (index >= size || index < 0)
            return -1;

        // Traverse to index
        Node *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->val;
    }

    // Insert node at head
    void addAtHead(int val)
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        size++;
    }

    // Insert node at tail
    void addAtTail(int val)
    {
        Node *newTail = new Node(val);

        // Empty list case
        if (head == nullptr)
        {
            head = newTail;
        }
        else
        {
            // Traverse to last node
            Node *curr = head;
            while (curr->next != nullptr)
                curr = curr->next;

            curr->next = newTail;
        }
        size++;
    }

    // Insert node at specific index
    void addAtIndex(int index, int val)
    {
        // Invalid index
        if (index < 0 || index > size)
            return;

        // Insert at head
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *curr = head;

        // Traverse to (index - 1)
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        // Insert node
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    // Delete node at given index
    void deleteAtIndex(int index)
    {
        // Invalid index
        if (index < 0 || index >= size)
            return;

        // Delete head
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            // Traverse to (index - 1)
            Node *curr = head;
            for (int i = 0; i < index - 1; i++)
                curr = curr->next;

            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        size--;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

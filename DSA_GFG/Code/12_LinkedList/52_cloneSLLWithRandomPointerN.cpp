
// problem statement:
//  Given a head of linked list where each node has two links: next pointer pointing to the next node and random pointer to any random node in the list.
//  Create a clone of this linked list. YOu have to create puerly new linked list means the addresses of both the links will be different.

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node *clone(Node *head)
{
    Node *head2 = nullptr;
    Node *prev = nullptr;
    unordered_map<Node *, Node *> um;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        Node *newNode = new Node(curr->data);
        um[curr] = newNode;

        if (head2 == nullptr)
        {
            head2 = newNode;
            prev = newNode;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
    }
    Node *curr1 = head;
    Node *curr2 = head2;

    while (curr1 != NULL)
    {
        if (curr1->random == nullptr)
            curr2->random = nullptr;
        else
        {
            Node *randomOfMainListNode = curr1->random;
            Node *equivalentNodeOfRandomOfMainListNodeInCloneList = um[randomOfMainListNode];
            curr2->random = equivalentNodeOfRandomOfMainListNodeInCloneList;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return head2;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << "Original list : \n";
    print(head);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);

    return 0;
}
//___________________________________________________________________________________________________________________________________________
// My understanding
//___________________________________________________________________________________________________________________________________________

/*

Keep in mind that the clone list is completely seperate list means it will have its own addresses.

Now In first loop we are only creating new nodes and making a normal single lists. We are not connecting random nodes.
In second loop we are connecting random nodes. Why we are not connecting random pointer in same first loop. BEcause random pointer can be anything.
Means ex first node's random pointer can be 7th node but we are building our clone list one by one. SO when we are on first node then
we have no further pointers as of yet. So we have to make singly normal regular LL first.

Why we need a map.

Last 1 : 10->20->30->40->50
consider 10's random is 40. And 20's random is 50.

Now when we make our new list see.
In fist loop:  10->20->30->40->50 only and no random pointer as of yet.

In second loop when we will try to connect random pointer then notice that first link and second link is completely seperate means 
their addresses are different. So when  I will ask node 1 of LL1 about its random ptr, it will say for ex 6th node which has address 0x8.
But since clone list have different addresses it cant find 6th node with 0x8 address. So when we were creating nodes one by one at that 
time we have to store in map every node's equivalent newly created node. Meaning if 10-20-30 is LL1 and 10's random is 30. 
Now I will save addresses of newly created node in map. Means i will say for node 10 address is 0x87 and the equivalent node created in
clone LL for node 10 is having address 0x46. Means when i will try to find node 10 in original list then i can also find whatever
node 10's equivalent address in clone list.

*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
First traversal: O(n)
Second traversal: O(n)
Hash lookups: O(1) average
✅ Total Time:
O(n)

6️⃣ Space Complexity
HashMap stores n entries
Extra pointers only
❌ Auxiliary Space:
O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Steps
Traverse original list:
Create cloned nodes
Build next chain of cloned list
Store mapping in hash map
Traverse both lists together:
For each original node’s random
Use hash map to assign correct cloned random


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Node *clone(Node *head)
{
    // Head of cloned list
    Node *head2 = nullptr;

    // Tail pointer for cloned list
    Node *prev = nullptr;

    // Map original node -> cloned node
    unordered_map<Node *, Node *> um;

    // -------- First pass: clone nodes & next pointers --------
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        // Create clone node with same data
        Node *newNode = new Node(curr->data);

        // Store mapping
        um[curr] = newNode;

        // Build cloned list using next pointers
        if (head2 == nullptr)
        {
            head2 = newNode;
            prev = newNode;
        }
        else
        {
            prev->next = newNode;
            prev = newNode;
        }
    }

    // -------- Second pass: set random pointers --------
    Node *curr1 = head;   // original list
    Node *curr2 = head2;  // cloned list

    while (curr1 != NULL)
    {
        if (curr1->random == nullptr)
            curr2->random = nullptr;
        else
            // Assign cloned equivalent of original random
            curr2->random = um[curr1->random];

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Return head of cloned list
    return head2;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

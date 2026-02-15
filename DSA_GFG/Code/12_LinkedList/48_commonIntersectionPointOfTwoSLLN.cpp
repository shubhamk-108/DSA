// two linked lists are given. we have to find common intersection point of the LL from where both linked lists have same nodes ahead.

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// A node of the singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

int commonIntersectionPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> us;
    Node *curr = head1;
    while (curr != NULL)
    {
        us.insert(curr);
        curr = curr->next;
    }

    curr = head2;
    while (curr != nullptr)
    {
        if (us.find(curr) != us.end())
            return curr->data;
        curr = curr->next;
    }
    return -1;
}

// Function to print nodes in a
// given linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    //    List 1  :10 20 30 40 50 60
    //    List 2  :3 5 7 40 50 60
    // from 40 the list is common so even if we set anyone list's head->next, we will still set elements in both the list
    // meaning, for 40 i will set both list some->next  = 40, but 40 owards even if i set list1->next = 50, sill it will reflect in both the list.

    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    Node *head2 = new Node(3);
    head2->next = new Node(5);
    head2->next->next = new Node(7);

    Node *common  = new Node(40);
    common->next = new Node(50);
    common->next->next = new Node(60);

    head1->next->next->next = common;
    head2->next->next->next = common;  

    printList(head1);
    cout << endl;
    cout<< commonIntersectionPoint(head1, head2);cout << endl;
    printList(head2);

    

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Traversing list 1 → O(n)
Traversing list 2 → O(m)
Hash lookups → O(1) average

✅ Total:
O(n + m)

💾 Space Complexity
Hash set stores up to n node addresses
❌ Extra space used:
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Goal:
Find the first node where two singly linked lists intersect by memory address, not by value.
Idea:
Traverse the first list and store addresses of all its nodes in a hash set.
Traverse the second list and check whether the current node’s address exists in the set.
The first match is the intersection point.
If no match is found, return -1.
Why this works:
Intersection means both lists share the same node in memory
Hash set gives O(1) average lookup time

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


int commonIntersectionPoint(Node *head1, Node *head2)
{
    // Hash set to store addresses of nodes in first linked list
    unordered_set<Node *> us;

    // Traverse first list and insert all node addresses
    Node *curr = head1;
    while (curr != nullptr)
    {
        us.insert(curr);        // store node address
        curr = curr->next;
    }

    // Traverse second list and check for intersection
    curr = head2;
    while (curr != nullptr)
    {
        // If current node address exists in set,
        // this node is the intersection point
        if (us.find(curr) != us.end())
            return curr->data;

        curr = curr->next;
    }

    // No intersection found
    return -1;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

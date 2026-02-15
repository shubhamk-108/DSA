// two linked lists are given. we have to find common intersection point of the LL from where both linked lists have same nodes ahead.

#include <bits/stdc++.h>
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
    Node *curr1 = head1;
    Node *curr2 = head2;

    int count1 = 0;
    while (curr1 != nullptr)
    {
        count1++;
        curr1 = curr1->next;
    }
    int count2 = 0;
    while (curr2 != nullptr)
    {
        count2++;
        curr2 = curr2->next;
    }

    int d = abs(count1 - count2);

    curr1 = head1;
    curr2 = head2;

    if (count1 > count2)
    {
        int i = 0;
        while (curr1 != NULL && i < d)
        {
            curr1 = curr1->next;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (curr2 != NULL && i < d)
        {
            curr2 = curr2->next;
            i++;
        }
    }

    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
            return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
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

    Node *common = new Node(40);
    common->next = new Node(50);
    common->next->next = new Node(60);

    head1->next->next->next = common;
    head2->next->next->next = common;

    printList(head1);
    cout << endl;
    cout << commonIntersectionPoint(head1, head2);
    cout << endl;
    printList(head2);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Counting lengths: O(n + m)
Alignment + traversal: O(n + m)
✅ Overall:
O(n + m)

💾 Space Complexity
Only pointers and counters used

✅ Extra space:
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse both lists to find their lengths.
Compute the absolute length difference d.
Move the pointer of the longer list forward by d nodes.
Traverse both lists simultaneously.
The first node where both pointers are equal is the intersection point.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


int commonIntersectionPoint(Node *head1, Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    // Count length of first linked list
    int count1 = 0;
    while (curr1 != nullptr)
    {
        count1++;
        curr1 = curr1->next;
    }

    // Count length of second linked list
    int count2 = 0;
    while (curr2 != nullptr)
    {
        count2++;
        curr2 = curr2->next;
    }

    // Find difference in lengths
    int d = abs(count1 - count2);

    // Reset pointers to list heads
    curr1 = head1;
    curr2 = head2;

    // Advance pointer of longer list by d nodes
    if (count1 > count2)
    {
        int i = 0;
        while (curr1 != nullptr && i < d)
        {
            curr1 = curr1->next;
            i++;
        }
    }
    else
    {
        int i = 0;
        while (curr2 != nullptr && i < d)
        {
            curr2 = curr2->next;
            i++;
        }
    }

    // Traverse both lists together to find intersection
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
            return curr1->data;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // No intersection found
    return -1;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Two-Pointer Alignment Pattern
Key idea:
Equalize traversal distance before moving pointers together



*/

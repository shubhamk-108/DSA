

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        if (list1->val <= list2->val)
        {
            head = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            tail = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        if (list1 == nullptr)
            tail->next = list2;
        else
            tail->next = list1;
        return head;
    }
};


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n + m)
n = length of list a
m = length of list b
Each node is visited exactly once

🧠 Space Complexity
O(1) auxiliary space

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Goal
Merge two already sorted linked lists a and b into one sorted linked list without creating new nodes.
High-level idea:
Decide the first node (head) of the merged list by comparing a->data and b->data
Maintain a tail pointer that always points to the last node of the merged list
Repeatedly:
Compare current nodes of a and b
Attach the smaller node to tail
Move forward in the list from which the node was taken
When one list becomes empty, attach the remaining part of the other list
This is exactly how merge step of merge sort works

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

Node *sortedMerge(Node *a, Node *b)
{
    // If one list is empty, return the other
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    Node *head = nullptr; // Head of merged list
    Node *tail = nullptr; // Tail of merged list

    // Initialize head and tail
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    // Merge while both lists have nodes
    while (a != nullptr && b != nullptr)
    {
        if (a->data <= b->data)
        {
            tail->next = a; // attach smaller node
            tail = a;       // move tail
            a = a->next;    // move list a
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    // Attach remaining nodes
    if (a == nullptr)
        tail->next = b;
    else
        tail->next = a;

    return head;
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> us;
        ListNode *curr = headA;
        while (curr != NULL)
        {
            us.insert(curr);
            curr = curr->next;
        }

        curr = headB;
        while (curr != nullptr)
        {
            if (us.find(curr) != us.end())
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
};

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

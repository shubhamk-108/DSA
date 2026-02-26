
/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Input: head = [1,2,3,4]
Output: [1,4,2,3]
*/

#include <iostream>
#include <vector>
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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next)
            return;

        vector<ListNode*> nodes;
        ListNode* curr = head;

        while (curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int i = 0;
        int j = nodes.size() - 1;

        while (i < j)
        {
            nodes[i]->next = nodes[j];
            i++;

            if (i == j) break;

            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};

//___________________________________________________________________________________________________________________________________________
// cycle creates if we increment pointer conventionally for even nodes
//___________________________________________________________________________________________________________________________________________

/*
while (i < j)
{
    nodes[i]->next = nodes[j];
    nodes[j]->next = nodes[i+1];
    i++;
    j--;
}

1-2-3-4-5-6
1 connects to 6 and 6 connects to 2 = 1-6-2
2 connects to 5 and 5 connects to 3 = 1-6-2-5-3
3 connects to 4 and 4 connects to 3 = 1-6-2-5-3-4-3 cycle here.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(N)
Space Complexity: O(N)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Step 1: Store All Nodes
Traverse the list once and store each node pointer in a vector/array.
Now we have random access to nodes.

Step 2: Use Two Pointers on the Array

i = 0
j = n - 1

Reorder like:

nodes[i]->next = nodes[j]
nodes[j]->next = nodes[i+1]
i++
j--

Repeat until pointers meet.

Step 3: Terminate the List
After merging, ensure the last node points to nullptr.
This is very important to avoid cycles.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next)
            return;

        // Step 1: Store all nodes in a vector
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while (curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        // Step 2: Reorder using two pointers
        int i = 0;
        int j = nodes.size() - 1;

        while (i < j)
        {
            nodes[i]->next = nodes[j];
            i++;

            if (i == j) break;

            nodes[j]->next = nodes[i];
            j--;
        }

        // Step 3: Properly terminate the list
        nodes[i]->next = nullptr;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Array Simulation of Linked List


*/

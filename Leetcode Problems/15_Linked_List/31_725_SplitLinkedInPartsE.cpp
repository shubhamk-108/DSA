/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.
Ex 1
Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Ex 2
Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.


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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        int eleEachGroupHolds = len / k;
        int extraNodes = len % k;

        curr = head;
        ListNode *prev = nullptr;
        vector<ListNode *> res(k, nullptr);

        for (int i = 0; i < k && curr != NULL; i++)
        {
            res[i] = curr;

            for (int count = 1; count <= eleEachGroupHolds + (extraNodes > 0 ? 1 : 0); count++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            extraNodes--;
        }
        return res;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(n)
(each node is visited once)

Space: O(1) extra

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

“First, I count the total number of nodes in the list.
Then I compute how many nodes each part should have and how many parts should get one extra node.
Finally, I iterate k times, assign the current node as the head of each part, move the required number of nodes, break the link, and continue.”


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        // Step 1: Calculate the length of the linked list
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            len++;
            curr = curr->next;
        }

        // Minimum number of nodes each group will have
        int eleEachGroupHolds = len / k;

        // Number of groups that will get one extra node
        int extraNodes = len % k;

        // Reset curr to start splitting from head
        curr = head;

        // prev will help us break the link after each group
        ListNode *prev = nullptr;

        // Result vector of size k, initialized with nullptr
        vector<ListNode *> res(k, nullptr);

        // Iterate over k parts or until list ends
        for (int i = 0; i < k && curr != NULL; i++)
        {
            // Current node is the head of this part
            res[i] = curr;

            // Traverse nodes belonging to this part
            for (int count = 1;
                 count <= eleEachGroupHolds + (extraNodes > 0 ? 1 : 0);
                 count++)
            {
                prev = curr;
                curr = curr->next;
            }

            // Break the link to separate this part from the next
            prev->next = nullptr;

            // Reduce extraNodes after assigning extra node to a part
            extraNodes--;
        }

        // Return heads of all k parts
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Partitioning with precomputed sizes
(Count → Distribute → Split)
*/

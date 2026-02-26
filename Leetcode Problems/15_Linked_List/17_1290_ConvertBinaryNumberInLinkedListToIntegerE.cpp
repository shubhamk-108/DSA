/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0

*/

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
    int getDecimalValue(ListNode *head)
    {
        int res = 0;
        while (head != NULL)
        {
            res = res << 1 | head->val; // res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};

//___________________________________________________________________________________________________________________________________________
// Important property of bits and then the code explanation: Read both.
//___________________________________________________________________________________________________________________________________________
/*

Let’s start with decimal (base-10)
Number:
23
Move digits LEFT (append a digit to the right)
23 → 230
Moving left we got one space vacant and we fill it with 0 because we multiply it with 10 (decimal).
Value:
23 × 10 = 230

Move digits RIGHT (remove last digit)
230 → 23
Value:
230 ÷ 10 = 23
Just to understand in my language: Moving to right the last digit goes out of scope so we remain with 23 only which is divides by 10.

So:
Left shift → ×10
Right shift → ÷10


Now binary (base-2)
Binary number:
101   (decimal 5)
Move bits LEFT (append 0 on right)
101 → 1010
Again here also moving left, one extra space vacant and we fill the last digit with 0.
101 = 5, moving left = 1010 - 10.
That is moving left gives us result multiply by 2 as we got in decimal multiply by 10.
Value:
5 × 2 = 10

Move bits RIGHT (remove last bit)
101 → 10
Moving to the right the last digit will go out of scope and we get the result equivalent to value divide by 2.
101 = 5 and 10 = 2. So 5/2 = 2/
Value:
5 ÷ 2 = 2

So:
Left shift → ×2
Right shift → ÷2

The same multiply by 2 and divide by 2 can be done using left shift and right shift operator.
left shift operator << multiplies the result by 2 and right shift >> divides the res by 2.


----- code explanation:

Ex: 101.

We will start with the result as 0. which is in binary 000.

Now we traverse 101 from left to right.
We take first 1. And we have to make space for 1 in result 000. But to make a space we have to left shift 000 to accomodate 1.
the msd goes our of scope while left shifting and we accomodate 1 and becomes 001. Now result is 001 which is 1 in decimal.

Take next bit 0.
Left shift again to make a spcae for 0. result was 001. left shifting it gets 0 1 _. Now fill this empty space wit our bit.
we get 010 which is 2. so result is 010 which is 2 in decimal.

Take next bit 1.
left shift result make a space for this bit. 1 0 _. Accomodate this bit. 1 0 1 which becomes 5 in decimal.

Now left shifting is << and we have to perform left shifting on our last result. So with left shift we also do bitwise OR operation.
Simply left shift wont work. We also have to do OR operation because we have to accomodate that bit as well.

So code will be
int res = 0;
res = res << 1 | head->val.

The same operation we can also do by below code.
int res = 0;
res = res * 2 + head->val.
Because left shift multiplies by 2 and plus here will do the job of bitwise OR.

dry run for 101:

res = 000
for first bit.

left shift res and Bitwise Or:
first bit 1:
<<  = 000
| 1 = 001
res = 001 (1 in binary).
now res is 001.

next bit 0:
<<  = 010
| 0 = 000
res = 010 (2 in binary).

next bit 1.
<<  = 100
|   = 001
res = 101 (5 in binary).





*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity

O(n)
We traverse the linked list once
💾 Space Complexity
O(1)
No extra data structures used

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
The linked list represents a binary number, from most significant bit (left) to least significant bit (right).
We start with result = 0
For every node:
Shift the current result left by 1 → this makes space for the next bit
(same as multiplying by 2)
Add the current bit (0 or 1)
Continue until the list ends
The final result is the decimal value

Formula form:
result = result * base + digit
Here:
base = 2
digit = 0 or 1

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int res = 0;

        while (head != NULL)
        {
            // Left shift res by 1 (multiply by 2)
            // Add current bit (0 or 1)
            res = (res << 1) | head->val;  
            // same as: res = res * 2 + head->val;

            head = head->next;
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

✅ Bit Manipulation + Iterative Accumulation
More specifically:
Left-shift accumulation pattern
Similar to:
converting binary string to decimal
building a number digit-by-digit


*/

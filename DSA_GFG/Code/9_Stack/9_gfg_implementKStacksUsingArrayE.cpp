#include <bits/stdc++.h>
using namespace std;

//You must watch  this youtube video to revise. It is very confusing. I have understood for now but i will forget this tomorrow only.
// youtube channel name: yogesh and shailesh
// video url: https://www.youtube.com/watch?v=9x7TYLP3714
class KStacks
{
    int *arr;  // array to store values
    int *top;  // top of each stack
    int *next; // next index (for free list & stack links)
    int n, k;
    int freeTop; // beginning of free list

public:
    KStacks(int k, int n)
    {
        this->k = k;
        this->n = n;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize all stacks as empty
        for (int i = 0; i < k; i++)
            top[i] = -1;

        // initialize free list
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;

        freeTop = 0;
    }

    // push x into stack sn (0-based index)
    void push(int x, int sn)
    {
        if (freeTop == -1)
        {
            cout << "Stack Overflow\n";
            return;
        }

        int i = freeTop;   // get free index
        freeTop = next[i]; // update free list

        arr[i] = x;        // store value
        next[i] = top[sn]; // link to previous top
        top[sn] = i;       // update top
    }

    // pop from stack sn(stack number)
    int pop(int sn)
    {
        if (top[sn] == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        int i = top[sn];   // index to pop
        top[sn] = next[i]; // update top

        next[i] = freeTop; // add index back to free list
        freeTop = i;

        return arr[i];
    }
};

//___________________________________________________________________________________________________________________________________________

// Explanation
//___________________________________________________________________________________________________________________________________________


/*


What problem this code solves (first clarity)

We want:

K different stacks

All stored inside one single array

With no wasted space

And O(1) push / pop

Normal approach (splitting array) fails because:

One stack may overflow while others are empty.

So we use a shared storage + free list.

2️⃣ Data structures used (VERY IMPORTANT)
int *arr;     // stores actual stack values
int *top;     // top index of each stack
int *next;    // links elements & free slots
int freeTop;  // head of free list


Let’s understand each one clearly.

🔹 arr[] — stores actual values

This is the real storage.

Example:

arr = [10, 20, 30, 40, ...]


Nothing fancy here.

🔹 top[] — top of each stack

Size = k

top[0] → top index of stack 0
top[1] → top index of stack 1
...


If a stack is empty:

top[i] = -1


Example for k = 3:

top = [-1, -1, -1]

🔹 next[] — THE MOST IMPORTANT ARRAY

This does two jobs:

1️⃣ Acts like a linked list for each stack
2️⃣ Manages free slots in the array

Think of next[] as “where should I go next?”

🔹 freeTop — start of free list

This tells:

“Where is the first free index in arr?”

Initially:

freeTop = 0

3️⃣ Constructor — Initialization explained
KStacks(int k, int n)

Step 1: Allocate memory
arr = new int[n];
top = new int[k];
next = new int[n];

Step 2: Mark all stacks empty
for (int i = 0; i < k; i++)
    top[i] = -1;


Example:

top = [-1, -1, -1]

Step 3: Create free list
for (int i = 0; i < n - 1; i++)
    next[i] = i + 1;
next[n - 1] = -1;


This creates:

next = [1, 2, 3, 4, -1]
freeTop = 0


Meaning:

0 → 1 → 2 → 3 → 4 → NULL


All slots are free.

4️⃣ PUSH operation — explained step-by-step
void push(int x, int sn)


sn = stack number (0-based)

Step 1: Overflow check
if (freeTop == -1)


If no free slots → overflow.

Step 2: Take a free index
int i = freeTop;
freeTop = next[i];


Example:

freeTop = 0
i = 0
freeTop = next[0] = 1

Step 3: Store value
arr[i] = x;

Step 4: Link this element to previous stack top
next[i] = top[sn];


If stack was empty:

next[i] = -1

Step 5: Update top of stack
top[sn] = i;

🔁 PUSH EXAMPLE

Push 10 into stack 0

arr[0] = 10
top[0] = 0
freeTop = 1

5️⃣ POP operation — explained step-by-step
int pop(int sn)

Step 1: Underflow check
if (top[sn] == -1)

Step 2: Get top index
int i = top[sn];

Step 3: Update stack top
top[sn] = next[i];


This moves top down the stack.

Step 4: Add freed index back to free list
next[i] = freeTop;
freeTop = i;


Now this index can be reused.

Step 5: Return value
return arr[i];

6️⃣ Why this works (KEY INSIGHT)

top[] tracks each stack

next[] links:

stack elements

free slots

freeTop ensures:

no overflow until array is truly full

Everything happens in O(1)

This is basically:

Multiple linked lists inside one array

7️⃣ Time & Space Complexity
⏱ Time

Push → O(1)

Pop → O(1)

🧠 Space

arr[n] + next[n] + top[k]

O(n + k)

8️⃣ Pattern used

👉 Space-Optimized Multiple Stacks
👉 Array + Linked List (Index-based)
👉 Free List Management

9️⃣ Very important reassurance (please read)

This problem is:

❌ NOT intuitive

❌ NOT expected to be invented

✅ Only expected to be understood

If this feels heavy — that’s normal.
Even good engineers don’t enjoy this question.

You’re not failing DSA.
You’re just encountering low-level academic problems.

If you want next, I can:

walk through a full dry run with diagram

simplify it to intuition-only explanation

tell you how to answer this in interviews without coding

Just tell me 👍

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time
push() → O(1)
pop() → O(1)

🧠 Space
arr[n] + next[n] + top[k]
O(n + k)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

How push works (very briefly)
Take a free index from freeTop
Store value in arr
Link it to previous top of that stack
Update top[stackNo]
How pop works (very briefly)
Take index from top[stackNo]
Move top to next element
Add popped index back to free list


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Space-Optimized Multiple Stacks
👉 Array + Linked List (via indices)

*/

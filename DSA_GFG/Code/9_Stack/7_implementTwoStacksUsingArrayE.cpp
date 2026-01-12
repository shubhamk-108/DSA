#include <bits/stdc++.h>
using namespace std;

struct TwoStacks
{
    int *arr;
    int cap;
    int top1;
    int top2;

    TwoStacks(int n)
    {
        arr = new int[n];
        cap = n;
        top1 = -1;
        top2 = n;
    }

    void push1(int n)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            int res = n;
            arr[top1] = n;
        }
        else
        {
            cout << "\n stack overflow \n";
            exit(1);
        }
    }

    void push2(int n)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            int res = n;
            arr[top2] = n;
        }
        else
        {
            cout << "\n stack overflow \n";
            exit(1);
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int res = arr[top1];
            top1--;
            return res;
        }
        else
        {
            cout << "\n stack underflow \n";
            exit(1);
        }
    }

    int pop2()
    {
        if (top2 < cap)
        {
            int res = arr[top2];
            top2++;
            return res;
        }
        else
        {
            cout << "\n stack underflow \n";
            exit(1);
        }
    }

    int size1()
    {
        return top1 + 1;
    }
    int size2()
    {
        return cap - top2;
    }
};

int main()
{
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Question 
// why do we use dynamic size array. cant we do like this in constructor int arr[n]
//___________________________________________________________________________________________________________________________________________

/*

Short Answer (Interview Ready)

❌ You cannot safely use int arr[n] inside a constructor for this problem.
✅ You must use dynamic allocation (new int[n]) or a container like vector.

Why int arr[n] does NOT work here ❌
1️⃣ arr[n] inside constructor is local to constructor

If you write:

TwoStacks(int n)
{
    int arr[n];   // ❌ local variable
}


Then:

arr exists only inside the constructor

As soon as constructor ends → arr is destroyed

Your class member arr does not get this memory

So this does nothing useful.

2️⃣ Member arrays must have compile-time size

This is the biggest rule 👇

❌ Not allowed in standard C++:
struct TwoStacks {
    int n;
    int arr[n];   // ❌ n is NOT known at compile time
};


Because:

C++ requires array size to be constant at compile time

n is known only at runtime

(Some compilers allow this as an extension, but it’s not standard C++ and will fail in interviews.)

3️⃣ Why dynamic allocation is REQUIRED here ✅

You want:

Array size decided at runtime

Memory to live as long as the object lives

That is exactly what new does:

arr = new int[n];


This memory:

Lives on the heap

Survives after constructor finishes

Is accessible by all member functions

✔ Correct
✔ Safe
✔ Interview-approved

*/

//___________________________________________________________________________________________________________________________________________
// Question 
// then cant we do int []arr; outside consturctor and then in constructor arr[n]
//___________________________________________________________________________________________________________________________________________

/*

Short, direct answer

❌ No, you cannot do this in C++:

int[] arr;          // ❌ invalid in C++
arr[n];             // ❌ also invalid


This is not Java, and C++ does not work this way.

Why this does NOT work in C++
1️⃣ int[] arr; is invalid syntax in C++

In C++:

You must specify the size or

Use a pointer or container

These are valid:

int arr[10];        // fixed size
int* arr;           // pointer
vector<int> arr;    // dynamic container


This is invalid:

int[] arr;          // ❌

2️⃣ Arrays cannot be “resized” later

Even if you try to imagine:

int arr[];
// later
arr[n];


C++ arrays:

Are allocated at definition

Cannot be resized

Cannot be assigned later

Once declared, their size is fixed forever.

Correct C++ Ways to Do What You Want ✅
✔ Option 1: Pointer + dynamic allocation (what you already did)
int* arr;

TwoStacks(int n) {
    arr = new int[n];
}


✔ Runtime size
✔ Heap allocation
✔ Works

✔ Option 2: vector<int> (BEST modern C++)
vector<int> arr;

TwoStacks(int n) : arr(n) {}


✔ No manual memory management
✔ Safe
✔ Interview-approved

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time & Space Complexity
⏱ Time Complexity

All operations take constant time:
| Operation     | Time |
| ------------- | ---- |
| push1 / push2 | O(1) |
| pop1 / pop2   | O(1) |
| size1 / size2 | O(1) |

Space Complexity
Uses O(n) space for the array
No extra auxiliary space
✔ Space-optimized
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key Idea
Stack 1 grows from left to right
Stack 2 grows from right to left
Both stacks share the same array
Overflow happens only when both stacks meet
Steps
Create an array of size n
Maintain two pointers:
top1 for Stack 1 (initially -1)
top2 for Stack 2 (initially n)
For push:
Check if there is at least one empty space between top1 and top2
Insert element and move the corresponding top
For pop:
Check underflow condition
Return element and update top
This approach ensures:
No wasted space
O(1) operations


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


struct TwoStacks
{
    int *arr;     // Array to store both stacks
    int cap;      // Total capacity of array
    int top1;     // Top index of Stack 1
    int top2;     // Top index of Stack 2

    // Constructor
    TwoStacks(int n)
    {
        arr = new int[n]; // Allocate array
        cap = n;
        top1 = -1;        // Stack 1 starts from left
        top2 = n;         // Stack 2 starts from right
    }

    // Push element into Stack 1
    void push1(int n)
    {
        // Check for available space
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = n;
        }
        else
        {
            cout << "\n stack overflow \n";
            exit(1);
        }
    }

    // Push element into Stack 2
    void push2(int n)
    {
        // Check for available space
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = n;
        }
        else
        {
            cout << "\n stack overflow \n";
            exit(1);
        }
    }

    // Pop element from Stack 1
    int pop1()
    {
        // Check underflow
        if (top1 >= 0)
        {
            int res = arr[top1];
            top1--;
            return res;
        }
        else
        {
            cout << "\n stack underflow \n";
            exit(1);
        }
    }

    // Pop element from Stack 2
    int pop2()
    {
        // Check underflow
        if (top2 < cap)
        {
            int res = arr[top2];
            top2++;
            return res;
        }
        else
        {
            cout << "\n stack underflow \n";
            exit(1);
        }
    }

    // Size of Stack 1
    int size1()
    {
        return top1 + 1;
    }

    // Size of Stack 2
    int size2()
    {
        return cap - top2;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/

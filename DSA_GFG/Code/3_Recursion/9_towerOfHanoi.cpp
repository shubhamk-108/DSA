// THis problem is written in my notebook (dsa-1)
// Problem id = problem 1

// Problem

// Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in 
// decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to
//  move the entire stack to another rod (here considered C), obeying the following simple rules: 

// Only one disk can be moved at a time.
// Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
// No disk may be placed on top of a smaller disk.


#include<iostream>
using namespace std;
 
int tohCount(int n, int from, int to, int auxiliary)
{
    if(n==1)
    {
        return 1;
    }

    int count = tohCount(n-1, from, auxiliary, to);
    // ek vel ashi yeil ki n-1 = 1 hoil ani every recursion call will return 1 to its parent.

    count += 1;
    // this plus 1 is for when n-1 discs are moved to auxiliary then the nth disc will be moved to 'to' rod. so that extra one is 
    // calculated here

    count += tohCount(n-1, auxiliary, to, from);
    // again some moves to move discs from auxiliary to 'to' rod.
    return count;

}

void tohPrint(int n, int from, int to, int auxiliary)
{
    if(n==1)
    {
        cout<<"Move disc "<<n <<" from rod "<<from<<" to rod "<<to<<endl;
        return;
    }

    tohPrint(n-1, from, auxiliary, to);
    cout<<"Move disc "<<n <<" from rod "<<from<<" to rod "<<to<<endl;

    tohPrint(n-1, auxiliary, to, from);
}


int main()
{
    int discs = 3;
    int from = 1;
    int to = 2;
    int auxiliary = 3;
    cout<<"\nNumber of steps taken to move "<< discs<< " discs from " <<from <<" to "<<to << " using auxiliary disc are " 
    << tohCount(3, 1, 2, 3)<<endl;
    tohPrint(discs, from, to, auxiliary);
    cout << " control ends " << " ";
    return 0;
}


// Time complexity: O(2N), There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(N times) is 2N
// Auxiliary Space: O(N), Function call stack space


// Logic :

// Parameters:

// n: Number of discs to move.

// from: The rod number where the discs are currently stacked.

// to: The rod number where discs need to be moved.

// auxiliary: The rod number used as temporary storage.

// Base Case:

// When n == 1, we just move the single disc directly from the from rod to the to rod and print the move.

// After printing, the function returns because the simplest case is done.

// Recursive Case:

// First, move the top n - 1 discs from from rod to auxiliary rod, using to as a helper rod.
// This is handled by the call:
// tohPrint(n - 1, from, auxiliary, to);

// Then, move the largest disc (n) from the from rod to the to rod.
// This move is printed explicitly with:
// cout << "Move disc " << n << " from rod " << from << " to rod " << to << endl;

// Finally, move the n - 1 discs that you placed on auxiliary in the first step over to the to rod, using from as auxiliary.
// This is handled by the call:
// tohPrint(n - 1, auxiliary, to, from);

// How the recursion breaks down the problem:
// Moving n discs is broken into smaller subproblems:

// Move the top n - 1 discs out of the way.

// Move the largest disc to the destination.

// Move the n - 1 discs onto the largest disc.

// Each recursive call further breaks the problem down until you reach the base case of moving a single disc
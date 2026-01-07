// Below code is aka Moore’s Voting Algorithm

// A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

// Examples : 

// Input : {3, 3, 4, 2, 4, 4, 2, 4, 4}
// Output : 4
// Explanation: The frequency of 4 is 5 which is greater than the half of the size of the array size. 

// Input : {3, 3, 4, 2, 4, 4, 2, 4}
// Output : No Majority Element
// Explanation: There is no element whose frequency is greater than the half of the size of the array size.


#include<iostream>
using namespace std;

int findMajority(int arr[], int n)
{
    int res = 0;
    int count = 1;

    for(int i =1; i<n; i++)
    {
        if(arr[res] == arr[i])
            count++;
        else
            count--;
        
        if(count==0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == arr[res])
            count++;
    }

    if(count > (n/2))
        return arr[res];
    
    return -1;
    
}

int main()
{
    int arr[] =  {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findMajority(arr,n);
    return 0;
}





// Time Complexity: O(n), As two traversal of the array, is needed, so the time complexity is linear.
// Auxiliary Space: O(1), As no extra space is required.




// Logic



/*



It's a brilliant two-phase process:

Phase 1: Find a Candidate. The first loop cleverly finds a single element that has the potential to be the majority element.

Phase 2: Verify the Candidate. The second loop confirms if this candidate is actually the majority element by counting its true frequency.

Let's break down the genius of Phase 1.

The Logic: Pairing and Canceling Out
Imagine you have a basket of colored balls. You want to find if any color makes up more than half the total.

The algorithm works like this:

You pick a ball and hold it. This is your candidate. Your count is 1.

You then pick the next ball.
If it's the same color as your candidate, you add it to your hand. Your count goes up.

If it's a different color, you take one of your candidate balls and the new ball and throw them both away. They cancel each other out. Your count goes down.

If your count ever reaches 0, it means your hand is empty. The candidate you were holding has been completely canceled out. You then pick the very next ball you see as your new candidate.

Since a true majority element appears more than n/2 times, it is guaranteed that it will not be fully canceled out by the end. The final ball left in your hand is your candidate for the majority element.

Phase 1: Code Walkthrough (Finding a Candidate)
Let's trace this with an example: arr = , where n = 7.
The majority element must appear more than 7 / 2 = 3.5 times, so at least 4 times. The answer should be 2.



int findMajority(int arr[], int n)
{
    // === PHASE 1: Find a candidate ===
    int res = 0, count = 1;

    for(int i = 1; i < n; i++)
    {
        // Is the current element the same as our candidate?
        if(arr[res] == arr[i])
            count++; // Yes, give a vote to the candidate.
        else 
            count--; // No, cancel one out.

        // Did our candidate get completely canceled out?
        if(count == 0)
        {
            // Yes. Pick a new candidate from this position.
            res = i; 
            count = 1;
        }
    }

    Phase 2: Verification
Why do we need this second phase? Because the first phase only guarantees to find a candidate, not that the candidate is
definitely the majority. For example, if the array was ``, the algorithm would end with 3 as the candidate, which is not a majority.


*/
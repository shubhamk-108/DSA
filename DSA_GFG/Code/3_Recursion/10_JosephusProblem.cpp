// Problem Statement (Classic Josephus)
// n people stand in a circle (numbered 0 to n-1).
// Starting from position 0, every k-th person is eliminated in circular fashion.
// After each elimination, counting resumes from the next person.
// This continues until only one person remains.
// 🔹 The task: Find the position (0-based index) of the survivor.

#include<iostream>
using namespace std;

int josephus(int n, int k)
{
    if(n==1)
    {
        return 0;
        // because there is only one person remainging and his index is 0
    }
    return (josephus(n-1, k) + k ) % n ;

}




int main ()
{
    int n = 5,  k = 2;
    cout<<josephus(n,k) +1;
    // the + 1 at the end is due to prior expression gives index value of survivor and we need who is present at that index 
    // basically its position that is why that one is taken
    return 0;
}



// Overall time complexity: O(n)
// Overall space complexity: O(n)




// Logic:

// the recursive call is like this (josephus(n - 1, k) + k) % n;
// Now 1 friend/person in circle will be deleted that is why n-1
// k is gonna remain same throughout.
// next +k logic is:
// now recursion is going to make fresh/independent call everytime. So when one person is deleted from the circle then 
// the indexes changes. And the next recursion has new indexes. So at the end josephus(n - 1, k) will return 0 we 
// will not get answer only from josephus(n - 1, k) this call because changing of index. So we need to add another things
// in that call. so that is why we are adding that k. Now how do we know that we have to add k.
// for that we draw different examples on paper like for josephus(5,2), josephus(4,2),josephus(3,2), josephus(2,2), josephus(1,2)
// then we notice that the answer is following one particular pattern that we have to add + k and then %n.
// n is the total number of people
// and we are taking n to wrap up index. wrapping up index is often useful in circular pattern problem.
// suppose we add 4 to something and then that index shoots to 6 means goes out of bound because original index was till 4 only.
// add that time taking modulo will help us to making our index again at the correct spot.
// index is till 3. and if we go to index 4 then in circular fashion index 4 means index 0. so do 4 % last index means 4 % 3 = 1
// so this means come to first position again




// Step-by-step intuition:
// When you have n people in a circle and eliminate every k-th person, after that first elimination, the circle has n - 1 people left.
// The recursive call josephus(n - 1, k) finds the safe position (the winner) in that smaller circle of n-1 people.
// But because the elimination shifted everyone’s position (counting restarts after the just eliminated person), you need to adjust 
// that position to the original numbering of the n-person circle.
// You do this by adding k (the step size) to the safe position from the smaller problem.
// Finally, % n wraps the position so it stays within the valid range [0, n-1].
// Imagine a line of people numbered 0 to n-1:
// Removing the k-th person splits the problem into a smaller circle.

// The safe position in the smaller circle is returned by josephus(n - 1, k).
// ------------------------------------------------------------------------------------------------------------------------------------
// ******But this is relative to the smaller circle’s start, so you shift it by k to map back to the original circle's numbering.******
// -------------------------------------------------------------------------------------------------------------------------------------

// If that still feels confusing, here’s a literal example for n=5, k=3:
// People: 0 1 2 3 4
// Remove person at position 2 (because k=3 means counting 3 people, starting at 0).
// Remaining circle: 0 1 3 4
// Now you solve the problem for these 4 people. The recursion gives you the safe position in this smaller group (say it returns 1).
// Since you removed one person and started counting again from person after the removed one, you add k (3) and wrap around modulo 5 
// to get the original numbering.
// So it becomes (1 + 3) % 5 = 4, which means person 4 is safe.
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

void printNByK(int arr[], int n, int k)
{
    // The map stores at most k-1 candidates and their current scores.
    std::unordered_map<int, int> m;

    // --- PASS 1: Find potential candidates ---
    for (int i = 0; i < n; i++)
    {
        // If the element is already a candidate, increment its score.
        if (m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;
        }
        // If there is space for a new candidate, add it with a score of 1.
        else if (m.size() < k - 1)
        {
            m[arr[i]] = 1;
        }
        // If the map is full, decrement all candidates' scores.
        else
        {
            // --- CORRECTED CANCELLATION LOOP ---
            // Use an explicit iterator to safely erase while looping.
            for (auto it = m.begin(); it != m.end(); /* no increment here */)
            {
                it->second--; // Decrement the score of the current candidate.
                if (it->second == 0)
                {
                    // If score is 0, erase the element and the erase() function
                    // returns an iterator to the next valid element.
                    it = m.erase(it);
                }
                else
                {
                    // If not erased, manually move to the next element.
                    ++it;
                }
            }
        }
    }

    // --- PASS 2: Verify candidates and print ---
    // At this point, 'm' holds the only possible candidates.
    // We must now count their true frequency in the original array.
    for (auto &p : m)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (p.first == arr[i])
            {
                count++;
            }
        }

        if (count > n / k)
        {
            std::cout << p.first << " ";
        }
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printNByK(arr, n, k);
}





// Questions and answer


/*
_____________________________________________________________________________________________________________
Question 1
_____________________________________________________________________________________________________________
Why we have only allowing k-1 elements in the map or hash. That is why m.size() < k - 1

Answer:

Suppose n is 13 and k is 4 then n/k is 3.25 means element can be our answer if it occurs at least 4 times. 
So lets say elements are : 
1 1 1 1 
2 2 2 2 
3 3 3 3
4
Observe that our answer will be 1,2 and 3. That means total 3 values. THat is  our answer is at most k-1 = 4-1 = 3. Means 3 elements at max
can be your answer.
Now this will continue till we have n = 15 and k =4. Because as soon as n becomes 16 then n/k becomes 4 and in that case 
our answer will be that element which occurs at least 5 times.

So now if we have n = 16 and k = 4 then n/k = 4 . i.e. we need 5 occurances of element to be the answer. So
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4

See we again have 3 answers 1,2, and 3. Means we will get at most k-1 answer. i.e. here we got 3 different elements as answer.  


_____________________________________________________________________________________________________________
Question 2
_____________________________________________________________________________________________________________
Why decrement all the values of elements  present in the hashmap. i.e. code is else part

Answer: 
Because when we get the new element when we are traversing array then we check if it is already present, if yes then increment count.
Second if hash is empty then directly insert element. And thirdly if first two conditions fail then we try to decrement all to see
if any spot become empty then we can put that element there on that emptied spot.
So how we are preserving answer here. The idea is that if we have some element occuring many time then decrementing it 
will not affect its presence because at the end of the day that element will still have some count so that we can comapare at the end.
But the those elements which does not occur a low of time , say 1 time 2 time (based on n and k, here 1 and 2 is just for example) 
and if other elements are occuring 3 4 times then those elements who have appeared one or two time they will get decremented and 
they will get out of hashmap when they become zero after decrementing. On the contrary those who appear more time they will preserve there 
space there in hash map. (Read Next question . Next quesiton is the follow up question of this). And the elements which stays even at the
end will be the potential candidate that they can be the n/k occuring elements. So we again run another loop and check them if they really 
occured more that n/k times. 
It is like  survival of the fittest"

_____________________________________________________________________________________________________________
Question 3  
_____________________________________________________________________________________________________________
what we are doing if we dont find that element already existing in the map, we dont have more space to store that element in 
map and after decrementing none element having value as zero so that we can discard that. so such element get ignore or what

Answer:

You're asking about this specific scenario:
A new element arr[i] arrives.
It's not already a candidate in the map m.
The map m is full (size is k-1).
We perform the cancellation step (decrement all counters).
After decrementing, no counter drops to zero, so no space is freed up.
So, what happens to the new element arr[i]?
It gets ignored.
That's it. It doesn't get stored, its count isn't tracked, it's simply discarded for that turn.
Why is it Okay to Ignore It?
This seems strange and lossy, but it's the core magic of the algorithm. When this situation occurs, you have a group of k distinct elements:
The k-1 candidates already in your map.
The new element arr[i].
By decrementing the counters of the k-1 elements in the map and simultaneously not adding the new element, you are effectively "canceling out" this
entire group of k distinct items. You are treating it as a block where each of the k different items appeared once, and you've conceptually 
removed that block from the stream.
The Guarantee: The mathematical proof behind the Misra-Gries algorithm guarantees that even with this "ignoring" step, any element that truly 
appears more than n/k times will have a positive counter and will remain in the map at the end of the first pass. 
So, in short: Yes, the element gets ignored


*/
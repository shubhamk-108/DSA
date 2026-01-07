// Input  : arr[] = {10, 20, 10, 5, 15}
// Output : prefixSum[] = {10, 30, 40, 45, 60}
// Explanation : While traversing the array, update the element by adding it with its previous element.
// prefixSum[0] = 10,
// prefixSum[1] = prefixSum[0] + arr[1] = 30,
// prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on.

// Prefix getSum

#include <iostream>
#include <cmath>
using namespace std;

int getSum(int prefix_sum_arr[], int l, int r)
{
    if(l ==0)
        return prefix_sum_arr[r];
    else
        return prefix_sum_arr[r] - prefix_sum_arr[l-1];
}

int main()
{

    int arr[]={2, 8, 3, 9, 6, 5, 4};
    int n=7;
    int prefix_sum_arr[n];
    
    prefix_sum_arr[0] = arr[0];
    for(int i = 1; i<n; i++)
    {
        prefix_sum_arr[i] = prefix_sum_arr[i-1] + arr[i];
    }

    // l = left index and r = right index

    int l = 1;
    int r = 3;
    cout<<getSum(prefix_sum_arr,l,r);
    return 0;
}


// Time Complexity: O(1)
// Auxiliary Space: O(n)


// Question:
// Time is O(1) but i think that it should have been O(n). Isnt it scam because whatever we have done in main function we have to do that 
// if we want our output through that code. SO what difference does it make we do it in main fun or getsum fun
// The reason it's not a "scam" and why the distinction is one of the most important concepts in algorithm design is this:

// You are trading a one-time upfront cost for an enormous, repeated benefit.

// The difference isn't about the total work done for a single query. The difference is about the total work done when you need to make 
// many queries.

// Let's compare two scenarios to make this crystal clear.

// Imagine you have a huge array of 1,000,000 numbers. You need to answer 500,000 different requests for subarray sums. Then it it is 
// preprocessed in getsum function then every time you need to calculate sum to answer query. But by  doing it in outside the function
// we only need to do it once(the preprocessing) so even if we have millions of queries we will do it in O(1) time.





// Logic:


/*



The code uses the prefix sum technique to find the sum of any subarray in constant O(1) time, after an initial O(n) setup.

Phase 1: Preprocessing in main()
This phase builds the data structure that makes our queries fast.

Input Array: arr[] = {2, 8, 3, 9, 6, 5, 4}

Initialization:

cpp
int prefix_sum_arr[n];
prefix_sum_arr[0] = arr[0];
The first element of our prefix_sum_arr is set to the first element of arr.

prefix_sum_arr is now: {2, ?, ?, ?, ?, ?, ?}

The Correct for Loop:
This loop correctly calculates the running total (prefix sum).

cpp
for(int i = 1; i<n; i++)
{
    prefix_sum_arr[i] = prefix_sum_arr[i-1] + arr[i];
}
Let's trace its execution:

When i = 1: prefix_sum_arr = prefix_sum_arr + arr -> 2 + 8 = 10

When i = 2: prefix_sum_arr = prefix_sum_arr + arr -> 10 + 3 = 13

When i = 3: prefix_sum_arr = prefix_sum_arr + arr -> 13 + 9 = 22

When i = 4: prefix_sum_arr = prefix_sum_arr + arr -> 22 + 6 = 28

When i = 5: prefix_sum_arr = prefix_sum_arr + arr -> 28 + 5 = 33

When i = 6: prefix_sum_arr = prefix_sum_arr + arr -> 33 + 4 = 37

Final State of prefix_sum_arr:
After the loop, the array correctly holds the running total:
prefix_sum_arr = {2, 10, 13, 22, 28, 33, 37}

Phase 2: The Query Phase with getSum()
Now that the setup is complete, we can make our query.

The Call:

cpp
int l = 1;
int r = 3;
cout<<getSum(prefix_sum_arr, l, r);
The program asks for the sum of the subarray from index 1 to index 3. This corresponds to {8, 3, 9} in the original array. The expected 
sum is 8 + 3 + 9 = 20.

Inside getSum:
The function receives the correctly populated prefix_sum_arr, l=1, and r=3.

cpp
if(l == 0) // l is 1, so this condition is false
    ...
else
    // This is the code that runs
    return prefix_sum_arr[r] - prefix_sum_arr[l-1];
The function calculates:
prefix_sum_arr - prefix_sum_arr[1-1] which is prefix_sum_arr - prefix_sum_arr

Using the values from our array:
22 - 2

The function returns 20.

The Result
The program will print 20, which is the correct answer.

Why This Logic Works (The Math Behind It)
The core of the prefix sum technique is the simple subtraction: prefix_sum_arr[r] - prefix_sum_arr[l-1]. Here's why it works:

prefix_sum_arr[r] is the sum of everything from the start up to index r.

Sum(arr...arr[r]) = {2 + 8 + 3 + 9} = 22

prefix_sum_arr[l-1] is the sum of everything from the start up to the element just before our desired subarray begins.

Sum(arr...arr) = {2} = 2

When you subtract the second value from the first, you are effectively removing the unwanted part from the total sum, leaving you with 
exactly the sum of the subarray you wanted.

(Sum of 0 to r) - (Sum of 0 to l-1) = (Sum of l to r)

(arr + ... + arr[l-1] + arr[l] + ... + arr[r]) - (arr + ... + arr[l-1]) = arr[l] + ... + arr[r]



*/
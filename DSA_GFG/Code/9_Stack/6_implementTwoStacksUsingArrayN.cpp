/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

/*


[Naive Approach] Dividing the space into two halves
The idea to implement two stacks is to divide the array into two halves and assign two halves to two stacks, i.e., use arr[0] 
to arr[n/2] for stack1, and arr[(n/2) + 1] to arr[n-1] for stack2 where arr[] is the array to be used to implement two stacks and size of 
array be n. 


Time Complexity: 

Both Push operation: O(1)
Both Pop operation: O(1)
Auxiliary Space: O(n), Use of array to implement stack.

Problem in the above implementation
The problem with the approach is that we divide the array into two fixed halves, with one half reserved for stack1 and the other half for stack2. This can lead to inefficient space usage because if stack1 fills up, it cannot use the space available in the second half of the array for stack2, even if that space is not fully utilized.

To fix this, we should allow both stacks to grow dynamically towards each other. Instead of reserving a fixed half for each stack, stack1 will start from the left side of the array, and stack2 will start from the right side. They will grow towards each other.




*/



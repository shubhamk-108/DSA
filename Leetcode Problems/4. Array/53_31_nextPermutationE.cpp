/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();

        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;

        int pivot = i - 1;

        if (pivot == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            int j = n - 1;
            while (j >= 0 && nums[pivot] >= nums[j])
                j--;

            swap(nums[pivot], nums[j]);
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5,9,8,6,4};

    sol.nextPermutation(v);

    for (auto x : v)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity | Value    | Why                                               |
| ---------- | -------- | ------------------------------------------------- |
| **Time**   | **O(n)** | One scan to find pivot + one to find j + reversal |
| **Space**  | **O(1)** | In-place operations only, no extra storage        |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Find Pivot
Scan from right to left to find the first index pivot such that:
nums[pivot] < nums[pivot + 1]
This identifies the point where the permutation can still be increased.

Handle Descending Case
If no such pivot exists (pivot == -1), the array is the last permutation.
So, reverse the entire array to return the first permutation.

Find Next Larger Element
From the right, find index j such that:

nums[j] > nums[pivot]

j is the closest choice to maintain minimal increment

Swap pivot with that element

Reverse the suffix (right side of pivot)
This ensures the suffix is the smallest possible arrangement — making the overall result the next lexicographically larger permutation.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();

        // Step 1: Find pivot where decreasing order breaks
        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        int pivot = i - 1;

        // Step 2: If array is fully non-increasing, this is last permutation → reverse
        if (pivot == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            // Step 3: Find element greater than pivot from the right
            int j = n - 1;
            while (j >= 0 && nums[pivot] >= nums[j])
                j--;

            // Step 4: Swap pivot with next greater element
            swap(nums[pivot], nums[j]);

            // Step 5: Reverse the suffix to make it minimal
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// My explanation
//___________________________________________________________________________________________________________________________________________

/*

See this number - 9,8,6,4. Now there is no next permutation of this because there is no greater number that 9, so no one can take place of 9. 
Going ahead if we consider for 8, further no one is greater than 8. And so on. So, there is no possible next permutation for 9,8,6,4.
Now take this example. 5,9,8,6,4. Now we can have next greater permutation because there are many numbers that are greater than 5 which are 
6,8,9. So how to find now which is next permutation. 
Next permutation means immediate greater number. ex. 241, its next permutation is 412.
Consider again our this example. 5,9,8,6,4. So we will traverse from right side and we know that as long is there is increasing sequence 
we dont have any next permutation so we will find for that number which is breaking this sequence. From right side ascending sequence or 
increasing sequence chalu aahe ani madhe ekhada small number yeto ani tya increasing sequence la break karto. Mhanje jo paryant asa 
number yet nahi to paryant i-- kara. Mhanje number 5 la find kartoy aapan karan ith paryant 9,8,6,4 increasing order asalyane there is no 
next permutation.
Aata  5 chi index bhetali aahe aapalyala by doing,
int i = n - 1;
while (i > 0 && nums[i - 1] >= nums[i])
Aata hya 5 chya index la pivot mhatal.
Now, 5 chi jaga kuthe pahije. Tr ti ithe 6 chya place vr pahije. 9,8,6,4. 
5 chi new place find karanyasathi aapan he kel. while (j >= 0 && nums[pivot] >= nums[j]).
So we again traverse from right side and we take the first greater or equal element then our nums[pivot] and we swap them.
Then we put 5 to its original place and whatever comes on the earlier position of 5 by swapping, from that number our next permutation starts.
Till now it is like this. 6,9,8,5,4. Aata 6 la thodya vel ignore kar ani 6 pasun pudhe mhanje pivot pasun pudhe we can see that, 
right side pasun(last pasun ) to pivot chya next index paryant numbers he increasing sequence madhe aahe. Mhanje smallest number saglyat
right side la mhanje last la aahe. Ani we want next permutation means immediate next greater element. Aata 6 pasun next greater element
ha start hoil. Pn 6 chya pudhe 9 yeil mhanje (69...) ki 6 chya pudhe 1 yeil (61...). Of course we want immediate greater element 
means we want 61.... 
So our next step becomes from pivot + 1 pasun last paryant  che numbers reverse karun takayache. And that will be our final answer.

One imp thing if pivot becomes -1 means there is no next permutation possible because consider 9,8,6,4. For this example as i said 
earlier there is no next permutation for this. so while finding such number which breaks this increaing asequence traversing from right side,
we get nothing and at the end i becomes -1 while we keep on decrementing i. So -1 means we should skip the process of swap and directly
reverse the nums array. This is because when we exhaust next permutation like in this case 9,8,6,4 then its next permutaiton will again
be the very first permutation (like this is cyclic). So next permutation is 4,6,8,9. So directly skip the swapping and only reverse it.
*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Two-Pointer Technique + Greedy Lexicographic Ordering
Specifically:
Right-to-left scan
Targeted swap using two pointers
Reverse subarray technique
This is a classic array rearrangement / permutation pattern.

*/

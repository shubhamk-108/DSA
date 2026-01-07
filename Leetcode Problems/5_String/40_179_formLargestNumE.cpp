/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.
Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{

private:
    int partition(vector<int> &arr, int low, int high)
    {
        // i is the write pointer and j is the traverser
        int pivot = arr[high];
        int i = low;
        for (int j = low; j < high; j++)
        {
            if (compare(arr[j], pivot))
            {
                swap(arr[j], arr[i]);
                i++;
            }
        }
        // take pivot to its correct position now and all the elements left to the pivot are lesses than pivot and from 0 to pivot
        // pivot is the smallest.
        swap(arr[i], arr[high]);
        return i;
    }

    bool compare(int firstNum, int pivot)
    {
        // In sorting algo generally smaller number comes first but here we have use this sign >. So larger number will come first
        // and this is because we want to form larger number
        return to_string(firstNum) + to_string(pivot) > to_string(pivot) + to_string(firstNum);
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        // Base case: if the range has one or no elements, it is already sorted
        if (low >= high)
            return;
        // Partition the array and get the pivot index
        int pivotIndex = partition(nums, low, high);
        // Recursively sort the sub-arrays
        quickSort(nums, low, pivotIndex - 1);  // left side array
        quickSort(nums, pivotIndex + 1, high); // right side array
    }

public:
    string largestNumber(vector<int> &nums)
    {
        string res;
        quickSort(nums, 0, nums.size() - 1);

        for (auto x : nums)
            res += to_string(x);
        
        if(res[0]=='0')
            return "0";
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};

    cout << sol.largestNumber(nums);

    return 0;
}

// timespace

/*

for detailed time and spcae refer quick sort in sorting chapter gfg.

Time Complexity

QuickSort average: O(n log n)
Each comparison involves string concatenation (which costs O(k), where k = max number of digits per number).
✅ So:
Time = O(n log n × k)

💾 Space Complexity
QuickSort recursion depth = O(log n)
Temporary strings created during comparisons = O(k)
✅ Total = O(log n + k)



*/

// Logic

/*

This code is written using quick sort. please refer quick sort in gfg->sorting chapter and then look this code.
Here there is just one chnage of compare function. comment is added in compare function.

compare function is This is the core of the logic.
It decides the correct order of two numbers.

Example:
Compare 9 and 34
"934" > "349" → true → 9 should come before 34.
So, this comparison ensures that concatenation order gives the largest number.
Chooses the last element as pivot.
i is the “write pointer” (where smaller elements — in your custom comparison — go).
For every j, if arr[j] should come before pivot (based on compare), swap it forward.
At the end, place pivot at its correct position.
So, after one partition:
Left side → elements “greater” by your custom compare (should come before pivot)
Right side → elements “smaller”
Recursively sorts the left and right partitions using your custom comparison.
Once complete, nums is arranged in the correct order to form the largest number.
Concatenates all numbers into a single string.
Handles edge case where the array is like [0, 0, 0].


*/




// dry run {17,16,3,9,7,12}.

/*

give dry run for {17,16,3,9,7,12}.

Initial State
nums = [17][16][3][9][7][12]

The main function calls quickSort(nums, 0, 5).

1. First partition call: partition(nums, 0, 5)
Subarray: [17][16][3][9][7][12]
Pivot: The last element, which is 12.
Logic: The partition will move every number x where compare(x, 12) is true to the left side of the array.
compare(17, 12) -> "1712" > "1217" -> True
compare(16, 12) -> "1612" > "1216" -> True
compare(3, 12) -> "312" > "123" -> True
compare(9, 12) -> "912" > "129" -> True
compare(7, 12) -> "712" > "127" -> True
Result: Since all other numbers are "greater" than the pivot 12, they are all moved to the left partition. The pivot 12 ends up in the last position.
Array after partition: [17][16][3][9][7][12]
Pivot Index Returned: 5
Next Calls:
quickSort(nums, 0, 4) (sort the left part [17, 16, 3, 9, 7])
quickSort(nums, 6, 5) (base case, does nothing)
2. Second partition call: partition(nums, 0, 4)
Subarray: [17][16][3][9][7]
Pivot: The last element of the subarray, 7.
Logic: The partition will check which numbers are "greater" than 7.
compare(17, 7) -> "177" < "717" -> False
compare(16, 7) -> "167" < "716" -> False
compare(3, 7) -> "37" < "73" -> False
compare(9, 7) -> "97" > "79" -> True
Result: Only 9 is "greater" than 7. The partition process will move 9 to the front and place the pivot 7 after it.
Array after partition: [9][7][3][17][16][12]
Pivot Index Returned: 1
Next Calls:
quickSort(nums, 0, 0) (base case on [9], does nothing)
quickSort(nums, 2, 4) (sort the right part [3][17][16])
3. Third partition call: partition(nums, 2, 4)
Subarray: [3][17][16]
Pivot: The last element, 16.
Logic: Check numbers against the pivot 16.
compare(3, 16) -> "316" > "163" -> True
compare(17, 16) -> "1716" > "1617" -> True
Result: Both 3 and 17 are "greater" than 16. The partition places them before the pivot.
Array after partition: [9][7][3][17][16][12]
Pivot Index Returned: 4
Next Calls:
quickSort(nums, 2, 3) (sort the left part [3][17])
quickSort(nums, 5, 4) (base case, does nothing)
4. Fourth partition call: partition(nums, 2, 3)
Subarray: [3][17]
Pivot: The last element, 17.
Logic: Check 3 against the pivot 17.
compare(3, 17) -> "317" > "173" -> True
Result: 3 is "greater" than 17. The partition keeps 3 before 17.
Array after partition: [9][7][3][17][16][12]
Pivot Index Returned: 3
Next Calls:
quickSort(nums, 2, 2) (base case on [3], does nothing)
quickSort(nums, 4, 3) (base case, does nothing)
Final Result
Sorting Complete: All recursive calls are finished. The final state of the array is sorted according to your custom comparison.
Final Sorted nums: [9][7][3][17][16][12]
Concatenation: The code now iterates through this sorted array and concatenates the numbers into a single string.
largestNum = ""
largestNum += "9" -> "9"
largestNum += "7" -> "97"
largestNum += "3" -> "973"
largestNum += "17" -> "97317"
largestNum += "16" -> "9731716"
largestNum += "12" -> "973171612"
Return Value: The function returns the final string "973171612".

*/
// In this particular problem, we are provided with a sorted array of integers. Our objective is to determine whether
// there exists a triplet (pair of 3 elements equal to given sum. )

// array must be sorted

#include <iostream>
#include <algorithm>
using namespace std;

bool find3NumbersEqualToGivenSum(int arr[], int n, int sum)
{
	// sort(arr.begin(), arr.end()); This works with vector not array

	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++)
	{
		int leftPtr = i + 1;
		int rightPtr = n - 1;

		while (leftPtr <= rightPtr)
		{
			if (arr[i] + arr[leftPtr] + arr[rightPtr] == sum)
				return true;
			else if (arr[i] + arr[leftPtr] + arr[rightPtr] > sum)
				rightPtr--;
			else
				leftPtr++;
		}
	}
	return 0;
}

int main()
{
	int arr[] = {2, 5, 8, 12, 30};
	int n = 5;
	int x = 25;

	cout << find3NumbersEqualToGivenSum(arr, n, x);

	return 0;
}



// Time: O(n*log n) for sorting  + O(n^2) for finding tripet. Overall O(n^2)
// space: O(logn) for sorting and O(1) for finding triplett. Overall : O(log n)


// Logic:



/*



 * @brief Finds if there are three numbers in an array that sum up to a given target sum.
 *
 * This function uses a combination of sorting and the two-pointer technique.
 * It first sorts the array to enable efficient searching. Then, it iterates through
 * each element, treating it as the first number of a potential triplet. For the
 * remaining two numbers, it employs two pointers (leftPtr and rightPtr) to search
 * the rest of the sorted array for a pair that, along with the fixed element,
 * adds up to the target sum.
 *
 * @param arr The input array of integers.
 * @param n The number of elements in the array.
 * @param sum The target sum to find.
 * @return True if three numbers summing to 'sum' are found, false otherwise.


bool find3NumbersEqualToGivenSum(int arr[], int n, int sum)
{
    // 1. Sort the array.
    // This is essential for the two-pointer approach to work efficiently.
    // std::sort uses Introsort, an optimized hybrid sorting algorithm.
    // 'arr' is a pointer to the first element, and 'arr + n' is a pointer
    // to the element immediately after the last element.
    std::sort(arr, arr + n);

    // 2. Iterate through the array to fix the first element (arr[i]).
    // We only need to iterate up to 'n - 2' because we need at least two
    // elements (leftPtr and rightPtr) after arr[i] to form a triplet.
    for (int i = 0; i < n - 2; i++) // Corrected loop bound: i < n - 2
    {
        // Initialize two pointers for the remaining sub-array.
        // 'leftPtr' starts at the element immediately after arr[i].
        int leftPtr = i + 1;
        // 'rightPtr' starts at the last element of the array.
        int rightPtr = n - 1;

        // 3. Use the two-pointer technique on the sub-array (arr[leftPtr...rightPtr]).
        // The loop continues as long as the left pointer is less than the right pointer.
        // If leftPtr == rightPtr, there's only one element left, so a pair cannot be formed.
        while (leftPtr < rightPtr) // Corrected loop condition: leftPtr < rightPtr
        {
            // Calculate the current sum of the three elements.
            int currentSum = arr[i] + arr[leftPtr] + arr[rightPtr];

            // Check if the current sum matches the target sum.
            if (currentSum == sum)
            {
                // If a triplet is found, we immediately return true.
                return true;
            }
            // If the current sum is greater than the target sum,
            // we need to decrease the sum, so move the 'rightPtr' to the left.
            else if (currentSum > sum)
            {
                rightPtr--;
            }
            // If the current sum is less than the target sum,
            // we need to increase the sum, so move the 'leftPtr' to the right.
            else // currentSum < sum
            {
                leftPtr++;
            }
        }
    }

    // If no triplet summing to 'sum' is found after checking all possibilities, return false.
    // Note: The original code returned 0, which implicitly converts to false for bool functions.
    // Returning 'false' explicitly is clearer.
    return false;
}



*/
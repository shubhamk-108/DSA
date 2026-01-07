// _______________________________________________________________________________+

// This problem is explained in my dsa notebook (dsa -1 ). Problem id: Problem Number - 4.
// ________________________________________________________________________________



#include <iostream>
#include <vector>
#include <algorithm> // For std::max and std::min
#include <climits>   // For INT_MIN and INT_MAX
#include <stdexcept> // For std::invalid_argument

// Use std::max and std::min for clarity.
using std::max;
using std::min;


double findMedianWithBinarySearch(const std::vector<int>& first_array, const std::vector<int>& second_array)
{
    // To ensure the binary search is performed on the smaller array for better performance
    // (reducing the search space), we can recursively call the function with swapped arrays
    // if the second array is smaller than the first.
    if (first_array.size() > second_array.size()) {
        return findMedianWithBinarySearch(second_array, first_array);
    }

    // Now, 'first_array' is guaranteed to be the smaller or equal-sized array.
    int size_of_first = first_array.size();
    int size_of_second = second_array.size();

    // The binary search will be performed on the possible "partitions" or "cuts"
    // of the smaller array (first_array). The number of elements we can take
    // from first_array ranges from 0 to its full size.
    int low = 0;
    int high = size_of_first; // 'high' is the size, not size-1, as we are searching partitions, not indices.

    // Calculate the total number of elements once.
    int total_size = size_of_first + size_of_second;

    // Start the binary search loop.
    while (low <= high)
    {
        // 'partition_in_arr_1' is the number of elements to take from first_array for the left half of the combined array.
        // This is our midpoint in the binary search.
        int partition_in_arr_1 = low + (high - low) / 2; // Avoids potential overflow

        // 'partition_in_arr_2' is the number of elements to take from second_array.
        // This is calculated to ensure that the total number of elements in the combined left half is (total_size + 1) / 2.
        // The +1 handles both even and odd total sizes correctly.
        int partition_in_arr_2 = (total_size + 1) / 2 - partition_in_arr_1;

        // Now, we identify the four key boundary elements around the partitions.

        // max_left_first: The largest element on the left side of the partition in first_array.
        // If the partition is at the very beginning (0 elements), there is no element on the left, so we use INT_MIN as a placeholder.
        int max_left_first = (partition_in_arr_1 == 0) ? INT_MIN : first_array[partition_in_arr_1 - 1];
        
        // min_right_first: The smallest element on the right side of the partition in first_array.
        // If the partition is at the very end (all elements are on the left), we use INT_MAX.
        // **CORRECTED LINE**: Check against 'size_of_first', not 'total_size'.
        int min_right_first = (partition_in_arr_1 == size_of_first) ? INT_MAX : first_array[partition_in_arr_1];

        // Do the same for the second array.
        int max_left_second = (partition_in_arr_2 == 0) ? INT_MIN : second_array[partition_in_arr_2 - 1];
        
        // **CORRECTED LINE**: Check against 'size_of_second', not 'total_size'.
        int min_right_second = (partition_in_arr_2 == size_of_second) ? INT_MAX : second_array[partition_in_arr_2];

        // Check if we have found the correct partition.
        // The condition for a correct partition is that every element in the left half
        // is less than or equal to every element in the right half. This simplifies to:
        // max_left_first <= min_right_second AND max_left_second <= min_right_first.
        if ((max_left_first <= min_right_second) && (max_left_second <= min_right_first))
        {
            // If the partition is correct, we can now calculate the median.
            if (total_size % 2 == 0) // If the total number of elements is even
            {
                // The median is the average of the two middle elements.
                // These are the largest element from the combined left half and the smallest from the combined right half.
                return (max(max_left_first, max_left_second) + min(min_right_first, min_right_second)) / 2.0;
            }
            else // If the total number of elements is odd
            {
                // The median is the single middle element, which is the largest element in the combined left half.
                return max(max_left_first, max_left_second);
            }
        }
        else if (max_left_first > min_right_second)
        {
            // If the max element on the left of first_array is too large, it means our partition
            // in first_array is too far to the right. We need to move left.
            high = partition_in_arr_1 - 1;
        }
        else // (max_left_second > min_right_first)
        {
            // If the max element on the left of second_array is too large, it means our partition
            // in first_array is too far to the left. We need to move right.
            low = partition_in_arr_1 + 1;
        }
    }

    // This part of the code should ideally never be reached if the input arrays are correctly sorted.
    // It's good practice to throw an exception to indicate that something went wrong.
    throw std::invalid_argument("Input arrays are not sorted or some other error occurred.");
}


// Time Complexity: O(log(min(N, M)))
// Space Complexity: O(1)
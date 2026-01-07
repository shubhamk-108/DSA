// program will return the floor of square root. For example sq root of 13 is 3.

#include <iostream>
using namespace std;

int sqRootFloor(int x)
{
    int low = 1, high = x, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int mSq = mid * mid;

        if (mSq == x)
            return mid;
        else if (mSq > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    return ans;
}

int main()
{

    cout << sqRootFloor(13);

    return 0;
}

// time : O(log n)
// space : o(1)

// Logic 


int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1; // Initialize answer to -1 (not found)

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            // If the middle element is too big, the floor must be in the left half.
            high = mid - 1;
        }
        // This is the `else` block you provided.
        // It runs if `arr[mid] <= x`, which means `arr[mid]` is a potential floor.
        else
        {
            // The element at `mid` is a valid floor. Let's look for a better
            // (larger) one in the right half of the array.
            low = mid + 1;
            
            // We store `mid` because it's our best candidate for the floor so far.
            // we stored ans when arr[mid] is < x and not > x because, for ex, when x is 13 then 10,11,12,13,...15 all
            // has sq root of 3. Because we are taking the floor value. 
            ans = mid;
        }
    }
    return ans;
}

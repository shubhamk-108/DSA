// a party which is running from 00 to 2359 full day, guests will be coming, their arrival and departure times are given.
// You have to fimd time so that you can meet maximum number of people at party.

// The goal of this function is to find the maximum number of guests present at a party at any given time. You are given two arrays: 
// one with the arrival times of all guests and another with their corresponding departure times.

// ip 1: {900, 940} . 9.00 am to 9.40 am
//     {1000, 1030}
// op : 2. Explanation: 9.40 to 10.00 means 940 to 1000

// ip2 : {800,700,600,500}
// {840,820,830,530}
// op: 3. Explanation 800 to 820

#include <bits/stdc++.h>
using namespace std;

int maxGuestInParty(int arrival[], int departure[], int n)
{
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int i = 1;
    int j = 0;
    int curr = 1;
    int res = 1;

    while(i<n && j <n)
    {
        if(arrival[i] <= departure[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    return res;

}

int main()
{
    int arrival[] = {900, 600, 700};
    int departure[] = {1000, 800, 730};
    int n = sizeof(arrival) / sizeof( arrival[0]);

    cout << maxGuestInParty(arrival, departure, n);

    return 0;
}


// time : O(nlogn )
// The dominant operation is sorting the arrays. Sorting takes O(n log n) time. The while loop runs in O(n) time because the pointers i and j 
// each traverse their respective arrays only once. The total time is O(n log n) + O(n log n) + O(n), which simplifies to O(n log n).

// space : O(1) 

// pattern 
//  based on a common algorithmic pattern known as the "Meeting Rooms" or "Two Pointers" pattern, often applied to interval-based
//  problems.
// the problem requires you to determine the point of maximum overlap among a set of intervals (the time each guest is at the party)
// logic



/*



#include <algorithm> // Required for std::sort and std::max

int maxGuestInParty(int arrival[], int departure[], int n) {
    // Step 1: Sort both arrival and departure arrays.
    // This allows us to process events (arrivals and departures) in chronological order.
    std::sort(arrival, arrival + n);
    std::sort(departure, departure + n);

    // Initialize pointers and counters.
    int i = 1;          // Pointer for the next arrival to consider (starts at the second guest).
    int j = 0;          // Pointer for the next departure to consider.
    int curr = 1;       // Current number of guests at the party. Starts at 1 for the first guest.
    int res = 1;        // Result: Maximum number of guests seen so far.

    // Step 2: Iterate through the sorted times using a two-pointer approach.
    // The loop continues as long as there are arrivals and departures to process.
    while (i < n && j < n) {
        // Compare the next arrival time with the next departure time.
        if (arrival[i] <= departure[j]) {
            // An arrival happens next (or at the same time as a departure).
            // A new guest arrives, so increment the current guest count.
            curr++;
            // Move to the next arrival time.
            i++;
        } else {
            // A departure happens next.
            // A guest leaves, so decrement the current guest count.
            curr--;
            // Move to the next departure time.
            j++; // This was the corrected line (was j--).
        }
        
        // Update the maximum result found so far.
        res = std::max(res, curr);
    }
    
    // Return the highest number of guests that were present simultaneously.
    return res;
}


*/
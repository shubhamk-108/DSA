/*

Naive approach and its drawback:

We can partition the array into n/k parts, but it wastes space and fails when stacks grow unevenly.
That’s why we use the shared-array + free-list approach.

That’s the whole answer.
Now let me explain why, with a clear example.

1️⃣ Partition approach (what you’re thinking)

Assume:

Array size = n = 12

Number of stacks = k = 3

We divide array equally:

Stack 0 → arr[0..3]
Stack 1 → arr[4..7]
Stack 2 → arr[8..11]s

Each stack gets size = n / k = 4.
The REAL problem: uneven usage
Now imagine real usage:

Stack 0 → needs 8 elements
Stack 1 → needs 1 element
Stack 2 → needs 1 element

What happens?
Stack 0 overflows
Stack 1 & 2 are almost empty
Free space exists but cannot be used
This is called space wastage.

*/
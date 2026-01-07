/*

✅ Lower Bound
Definition

Lower Bound of a target x in a sorted array is:
👉 the first position/index where x can be inserted such that the array remains sorted.
👉 OR the first element that is >= x.

In simpler words

The first element not less than x.

Example

Array: [1, 2, 4, 4, 5, 7]

x	lower_bound(x) returns index	reason
4	2	arr[2] = 4 is the first ≥ 4
6	5	arr[5] = 7 is the first ≥ 6
0	0	first place to insert 0
8	6	insert after last element
✅ Upper Bound
Definition

Upper Bound of target x is:
👉 the first position where element is > x.

In simpler words

The first element strictly greater than x.

Example

Array: [1, 2, 4, 4, 5, 7]

x	upper_bound(x) returns index	reason
4	4	arr[4] = 5 is the first > 4
6	5	arr[5] = 7 is the first > 6
7	6	position after the last (no > 7 exists)
🔍 Visual Difference

Array: [1, 2, 4, 4, 5, 7]

Index:     0 1 2 3 4 5
Value:     1 2 4 4 5 7

lower_bound(4) → index 2  (first >=4)
upper_bound(4) → index 4  (first >4)

🧠 Why these matter?

They are used for:

✔ Finding first/last occurrence

First occurrence of x = lower_bound(x)

Last occurrence of x = upper_bound(x) - 1

✔ Counting frequency

count = upper_bound(x) - lower_bound(x)

✔ Insert in sorted order

insert at lower_bound(x)

✔ Common in competitive programming (2-pointer + binary search tricks)
🧾 How C++ uses them
auto it1 = lower_bound(arr.begin(), arr.end(), x); // first >= x
auto it2 = upper_bound(arr.begin(), arr.end(), x); // first > x

| Function    | Meaning            | Returns                     |
| ----------- | ------------------ | --------------------------- |
| lower_bound | first element >= x | insertion point of x        |
| upper_bound | first element > x  | insertion point after all x |


*/
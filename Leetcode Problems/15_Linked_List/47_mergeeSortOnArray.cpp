/*
In this code these is complete explanation of merge sort in recursion perspective. It will teach you how recursion works.
*/

#include <iostream>
#include <vector>

using namespace std;

void mergeTwoArrays(int arr[], int low, int mid, int high)
{

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left_arr[n1];
    int right_arr[n2];

    for (int i = 0; i < n1; i++)
    {
        left_arr[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else // if(right_arr[j] < left_arr[i])
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (right > left)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        mergeTwoArrays(arr, left, mid, right);
    }
}

int main()
{

    int a[] = {10, 5, 30, 15, 7};
    int left = 0, right = 4;

    mergeSort(a, left, right);
    for (int x : a)
        cout << x << " ";
}

//___________________________________________________________________________________________________________________________________________
// How recursion calls are happening.
//___________________________________________________________________________________________________________________________________________
/*

Check below recursoon function:


void mergeSort(int arr[], int left, int right)
{
    if(right > left)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        mergeTwoArrays(arr,left, mid, right);
    }
}

Three calls for left, right and merge both left right.


We’ll use this example:
arr = [8, 3, 5, 4]

the main call. left is 0 and right is 3.
mergeSort(0,3)

🌳 STEP 1 — Initial Call
mergeSort(0,3)

Mid = 1

Tree starts growing:

                (0,3)

🌳 STEP 2 — Go Left First (Depth First)

Call:

mergeSort(0,3)  This is parent call. Child will use its parameters. Meaning left is 0, right is 3. So medium is 0+3/2 = 1.
So from 0 to 1 the left call we be there. And whenever there will be right call in future at that time also we will see parent is having
parameters of left to right as 0 to 3. so mid is 1. So 0 to 1 is left side call and 1 onwards means 2 to 3 is right side call.
mergeSort(0,1)

Tree becomes:

                (0,3)
               /
           (0,1)

Now this (0,3) will start its execution but in the road it will see another call. So it will go on waiting and calculate mid
for another call that is (0 to 1). Now this (0,1) will again start fresh function right from very first line of code. And when it 
will see that another recursive call at that time it will say, are yaar, parat ek function call, aata chala prt start pasun survat kara.
(0,1) call parat waiting vr jail mg. 0 and 1 hya values use karaun parat mid find kela jail children sathi. Again left side will go to 
left part and right side will go to right child but only when there is a right side call.

🌳 STEP 3 — Again Go Left

Call:

mergeSort(0,0)

Tree:

                (0,3)
               /
           (0,1)
           /
       (0,0)

Now (0,0) is base case → returns immediately.

🌳 STEP 4 — Now Go Right of (0,1)

Now (0,0) return karel ani jail parent kade. Parent mhanel, ayy mi maz execution ardhvat (half) madhech sodun aalo hoto, aata mi te continue
karel.
Hya line pasun tyala child call kela hota. mergeSort(arr, left, mid); Mhanje hya line chya pudhun mala execution continue karayach aahe.
Aata to baghel are mala tr right side la call karayacha aahe. So right call hoil. (0,1) ha parent hota. Hyach values use karun mhanje
parent chyach values use karun call jato child la. 0+1/2 = 0. so mid is 0. So for (0,1) (0,0 : left to mid) is right call and (1,1 : mid+1, right)
is the right call and currently we are maling right call (1,1).

Call:

mergeSort(1,1)

Tree:

                (0,3)
               /
           (0,1)
           /    \
       (0,0)  (1,1)

(1,1) is base case → returns.
Now (0,1) parent kade children return karenl tevha (0,1) mhanel ki mi maz execution complete karat hoto ani aata mi left call complete 
kela aahe, right call pn complete kela aahe , so next line of code kay aahe  mergeTwoArrays(arr, left, mid, right);
Now me hya call sathi both left side ani right side values la merge karel. 

So, (0,1) was parent.
It gave left call and left returned to parent.
It gave right call and left returned to parent.
It gave mergeArray call. Now this call is of (0,1) And since both of the children have returned their arrays so now these (0,1)'s
call will merge them and now this will also return sorted array to the parent (0,1). Why sorted array, because while mergeing 
we use two indices one for left child and one for right. And remember the arrays we pass after mergine will be sorted.
How sorted. Imagine we have the last call.
[24][18]
left call will be 24
right call will be 18
array left = [24] and array right = [18]
Now one pointer is on 24 and one pointer is on 18.
Those will have lower value will be considered first and then greater values.
so first 18 and then 24. So the two size array 18,24 will be sorted and they are passed to the parent.
This is how sorting is done.

And the same will happen for every call.



🔄 STEP 5 — MERGE (0,0) & (1,1)

Now both children of (0,1) are done.

So we merge:

mergeTwoArrays(0,0,1)

Left half sorted.

We now return to parent (0,3).

🌳 STEP 6 — Now Go Right of Root

Call:

mergeSort(2,3)

Tree:

                (0,3)
               /     \
           (0,1)     (2,3)
           /    \
       (0,0)  (1,1)


🌳 STEP 7 — Go Left of (2,3)

Call:

mergeSort(2,2)

Tree:

                (0,3)
               /     \
           (0,1)     (2,3)
           /    \      /
       (0,0)  (1,1)  (2,2)

Base case → return.

🌳 STEP 8 — Go Right of (2,3)

Call:

mergeSort(3,3)

Tree:

                (0,3)
               /     \
           (0,1)     (2,3)
           /    \      /   \
       (0,0)  (1,1)  (2,2) (3,3)

Base case → return.

🔄 STEP 9 — MERGE (2,2) & (3,3)
mergeTwoArrays(2,2,3)


Right half sorted.

Return to root.

🔄 STEP 10 — FINAL MERGE

Now both halves are sorted:

mergeTwoArrays(0,1,3)

Entire array sorted.

🔥 Final Recursion Tree (Complete View)
                        (0,3)
                       /      \
                  (0,1)        (2,3)
                 /     \       /     \
            (0,0)   (1,1)  (2,2)   (3,3)


*/

//___________________________________________________________________________________________________________________________________________
// very imporatant realisation
//___________________________________________________________________________________________________________________________________________

/*

Forget everything that there are these many children and we have to do n number of calls and this will do that and bla bla bla.

See, we have 3 function calls.
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
mergeTwoArrays(arr, left, mid, right);

Imagine there will be one parent. 
The parent will call for these three calls in sequence.
First this call mergeSort(arr, left, mid);.
Second this call mergeSort(arr, mid + 1, right);
And third this call mergeTwoArrays(arr, left, mid, right);

Menas we divide the array into left part and then we divide it into right part and then we merge them(in merge we sort them as weell).

        (0,3)
       /      \
  (0,1)        (2,3)

  divide into left half
  divide into right half
  and merge them while sorting

*/

//___________________________________________________________________________________________________________________________________________
// Question
//are we sorting using two pointers and then merging and if yes this is not only mergine this is sorting and then merging
//___________________________________________________________________________________________________________________________________________

/*

Answer:

❌ No, we are NOT sorting inside merge.
✅ Sorting already happened due to recursion.
Merge only combines two already sorted arrays
It keep on dividing so at the end of the day we just have two values in the final call say 8 and 3.
Now we have to combine/merge 8 and 3. 8 from left call and 3 from right call.
But the question is should we wrtie 8,3 or 3,8. So we choose to write 3,8.
We just write 3  first and then 8 using two pointer.

Now we pass this (3,8) to the parent.
Now this parent will also acts as someone else's child means now the parent is child for someone means consider it is the left child.
So on left we got (3,8) similarly from some right child we would have got 2, 51, imagine this.

Now left child having (3,8) and right child having 2, 51.

    parent
    /   \
(3,8)   (2,51)

Now again when we merge this we dont sort them, they are already sorted we just choose theie order that who will come first and 
here we direclty change this order in the original array we directly override original array.
Use two pointer, one ptr on left and one on right child.
write 2 first thn 3 then 8 then 51 and again pass this (2,3,8,51) to its parent. And So On......


*/

//___________________________________________________________________________________________________________________________________________
// understanding the merge function
//___________________________________________________________________________________________________________________________________________

/*

We have two array to merge and those two arrays are actually one array from left to right one array but from left to middle first array
and from  mid +1 to right second array.
void mergeTwoArrays(int arr[], int low, int mid, int high)
{

[x] [x] [x]    || [3] [2] [1] [8]  ||    [x] [x] [x] [x] 
Now those subarray after dividing and splitting could be anywhere in the array. So we calculate their legth using low, mid , high.
    int n1 = mid - low + 1;

    n2 = high - (mid+1) + 1 = high - mid - 1 + 1 
    int n2 = high - mid;

[x] [x] [x]    || [3] [2] [1] [8]  ||    [x] [x] [x] [x] 
here (3,2), (1,8) are being overwritten into original array while merging. SO we have to make copies of those two array as we will
overwrite it. So we make two temporary arrays and store elements in that.
    int left_arr[n1];
    int right_arr[n2];

    for (int i = 0; i < n1; i++)
    {
the array could be anywhere in the original array so we get the index using low and thereafter we increment using i.
        left_arr[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
same here but using mid+1 for the right half
        right_arr[i] = arr[mid + 1 + i];
    }

now we will place that element which is smaller while overwriting. So use two pointer. And remember that in original array our array 
starts at index low.

index for left array
    int i = 0;
j for right array
    int j = 0;
    int k = low;

if element at ith is smaller put ith ele first otherwise put jth.
    while (i < n1 && j < n2)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        else // if(right_arr[j] < left_arr[i])
        {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
    }

if ith element remains after it then place them. remember that the left half and right half is sorted in themselves so we can directly place it.
    while (i < n1)
    {
        arr[k] = left_arr[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = right_arr[j];
        k++;
        j++;
    }
}

*/

//___________________________________________________________________________________________________________________________________________
// Timespace, logic
//___________________________________________________________________________________________________________________________________________

/*



// Time Complexity: O(n log n)

// The algorithm consistently divides the array into halves, which results in log n levels of recursion.
// At each level of recursion, the mergeTwoArrays function processes every element of the array once, which takes O(n) time.
// The total time is the work at each level (O(n)) multiplied by the number of levels (O(log n)), giving a total time complexity 
// of O(n log n) in all cases (best, average, and worst).

// Space Complexity: O(n)

// The primary consumer of space is the mergeTwoArrays function, which creates temporary arrays (left_arr and right_arr) to hold 
// the subarrays being merged.
// Therefore, the space complexity is O(n) because it requires auxiliary space proportional to the size of the input array.



// logic:


// Merge Sort is a highly efficient, comparison-based sorting algorithm that operates on the divide-and-conquer principle. The process can be
// broken down into three main steps :

// Divide: The algorithm starts by splitting the input array into two equal halves. It then recursively calls itself on each of these halves, 
// continuing to split them until it has many small subarrays, each containing only a single element. By definition, an array with one element 
// is already sorted.

// Conquer: This is the "base case" of the recursion. Since the single-element arrays are already sorted, no further work is needed at this stage.

// Combine (Merge): The algorithm then begins to merge the smaller, sorted subarrays back together. It takes two adjacent sorted subarrays and 
// combines them into a single, larger sorted array. This merging process continues up the chain of recursion until the entire original array is 
// reassembled in a fully sorted order.

// The key to the algorithm's effectiveness lies in the merge step, which can efficiently combine two already-sorted lists in linear time.





*/


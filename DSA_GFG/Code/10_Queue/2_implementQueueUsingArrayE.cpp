#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class myQueue
{
private:
    int *arr;
    int front;
    int size;
    int capacity;

public:
    myQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    ~myQueue()
    {
        delete[] arr;
    }
    
    void enqueue(int x)
    {
 
        if (size == capacity)
        {
            cout << "Queue is full!\n";
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;

        int currRear = (front + size - 1) % capacity;
        return arr[currRear];
    }
};

int main()
{
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
    q.enqueue(40);
    cout << q.getFront() << " " << q.getRear() << endl;
    return 0;
}




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Constructor
myQueue(int cap)
What it does
Assigns a few integers
Allocates an array of size cap
Time Complexity
O(n) where n = cap (array allocation)
Allocation initializes memory → proportional to capacity

| Operation   | Time Complexity |
| ----------- | --------------- |
| Constructor | **O(n)**        |
| enqueue     | **O(1)**        |
| dequeue     | **O(1)**        |
| getFront    | **O(1)**        |
| getRear     | **O(1)**        |


*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*




*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*




*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/


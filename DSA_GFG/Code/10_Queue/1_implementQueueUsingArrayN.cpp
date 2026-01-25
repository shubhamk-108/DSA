/*

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

class MyQueue
{
    int *arr;
    int capacity;
    int size;

public:
    MyQueue(int c)

    {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        arr[size] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[0];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main()
{
    MyQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.getFront() << endl;
    q.dequeue();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.enqueue(40);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

if correct , please give me approach of code, comment my code, then say time and space and then tell which pattern is used to solve problem.

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

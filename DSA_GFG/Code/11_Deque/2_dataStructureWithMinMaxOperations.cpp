/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

struct MyDS
{

    deque<int> dq;

    void insertMin(int x)
    {

        dq.push_front(x);
    }

    void insertMax(int x)
    {

        dq.push_back(x);
    }

    int getMin()
    {

        return dq.front();
    }

    int getMax()
    {

        return dq.back();
    }

    int extractMin()
    {
        int x = dq.front();

        dq.pop_front();

        return x;
    }

    int extractMax()
    {
        int x = dq.back();

        dq.pop_back();

        return x;
    }
};

int main()
{
    struct MyDS ds;

    ds.insertMin(10);
    ds.insertMax(15);
    ds.insertMin(5);

    int x = ds.extractMin();
    cout << x << endl;

    x = ds.extractMax();
    cout << x << endl;

    ds.insertMin(8);

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

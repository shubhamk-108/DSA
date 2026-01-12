#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new int [cap];
        top=-1;
    }
    
    void push(int x){
        if(top==cap-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top]=x;
    }
    
    int pop(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        int res=arr[top];
        top--;
        return res;
    }
    
    int peek(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        return arr[top];
    }
    
    int size(){
        return (top+1);
    }
    
    bool isEmpty(){
        return top==-1;
    }
};

int main()
{
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}
 
// Interview question:
// when we create custom data type then we used struct more than class in cpp. why

/*

Answer:

Short answer
We usually use struct for custom data types because:
Members are public by default
It clearly communicates “this is just a data holder”
It matches how C-style data structures are written
Many STL / DSA examples follow this convention

Key difference: struct vs class
In C++, struct and class are almost identical.
The only real language differences are:
| Feature             | struct   | class     |
| ------------------- | -------- | --------- |
| Default access      | `public` | `private` |
| Default inheritance | `public` | `private` |

2️⃣ Intent matters (very important)
In C++, struct = plain data
class = behavior + abstraction
struct → “This is just data”
class → “This has logic, rules, invariants”

3️⃣ C compatibility & history
struct comes from C
Many low-level and system-style codebases keep using it
Competitive programming + DSA inherited this habit

4️⃣ STL itself uses structs
C++ standard library uses struct heavily:
struct pair {
    T first;
    U second;
};

5️⃣ Performance? ❌ NO difference
Important myth to kill:
❌ struct is faster than class
FALSE
They compile to the same machine code.
Only access control differs at compile time.

*/
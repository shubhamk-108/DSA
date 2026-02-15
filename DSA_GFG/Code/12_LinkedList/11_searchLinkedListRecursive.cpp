#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

int search(Node *head, int x)
{
    if(head == NULL)
        return -1;
    if(head->data == x)
        return 1; 
    else
    {
        int res = search(head->next, x);
        if(res==-1)
            return -1;
        else
            return res +1 ;
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	printlist(head);
	cout<<"Position of element in Linked List: "<<search(head,40);
	return 0;
} 





//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________

/*

How we are calculating position.
For ex: 10,20,30,40,50,60,70. x = 50, ans = pos = 5

function call stack:

search(10)
  → search(20)
      → search(30)
          → search(40)
                → search(50)


Now for 50 we will hit this.
if(head->data == x)
        return 1; 

Now 50 will return 1 and thereafter all remaining funtion will execute its remaining code.
if(res==-1)
    return -1;
else
    return res + 1; 

50 will get res as 1 and will return 1.

Now you will wonder that for remaining function the code is just this.
if(res==-1)
    return -1;
else
    return res + 1; 

Then how it is returning position like 3 then 4 then 5, etc.

That is because even thought the remaining code is this much  for remaining function in call stack but everytime while 
returning to parent it is also saving that result in res variable.

When i return that res = 1 to parent then → search(50) this call also saved result in res variable because we call it like this 
int res = search(head->next, x);

When this call → search(40) start its remaining execution at that time its child aready had stored res as 1.
So it uses that res and now pass 1 + 1 = 2 to its parent. It not only passes but store this 2 result in res variable.

Similarly,
→ search(30) :  pass 2 + 1 = 3 and store 3 as res.
→ search(20) : pass 3 + 1 = 4 and store 4 as res
→ search(10) : pass 4 + 1 = 5 and store 5 as res And this returns final res as 5 which is our position.
   
      

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*
Go forward recursively until:
the list ends (head == NULL), or
the key is found (head->data == x)
When the key is found:
return 1 (base position from that node)
While returning back (backtracking):
each previous node adds +1
this builds the position from the original head
If key is not found:
propagate -1 all the way back



*/


//___________________________________________________________________________________________________________________________________________
// time space
//___________________________________________________________________________________________________________________________________________


/*
both O(n)
*/

#include <iostream>
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

Node * deleteHead(Node *head)
{
    if(head==NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete(head);
        return temp;
    }
}


int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	head = deleteHead(head);
	printlist(head);
	
	return 0;
} 


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(1) → Only a constant number of operations.
Space Complexity: O(1)
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Check if the list is empty:
If head == NULL, return NULL immediately. This avoids segmentation faults.
Store the second node:
Node* temp = head->next;
This will be the new head after deletion.
Delete the old head:
delete head; frees the memory (important in C++ to avoid memory leaks).
Return the new head:
The list now starts from temp.
Summary: Simply unlink the first node and free memory. The rest of the list remains intact.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


Node* deleteHead(Node* head) {
    if (head == NULL)          // If the list is empty, nothing to delete
        return NULL;           // Return NULL as the new head
    else {
        Node* temp = head->next;  // Store the second node as new head
        delete head;              // Free memory of the old head
        return temp;              // Return new head
    }
}


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/


// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node *reverse(Node *head){
        if(!head || !head->next)
        return head;
        
        Node *newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node *l1=reverse(first);
        Node *l2=reverse(second);
       
        Node* newHead=new Node(-1);
        Node *last=newHead;
        int carry=0;
        while(l1 && l2){
            int val=l1->data+l2->data+carry;
            Node *temp=new Node(val%10);
            carry=val/10;
            last->next=temp;
            last=temp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
               int val=l1->data+carry;
            Node *temp=new Node(val%10);
            carry=val/10;
            last->next=temp;
            last=temp;
            l1=l1->next;
        }
        while(l2){
               int val=l2->data+carry;
            Node *temp=new Node(val%10);
            carry=val/10;
            last->next=temp;
            last=temp;
            l2=l2->next;
        }
        if(carry>0){
            last->next=new Node(carry);
        }
        return reverse(newHead->next);
        
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
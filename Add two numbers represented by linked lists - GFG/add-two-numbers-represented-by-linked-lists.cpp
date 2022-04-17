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
    Node *reverse(struct Node* k){
        Node *prev=NULL;
        while(k){
            Node* next=k->next;
            k->next=prev;
            prev=k;
            k=next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node * k=reverse(first);
        Node *j=reverse(second);
        
        int carry=0;
        Node *dummy=new Node(-1),*last=dummy;
        while(k && j){
            int val=k->data+j->data+carry;
            // cout<<k->data<<" "<<j->data<<endl;
            Node *temp=new Node(val%10);
            last->next=temp;
            // cout<<last->data<<endl;
            last=temp;
            carry=val/10;
            k=k->next;
            j=j->next;
        }
        while(k){
              int val=k->data+carry;
            Node *temp=new Node(val%10);
            last->next=temp;
            last=temp;
            carry=val/10;
            k=k->next;

        }
         while(j){
              int val=j->data+carry;
            Node *temp=new Node(val%10);
            last->next=temp;
            last=temp;
            carry=val/10;
            j=j->next;

        }
        if(carry>0){
            last->next=new Node(carry);
        }
        return reverse(dummy->next);
        
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
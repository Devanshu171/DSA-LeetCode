// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
Node* reverse(Node* k){
    Node *prev=NULL;
    while(k){
        Node*  next=k->next;
        k->next=prev;
        prev=k;
        k=next;
    }
    return prev;
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
       head=reverse(head);
        Node *k=head,*prev=k;
        int carry=1;
            while(carry!=0 && k){
                int val=k->data+carry;
                k->data=val%10;
                // cout<<val<<endl;
                carry=val/10;
                prev=k;
                k=k->next;
            }
            if(carry>0){
                prev->next=new Node(carry);
            }
        
        return reverse(head);
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
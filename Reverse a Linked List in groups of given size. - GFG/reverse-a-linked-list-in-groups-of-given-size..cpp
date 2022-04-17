// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *rev(struct node* begin,struct node* end){
        node* cur=begin->next,*prev=NULL,*first=cur;
        while(cur!=end){
            node *nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        begin->next->next=cur;
        begin->next=prev;
        return first;
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(!head || !head->next || k==1)
        return head;
        node *dummy=new node(-1);
        dummy->next=head;
        node* begin=dummy;
        int i=0;
        while(head){
            i++;
            if(i%k==0 || head->next==NULL){
                begin=rev(begin,head->next);
                head=begin->next;
            }else{
            head=head->next;
            }
        }
        return dummy->next;
        
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends
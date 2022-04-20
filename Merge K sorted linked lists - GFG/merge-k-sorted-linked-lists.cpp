// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node *merge(Node *l1,Node *l2){
        Node *head=NULL,*last=NULL;
        while(l1 && l2){
            if(l1->data<=l2->data){
                if(!last){
                    head=l1;
                }else{
                    last->next=l1;
                }
                last=l1;
                l1=l1->next;
            }else{
                if(!last){
                    head=l2;
                }else{
                    last->next=l2;
                }
                last=l2;
                l2=l2->next;
            }
        }
        if(l1) last->next=l1;
        if(l2) last->next=l2;
        
        return head;
    }
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           
          if(k==0)
          return NULL;
           Node *cur=arr[0];
           Node *head=cur;
           for(int i=1;i<k;i++){
             head= merge(head,arr[i]);
             
           }
           return head;
           
           
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends
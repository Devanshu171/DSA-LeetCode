// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
class triplet{
    public:
  node *left,*right,*pivot;
  triplet(node *l,node *r,node *p){
      left=l;
      right=r;
      pivot=p;
  }
};
triplet* getPivot(node *head){
    node *pivot=head;
    head=head->next;
    pivot->next=NULL;
    node *left=new node(-1),*right=new node(-1);
    node *ll=left,*lr=right;
    while(head){
        if(head->data<pivot->data){
            ll->next=head;
            ll=head;
        }else{
            lr->next=head;
            lr=head;   
        }
        head=head->next;
    }
  if(ll)  ll->next=NULL;
   if(lr) lr->next=NULL;

    return new triplet(left->next,right->next,pivot);
}

node* qs(node *head){
    
    if(!head || !head->next)
    return head;
    
    triplet* cur=getPivot(head);
    node *pivot=cur->pivot;
    cur->left=qs(cur->left);
    cur->right=qs(cur->right);

   pivot->next=cur->right;
    if(!cur->left) return pivot;
    node *temp=cur->left;
    while(temp->next) temp=temp->next;
    temp->next=pivot;
    return cur->left;
    
    
}
void quickSort(struct node **headRef) {
    node *head=*headRef;
    // cout<<head->data<<endl;
   *headRef= qs(*headRef);
}
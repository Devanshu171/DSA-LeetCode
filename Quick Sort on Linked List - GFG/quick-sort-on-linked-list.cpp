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
//   static class Triplet{
//       Node left,pivot,right;
//       Triplet(Node left, Node pivot, Node right){
//           this.left = left;
//           this.pivot = pivot;
//           this.right = right;
//       }
//   }
   
//   static Triplet getPivot(Node head){
//       Node pivot = head;
//       head = head.next;
//       pivot.next = null;
//       Node left = new Node(0);
//       Node right = new Node(0);
//       Node lptr = left;
//       Node rptr = right;
//       while(head!=null){
//           if(head.data<pivot.data){
//               lptr.next = head;
//               lptr = lptr.next;
//           }else{
//               rptr.next = head;
//               rptr = rptr.next;
//           }
//           head = head.next;
//       }
//       if(lptr!=null) lptr.next = null;
//       if(rptr!=null) rptr.next = null;
//       return new Triplet(left.next,pivot,right.next);
//   }
   
//   public static Node quickSort(Node node){
//       //Your code here
//       if(node==null || node.next==null) return node;
//       Triplet curr = getPivot(node);
//       curr.left = quickSort(curr.left);
//       curr.right = quickSort(curr.right);
//       curr.pivot.next = curr.right;
//       if(curr.left==null) return curr.pivot;
//       Node temp = curr.left;
//       while(temp.next!=null) temp = temp.next;
//       temp.next = curr.pivot;
//       return curr.left;
//   }
// }
node *parti(node* head,node* tail){
    node *pvt=head,*cur=head->next,*prev=head;
    while(cur!=tail->next){
        if(pvt->data >cur->data){
            swap(prev->next->data,cur->data);
            prev=prev->next;
        }
        cur=cur->next;
    }
    swap(pvt->data,prev->data);
    return prev;
}
void qs(node * head,node* tail){
    if(!head || !tail || head==tail) return;
    node *pvt=parti(head,tail);
    qs(head,pvt);
    qs(pvt->next,tail);
}
void quickSort(struct node **head) {
    // if(!head || !head->next) return;
    node *tail=*head;
    while(tail->next) tail=tail->next;
    qs(*head,tail);
    
    
}
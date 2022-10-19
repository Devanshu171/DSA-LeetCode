//{ Driver Code Starts
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
    
    void insertNode(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    head = new Node(data);
    tail = head;
    return;
  }

  Node *n = new Node(data);
  tail->next = n;
  tail = n;
  return;
}
    
Node *reverse(Node *&head)
{
  if (head == NULL)
  {
    return NULL;
  }

  Node *prev = NULL;
  Node *curr = head;
  Node *nxt = NULL;

  while (curr != NULL)
  {
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  head = prev;
  return head;
}

Node *sumOfLL(Node *&head1, Node *&head2)
{
  if (head1 == NULL)
  {
    return head2;
  }
  if (head2 == NULL)
  {
    return head1;
  }

  head1 = reverse(head1);
  head2 = reverse(head2);

  Node *newH = NULL;
  Node *newT = newH;
  int carry = 0;
  int sum = 0;
  while (head1 != NULL && head2 != NULL)
  {
    sum = head1->data + head2->data + carry;
    

    if (sum >= 0 && sum <= 9)
    {
      insertNode(newH, newT, sum);
      carry=0;
    }
    else
    {
      int temp = sum % 10;
      insertNode(newH, newT, temp);
      carry = sum / 10;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

// printList(head1);
// cout<<carry<<endl;
// printList(head2);
// print
  while (head2 != NULL)
  {
    sum = head2->data + carry;
    if (sum >= 0 && sum <= 9)
    {
      insertNode(newH, newT, sum);
      carry=0;
    }
    else
    {
      int temp = sum % 10;
      insertNode(newH, newT, temp);
      carry = sum / 10;
    }
    head2 = head2->next;
  }
//   printList(newH);

  while (head1 != NULL)
  {
    sum = head1->data + carry;
    if (sum >= 0 && sum <= 9)
    {
      insertNode(newH, newT, sum);
      carry=0;
    }
    else
    {
      int temp = sum % 10;
      insertNode(newH, newT, temp);
      carry = sum / 10;
    }
    head1 = head1->next;
  }

  if (carry != 0)
  {
    insertNode(newH, newT, carry);
  }

  return reverse(newH);
}
    
    
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
         return sumOfLL(first,second);
    }
};


//{ Driver Code Starts.

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
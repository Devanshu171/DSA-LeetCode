// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends



class Solution{
  public:
  Node *getMid(Node *head){
      Node *slow=head;
      Node *fast=head,*temp=head;
      
      while(fast && fast->next){
          temp=slow;
          slow=slow->next;
          fast=fast->next->next;
      }
      return temp;
  }
    Node *merge(Node *l1,Node *l2){
        if(!l2)
        return l1;
        if(!l1)
        return l2;
        Node *dummy=new Node(-1);
        Node *last=dummy;
        
        while(l1 && l2){
            if(l1->data<=l2->data){
                last->next=l1;
                last=l1;
                l1=l1->next;
            }else{
                last->next=l2;
                last=l2;
                l2=l2->next;
            }
        }
        if(l1) last->next=l1;
        if(l2) last->next=l2;
        
        return dummy->next;
    }
    Node* mergeSort(Node* head) {
        
        if(!head || !head->next)
        return head;
        
        Node *left=head;
        Node *mid=getMid(head);
        Node *right=mid->next;
        mid->next=NULL;
        
       left= mergeSort(left);
       right= mergeSort(right);
        
        Node *result=merge(left,right);
        return result;
        
        
     }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
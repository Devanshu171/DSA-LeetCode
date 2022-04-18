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
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* merge(Node* a,Node* b){
        if(!a) return b;
        if(!b) return a;
        
        Node* dummy=new Node(-1);
        Node* last=dummy;
        while( a && b){
            if(a->data<=b->data){
                last->next=a;
                last=a;
                a=a->next;
            }else{
                 
                last->next=b;
                last=b;
                b=b->next;
            }
        }
        if(a) last->next=a;
        if(b) last->next=b;
        
        return dummy->next;
    }
    Node* findMid(Node* k){
        Node* slow=k,*fast=k,*temp;
        
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return temp;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next){
            return head;
        }
        
        Node* mid=findMid(head);
        
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node* res= merge(left,right);
        
        return res;
        
        
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
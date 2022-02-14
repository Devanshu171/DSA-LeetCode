/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        
        if(p==NULL) return q;
        if(q==NULL) return p;
        ListNode*head,*last=NULL;
        if(p->val<=q->val){
            head=p;
            p=p->next;
            head->next=last;
            last=head;
        }
        else{
            head=q;
            q=q->next;
            head->next=last;
            last=head;
        }
        
        while(p!=NULL && q!=NULL){
            if(p->val<=q->val){
            last->next=p;
                last=p;
                p=p->next;
                last->next=NULL;
           
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
              last->next=NULL;
        }
        }
        if(p)last->next=p;
        else last->next=q;
        
        return head;

    }
};
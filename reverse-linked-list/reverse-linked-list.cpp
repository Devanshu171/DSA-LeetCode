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
    ListNode* reverseList(ListNode* head) {
        ListNode *k=head;
        ListNode *q,*r;
        q=r=NULL;
        if(head==NULL || head->next==NULL) return head;
        while(k!=NULL){
            
            r=q;
            q=k;
            k=k->next;
            q->next=r;
        }
        return q;
    }
};
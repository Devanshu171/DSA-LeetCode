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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode*p=head->next,*q=head;
        
        
        while(p){
            if(p->val==q->val){
                ListNode* temp=p;
                p=p->next;
                q->next=temp->next;
                delete temp; 
            }
            else{
                q=p;
                p=p->next;
            }
        }
        return head;
    }
};
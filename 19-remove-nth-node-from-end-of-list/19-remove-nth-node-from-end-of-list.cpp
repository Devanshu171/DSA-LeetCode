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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode *newHead=new ListNode(-1),*slow=newHead,*fast=newHead;
        newHead->next=head;
        for(int i=0;i<n;i++) fast=fast->next;
        ListNode *prev=NULL;
        while(fast){
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }
        prev->next=slow->next;
        delete slow;
        return newHead->next;
        
        
    }
};
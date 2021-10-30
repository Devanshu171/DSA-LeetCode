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
    ListNode* rotateRight(ListNode* head, int n) {
        
        if(n==0 || head==NULL || head->next==NULL)
            return head;
        
        int len=0;
        ListNode *k=head,*pre;
        while(k!=NULL){
            pre=k;
            k=k->next;
            len++;
        }
        pre->next=head;
        
        k=head;
        n=n%len;
        
        for(int i=0;i<len-n-1;i++){
            k=k->next;
        }
        head=k->next;
        k->next=NULL;
        
        return head;
    }
};
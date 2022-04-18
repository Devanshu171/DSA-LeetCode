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
     ListNode* merge(ListNode* a,ListNode* b){
        if(!a) return b;
        if(!b) return a;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* last=dummy;
        while( a && b){
            if(a->val<=b->val){
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

        if(b)  last->next=b;

        return dummy->next;
    }
    ListNode* findMid(ListNode* k){
        ListNode* slow=k,*fast=k,*temp;
        
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return temp;
    }
    ListNode* sortList(ListNode* head) {
          if(!head || !head->next){
            return head;
        }
        
        ListNode* mid=findMid(head);
        
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode* res= merge(left,right);
        
        return res;
    }
};
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
     ListNode *merge(ListNode *l1,ListNode *l2){
        ListNode *head=NULL,*last=NULL;
         if(!l1) return l2;
         if(!l2) return l1;
        while(l1 && l2){
            if(l1->val<=l2->val){
                if(!last){
                    head=l1;
                }else{
                    last->next=l1;
                }
                last=l1;
                l1=l1->next;
            }else{
                if(!last){
                    head=l2;
                }else{
                    last->next=l2;
                }
                last=l2;
                l2=l2->next;
            }
        }
        if(l1) last->next=l1;
        if(l2) last->next=l2;
        
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          
         int k=lists.size();
              if(k==0)
          return NULL;
        
           ListNode *head=lists[0];
           for(int i=1;i<k;i++){
             head= merge(head,lists[i]);
             
           }
           return head;
           
    }
};
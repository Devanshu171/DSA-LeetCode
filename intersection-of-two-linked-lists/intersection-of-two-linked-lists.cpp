/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        
            ListNode *ptr1=headA,*ptr2=headB;
        
             int l1=0,l2=0;
        
        while(ptr1!=NULL){
        
                ptr1=ptr1->next;
                l1++;
            }
        
            while(ptr2!=NULL){
                ptr2=ptr2->next;
                l2++;
            }
        
        
        ptr1=headA; ptr2=headB;
        
            int diff=abs(l1-l2);
            
            if(l1>l2){
                while(diff){
                    ptr1=ptr1->next;
                    diff--;
                }
            }
                
                else
                    while(diff) {
                        ptr2=ptr2->next;
                        diff--;
                    }
            
            
        
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1==ptr2)
                return ptr1;
            
        ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        
        return NULL;
        
    }
};
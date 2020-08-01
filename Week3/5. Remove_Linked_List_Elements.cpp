/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        ListNode* current = head, *prev = head;
        //ListNode* prev = head;
        
        
        while(current!=NULL){
            
            if(current->val == val){
                prev->next = current->next;
                //if the first element == val
                if(head->val == val && head == prev){
                    head = head->next;
                    prev = head;
                    }
                }
            else{
                prev = current;
                }
            
            current = current->next;
        }
        
        return head;
        
/*        if(!head)
            return head;
        ListNode* current = head, *prev = head;
        while(current != NULL){
            if (current->val == val){
                prev->next = current->next;
                //current->next = NULL;
                if (head->val == val && head == prev){
                    head = head->next;
                    prev = head;
                }
            }
            else{
                prev = current;
            }
            
            current = current->next;
        }
        
    return head;*/
        
        
        
    }
};

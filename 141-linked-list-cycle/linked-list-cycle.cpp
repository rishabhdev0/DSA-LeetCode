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
    bool hasCycle(ListNode *head) {
       if(head == nullptr || head->next == nullptr){
        return false;
       }
        ListNode*slow=head;
        ListNode*fast=head;
        while(slow!=nullptr && fast!=nullptr){
         fast=fast->next;
         if(fast!=nullptr){
            fast=fast->next;
         }
         slow=slow->next;
         if(slow==fast){
            return slow;
         }
        }
        return false;
    }
};
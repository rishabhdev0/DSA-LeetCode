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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* dummy_node = new ListNode(-1);
        dummy_node->next = head;
        ListNode* prev = dummy_node;

        for(int i = 1;i<left;i++){
            prev = prev->next;
        }
        ListNode* forward = nullptr;
        ListNode* curr = prev->next;

     for(int i = left;i<right;i++){
      forward = curr->next; 
      curr->next = forward->next;
      forward->next = prev->next;
      prev->next = forward;
     }
     return dummy_node->next;
    }
};
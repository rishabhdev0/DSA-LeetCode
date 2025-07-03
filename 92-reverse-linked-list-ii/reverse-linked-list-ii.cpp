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
        ListNode* curr = prev->next;

     for(int i = 1 ;i<=right- left;i++){
      ListNode* temp = prev->next; 
      prev->next = curr->next;
      curr->next = curr->next->next;
      prev->next->next = temp;
     }
     return dummy_node->next;
    }
};
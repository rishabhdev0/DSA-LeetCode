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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode* small_ptr = small;
        ListNode* greater_ptr = greater;
        
        while(head) {
            if(head->val < x) {
                small_ptr->next = head;
                small_ptr = small_ptr->next;
            } else {
                greater_ptr->next = head;
                greater_ptr = greater_ptr->next;
            }
            head = head->next;
        }
        small_ptr->next = greater->next;  
        greater_ptr->next = nullptr;
        return small->next;
    }
};